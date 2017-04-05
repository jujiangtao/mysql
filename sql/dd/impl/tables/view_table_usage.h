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

#ifndef DD_TABLES__VIEW_TABLE_USAGE_INCLUDED
#define DD_TABLES__VIEW_TABLE_USAGE_INCLUDED

#include "my_global.h"

#include "dd/object_id.h"                    // dd::Object_id
#include "dd/impl/types/object_table_impl.h" // dd::Object_table_impl

namespace dd {
  class Object_key;
namespace tables {

///////////////////////////////////////////////////////////////////////////

class View_table_usage : public Object_table_impl
{
public:
  static const View_table_usage &instance();

  static const std::string &table_name()
  {
    static std::string s_table_name("view_table_usage");
    return s_table_name;
  }

public:
  enum enum_fields
  {
    FIELD_VIEW_ID,
    FIELD_TABLE_CATALOG,
    FIELD_TABLE_SCHEMA,
    FIELD_TABLE_NAME
  };

public:
  View_table_usage();

  virtual const std::string &name() const
  { return View_table_usage::table_name(); }

public:
  static Object_key *create_key_by_view_id(Object_id view_id);

  static Object_key *create_primary_key(Object_id view_id,
                                        const std::string &table_catalog,
                                        const std::string &table_schema,
                                        const std::string &table_name);

  static Object_key *create_key_by_name(const std::string &table_catalog,
                                        const std::string &table_schema,
                                        const std::string &table_name);
};

///////////////////////////////////////////////////////////////////////////

}
}

#endif // DD_TABLES__VIEW_TABLE_USAGE_INCLUDED
