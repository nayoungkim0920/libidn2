# 주로 autoconf 매크로들을 사용하는 곳
# Copyright (C) 2011-2024 Simon Josefsson

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# 추가
IT_PROG_INTLTOOL([0.40.0]) # 다국어 지원을 위한 도구
GTK_DOC_CHECK([1.0]) # API 문서를 생성하는 도구



AC_INIT([Libidn2],
        m4_esyscmd([build-aux/git-version-gen .tarball-version]),
        [help-libidn@gnu.org],,
        [https://www.gnu.org/software/libidn/#libidn2])

# Library code modified:                              REVISION++
# Interfaces changed/added/removed:   CURRENT++       REVISION=0
# Interfaces added:                             AGE++
# Interfaces removed:                           AGE=0
#추가
AC_PREFIX_DEFAULT([/mingw64])
AC_SUBST([datadir], [$prefix/share])


AC_SUBST(LT_CURRENT, 4)
AC_SUBST(LT_REVISION, 0)
AC_SUBST(LT_AGE, 4)

DLL_VERSION=`expr ${LT_CURRENT} - ${LT_AGE}`
AC_SUBST(DLL_VERSION)

AC_SUBST([MAJOR_VERSION], [`echo $PACKAGE_VERSION|cut -d'.' -f1`])
AC_SUBST([MINOR_VERSION], [`echo $PACKAGE_VERSION|cut -d'.' -f2`])
AC_SUBST([PATCH_VERSION], [`echo $PACKAGE_VERSION|cut -d'.' -f3`])
AC_SUBST([NUMBER_VERSION], [`printf '0x%02x%02x%04x' $MAJOR_VERSION $MINOR_VERSION $PATCH_VERSION`])

AC_MSG_NOTICE([$PACKAGE_NAME $PACKAGE_VERSION $PACKAGE_TARNAME $MAJOR_VERSION.$MINOR_VERSION.$PATCH_VERSION $NUMBER_VERSION $LT_CURRENT:$LT_REVISION:$LT_AGE $DLL_VERSION])

AC_CONFIG_AUX_DIR([build-aux])
#AC_CONFIG_MACRO_DIRS([m4]) #추가 autoconf에서 사용
#AC_CONFIG_MACRO_DIRS([/usr/share/aclocal])
#AC_CONFIG_MACRO_DIRS([/mingw64/share/aclocal /usr/share/aclocal m4])
AC_CONFIG_MACRO_DIRS([/mingw64/share/aclocal /usr/share/aclocal /c/libidn2/m4])
AC_CONFIG_HEADERS([config.h])

# 추가된 설정
AC_CONFIG_SRCDIR([src/idn2.c])


# 추가
m4_include([/c/libidn2/m4/custom-macros.m4])
m4_include([/c/libidn2/m4/gtk-doc.m4])
m4_pattern_allow([AC_PROG_GETTEXT])

#추가
CFLAGS=""
CPPFLAGS=""
LDFLAGS=""

AC_PROG_CC

AM_INIT_AUTOMAKE([1.14 -Wall -Wno-portability subdir-objects])
AM_SILENT_RULES([yes])


AC_USE_SYSTEM_EXTENSIONS
gl_EARLY
unistring_EARLY
AM_MISSING_PROG(HELP2MAN, help2man, $missing_dir)
LT_INIT([win32-dll])
gl_INIT
unistring_INIT

# Add warnings 추가 Makefile.am파일에서 설정하는게 일반적
#AM_CFLAGS = -Werror

#추가
CFLAGS="$CFLAGS -Werror"

AC_DEFINE([GNULIB_NO_VLA], 1, [Disable VLA usage in gettext.h.])

# 타겟 시스템 감지
case "${host_os}" in
    linux-gnu)
        build_linux_gnu=yes
esac
AM_CONDITIONAL([TEST_GLIBC], [test "$build_linux_gnu" = "yes"])

# 컴파일러 지원 확인
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([
__attribute__((visibility("hidden")))
int
versioned_symbol_internal (void)
{
}
__typeof__ (versioned_symbol_internal) versioned_symbol
   __attribute__ ((visibility ("default"),
                   alias ("versioned_symbol_internal")));
__asm__ (".symver versioned_symbol, versioned_symbol@IDN2_0.0.0");
])], [AC_DEFINE([HAVE_SYMVER_ALIAS_SUPPORT], [1],
     [The toolchain supports aliases and .symver.])])

#
# gtk-doc 체크
#
m4_ifdef([GTK_DOC_CHECK], [
GTK_DOC_CHECK([1.14],[--flavour no-tmpl])
],[
AM_CONDITIONAL([ENABLE_GTK_DOC], false)
])
# 구버전 gtk-doc를 위한 설정
m4_ifdef([GTK_DOC_USE_LIBTOOL], [], [
AM_CONDITIONAL([GTK_DOC_USE_LIBTOOL], false)
])

AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION([0.19.8])

AX_CODE_COVERAGE

AC_ARG_ENABLE([gcc-warnings],
  [AS_HELP_STRING([[--enable-gcc-warnings[=TYPE]]],
    [control generation of GCC warnings.  The TYPE 'no' disables
     warnings; 'yes' (default) generates cheap warnings;
     'expensive' in addition generates expensive warnings
     and 'error' also turn warnings into errors.])])

# GCC 경고 설정
AS_IF([test "$enable_gcc_warnings" != no],
  [
    nw=
    if test "$enable_gcc_warnings" = yes; then
      nw="$nw -fanalyzer"
    fi
    nw="$nw -Wbad-function-cast"
    nw="$nw -Winline"
    nw="$nw -Wsign-compare"
    nw="$nw -Wstrict-overflow"
    nw="$nw -Wsystem-headers"

    nw="$nw -Wsuggest-attribute=pure"
    nw="$nw -Wsuggest-attribute=const"

    # Define or use gl_MANYWARN_ALL_GCC
    gl_MANYWARN_ALL_GCC $nw 

    # Complement and modify warning options 주석처리
    #desired_warning_options="-Werror"
    #possible_warning_options="$nw"
    # Define warning options 추가
    nw="-Wall -Wextra"
    # Check for required warnings
    desired_warning_options="-Werror -Wall -Wextra"
    remaining_undesired_warning_options="-Wno-unused-variable -Wno-unused-parameter"
    possible_warning_options="$nw"
    
    # Correct way to call gl_MANYWARN_COMPLEMENT
    gl_MANYWARN_COMPLEMENT "$desired_warning_options" "$possible_warning_options"
    gl_MANYWARN_COMPLEMENT "$remaining_undesired_warning_options" "$nw"

    # Process desired warning options
    for w in $desired_warning_options; do
        gl_WARN_ADD $w
    done

    # Process remaining undesired warning options
    for w in `echo "$remaining_undesired_warning_options" | sed -e 's/-W/-Wno-/g'`; do
       gl_WARN_ADD $w
    done


    # Apply desired warning options
    #for w in $desired_warning_options; do
    #    gl_WARN_ADD("-W$w")
    #done

    # Apply remaining undesired warning options
    #for w in `echo "$remaining_undesired_warning_options" | sed -e 's/-W/-Wno-/g'`; do
    #    gl_WARN_ADD("-W$w")
    #done

    #주석처리
    #gl_MANYWARN_COMPLEMENT("$desired_warning_options", "$possible_warning_options")
    #gl_MANYWARN_COMPLEMENT("$remaining_undesired_warning_options", "$nw")

    
  ])
AC_ARG_ENABLE(doc,
  AS_HELP_STRING([--disable-doc], [don't generate any documentation]),
  [enable_doc=$enableval], [enable_doc=yes])

# 설정할 파일 목록
AC_CONFIG_FILES([
    Makefile
    gl/Makefile
    doc/Makefile
    lib/Makefile
    gnulib/lib/unictype/Makefile
    gnulib/Makefile
    src/Makefile
    tests/Makefile
    doc/reference/Makefile
    examples/Makefile
    fuzz/Makefile
    gettext-0.19.8/os2/Makefile
    po/Makefile
    libidn2.pc
    po/Makefile.in
    lib/idn2.h
])

# 추가 설정 (AC_CONFIG_COMMANDS 사용)
AC_CONFIG_COMMANDS([post-configure], [
  chmod a+x misc/gettextize
  chmod a+x misc/autopoint
  chmod a+x misc/convert-archive
  FIX_MAKEFILE_DISTRIB
])

AC_OUTPUT

#추가
#AC_PROG_LIBTOOL -> LT_INIT대체 libtool 버전 2.2 이상에서 사용 가능
LT_INIT
#AC_CHECK_LIB([iconv], [iconv])
#AC_CHECK_LIB([intl], [gettext])
#추가
AC_CHECK_LIB([iconv], [iconv], [], [AC_MSG_ERROR([iconv library not found!])])
AC_CHECK_LIB([intl], [gettext], [], [AC_MSG_ERROR([gettext library not found!])])
#AC_PROG_GETTEXT #error: possibly undefined macro: AC_PROG_GETTEXT

#추가
AC_SUBST(CFLAGS)

AC_MSG_NOTICE([summary of main build options:

#추가
PATH=/mingw64/bin:/usr/bin:/bin:$PATH
export PATH

  Version:            ${VERSION}
  Libtool version     $LT_CURRENT:$LT_REVISION:$LT_AGE
  DLL version:        $DLL_VERSION
  Header version:     major $MAJOR_VERSION minor $MINOR_VERSION patch $PATCH_VERSION number $NUMBER_VERSION
  Build system:       ${build}
  Host/Target system: ${host}
  Install prefix:     ${prefix}
  Compiler:           ${CC}
  CFLAGS:             ${CFLAGS}
  CPPFLAGS:           ${CPPFLAGS}
  LDFLAGS:            ${LDFLAGS}
  Library types:      Shared=${enable_shared}, Static=${enable_static}

  Warning flags:      $enable_gcc_warnings
      WERROR_CFLAGS:  $WERROR_CFLAGS
WERROR_TESTS_CFLAGS:  $WERROR_TESTS_CFLAGS
        WARN_CFLAGS:  $WARN_CFLAGS

  Documentation:      ${enable_doc}

  nl_langinfo:        $am_cv_langinfo_codeset
  Libiconv:           $am_cv_func_iconv_summary
         LTLIBICONV:  $LTLIBICONV
  Libunistring:       $ac_cv_libunistring
            VERSION:  $LIBUNISTRING_VERSION
     LTLIBUNISTRING:  $LTLIBUNISTRING

  Version script:     $have_ld_version_script

  Valgrind:           $gl_cv_prog_valgrind_works $VALGRIND_PROGRAM $DEFAULT_VALGRINDFLAGS $VALGRINDFLAGS
])
