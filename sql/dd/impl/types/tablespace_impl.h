/* Copyright (c) 2014, 2016, Oracle and/or its affiliates. All rights reserved.

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

#ifndef DD__TABLESPACE_IMPL_INCLUDED
#define DD__TABLESPACE_IMPL_INCLUDED

#include "my_global.h"

#include "dd/impl/types/entity_object_impl.h" // dd::Entity_object_impl
#include "dd/types/dictionary_object_table.h" // dd::Dictionary_object_table
#include "dd/types/object_type.h"             // dd::Object_type
#include "dd/types/tablespace.h"              // dd::Tablespace
#include "dd/types/tablespace_file.h"         // dd::Tablespace_file

#include <memory>   // std::unique_ptr

namespace dd {

///////////////////////////////////////////////////////////////////////////

class Tablespace_impl : public Entity_object_impl,
                        public Tablespace
{
public:
  Tablespace_impl();

  virtual ~Tablespace_impl();

public:
  virtual const Dictionary_object_table &object_table() const
  { return Tablespace::OBJECT_TABLE(); }

  virtual bool validate() const;

  virtual bool restore_children(Open_dictionary_tables_ctx *otx);

  virtual bool store_children(Open_dictionary_tables_ctx *otx);

  virtual bool drop_children(Open_dictionary_tables_ctx *otx) const;

  virtual bool store_attributes(Raw_record *r);

  virtual bool restore_attributes(const Raw_record &r);

  void serialize(Sdi_wcontext *wctx, Sdi_writer *w) const;

  bool deserialize(Sdi_rcontext *rctx, const RJ_Value &val);

  virtual void debug_print(std::string &outb) const;

public:
  /////////////////////////////////////////////////////////////////////////
  // comment.
  /////////////////////////////////////////////////////////////////////////

  virtual const std::string &comment() const
  { return m_comment; }

  virtual void set_comment(const std::string &comment)
  { m_comment= comment; }

  /////////////////////////////////////////////////////////////////////////
  // options.
  /////////////////////////////////////////////////////////////////////////

  virtual const Properties &options() const
  { return *m_options; }

  virtual Properties &options()
  { return *m_options; }

  virtual bool set_options_raw(const std::string &options_raw);

  /////////////////////////////////////////////////////////////////////////
  // se_private_data.
  /////////////////////////////////////////////////////////////////////////

  virtual const Properties &se_private_data() const
  { return *m_se_private_data; }

  virtual Properties &se_private_data()
  { return *m_se_private_data; }

  virtual bool set_se_private_data_raw(const std::string &se_private_data_raw);

  /////////////////////////////////////////////////////////////////////////
  // m_engine.
  /////////////////////////////////////////////////////////////////////////

  virtual const std::string &engine() const
  { return m_engine; }

  virtual void set_engine(const std::string &engine)
  { m_engine= engine; }

  /////////////////////////////////////////////////////////////////////////
  // Tablespace file collection.
  /////////////////////////////////////////////////////////////////////////

  virtual Tablespace_file *add_file();

  virtual bool remove_file(std::string data_file);

  virtual const Tablespace_file_collection &files() const
  { return m_files; }

  // Fix "inherits ... via dominance" warnings
  virtual Weak_object_impl *impl()
  { return Weak_object_impl::impl(); }
  virtual const Weak_object_impl *impl() const
  { return Weak_object_impl::impl(); }
  virtual Object_id id() const
  { return Entity_object_impl::id(); }
  virtual bool is_persistent() const
  { return Entity_object_impl::is_persistent(); }
  virtual const std::string &name() const
  { return Entity_object_impl::name(); }
  virtual void set_name(const std::string &name)
  { Entity_object_impl::set_name(name); }

private:
  // Fields

  std::string m_comment;
  std::unique_ptr<Properties> m_options;
  std::unique_ptr<Properties> m_se_private_data;
  std::string m_engine;

  // Collections.

  Tablespace_file_collection m_files;

  Tablespace_impl(const Tablespace_impl &src);

  Tablespace *clone() const
  {
    return new Tablespace_impl(*this);
  }
};

///////////////////////////////////////////////////////////////////////////

class Tablespace_type : public Object_type
{
public:
  virtual void register_tables(Open_dictionary_tables_ctx *otx) const;

  virtual Weak_object *create_object() const
  { return new (std::nothrow) Tablespace_impl(); }
};

///////////////////////////////////////////////////////////////////////////

}

#endif // DD__TABLESPACE_IMPL_INCLUDED
