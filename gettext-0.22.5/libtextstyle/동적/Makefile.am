## Makefile for the toplevel directory of GNU libtextstyle
## Copyright (C) 1995-2022 Free Software Foundation, Inc.
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## Process this file with automake to produce Makefile.in.

AUTOMAKE_OPTIONS = 1.13 gnu no-dependencies subdir-objects
ACLOCAL_AMFLAGS = -I m4 -I gnulib-m4

# The list of subdirectories containing Makefiles.
SUBDIRS = lib tests adhoc-tests doc

# Remove the dynamic library rule
# lib_LTLIBRARIES = libtextstyle.la

# Add a static library rule
noinst_LIBRARIES = libtextstyle.a

libtextstyle_a_SOURCES = \
  lib/foo.c \
  lib/bar.c \
  lib/baz.c 

# Remove any dynamic library specific rules
# if WOE32DLL
# libtextstyle_la_LDFLAGS = -export-dynamic
# endif

EXTRA_DIST = \
  version.sh \
  DEPENDENCIES \
  HACKING \
  autogen.sh \
  gnulib-local/build-aux/moopp \
  gnulib-local/lib/fd-ostream.oo.c \
  gnulib-local/lib/fd-ostream.oo.h \
  gnulib-local/lib/file-ostream.oo.c \
  gnulib-local/lib/file-ostream.oo.h \
  gnulib-local/lib/glibconfig.in.h \
  gnulib-local/lib/glib/ghash.c \
  gnulib-local/lib/glib/ghash.in.h \
  gnulib-local/lib/glib/glist.c \
  gnulib-local/lib/glib/glist.in.h \
  gnulib-local/lib/glib/gmacros.in.h \
  gnulib-local/lib/glib/gmessages.c \
  gnulib-local/lib/glib/gprimes.c \
  gnulib-local/lib/glib/gprimes.in.h \
  gnulib-local/lib/glib/gprintfint.in.h \
  gnulib-local/lib/glib/gstrfuncs.c \
  gnulib-local/lib/glib/gstrfuncs.in.h \
  gnulib-local/lib/glib/gstring.c \
  gnulib-local/lib/glib/gstring.in.h \
  gnulib-local/lib/glib/gtypes.in.h \
  gnulib-local/lib/glib.in.h \
  gnulib-local/lib/glib/README \
  gnulib-local/lib/html-ostream.oo.c \
  gnulib-local/lib/html-ostream.oo.h \
  gnulib-local/lib/html-styled-ostream.oo.c \
  gnulib-local/lib/html-styled-ostream.oo.h \
  gnulib-local/lib/iconv-ostream.oo.c \
  gnulib-local/lib/iconv-ostream.oo.h \
  gnulib-local/lib/libcroco/cr-additional-sel.c \
  gnulib-local/lib/libcroco/cr-additional-sel.h \
  gnulib-local/lib/libcroco/cr-attr-sel.c \
  gnulib-local/lib/libcroco/cr-attr-sel.h \
  gnulib-local/lib/libcroco/cr-cascade.c \
  gnulib-local/lib/libcroco/cr-cascade.h \
  gnulib-local/lib/libcroco/cr-declaration.c \
  gnulib-local/lib/libcroco/cr-declaration.h \
  gnulib-local/lib/libcroco/cr-doc-handler.c \
  gnulib-local/lib/libcroco/cr-doc-handler.h \
  gnulib-local/lib/libcroco/cr-enc-handler.c \
  gnulib-local/lib/libcroco/cr-enc-handler.h \
  gnulib-local/lib/libcroco/cr-fonts.c \
  gnulib-local/lib/libcroco/cr-fonts.h \
  gnulib-local/lib/libcroco/cr-input.c \
  gnulib-local/lib/libcroco/cr-input.h \
  gnulib-local/lib/libcroco/cr-num.c \
  gnulib-local/lib/libcroco/cr-num.h \
  gnulib-local/lib/libcroco/cr-om-parser.c \
  gnulib-local/lib/libcroco/cr-om-parser.h \
  gnulib-local/lib/libcroco/cr-parser.c \
  gnulib-local/lib/libcroco/cr-parser.h \
  gnulib-local/lib/libcroco/cr-parsing-location.c \
  gnulib-local/lib/libcroco/cr-parsing-location.h \
  gnulib-local/lib/libcroco/cr-prop-list.c \
  gnulib-local/lib/libcroco/cr-prop-list.h \
  gnulib-local/lib/libcroco/cr-pseudo.c \
  gnulib-local/lib/libcroco/cr-pseudo.h \
  gnulib-local/lib/libcroco/cr-rgb.c \
  gnulib-local/lib/libcroco/cr-rgb.h \
  gnulib-local/lib/libcroco/cr-selector.c \
  gnulib-local/lib/libcroco/cr-selector.h \
  gnulib-local/lib/libcroco/cr-sel-eng.c \
  gnulib-local/lib/libcroco/cr-sel-eng.h \
  gnulib-local/lib/libcroco/cr-simple-sel.c \
  gnulib-local/lib/libcroco/cr-simple-sel.h \
  gnulib-local/lib/libcroco/cr-statement.c \
  gnulib-local/lib/libcroco/cr-statement.h \
  gnulib-local/lib/libcroco/cr-string.c \
  gnulib-local/lib/libcroco/cr-string.h \
  gnulib-local/lib/libcroco/cr-style.c \
  gnulib-local/lib/libcroco/cr-style.h \
  gnulib-local/lib/libcroco/cr-stylesheet.c \
  gnulib-local/lib/libcroco/cr-stylesheet.h \
  gnulib-local/lib/libcroco/cr-term.c \
  gnulib-local/lib/libcroco/cr-term.h \
  gnulib-local/lib/libcroco/cr-tknzr.c \
  gnulib-local/lib/libcroco/cr-tknzr.h \
  gnulib-local/lib/libcroco/cr-token.c \
  gnulib-local/lib/libcroco/cr-token.h \
  gnulib-local/lib/libcroco/cr-utils.c \
  gnulib-local/lib/libcroco/cr-utils.h \
  gnulib-local/lib/libcroco/libcroco-config.h \
  gnulib-local/lib/libcroco/libcroco.h \
  gnulib-local/lib/libcroco/README \
  gnulib-local/lib/libxml/xmlversion.in.h.diff \
  gnulib-local/lib/memory-ostream.oo.c \
  gnulib-local/lib/memory-ostream.oo.h \
  gnulib-local/lib/moo.h \
  gnulib-local/lib/noop-styled-ostream.oo.c \
  gnulib-local/lib/noop-styled-ostream.oo.h \
  gnulib-local/lib/ostream.oo.c \
  gnulib-local/lib/ostream.oo.h \
  gnulib-local/lib/styled-ostream.oo.c \
  gnulib-local/lib/styled-ostream.oo.h \
  gnulib-local/lib/term-ostream.oo.c \
  gnulib-local/lib/term-ostream.oo.h \
  gnulib-local/lib/term-styled-ostream.oo.c \
  gnulib-local/lib/term-styled-ostream.oo.h \
  gnulib-local/m4/libcroco.m4 \
  gnulib-local/m4/libglib.m4 \
  gnulib-local/m4/moo.m4 \
  gnulib-local/m4/term-ostream.m4 \
  gnulib-local/modules/fd-ostream \
  gnulib-local/modules/file-ostream \
  gnulib-local/modules/html-ostream \
  gnulib-local/modules/html-styled-ostream \
  gnulib-local/modules/iconv-ostream \
  gnulib-local/modules/libcroco \
  gnulib-local/modules/libglib \
  gnulib-local/modules/libxml.diff \
  gnulib-local/modules/memory-ostream \
  gnulib-local/modules/memory-ostream-tests \
  gnulib-local/modules/moo \
  gnulib-local/modules/moo-tests \
  gnulib-local/modules/noop-styled-ostream \
  gnulib-local/modules/ostream \
  gnulib-local/modules/styled-ostream \
  gnulib-local/modules/term-ostream \
  gnulib-local/modules/term-ostream-tests \
  gnulib-local/modules/term-styled-ostream \
  gnulib-local/tests/test-memory-ostream.c \
  gnulib-local/tests/test-term-ostream.c

# Add the static archive to be installed
install: all
	$(INSTALL) -m 755 lib/libtextstyle.a $(prefix)/lib

clean:
	rm -f lib/libtextstyle.a
	$(MAKE) -C $(top_builddir)/lib clean
	$(MAKE) -C $(top_builddir)/tests clean
	$(MAKE) -C $(top_builddir)/adhoc-tests clean
	$(MAKE) -C $(top_builddir)/doc clean
