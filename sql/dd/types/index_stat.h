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

#ifndef DD__INDEX_STAT_INCLUDED
#define DD__INDEX_STAT_INCLUDED


#include "my_global.h" // ulonglong

namespace dd {

///////////////////////////////////////////////////////////////////////////

class Object_type;
class Composite_4char_key;

///////////////////////////////////////////////////////////////////////////

class Index_stat : virtual public Dictionary_object
{
public:
  static const Object_type &TYPE();
  static const Dictionary_object_table &OBJECT_TABLE();

  typedef Composite_4char_key name_key_type;

public:
  /////////////////////////////////////////////////////////////////////////
  // schema name.
  /////////////////////////////////////////////////////////////////////////

  virtual const std::string &schema_name() const = 0;
  virtual void set_schema_name(const std::string &schema_name) = 0;

  /////////////////////////////////////////////////////////////////////////
  // table name.
  /////////////////////////////////////////////////////////////////////////

  virtual const std::string &table_name() const = 0;
  virtual void set_table_name(const std::string &table_name) = 0;

  /////////////////////////////////////////////////////////////////////////
  // index name.
  /////////////////////////////////////////////////////////////////////////

  virtual const std::string &index_name() const = 0;
  virtual void set_index_name(const std::string &index_name) = 0;

  /////////////////////////////////////////////////////////////////////////
  // column name.
  /////////////////////////////////////////////////////////////////////////

  virtual const std::string &column_name() const = 0;
  virtual void set_column_name(const std::string &column_name) = 0;

  /////////////////////////////////////////////////////////////////////////
  // cardinality.
  /////////////////////////////////////////////////////////////////////////

  virtual ulonglong cardinality() const = 0;
  virtual void set_cardinality(ulonglong cardinality) = 0;

};

///////////////////////////////////////////////////////////////////////////

}

#endif // DD__INDEX_STAT_INCLUDED
