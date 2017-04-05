/* Copyright (c) 2016, Oracle and/or its affiliates. All rights reserved.

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

/* This header file contains type declarations used by UCA code. */

#ifndef STR_UCA_TYPE_H
#define STR_UCA_TYPE_H
/*
  So far we have only Croatian collation needs to reorder Latin and
  Cyrillic group of characters. May add more in future.
*/
#define UCA_MAX_CHAR_GRP 4
enum enum_char_grp
{
  CHARGRP_NONE,
  CHARGRP_CORE,
  CHARGRP_LATIN,
  CHARGRP_CYRILLIC,
  CHARGRP_ARAB,
  CHARGRP_OTHERS
};

struct Weight_boundary
{
  uint16  begin;
  uint16  end;
};

struct Reorder_wt_rec
{
  struct Weight_boundary old_wt_bdy;
  struct Weight_boundary new_wt_bdy;
};

struct Reorder_param
{
  enum enum_char_grp     reorder_grp[UCA_MAX_CHAR_GRP];
  struct Reorder_wt_rec  wt_rec[2 * UCA_MAX_CHAR_GRP];
  uint16                 max_weight;
};

struct Coll_param
{
  struct Reorder_param *reorder_param;
  my_bool               norm_enabled; // false = normalization off, default;
                                      // true = on
};

#endif
