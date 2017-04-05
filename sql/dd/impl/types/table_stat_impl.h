/* Copyright (c) 2014, 2016 Oracle and/or its affiliates. All rights reserved.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   51 Franklin Street, Suite 500, Boston, MA 02110-1335 USA */

#ifndef DD__TABLE_STAT_IMPL_INCLUDED
#define DD__TABLE_STAT_IMPL_INCLUDED

#include "dd/impl/types/entity_object_impl.h" // dd::Entity_object_impl
#include "dd/types/dictionary_object_table.h" // dd::Dictionary_object_table
#include "dd/types/object_type.h"             // dd::Object_type
#include "dd/types/table_stat.h"              // dd::Table_stat

#include <memory>

namespace dd {

///////////////////////////////////////////////////////////////////////////

class Raw_table;
class Transaction;

class Charset;

///////////////////////////////////////////////////////////////////////////

class Table_stat_impl : public Entity_object_impl,
                        public Table_stat
{
public:
  Table_stat_impl()
   :m_table_rows(0),
    m_avg_row_length(0),
    m_data_length(0),
    m_max_data_length(0),
    m_index_length(0),
    m_data_free(0),
    m_auto_increment(0),
    m_checksum(0),
    m_update_time(0),
    m_check_time(0)
  { }

public:
  virtual void debug_print(std::string &outb) const;

  virtual const Dictionary_object_table &object_table() const
  { return Table_stat::OBJECT_TABLE(); }

  virtual bool validate() const;

  virtual bool restore_attributes(const Raw_record &r);
  virtual bool store_attributes(Raw_record *r);

public:

  /////////////////////////////////////////////////////////////////////////
  // schema name.
  /////////////////////////////////////////////////////////////////////////

  virtual const std::string &schema_name() const
  { return m_schema_name; }

  virtual void set_schema_name(const std::string &schema_name)
  { m_schema_name= schema_name; }

  /////////////////////////////////////////////////////////////////////////
  // table name.
  /////////////////////////////////////////////////////////////////////////

  virtual const std::string &table_name() const
  { return m_table_name; }

  virtual void set_table_name(const std::string &table_name)
  { m_table_name= table_name; }

  /////////////////////////////////////////////////////////////////////////
  // table_rows.
  /////////////////////////////////////////////////////////////////////////

  virtual ulonglong table_rows() const
  { return m_table_rows; }

  virtual void set_table_rows(ulonglong table_rows)
  { m_table_rows= table_rows; }

  /////////////////////////////////////////////////////////////////////////
  // avg_row_length.
  /////////////////////////////////////////////////////////////////////////

  virtual ulonglong avg_row_length() const
  { return m_avg_row_length; }

  virtual void set_avg_row_length(ulonglong avg_row_length)
  { m_avg_row_length= avg_row_length; }

  /////////////////////////////////////////////////////////////////////////
  // data_length.
  /////////////////////////////////////////////////////////////////////////

  virtual ulonglong data_length() const
  { return m_data_length; }

  virtual void set_data_length(ulonglong data_length)
  { m_data_length= data_length; }

  /////////////////////////////////////////////////////////////////////////
  // max_data_length.
  /////////////////////////////////////////////////////////////////////////

  virtual ulonglong max_data_length() const
  { return m_max_data_length; }

  virtual void set_max_data_length(ulonglong max_data_length)
  { m_max_data_length= max_data_length; }

  /////////////////////////////////////////////////////////////////////////
  // index_length.
  /////////////////////////////////////////////////////////////////////////

  virtual ulonglong index_length() const
  { return m_index_length; }

  virtual void set_index_length(ulonglong index_length)
  { m_index_length= index_length; }

  /////////////////////////////////////////////////////////////////////////
  // data_free.
  /////////////////////////////////////////////////////////////////////////

  virtual ulonglong data_free() const
  { return m_data_free; }

  virtual void set_data_free(ulonglong data_free)
  { m_data_free= data_free; }

  /////////////////////////////////////////////////////////////////////////
  // auto_increment.
  /////////////////////////////////////////////////////////////////////////

  virtual ulonglong  auto_increment() const
  { return m_auto_increment; }

  virtual void set_auto_increment(ulonglong auto_increment)
  { m_auto_increment= auto_increment; }

  /////////////////////////////////////////////////////////////////////////
  // checksum.
  /////////////////////////////////////////////////////////////////////////

  virtual ulonglong  checksum() const
  { return m_checksum; }

  virtual void set_checksum(ulonglong checksum)
  { m_checksum= checksum; }

  /////////////////////////////////////////////////////////////////////////
  // update_time.
  /////////////////////////////////////////////////////////////////////////

  virtual ulonglong update_time() const
  { return m_update_time; }

  virtual void set_update_time(ulonglong update_time)
  { m_update_time= update_time; }

  /////////////////////////////////////////////////////////////////////////
  // check_time.
  /////////////////////////////////////////////////////////////////////////

  virtual ulonglong check_time() const
  { return m_check_time; }

  virtual void set_check_time(ulonglong check_time)
  { m_check_time= check_time; }


public:
  virtual Object_key *create_primary_key() const;
  virtual bool has_new_primary_key() const;

private:
  // Fields
  std::string m_schema_name;
  std::string m_table_name;

  ulonglong m_table_rows;
  ulonglong m_avg_row_length;
  ulonglong m_data_length;
  ulonglong m_max_data_length;
  ulonglong m_index_length;
  ulonglong m_data_free;
  ulonglong m_auto_increment;
  ulonglong m_checksum;
  ulonglong m_update_time;
  ulonglong m_check_time;

};

///////////////////////////////////////////////////////////////////////////

class Table_stat_type : public Object_type
{
public:
  virtual Weak_object *create_object() const
  { return new (std::nothrow) Table_stat_impl(); }

  virtual void register_tables(Open_dictionary_tables_ctx *otx) const;
};

///////////////////////////////////////////////////////////////////////////

}

#endif // DD__TABLE_STAT_IMPL_INCLUDED
