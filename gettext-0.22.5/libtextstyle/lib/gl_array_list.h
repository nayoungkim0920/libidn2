#include "config.h"
/* Sequential list data type implemented by an array.
   Copyright (C) 2006, 2009-2024 Free Software Foundation, Inc.
   Written by Bruno Haible <bruno@clisp.org>, 2006.

   This file is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#ifndef _GL_ARRAY_LIST_H
#define _GL_ARRAY_LIST_H

#include "gl_list.h"
#include "xsize.h" /*추가*/

/* If DLL_VARIABLE is not defined, define it as empty. */
#ifndef DLL_VARIABLE
#define DLL_VARIABLE
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern DLL_VARIABLE const struct gl_list_implementation gl_array_list_implementation;
#define GL_ARRAY_LIST &gl_array_list_implementation

#ifdef __cplusplus
}
#endif

#endif /* _GL_ARRAY_LIST_H */