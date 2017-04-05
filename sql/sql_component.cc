/*
   Copyright (c) 2016, Oracle and/or its affiliates. All rights reserved.

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

#include "../components/mysql_server/server_component.h" // imp_*
#include <mysql/components/my_service.h>
#include "sql_class.h"         // THD
#include "sql_component.h"

bool Sql_cmd_install_component::execute(THD *thd)
{
  my_service<SERVICE_TYPE(persistent_dynamic_loader)> service_dynamic_loader(
    "persistent_dynamic_loader", &imp_mysql_server_registry);
  if (service_dynamic_loader)
  {
    my_error(ER_COMPONENTS_CANT_ACQUIRE_SERVICE_IMPLEMENTATION, MYF(0),
      "persistent_dynamic_loader");
    return true;
  }

  std::vector<const char*> urns(m_urns.size());
  for (size_t i= 0; i < m_urns.size();  ++i)
  {
    urns[i] = m_urns[i].str;
  }
  if (service_dynamic_loader->load(thd, urns.data(), m_urns.size()))
  {
    return true;
  }
  my_ok(thd);
  return false;
}

bool Sql_cmd_uninstall_component::execute(THD *thd)
{
  my_service<SERVICE_TYPE(persistent_dynamic_loader)> service_dynamic_loader(
    "persistent_dynamic_loader", &imp_mysql_server_registry);
  if (service_dynamic_loader)
  {
    my_error(ER_COMPONENTS_CANT_ACQUIRE_SERVICE_IMPLEMENTATION, MYF(0),
      "persistent_dynamic_loader");
    return true;
  }

  std::vector<const char*> urns(m_urns.size());
  for (size_t i= 0; i < m_urns.size(); ++i)
  {
    urns[i] = m_urns[i].str;
  }
  if (service_dynamic_loader->unload(thd, urns.data(), m_urns.size()))
  {
    return true;
  }
  my_ok(thd);
  return false;
}
