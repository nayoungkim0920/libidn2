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
ACLOCAL_AMFLAGS = -I m4 -I gnulib-m4 -I /mingw64/share/aclocal
AM_CPPFLAGS = -I${top_builddir} # 전처리기 플래그 설정 추가
#CFLAGS = -Wall -Wextra -Wpedantic -fdiagnostics-show-option # 모든 경고와 추가적인 경고를 활성화
#INCLUDES = -I$(top_srcdir) #AM_CPPFLAGS의 old name

# CFLAGS 설정
#AM_CFLAGS = -Wall -Wextra -Wpedantic -fdiagnostics-show-option # 모든 경고와 추가적인 경고를 활성화
AM_CFLAGS = -Wall -Wextra -Wpedantic -fdiagnostics-show-option \
            $(ITL_CFLAGS) $(NCURSES_CFLAGS) $(GLIB_CFLAGS)

# 링크 시 필요한 라이브러리 추가
AM_LIBS = $(ITL_LIBS) $(NCURSES_LIBS) $(GLIB_LIBS)


#TEXI2DVI = texi2dvi # 추가
#TEXI2PDF = $(TEXI2DVI) --pdf # 추가
#DVIPS = dvips -D600 # 추가

#DEFAULT_INCLUDES = -I. -I$(srcdir) -I$(top_builddir)/lib -I$(top_builddir) # Include directory 설정 추가
#DEFAULT_INCLUDES = -I$(srcdir) -I.

# The list of subdirectories containing Makefiles.
SUBDIRS = po lib tests adhoc-tests doc

# 공유 라이브러리로 설정
lib_LTLIBRARIES = libtextstyle.la libltdlc.la

# libtextstyle 라이브러리 설정
libtextstyle_la_SOURCES = \ #라이브러리에 포함될 소스 파일 목록을 나열
	lib/color.c \
	lib/gl_array_list.c \
	lib/term-ostream.c \
	lib/ostream.c \
	lib/concat-filename.c \
	lib/xconcat-filename.c \
    lib/xsize.c \
	lib/error.c \
	lib/full-write.c \
	lib/term-style-control.c \
	lib/fsync.c \
	lib/xstrdup.c \
	lib/xgethostname.c

# libtextstyle 라이브러리에 사용할 객체 파일을 지정
#libtextstyle_la_LDADD = \
#    color$(EXEEXT) \
#    gl_array_list$(EXEEXT) \
#    term-ostream$(EXEEXT) \
#    ostream$(EXEEXT) \
#    concat-filename$(EXEEXT) \
#    xconcat-filename$(EXEEXT) \
#    xsize$(EXEEXT) \
#    error$(EXEEXT) \
#    full-write$(EXEEXT) \
#    term-style-control$(EXEEXT) \
#    fsync$(EXEEXT) \
#    xstrdup$(EXEEXT) \
#    xgethostname$(EXEEXT)

# LIBOBJS=>AC_LIBOBJ로 변경
#libtextstyle_la_LIBOBJS = $(LIBOBJS)
AC_LIBOBJ([color])
AC_LIBOBJ([gl_array_list])
AC_LIBOBJ([term-ostream])
AC_LIBOBJ([ostream])
AC_LIBOBJ([concat-filename])
AC_LIBOBJ([xconcat-filename])
AC_LIBOBJ([xsize])
AC_LIBOBJ([error])
AC_LIBOBJ([full-write])
AC_LIBOBJ([term-style-control])
AC_LIBOBJ([fsync])
AC_LIBOBJ([xstrdup])
AC_LIBOBJ([xgethostname])
#libtextstyle_la_LIBOBJS = $(AC_LIBOBJ(baz) $(AC_LIBOBJ(qux))
#libtextstyle_la_LIBOBJS = $(AC_LIBOBJ)
#bin_PROGRAMS = libtextstyle_la 실행가능한 프로그램인 경우
libtextstyle_la_LIBS = -lncurses $(GNULIB_LIBS) $(GL_LIBOBJS) $(LTDLIBS) $(LT_LIBOBJS) -lltdl # libtextstyle 라이브러리에 링크할 라이브러리들
#libtextstyle_la_SOURCES = libtextstyle.o
#libtextstyle_la_LDADD = libtextstyle.la -L/c/libidn2/gettext-0.22.5/gettext-runtime/intl/.libs -lintl
libtextstyle_la_LIBADD = $(NCURSES_LIBS) #ncurses 라이브러리를 링크하기 위해 $(NCURSES_LIBS)를 사용# 설치할 라이브러리의 위치
#libtextstyle_la_LDFLAGS = -shared -Wl,--out-implib=libtextstyle.dll.a -lltdl $(LDFLAGS) #DLL을 생성하기 위한 필수 플래그를 추가
libtextstyle_la_LDFLAGS = -shared -Wl,--out-implib=libtextstyle.dll.a -lltdl #DLL을 생성하기 위한 필수 플래그를 추가
# -shared는 공유 라이브러리를 생성하는 옵션이며, 
# -Wl, --out-implib=libtextstyle.dll.a는 DLL의 import 라이브러리를 생성
libtextstyle_la_CFLAGS = -g -02 #포함된 객체 파일의 최적화를 설정

#libltdlc 라이브러리 설정
libltdlc_la_SOURCES = \
  libltdl/lt__alloc.c \
  libltdl/lt__argz.c \
  libltdl/lt_dlloader.c \
  libltdl/lt_error.c \
  libltdl/ltdl.c \
  libltdl/slist.c

# libltdlc 라이브러리에 사용할 객체 파일을 지정
#libltdlc_la_LDADD = \
#    lt__alloc$(EXEEXT) \
#    lt__argz$(EXEEXT) \
#    lt_dlloader$(EXEEXT) \
#    lt_error$(EXEEXT) \
#    ltdl$(EXEEXT) \
#    slist$(EXEEXT)

# LIBOBJS=>AC_LIBOBJ로 변경
#libltdlc_la_LIBOBJS = $(LIBOBJS)
AC_LIBOBJ([lt__alloc])
AC_LIBOBJ([lt__argz])
AC_LIBOBJ([lt_dlloader])
AC_LIBOBJ([lt_error])
AC_LIBOBJ([ltdl])
AC_LIBOBJ([slist])
#libltdlc_la_LIBOBJS = baz.lo qux.lo
#libltdlc_la_LIBOBJS = $(AC_LIBOBJ(baz) $(AC_LIBOBJ(qux))
#libltdlc_la_LIBOBJS = $(AC_LIBOBJ)
#libltdlc_la_LIBS = -lncurses $(GNULIB_LIBS) $(GL_LIBOBJS) $(LTDLIBS) $(LT_LIBOBJS) # LIBOBJS -> AC_LIBOBJ
libltdlc_la_LIBS = -lncurses $(GNULIB_LIBS) $(AC_LIBOBJ) $(LTDLIBS) $(AC_LIBOBJ) # LIBOBJS -> AC_LIBOBJ
libltdlc_la_LIBADD = -lltdl
libltdlc_la_LDFLAGS = -shared -Wl,--out-implib=libltdlc.dll.a
libltdlc_la_CFLAGS = -g -02 #포함된 객체 파일의 최적화를 설정

# Add this rule to copy argz.in.h to argz.h
lib/argz.h: lib/argz.h.in
	cp lib/argz.h.in lib/argz.h

# 헤더 파일을 설치할 디렉토리
include_HEADERS = \
    foo.h \
    bar.h \
    color.h \
    gl_array_list.h \
    term-ostream.h \
    ostream.h \
    concat-filename.h \
    xconcat-filename.h \
    xsize.h \
    error.h \
    full-write.h \
    term-style-control.h \
    fsync.h \
    xstrdup.h \
    xgethostname.h

# Add gnulib modules to the sources
# $(top_srcdir) : .
noinst_HEADERS = $(top_srcdir)/lib/fsync.h $(top_srcdir)/lib/xalloc.h

# Add gnulib modules to the sources
#noinst_SOURCES = $(top_srcdir)/lib/fsync.c

# Makefile.am에 새로운 타겟 추가
print-noinst-headers-sources:
	@echo ">>>>>>>>>>>>>>>>>>>>>>$(noinst_HEADERS)"
#	@echo ">>>>>>>>>>>>>>>>>>>>>>$(noinst_SOURCES)"

# 추가
if INCLUDED_LIBXML
# 관련 규칙 또는 변수 설정
endif

EXTRA_DIST = \
  version.sh \
  DEPENDENCIES \
  HACKING \
  autogen.sh \
  lib\argz.h.in \
  m4/gnulib-cache.m4 \
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
# 정적 라이브러리 설치 코드를 추가(주석제거)
install: all
	$(INSTALL) -m 755 lib/libtextstyle.a $(prefix)/lib

clean:
	rm -f lib/libtextstyle.a
	$(MAKE) -C $(top_builddir)/lib clean
	$(MAKE) -C $(top_builddir)/tests clean
	$(MAKE) -C $(top_builddir)/adhoc-tests clean
	$(MAKE) -C $(top_builddir)/doc clean
