/* Copyright (c) 2015, 2016, Oracle and/or its affiliates. All rights reserved.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#include "dd_view.h"

#include "dd_table_share.h"                   // dd_get_mysql_charset
#include "item_func.h"                        // Item_func
#include "log.h"                              // sql_print_error, sql_print_..
#include "parse_file.h"                       // PARSE_FILE_TIMESTAMPLENGTH
#include "sql_class.h"                        // THD
#include "sql_tmp_table.h"                    // create_tmp_field
#include "transaction.h"                      // trans_commit
#include "sp_head.h"                          // sp_name
#include "sp.h"                               // Sroutine_hash_entry

#include "dd/dd.h"                            // dd::get_dictionary
#include "dd/dd_table.h"                      // fill_dd_columns_from_create_*
#include "dd/dictionary.h"                    // dd::Dictionary
#include "dd/properties.h"                    // dd::Properties
#include "dd/cache/dictionary_client.h"       // dd::cache::Dictionary_client
#include "dd/impl/dictionary_impl.h"          // default_catalog_name
#include "dd/types/abstract_table.h"          // dd::enum_table_type
#include "dd/types/schema.h"                  // dd::Schema
#include "dd/types/view.h"                    // dd::View
#include "dd/types/view_table.h"              // dd::View_table
#include "dd/types/view_routine.h"            // dd::View_routine

namespace dd {

static ulonglong dd_get_old_view_check_type(dd::View::enum_check_option type)
{
  switch (type)
  {
  case dd::View::CO_NONE:
    return VIEW_CHECK_NONE;

  case dd::View::CO_LOCAL:
    return VIEW_CHECK_LOCAL;

  case dd::View::CO_CASCADED:
    return VIEW_CHECK_CASCADED;

  }

/* purecov: begin deadcode */
  sql_print_error("Error: Invalid view check option.");
  DBUG_ASSERT(false);

  return VIEW_CHECK_NONE;
/* purecov: end */
}


/** For enum in dd::View */
static dd::View::enum_check_option dd_get_new_view_check_type(ulonglong type)
{
  switch (type)
  {
  case VIEW_CHECK_NONE:
    return dd::View::CO_NONE;

  case VIEW_CHECK_LOCAL:
    return dd::View::CO_LOCAL;

  case VIEW_CHECK_CASCADED:
    return dd::View::CO_CASCADED;

  }

/* purecov: begin deadcode */
  sql_print_error("Error: Invalid view check option.");
  DBUG_ASSERT(false);

  return dd::View::CO_NONE;
/* purecov: end */
}


static enum enum_view_algorithm
dd_get_old_view_algorithm_type(dd::View::enum_algorithm type)
{
  switch (type)
  {
  case dd::View::VA_UNDEFINED:
    return VIEW_ALGORITHM_UNDEFINED;

  case dd::View::VA_TEMPORARY_TABLE:
    return VIEW_ALGORITHM_TEMPTABLE;

  case dd::View::VA_MERGE:
    return VIEW_ALGORITHM_MERGE;

  }

/* purecov: begin deadcode */
  sql_print_error("Error: Invalid view algorithm.");
  DBUG_ASSERT(false);

  return VIEW_ALGORITHM_UNDEFINED;
/* purecov: end */
}


static dd::View::enum_algorithm
dd_get_new_view_algorithm_type(enum enum_view_algorithm type)
{
  switch (type)
  {
  case VIEW_ALGORITHM_UNDEFINED:
    return dd::View::VA_UNDEFINED;

  case VIEW_ALGORITHM_TEMPTABLE:
    return dd::View::VA_TEMPORARY_TABLE;

  case VIEW_ALGORITHM_MERGE:
    return dd::View::VA_MERGE;

  }

/* purecov: begin deadcode */
  sql_print_error("Error: Invalid view algorithm.");
  DBUG_ASSERT(false);

  return dd::View::VA_UNDEFINED;
/* purecov: end */
}


static ulonglong
dd_get_old_view_security_type(dd::View::enum_security_type type)
{
  switch (type)
  {
  case dd::View::ST_DEFAULT:
    return VIEW_SUID_DEFAULT;

  case dd::View::ST_INVOKER:
    return VIEW_SUID_INVOKER;

  case dd::View::ST_DEFINER:
    return VIEW_SUID_DEFINER;

  }

/* purecov: begin deadcode */
  sql_print_error("Error: Invalid view security type.");
  DBUG_ASSERT(false);

  return VIEW_SUID_DEFAULT;
/* purecov: end */
}


static dd::View::enum_security_type
dd_get_new_view_security_type(ulonglong type)
{
  switch (type)
  {
  case VIEW_SUID_DEFAULT:
    return dd::View::ST_DEFAULT;

  case VIEW_SUID_INVOKER:
    return dd::View::ST_INVOKER;

  case VIEW_SUID_DEFINER:
    return dd::View::ST_DEFINER;

  }

/* purecov: begin deadcode */
  sql_print_error("Error: Invalid view security type.");
  DBUG_ASSERT(false);

  return dd::View::ST_DEFAULT;
/* purecov: end */
}


/**
  Method to fill view columns from the first SELECT_LEX of view query.

  @param  thd       Thread Handle.
  @param  view_obj  DD view object.
  @param  view      TABLE_LIST object of view.

  @retval false     On Success.
  @retval true      On failure.
*/

static bool fill_dd_view_columns(THD *thd,
                                 View *view_obj,
                                 const TABLE_LIST *view)
{
  DBUG_ENTER("fill_dd_view_columns");

  // Helper class which takes care restoration of THD::variables.sql_mode and
  // delete handler created for dummy table.
  class Context_handler
  {
  public:
    Context_handler(THD *thd, handler *file)
      : m_thd(thd),
        m_file(file)
    {
      m_sql_mode= m_thd->variables.sql_mode;
      m_thd->variables.sql_mode= 0;
    }
    ~Context_handler()
    {
      m_thd->variables.sql_mode= m_sql_mode;
      delete m_file;
    }
  private:
    // Thread Handle.
    THD *m_thd;

    // Handler object of dummy table.
    handler *m_file;

    // sql_mode.
    sql_mode_t m_sql_mode;
  };

  // Creating dummy TABLE and TABLE_SHARE objects to prepare Field objects from
  // the items of first SELECT_LEX of the view query. We prepare these once and
  // reuse them for all the fields.
  TABLE table;
  TABLE_SHARE share;
  init_tmp_table_share(thd, &share, "", 0, "", "");
  memset(&table, 0, sizeof(table));
  table.s= &share;
  handler *file= get_new_handler(&share, thd->mem_root,
                                 ha_default_temp_handlerton(thd));
  if (file == nullptr)
  {
    my_error(ER_STORAGE_ENGINE_NOT_LOADED, MYF(0), view->db, view->table_name);
    DBUG_RETURN(true);
  }

  Context_handler ctx_handler(thd, file);

  // Iterate through all the items of first SELECT_LEX of the view query.
  Item *item;
  List<Create_field> create_fields;
  List_iterator_fast<Item> it(thd->lex->select_lex->item_list);
  while ((item= it++) != nullptr)
  {
    bool is_sp_func_item= false;
    // Create temporary Field object from the item.
    Field *tmp_field;
    if (item->type() == Item::FUNC_ITEM)
    {
      if (item->result_type() != STRING_RESULT)
      {
        is_sp_func_item=
          ((static_cast<Item_func *>(item))->functype() == Item_func::FUNC_SP);
        /*
          INT Result values with MY_INT32_NUM_DECIMAL_DIGITS digits may or may
          not fit into Field_long so make them Field_longlong.
        */
        if (is_sp_func_item == false &&
            item->result_type() == INT_RESULT &&
            item->max_char_length() >= (MY_INT32_NUM_DECIMAL_DIGITS - 1))
        {
          tmp_field= new (thd->mem_root) Field_longlong(item->max_char_length(),
                                                        item->maybe_null,
                                                        item->item_name.ptr(),
                                                        item->unsigned_flag);
          if (tmp_field)
            tmp_field->init(&table);
        }
        else
          tmp_field= item->tmp_table_field(&table);
      }
      else
      {
        switch (item->field_type())
        {
        case MYSQL_TYPE_TINY_BLOB:
        case MYSQL_TYPE_MEDIUM_BLOB:
        case MYSQL_TYPE_LONG_BLOB:
        case MYSQL_TYPE_BLOB:
          // Packlength is not set for blobs as per the length in
          // tmp_table_field_from_field_type, so creating the blob field by
          // passing set_packlenth value as "true" here.
          tmp_field= new (thd->mem_root) Field_blob(item->max_length,
                                                    item->maybe_null,
                                                    item->item_name.ptr(),
                                                    item->collation.collation,
                                                    true);

          if (tmp_field)
            tmp_field->init(&table);
          break;
        default:
          tmp_field= item->tmp_table_field_from_field_type(&table, false);
        }
      }
    }
    else
    {
      Field *from_field, *default_field;
      tmp_field= create_tmp_field(thd, &table, item, item->type(),
                                  nullptr,
                                  &from_field, &default_field,
                                  false, false, false, false);
    }
    if (!tmp_field)
    {
      my_error(ER_OUT_OF_RESOURCES, MYF(ME_FATALERROR));
      DBUG_RETURN(true);
    }

    // We have to take into account both the real table's fields and
    // pseudo-fields used in trigger's body. These fields are used to copy
    // defaults values later inside constructor of the class Create_field.
    Field *orig_field= nullptr;
    if (item->type() == Item::FIELD_ITEM ||
        item->type() == Item::TRIGGER_FIELD_ITEM)
      orig_field= ((Item_field *) item)->field;

    // Create object of type Create_field from the tmp_field.
    Create_field *cr_field= new (thd->mem_root) Create_field(tmp_field,
                                                             orig_field);
    if (cr_field == nullptr)
    {
      my_error(ER_OUT_OF_RESOURCES, MYF(ME_FATALERROR));
      DBUG_RETURN(true);
    }

    if (is_sp_func_item)
      cr_field->field_name= item->item_name.ptr();
    cr_field->after= nullptr;
    cr_field->offset= 0;
    cr_field->pack_length_override= 0;
    cr_field->create_length_to_internal_length();
    cr_field->maybe_null= !(tmp_field->flags & NOT_NULL_FLAG);
    cr_field->is_zerofill= (tmp_field->flags & ZEROFILL_FLAG);
    cr_field->is_unsigned= (tmp_field->flags & UNSIGNED_FLAG);

    create_fields.push_back(cr_field);
  }

  // Fill view columns information from the Create_field objects.
  DBUG_RETURN(fill_dd_columns_from_create_fields(thd, view_obj,
                                                 create_fields, file));
}


/**
  Method to fill base table and view names used by view query in DD
  View object.

  @param  view_obj       DD view object.
  @param  view           TABLE_LIST object of view.
  @param  query_tables   View query tables list.
*/

static void fill_dd_view_tables(View *view_obj, const TABLE_LIST *view,
                                const TABLE_LIST *query_tables)
{
  DBUG_ENTER("fill_dd_view_tables");

  for (const TABLE_LIST *table= query_tables; table != nullptr;
       table= table->next_global)
  {
    // Skip tables which are not diectly referred by the view and not
    // a non-temporary user table.
    {
      if (table->referencing_view && table->referencing_view != view)
        continue;
      else if (is_temporary_table(const_cast<TABLE_LIST *>(table)))
        continue;
      else if (get_dictionary()->is_dd_schema_name(table->get_db_name()))
        continue;
      else
      {
        LEX_STRING db_name= { const_cast<char*>(table->get_db_name()),
                               strlen(table->get_db_name()) };
        LEX_STRING table_name= { const_cast<char*>(table->get_table_name()),
                                 strlen(table->get_table_name()) };

        if (get_table_category(db_name, table_name) != TABLE_CATEGORY_USER)
          continue;
      }
    }

    LEX_CSTRING db_name;
    LEX_CSTRING table_name;
    if (table->is_view())
    {
      db_name= table->view_db;
      table_name= table->view_name;
    }
    else
    {
      db_name= { table->db, table->db_length };
      table_name= { table->table_name, table->table_name_length };
    }

    // Avoid duplicate entries.
    {
      bool duplicate_vw= false;
      for (const View_table *vw : view_obj->tables())
      {
        if (!strcmp(vw->table_schema().c_str(), db_name.str) &&
            !strcmp(vw->table_name().c_str(), table_name.str))
        {
          duplicate_vw= true;
          break;
        }
      }
      if (duplicate_vw)
        continue;
    }

    View_table *view_table_obj= view_obj->add_table();

    // view table catalog
    view_table_obj->set_table_catalog(Dictionary_impl::default_catalog_name());

    // View table schema
    view_table_obj->set_table_schema(std::string(db_name.str, db_name.length));

    // View table name
    view_table_obj->set_table_name(std::string(table_name.str,
                                               table_name.length));
  }

  DBUG_VOID_RETURN;
}


/**
  Method to fill view routines from the set of routines used by view query.

  @param  view_obj  DD view object.
  @param  routines  Set of routines used by view query.
*/

static void fill_dd_view_routines(
  View *view_obj,
  const SQL_I_List<Sroutine_hash_entry> *routines)
{
  DBUG_ENTER("fill_dd_view_routines");

  // View stored functions.
  for (Sroutine_hash_entry *rt= routines->first; rt; rt= rt->next)
  {
    View_routine *view_sf_obj= view_obj->add_routine();

    char qname_buff[NAME_LEN*2+1+1];
    sp_name sf(&rt->mdl_request.key, qname_buff);

    // view routine catalog
    view_sf_obj->set_routine_catalog(Dictionary_impl::default_catalog_name());

    // View routine schema
    view_sf_obj->set_routine_schema(std::string(sf.m_db.str, sf.m_db.length));

    // View routine name
    view_sf_obj->set_routine_name(std::string(sf.m_name.str, sf.m_name.length));
  }

  DBUG_VOID_RETURN;
}


bool create_view(THD *thd,
                 TABLE_LIST *view,
                 const char *schema_name,
                 const char *view_name)
{
  dd::cache::Dictionary_client *client= thd->dd_client();

  // Check if the schema exists.
  dd::cache::Dictionary_client::Auto_releaser releaser(client);
  const dd::Schema *sch_obj= nullptr;
  if (client->acquire<dd::Schema>(schema_name, &sch_obj))
  {
    // Error is reported by the dictionary subsystem.
    return true;
  }

  if (!sch_obj)
  {
    my_error(ER_BAD_DB_ERROR, MYF(0), schema_name);
    return true;
  }

  // Create dd::View object.
  std::unique_ptr<dd::View> view_obj;
  if (dd::get_dictionary()->is_system_view_name(schema_name, view_name))
  {
    view_obj.reset(sch_obj->create_system_view(thd));
  }
  else
  {
    view_obj.reset(sch_obj->create_view(thd));
  }

  // View name.
  view_obj->set_name(view_name);

  // Set definer.
  view_obj->set_definer(view->definer.user.str, view->definer.host.str);

  // View definition.
  view_obj->set_definition(std::string(view->select_stmt.str,
                                       view->select_stmt.length));

  view_obj->set_definition_utf8(std::string(view->view_body_utf8.str,
                                            view->view_body_utf8.length));

  // Set updatable.
  view_obj->set_updatable(view->updatable_view);

  // Set check option.
  view_obj->set_check_option(dd_get_new_view_check_type(view->with_check));

  // Set algorithm.
  view_obj->set_algorithm(
              dd_get_new_view_algorithm_type(
                (enum enum_view_algorithm) view->algorithm));

  // Set security type.
  view_obj->set_security_type(
              dd_get_new_view_security_type(view->view_suid));

  // Assign client collation ID. The create option specifies character
  // set name, and we store the default collation id for this character set
  // name, which implicitly identifies the character set.
  const CHARSET_INFO *collation= nullptr;
  if (resolve_charset(view->view_client_cs_name.str, system_charset_info,
                      &collation))
  {
    // resolve_charset will not cause an error to be reported if the
    // character set was not found, so we must report error here.
    my_error(ER_UNKNOWN_CHARACTER_SET, MYF(0), view->view_client_cs_name.str);
    return true;
  }

  view_obj->set_client_collation_id(collation->number);

  // Assign connection collation ID.
  if (resolve_collation(view->view_connection_cl_name.str, system_charset_info,
                        &collation))
  {
    // resolve_charset will not cause an error to be reported if the
    // collation was not found, so we must report error here.
    my_error(ER_UNKNOWN_COLLATION, MYF(0), view->view_connection_cl_name.str);
    return true;
  }

  view_obj->set_connection_collation_id(collation->number);

  time_t tm= my_time(0);
  get_date(view->timestamp.str,
           GETDATE_DATE_TIME|GETDATE_GMT|GETDATE_FIXEDLENGTH,
           tm);
  view->timestamp.length= PARSE_FILE_TIMESTAMPLENGTH;

  dd::Properties *view_options= &view_obj->options();
  view_options->set("timestamp", std::string(view->timestamp.str,
                                             view->timestamp.length));
  view_options->set_bool("view_valid", true);

  // Fill view columns information in View object.
  if (fill_dd_view_columns(thd, view_obj.get(), view))
    return true;

  // Fill view tables information in View object.
  fill_dd_view_tables(view_obj.get(), view, thd->lex->query_tables);

  // Fill view routines information in View object.
  fill_dd_view_routines(view_obj.get(), &thd->lex->sroutines_list);

  Disable_gtid_state_update_guard disabler(thd);

  // Store info in DD views table.
  if (client->store(view_obj.get()))
  {
    trans_rollback_stmt(thd);
    // Full rollback in case we have THD::transaction_rollback_request.
    trans_rollback(thd);
    return true;
  }

  return trans_commit_stmt(thd) ||
         trans_commit(thd);
}


void read_view(TABLE_LIST *view,
               const dd::View &view_obj,
               MEM_ROOT *mem_root)
{
  // Fill TABLE_LIST 'view' with view details.
  std::string definer_user= view_obj.definer_user();
  view->definer.user.length= definer_user.length();
  view->definer.user.str= (char*) strmake_root(mem_root,
                                               definer_user.c_str(),
                                               definer_user.length());

  std::string definer_host= view_obj.definer_host();
  view->definer.host.length= definer_host.length();
  view->definer.host.str= (char*) strmake_root(mem_root,
                                               definer_host.c_str(),
                                               definer_host.length());

  // View definition body.
  std::string vd_utf8= view_obj.definition_utf8();
  view->view_body_utf8.length= vd_utf8.length();
  view->view_body_utf8.str= (char*) strmake_root(mem_root,
                                                 vd_utf8.c_str(),
                                                 vd_utf8.length());

  // Get updatable.
  view->updatable_view= view_obj.is_updatable();

  // Get check option.
  view->with_check= dd_get_old_view_check_type(view_obj.check_option());

  // Get algorithm.
  view->algorithm= dd_get_old_view_algorithm_type(view_obj.algorithm());

  // Get security type.
  view->view_suid= dd_get_old_view_security_type(view_obj.security_type());

  // Mark true, if we are reading a system view.
  view->is_system_view=
    (view_obj.type() == dd::enum_table_type::SYSTEM_VIEW);

  // Get definition.
  std::string view_definition= view_obj.definition();
  view->select_stmt.length= view_definition.length();
  view->select_stmt.str= (char*) strmake_root(mem_root,
                                         view_definition.c_str(),
                                         view_definition.length());

  // Get view_client_cs_name. Note that this is the character set name.
  CHARSET_INFO *collation= dd_get_mysql_charset(view_obj.client_collation_id());
  DBUG_ASSERT(collation);
  view->view_client_cs_name.length= strlen(collation->csname);
  view->view_client_cs_name.str= strdup_root(mem_root, collation->csname);

  // Get view_connection_cl_name. Note that this is the collation name.
  collation= dd_get_mysql_charset(view_obj.connection_collation_id());
  DBUG_ASSERT(collation);
  view->view_connection_cl_name.length= strlen(collation->name);
  view->view_connection_cl_name.str= strdup_root(mem_root, collation->name);
}


bool update_view_status(THD *thd, const char *schema_name,
                        const char *view_name, bool status)
{
  dd::cache::Dictionary_client::Auto_releaser releaser(thd->dd_client());
  const dd::View *view= nullptr;
  if (thd->dd_client()->acquire<dd::View>(schema_name, view_name, &view))
    return true;
  if (view == nullptr)
    return false;

  // Update view error status.
  std::unique_ptr<dd::View> new_view(view->clone());
  dd::Properties *view_options= &new_view->options();
  view_options->set_bool("view_valid", status);

  Disable_gtid_state_update_guard disabler(thd);

  // Update DD tables.
  if (thd->dd_client()->update(&view, new_view.get()))
  {
    trans_rollback_stmt(thd);
    trans_rollback(thd);
    return true;
  }

  return (trans_commit_stmt(thd) || trans_commit(thd));
}

} // namespace dd
