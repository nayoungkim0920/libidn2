dnl Configuration for the toplevel directory of GNU libtextstyle
dnl Copyright (C) 2009-2023 Free Software Foundation, Inc.
dnl
dnl This program is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 3 of the License, or
dnl (at your option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program.  If not, see <https://www.gnu.org/licenses/>.

dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.64])  # Autoconf minimum version
AC_INIT([libtextstyle], [0.1], [bug-libtextstyle@example.com])
AC_CONFIG_SRCDIR([lib/color.c])  # Primary source file
AC_CONFIG_AUX_DIR([build-aux])  # Auxiliary files directory
# AC_CONFIG_HEADERS([config.h])  # Create config.h file
AC_CONFIG_MACRO_DIRS([m4])
AM_GNU_GETTEXT([external]) # configure.ac: not using Gettext

# Read version number from version.sh
. $srcdir/version.sh
gl_INIT_PACKAGE([libtextstyle], [$VERSION_NUMBER])

# Initialize Automake
AM_INIT_AUTOMAKE([1.13 silent-rules])

# Set C++ standard to C++17
CXXFLAGS="$CXXFLAGS -std=c++17"
AC_SUBST(CXXFLAGS)

# Enable system extensions before other checks
AC_USE_SYSTEM_EXTENSIONS

# Check for C99 support
#AC_PROG_CC
#AC_LANG([C])
#AC_COMPILE_IFELSE([AC_LANG_PROGRAM([], [[__STDC_VERSION__ >= 199901L]])],
#    [AC_DEFINE([HAVE_C99], [1], [Define if the C compiler supports C99.])],
#    [AC_MSG_ERROR([C99 support is required but not available.])])

# C99->C11
AC_PROG_CC
AC_LANG([C])
AC_COMPILE_IFELSE(
  [AC_LANG_PROGRAM([], [[#if __STDC_VERSION__ >= 201112L
                         #else
                         # error "C11 not supported"
                         #endif]])],
  [
    AC_DEFINE([HAVE_C11], [1], [Define if the C compiler supports C11.])
    CFLAGS="$CFLAGS -std=c11 -fno-inline -UNDEFINED_MACRO"
  ],
  [AC_MSG_ERROR([C11 support is required but not available.])]
)

# Check for required system headers
AC_CHECK_HEADERS([stdio.h stdlib.h wchar.h attributes.h])

# Check for the presence of getprogname function
AC_CHECK_FUNCS([getprogname printf malloc])

# Initialize Gnulib
m4_pattern_allow([GNULIB_MODULES])
m4_pattern_allow([gl_CC_GNULIB_WARNINGS])
m4_include([m4/gnulib-common.m4]) #"C:\libidn2\gettext-0.22.5\libtextstyle\m4\gnulib-common.m4"
m4_include([m4/gnulib-tool.m4]) #"C:\libidn2\gettext-0.22.5\libtextstyle\m4\gnulib-tool.m4"
m4_pattern_allow([AC_CHECK_FUNCS])
m4_pattern_allow([gl_INIT])
m4_pattern_allow([gl_EARLY])
m4_pattern_allow([gl_COMMON])
m4_pattern_allow([gl_PROG_AR_RANLIB])
m4_pattern_allow([AC_CONFIG_RPATH])
m4_pattern_allow([AC_CONFIG_LIBS])

# Early Gnulib configuration
gl_EARLY

# Initialize Gnulib
gl_INIT

# Add necessary Gnulib modules
gl_MODULES([xalloc-die])
gl_MODULES([xmalloca])
gl_MODULES([fsync])
gl_MODULES([xstrdup])
#gl_MODULES([tputs])
#gl_MODULES([safe-write])
#gl_MODULES([term-utils])
#gl_MODULES([gettext])
#gl_MODULES([getopt-gnu])
#gl_MODULES([getopt-posix])

# Define headers
#AC_CHECK_HEADERS([xstrdup.h], [], [AC_DEFINE([USE_XSTRDUP], [1], [Define if you want to use xstrdup])])

# Define various macros
AC_DEFINE([_GL_ASYNC_SAFE], [], [Define to enable async safe functions])

# _GL_ATTRIBUTE_ALLOC_SIZE
# Check if the compiler supports the __attribute__((__alloc_size__)) attribute
AC_MSG_CHECKING([whether the compiler supports __attribute__((__alloc_size__))])
AC_COMPILE_IFELSE(
  [AC_LANG_PROGRAM([[]], [[
    void* xmalloc(size_t) __attribute__((__alloc_size__(1)));
  ]])],
  [AC_DEFINE([_GL_HAS_ATTRIBUTE_ALLOC_SIZE], [1], [Define if compiler supports __attribute__((__alloc_size__))])],
  [AC_DEFINE([_GL_HAS_ATTRIBUTE_ALLOC_SIZE], [0], [Define if compiler does not support __attribute__((__alloc_size__))])]
)
AC_MSG_RESULT([done])


# Check for compiler attributes
AC_DEFUN([CHECK_HAS_ATTRIBUTE], [
    AC_COMPILE_IFELSE([
        AC_LANG_PROGRAM([[
            #ifdef __cplusplus
            #define _GL_HAS_ATTRIBUTE(x) __has_attribute(x)
            #else
            #define _GL_HAS_ATTRIBUTE(x) 0
            #endif
        ]], [])
    ], [
        AC_SUBST([_GL_HAS_ATTRIBUTE], [__has_attribute])
    ], [
        AC_SUBST([_GL_HAS_ATTRIBUTE], [0])
    ])
])
# Call the macro to check for attributes
CHECK_HAS_ATTRIBUTE

#AC_DEFINE([_GL_ATTRIBUTE_RETURNS_NONNULL], [], [Define to enable returns nonnull attributes])
# Check if the compiler supports the __attribute__((returns_nonnull)) attribute
AC_MSG_CHECKING([whether the compiler supports __attribute__((returns_nonnull))])
AC_COMPILE_IFELSE(
  [AC_LANG_PROGRAM([[]], [[
    void* test_returns_nonnull(void) __attribute__((returns_nonnull));
  ]])],
  [AC_DEFINE([_GL_HAS_ATTRIBUTE_RETURNS_NONNULL], [1], [Define if compiler supports __attribute__((returns_nonnull))])],
  [AC_DEFINE([_GL_HAS_ATTRIBUTE_RETURNS_NONNULL], [0], [Define if compiler does not support __attribute__((returns_nonnull))])]
)
AC_MSG_RESULT([done])

# Define IN_LIBTEXTSTYLE when building the library
AC_SUBST([IN_LIBTEXTSTYLE], [1])


AC_DEFINE([_GL_INLINE],[inline],[Define for inline])
AC_DEFINE([_GL_INLINE_HEADER_BEGIN], [], [Define for inline header start])
AC_DEFINE([_GL_INLINE_HEADER_END], [], [Define for inline header end])
AC_DEFINE([_GL_CONFIG_H_INCLUDED], [1], [Define to prevent multiple inclusion])
AC_DEFINE([_GL_LIST_INLINE], [inline], [Define for list inline])
AC_DEFINE([GNULIB_XALLOC], [1], [Define for gnulib xalloc])
AC_DEFINE([GNULIB_XALLOC_DIE], [1], [Define if xalloc_die is available])

AC_DEFINE([GNULIB_XSTRDUP], [1], [Define if xstrdup module is used])
AC_DEFINE([GNULIB_TPUTS], [1], [Define if tputs module is used])
AC_DEFINE([GNULIB_SAFE_WRITE], [1], [Define if safe-write module is used])

# Define macros for C++ and C
#if test "$ac_cv_cxx" = yes; then
#  AC_DEFINE([_GL_EXTERN_C], [extern "C"], [Define to extern "C" for C++])
#else
#  AC_DEFINE([_GL_EXTERN_C], [extern], [Define to extern for C])
#fi


#AC_MSG_CHECKING([whether the compiler supports extern "C"])
#AC_COMPILE_IFELSE(
#  [AC_LANG_PROGRAM([[#ifdef __cplusplus]])],
#  [AC_DEFINE([_GL_EXTERN_C], [extern "C"], [Define if compiler supports extern "C"])],
#  [AC_DEFINE([_GL_EXTERN_C], [extern], [Define if compiler does not support extern])]
#)
#AC_MSG_RESULT([done])

#/* Define to extern for C only */
#define _GL_EXTERN_C extern "C"
#
#AC_MSG_CHECKING([whether the compiler supports extern "C"])
#AC_COMPILE_IFELSE([
#AC_LANG_PROGRAM([[
#            #ifdef __cplusplus
#            #define _GL_EXTERN_C extern "C"
#            #else
#            #define _GL_EXTERN_C extern
#            #endif
#        ]], [])
#    ], [
#        AC_DEFINE([_GL_EXTERN_C], [extern "C"], [Define to extern "C" for C++ and extern for C])
#    ], [
#        AC_DEFINE([_GL_EXTERN_C], [extern], [Define to extern for C only])
#    ]
#)	
#AC_MSG_RESULT([done])

#/* Define to extern for C only */
#define _GL_EXTERN_C extern "C"
#
# Check if we are compiling with C++
#AC_MSG_CHECKING([whether the compiler supports extern "C"])
#AC_COMPILE_IFELSE(
#  [AC_LANG_PROGRAM([[
#    #ifdef __cplusplus
#    extern "C"
#    #else
#    extern
#    #endif
#  ]], [])],
#  [AC_DEFINE([_GL_EXTERN_C], [extern "C"], [Define to extern "C" for C++ and extern for C])],
#  [AC_DEFINE([_GL_EXTERN_C], [extern], [Define to extern for C only])]
#)
#AC_MSG_RESULT([done])

#AC_PROG_CXX
#if test "x$CXX" != "x"; then
#  AC_DEFINE([_GL_EXTERN_C], [extern "C"], [Define if compiling with C++])
#else
#  AC_DEFINE([_GL_EXTERN_C], [extern], [Define if compiling with C])
#fi


#AC_PROG_CXX
#if test "x$CXX" != "x"; then
#  AC_DEFINE([_GL_EXTERN_CXX], [1], [Define if compiling with C++])
#fi

#AC_CONFIG_COMMANDS([post-config-h], [
#  echo "/* Define extern linkage */" >> config.h
#  echo "#ifdef __cplusplus" >> config.h
#  echo "# define _GL_EXTERN_C extern \"C\"" >> config.h
#  echo "#else" >> config.h
#  echo "# define _GL_EXTERN_C extern" >> config.h
#  echo "#endif" >> config.h
#])



# Define _GL_FUNCDECL_RPL and _GL_FUNCDECL_RPL_1 macros
# AH_BOTTOM([
##define _GL_FUNCDECL_RPL(func, rettype, parameters, ...) _GL_FUNCDECL_RPL_1(rpl_##func, rettype, parameters, __VA_ARGS__)
##define _GL_FUNCDECL_RPL_1(rpl_func, rettype, parameters, ...) _GL_EXTERN_C_FUNC __VA_ARGS__ rettype rpl_func parameters
#])


#AC_DEFINE_UNQUOTED([_GL_ARG_NONNULL_1], [__attribute__((nonnull(1)))], [Define _GL_ARG_NONNULL ((1))])
#AC_DEFINE_UNQUOTED([_GL_ARG_NONNULL_1_3], [__attribute__((nonnull(1,3)))], [Define _GL_ARG_NONNULL ((1, 3))])
#AC_DEFINE_UNQUOTED([_GL_ARG_NONNULL_1_2], [__attribute__((nonnull(1,2)))], [Define _GL_ARG_NONNULL ((1, 2))])
#AC_DEFINE_UNQUOTED([_GL_ARG_NONNULL_3], [__attribute__((nonnull(3)))], [Define _GL_ARG_NONNULL ((3))])



#AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_PURE], [__attribute__((pure))], [Define _GL_ATTRIBUTE_PURE macro for pure function attribute])
# Define a macro to check for attribute support
#AC_DEFUN([_GL_HAS_ATTRIBUTE],
#  [AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
#    [[#ifndef __has_attribute
#      # define __has_attribute(x) 0
#    #endif]],  # <-- 첫 번째 코드 블록의 끝
#    [[int foo __attribute__ (($1));]])],  # <-- 두 번째 코드 블록의 끝
#    [AC_DEFINE([_GL_HAS_ATTRIBUTE_$1], [1],
#      [Define if the compiler supports __attribute__((($1)))])],  # <-- 성공 시
#    [AC_DEFINE([_GL_HAS_ATTRIBUTE_$1], [0],
#      [Define if the compiler does not support __attribute__((($1)))])])  # <-- 실패 시
#  ])

# Check for 'pure' attribute support
#_GL_HAS_ATTRIBUTE([pure])



# __attribute__((__pure__)) 지원 여부 확인
AC_MSG_CHECKING([for __attribute__((__pure__)) support])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
void __attribute__((__pure__)) test_function(int* ptr) {
    (void)ptr;
}
int main() {
    int a = 0;
    test_function(&a);
    return 0;
}
]])],
[AC_MSG_RESULT([yes])
 AC_DEFINE([HAVE_ATTRIBUTE_PURE], [1], [Define if compiler supports __attribute__((__pure__))])
],
[AC_MSG_RESULT([no])
 AC_DEFINE([HAVE_ATTRIBUTE_PURE], [0], [Define if compiler does not support __attribute__((__pure__))])
])

# _GL_ARG_NONNULL 매크로 정의
if test "$HAVE_ATTRIBUTE_PURE" = 1; then
    AC_DEFINE([_GL_ATTRIBUTE_PURE], [__attribute__((__pure__))], [Define to use __attribute__((__pure__))])
else
    AC_DEFINE([_GL_ATTRIBUTE_PURE], [], [Define as empty if __attribute__((__pure__)) is not supported])
fi



# __attribute__((nonnull)) 지원 여부 확인
AC_MSG_CHECKING([for __attribute__((nonnull)) support])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
void __attribute__((nonnull(1))) test_function(int* ptr) {
    (void)ptr;
}

int main() {
    int a = 0;
    test_function(&a);
    return 0;
}
]])],
[AC_MSG_RESULT([yes])
 AC_DEFINE([HAVE_ATTRIBUTE_NONNULL], [1], [Define if compiler supports __attribute__((nonnull))])
],
[AC_MSG_RESULT([no])
 AC_DEFINE([HAVE_ATTRIBUTE_NONNULL], [0], [Define if compiler does not support __attribute__((nonnull))])
])

# _GL_ARG_NONNULL 매크로 정의
if test "$HAVE_ATTRIBUTE_NONNULL" = 1; then
    AC_DEFINE([_GL_ARG_NONNULL_1_2], [__attribute__((nonnull(1,2)))], [Define to use __attribute__((nonnull(1,2)))])
	AC_DEFINE([_GL_ARG_NONNULL_1], [__attribute__((nonnull(1)))], [Define to use __attribute__((nonnull(1)))])
	AC_DEFINE([_GL_ARG_NONNULL_1_3], [__attribute__((nonnull(1,3)))], [Define to use __attribute__((nonnull(1,3)))])
	AC_DEFINE([_GL_ARG_NONNULL_3], [__attribute__((nonnull(3)))], [Define to use __attribute__((nonnull(3)))])
else
    AC_DEFINE([_GL_ARG_NONNULL_1_2], [], [Define as empty if __attribute__((nonnull(1,2))) is not supported])
	AC_DEFINE([_GL_ARG_NONNULL_1], [], [Define as empty if __attribute__((nonnull(1))) is not supported])
	AC_DEFINE([_GL_ARG_NONNULL_1_3], [], [Define as empty if __attribute__((nonnull(1,3))) is not supported])
	AC_DEFINE([_GL_ARG_NONNULL_3], [], [Define as empty if __attribute__((nonnull(3))) is not supported])
fi


# __attribute__((__malloc__)) 지원 여부 확인
AC_MSG_CHECKING([for __attribute__((__malloc__)) support])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
void __attribute__((__malloc__)) test_function(int* ptr) {
    (void)ptr;
}
int main() {
    int a = 0;
    test_function(&a);
    return 0;
}
]])],
[AC_MSG_RESULT([yes])
 AC_DEFINE([HAVE_ATTRIBUTE_MALLOC], [1], [Define if compiler supports __attribute__((__malloc__))])
],
[AC_MSG_RESULT([no])
 AC_DEFINE([HAVE_ATTRIBUTE_MALLOC], [0], [Define if compiler does not support __attribute__((__malloc__))])
])

# _GL_ARG_NONNULL 매크로 정의
if test "$HAVE_ATTRIBUTE_MALLOC" = 1; then
    AC_DEFINE([_GL_ATTRIBUTE_MALLOC], [__attribute__((__malloc__))], [Define to use __attribute__((__malloc__))])
else
    AC_DEFINE([_GL_ATTRIBUTE_MALLOC], [], [Define as empty if __attribute__((__malloc__)) is not supported])
fi


if test "$HAVE_ATTRIBUTE_DEALLOC" = 1; then
    AC_DEFINE([_GL_ATTRIBUTE_DEALLOC(f, i)], [__attribute__((__malloc__ (f, i)))], [Define to use __attribute__((__malloc__ (f, i)))])
else
    AC_DEFINE([_GL_ATTRIBUTE_DEALLOC(f, i)], [], [Define as empty if __attribute__((__malloc__ (f, i))) is not supported])
fi


##AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_NODISCARD], [__attribute__((nodiscard))], [Define for attribute nodiscard])
#AC_MSG_CHECKING([whether the compiler supports __attribute__((nodiscard))])
#AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[__attribute__((nodiscard)) int x;]])],
#  [AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_NODISCARD], [__attribute__((nodiscard))], [Define for attribute nodiscard])],
#  [AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_NODISCARD], [], [Define for attribute nodiscard])])
#AC_MSG_RESULT([done])

# Check for __attribute__((nodiscard)) support
#AC_MSG_CHECKING([whether the compiler supports __attribute__((nodiscard))])
#AC_COMPILE_IFELSE(
#  [AC_LANG_PROGRAM([[]], [[__attribute__((nodiscard)) int x;]])],
#  [AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_NODISCARD], [__attribute__((nodiscard))], [Define for attribute nodiscard])],
#  [AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_NODISCARD], [], [Define for attribute nodiscard])]
#)
#AC_MSG_RESULT([done])


AC_MSG_CHECKING([whether the compiler supports __attribute__((noreturn))])
AC_COMPILE_IFELSE(
  [AC_LANG_PROGRAM([[]], [[__attribute__((noreturn)) void x();]])],
  [AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_NORETURN], [__attribute__((noreturn))], [Define for attribute noreturn])],
  [AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_NORETURN], [], [Define for attribute noreturn])]
)
AC_MSG_RESULT([done])

AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_MAYBE_UNUSED], [__attribute__((unused))], [Define to __attribute__((unused))])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_COLD], [__attribute__((cold))], [Define to __attribute__((cold))])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_SPEC_PRINTF_ERROR], [__attribute__((format(printf, 3, 4)))], [Define to __attribute__((format(printf, 3, 4)))])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_FORMAT], [_GL_ATTRIBUTE_SPEC_PRINTF_ERROR], [Define to _GL_ATTRIBUTE_SPEC_PRINTF_ERROR])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_FORMAT_ERROR_AT_LINE], [__attribute__((format(printf, 5, 6)))], [Define for format attribute with index 5, 6])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_SPEC_PRINTF_STANDARD_ERROR], [__attribute__((format(printf, 3, 0)))], [Define for format attribute with index 3, 0])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_SPEC_PRINTF_STANDARD_ERROR_AT_LINE], [__attribute__((format(printf, 5, 0)))], [Define for format attribute with index 5, 0])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_1_2], [__attribute__((format(printf, 1, 2)))], [Define to use printf format attribute with parameters (1, 2)])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_2_0], [__attribute__((format(printf, 2, 0)))], [Define to use printf format attribute with parameters (2, 0)])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_2_3], [__attribute__((format(printf, 2, 3)))], [Define to use printf format attribute with parameters (2, 3)])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_3_0], [__attribute__((format(printf, 3, 0)))], [Define to use printf format attribute with parameters (3, 0)])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_3_4], [__attribute__((format(printf, 3, 4)))], [Define to use printf format attribute with parameters (3, 4)])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_FORMAT_PRINTF_SYSTEM_2_3], [__attribute__((format(printf, 2, 3)))], [Define to use printf format attribute with parameters (2, 3)])
AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_FORMAT_PRINTF_SYSTEM_1_0], [__attribute__((format(printf, 1, 0)))], [Define to use printf format attribute with parameters (1, 0)])

# Define DLL_VARIABLE for Windows DLL exports
if test "$host_os" = "mingw32"; then
    AC_DEFINE([DLL_VARIABLE], [__declspec(dllexport)], [Define to __declspec(dllexport)])
else
    AC_DEFINE([DLL_VARIABLE], [], [Define to nothing for non-Windows platforms])
fi
AC_SUBST([DLL_VARIABLE]) # DLL_VARIABLE macro setting

# Check for wchar_t type
AC_CHECK_TYPE([wchar_t],
  [HAVE_WCHAR_T=1],
  [HAVE_WCHAR_T=0]
)
AC_SUBST([HAVE_WCHAR_T])

# CFLAGS 설정 추가
#CFLAGS="$CFLAGS -std=c99 -fno-inline -UNDEFINED_MACRO"
#AC_SUBST(CFLAGS)

# LDFLAGS 설정 추가 ~/.bashrc에 선언
#AC_SUBST([LDFLAGS], [  
#  -L/c/libidn2/gettext-0.22.5/libtextstyle/lib \
#  -L/mingw64/lib \
#  -L/usr/lib \
#  -Wl,-rpath,/mingw64/bin \
#  $LDFLAGS 
#])
LDFLAGS="$LDFLAGS"
AC_SUBST(LDFLAGS)

AC_SUBST([CPPFLAGS], ["-I/mingw64/include"]) #헤더파일

# Compiler and toolchain checks
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_MKDIR_P

# Host system type checks
AC_CANONICAL_HOST
echo "configure.ac: Configured host OS: $host_os"

# Windows-specific settings for mingw and Cygwin
case "$host_os" in
  mingw* | cygwin*) 
    is_woe32=yes
    ;;
  *) 
    is_woe32=no
    ;;
esac

if test "$host_os" = "mingw32"; then
    AM_CONDITIONAL([WOE32DLL], true)
    AM_CONDITIONAL([WOE32], true)
    echo "WOE32DLL and WOE32 are enabled."
    LDFLAGS="$LDFLAGS -no-undefined -export-dynamic"
else
    AM_CONDITIONAL([WOE32DLL], false)
    AM_CONDITIONAL([WOE32], false)
    echo "WOE32DLL and WOE32 are disabled."
    LDFLAGS="$LDFLAGS -no-undefined"
fi

# Define AM_CONDITIONAL for INCLUDED_LIBXML
AM_CONDITIONAL([INCLUDED_LIBXML], [test "x$have_libxml" = "xyes"])

# Check for specific headers and libraries
AC_CHECK_HEADERS([textstyle/woe32dll.h], [WOE32DLL=1], [WOE32DLL=0])

if test "$WOE32DLL" = "1"; then
  AM_LDFLAGS='-export-dynamic'
fi

# Additional configuration for libraries and tools
LT_INIT([win32-dll])
LT_LANG([Windows Resource])

# Set up paths for documentation tools
ac_aux_dir_abs=`cd $ac_aux_dir && pwd`
AC_PATH_PROG([TEXI2DVI], [texi2dvi], [$ac_aux_dir_abs/missing texi2dvi])
AC_PATH_PROG([DVIPS], [dvips], [$ac_aux_dir_abs/missing dvips])
AC_PATH_PROG([PERL], [perl], [$ac_aux_dir_abs/missing perl])

# Enable or disable namespacing
AC_ARG_ENABLE([namespacing],
  [  --disable-namespacing   build a library that exports undesired symbols],
  [:], [enable_namespacing=yes])
if test "$enable_namespacing" != no; then
  NAMESPACING=yes
else
  NAMESPACING=
fi
AC_SUBST([NAMESPACING])

# Substitutable version number
AC_PROG_AWK
changequote(,)
sed_extract_major='/^[0-9]/{s/^\([0-9]*\).*/\1/p;q;}
i\
0
q
'
sed_extract_minor='/^[0-9][0-9]*[.][0-9]/{s/^[0-9]*[.]\([0-9]*\).*/\1/p;q;}
i\
0
q
'
sed_extract_subminor='/^[0-9][0-9]*[.][0-9][0-9]*[.][0-9]/{s/^[0-9]*[.][0-9]*[.]\([0-9]*\).*/\1/p;q;}
i\
0
q
'
changequote([,])
version_major=`echo "${VERSION}" | sed -n -e "$sed_extract_major"`
version_minor=`echo "${VERSION}" | sed -n -e "$sed_extract_minor"`
version_subminor=`echo "${VERSION}" | sed -n -e "$sed_extract_subminor"`
HEXVERSION=0x`$AWK 'BEGIN { printf("%02X%02X%02X", "$version_major", "$version_minor", "$version_subminor") }'`
AC_SUBST([HEXVERSION])

if test "$am_func_iconv" = yes; then
  HAVE_ICONV=1
else
  HAVE_ICONV=0
fi
AC_SUBST([HAVE_ICONV])

# Create Makefiles and output configurations
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([doc/Makefile])
AC_CONFIG_FILES([lib/Makefile])
AC_CONFIG_FILES([lib/exported.sh])
AC_CONFIG_FILES([lib/textstyle/version.h:lib/textstyle/version.in.h])
AC_CONFIG_FILES([lib/textstyle/woe32dll.h:lib/textstyle/woe32dll.in.h])
AC_CONFIG_FILES([tests/Makefile])
AC_CONFIG_FILES([adhoc-tests/Makefile])

AC_CONFIG_HEADERS([config.h]) # config.h.in => config.h 생성

AC_OUTPUT
