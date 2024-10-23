/* Retrieve information about a FILE stream.
   Copyright (C) 2007, 2009-2024 Free Software Foundation, Inc.

   This file is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* This file uses _GL_ATTRIBUTE_PURE, HAVE___FREADABLE, HAVE_STDIO_EXT_H.  */
#if !_GL_CONFIG_H_INCLUDED
 #error "Please include config.h first."
#endif

#include <stdio.h>

/* Return true if the stream STREAM supports reading, false if it supports
   only writing, i.e. if it was opened write-only or append-only.
   STREAM must not be wide-character oriented.
   The result doesn't change until the stream is closed or re-opened.  */

#if HAVE___FREADABLE
/* glibc >= 2.2, Solaris >= 7, UnixWare >= 7.1.4.MP4, Cygwin >= 1.7.34, Android API >= 23, musl libc */

# if HAVE_STDIO_EXT_H
#  include <stdio_ext.h>
# endif
# define freadable(stream) (__freadable (stream) != 0)

#else

# ifdef __cplusplus
extern "C" {
# endif

extern bool freadable (FILE *stream) _GL_ATTRIBUTE_PURE;

# ifdef __cplusplus
}
# endif

#endif
