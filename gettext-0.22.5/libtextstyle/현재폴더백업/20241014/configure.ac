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
AC_PREREQ([2.69])  # Autoconf 버전 요구사항
AC_INIT([libtextstyle], [1.0], [bug-libtextstyle@example.com])

# config.h가 없으면 생성
#if test ! -f config.h; then
#    AC_MSG_NOTICE([config.h does not exist. Creating it...])
#fi
# lib/argz.h가 없으면 생성
#if test ! -f lib/argz.h; then
#    AC_MSG_NOTICE([lib/argz.h does not exist. Creating it...])
#    mkdir -p lib  # lib 디렉토리가 없을 경우 생성
#fi

#config.h만 생성됨
#AC_CONFIG_HEADERS(
#	[C:\libidn2\gettext-0.22.5\libtextstyle\config.h] 
#	[C:\libidn2\gettext-0.22.5\libtextstyle\lib\argz.h]	
#)

#config.h만 생성됨
#AC_CONFIG_HEADERS(
#	[C:\libidn2\gettext-0.22.5\libtextstyle\config.h], 
#	[C:\libidn2\gettext-0.22.5\libtextstyle\lib\argz.h]	
#)

#AC_CONFIG_COMMANDS_PRE([
#  top_dir=`pwd`
#  AC_SUBST(top_dir)
#])
#AC_SUBST(top_dir, `pwd`)
#AC_MSG_NOTICE([Top-level directory: $top_dir])
#AC_MSG_NOTICE([1: Current ac_config_headers: $ac_config_headers])
#ac_config_headers="$top_dir/"
#AC_CONFIG_HEADERS([/c/libidn2/gettext-0.22.5/libtextstyle/config.h])
AC_CONFIG_HEADERS([c:/libidn2/gettext-0.22.5/libtextstyle/config.h])
# Now $ac_config_headers should contain 'config.h'
#AC_MSG_NOTICE([2: Current ac_config_headers: $ac_config_headers])
#configure: Top-level directory: /c/libidn2/gettext-0.22.5/libtextstyle
#configure: 1: Current ac_config_headers:
#configure: 2: Current ac_config_headers: /c/libidn2/gettext-0.22.5/libtextstyle config.h



#AC_CAN_COMPILE
m4_pattern_allow([AC_CAN_COMPILE])
# Gnulib에서 최소 요구 버전을 설정
m4_ifdef([GL_REQUIRE_VERSION], [GL_REQUIRE_VERSION([2.0])])

# Enable system extensions before other checks
AC_USE_SYSTEM_EXTENSIONS # AC_INIT 보다 먼저 호출하면 안됨
# Additional configuration for libraries and tools
#LT_INIT([win32-dll], [dlopen], [libltdl]) # 중복선언안됨. dlopen 모드를 활성화하여 libltdl 사용. win32-dll과 dlopen을 동시에 초기화
LT_CONFIG_LTDL_DIR([libltdl])
LT_INIT([win32-dll], [dlopen disable-static]) #dlopen을 활성화하고 정적 라이브러리를 비활성화
LTDL_INIT
#L_INLTDIT #라이브러리 동적 로딩을 위한 초기화, LT_INIT보다 먼저 선언되면 안됨
#LT_WITH_LTDL([libltdl]) 지원 중단
#LT_CONFIG_LTDL_DIR([/c/libidn2/gettext-0.22.5/libtextstyle/lib/ltdl])
#AC_CONFIG_SUBDIRS([libltdl])
AM_GNU_GETTEXT([external]) # GNU Gettext의 사용을 활성화, AC_INIT 바로 아래에 위치
AM_GNU_GETTEXT_VERSION([0.22.4])
#AM_GNU_GETTEXT([prefer-ngettext])
IT_PROG_INTLTOOL([0.50]) # intltool의 버전을 확인하고 필요한 경우 설치
GTK_DOC_CHECK([1.34])  # Gtkdoc 버전 요구 사항을 설정합니다.


#./configure --with-libintl-prefix=/c/msys64/mingw64
# /c/msys64/mingw64/bin/gcc.exe
AC_ARG_WITH([libintl-prefix],
            [AS_HELP_STRING([--with-libintl-prefix=DIR],
                            [Specify the installation directory of libintl])],
            [libintl_prefix="$withval"], [libintl_prefix="/c/msys64/mingw64"])


#checking whether we are cross compiling... no
# 크로스 컴파일 체크
AC_CANONICAL_HOST

# 크로스 컴파일을 위한 설정
if test "$host" != "$build"; then
    AC_MSG_NOTICE([Cross-compiling for $host])
    CC=x86_64-w64-mingw32-gcc
    CXX=x86_64-w64-mingw32-g++
else
    AC_MSG_NOTICE([Not cross-compiling])
fi

# 필요한 라이브러리 및 헤더 체크 (예: stdlib.h, stdio.h 등)
AC_CHECK_HEADERS([stdlib.h stdio.h xalloc.h string.h unistd.h stdint.h])

#AM_INIT_AUTOMAKE([1.9.6 foreign])
#AC_PROG_LIBTOOL 제거됨 -> LT_INIT

AC_PREREQ([2.64])  # Autoconf minimum version

AC_CONFIG_SRCDIR([lib/color.c])  # Primary source file
AC_CONFIG_AUX_DIR([build-aux])  # Auxiliary files directory
# AC_CONFIG_HEADERS([config.h])  # Create config.h file
AC_CONFIG_MACRO_DIRS([m4])

# Read version number from version.sh
. $srcdir/version.sh
gl_INIT_PACKAGE([libtextstyle], [$VERSION_NUMBER])

# Initialize Automake
AM_INIT_AUTOMAKE([1.13 silent-rules]) #gl_INIT_PACKAGE보다 먼저 선언되면 안됨


# LT_WITH_LTDL # 더이상 제공되지 않음

LT_LANG([C])
LT_LANG([C++])
LT_LANG([Windows Resource])

AC_PROG_CC
m4_ifdef([AX_PREFIX_CONFIG_H], [AX_PREFIX_CONFIG_H])
# C17 표준을 컴파일러 플래그로 추가
#AX_CHECK_COMPILE_FLAG([-std=c17], [CFLAGS="$CFLAGS -std=c17"])
# 필요시 C17을 나타내는 변수 설정
#AC_SUBST([CC_STANDARD], [17])

#AC_SUBST([CFLAGS], ["-std=c17 -I/mingw64/include -O2"]) #-std=c23 제거 지원안함 gcc 14.2
#AC_SUBST([CPPFLAGS], ["-I/mingw64/include -O2"])
#AC_SUBST([CXXFLAGS], ["-std=c++17 -I/mingw64/include -O2 -DDEBUG -DVERSION=\"1.0.0\""])

#AC_SUBST([TEXI2DVI], [texi2dvi]) # 추가
#AC_SUBST([TEXI2PDF], [$(TEXI2DVI) --pdf]) # 추가
#AC_SUBST([DVIPS], [dvips -D600]) # 추가
#AC_SUBST([DEFAULT_INCLUDES], [-I. -I$(srcdir) -I$(top_builddir)/lib -I$(top_builddir)]) # 추가

# C 컴파일러가 -std=c11 플래그를 지원하는지 확인
AC_LANG(C)
AC_COMPILE_IFELSE([  
    AC_LANG_SOURCE([[  // C 프로그램을 정의
        #include <stdio.h>
        #include <stdlib.h>
        #include <stdalign.h>

        int main(void) {
            // C11에서 도입된 _Alignas를 사용하여 16바이트 정렬된 변수 선언
            _Alignas(16) char buffer[32];  // 16바이트 정렬된 배열

            // static_assert로 C11 지원 여부 확인
            _Static_assert(1, "C11 is supported.");  // 항상 참인 조건

            printf("C11 is supported.\n");  // 출력 메시지
            return 0; // 성공
        }
    ]])
], [
	CFLAGS="$CFLAGS -std=c11"  # C11 플래그 추가
	AC_DEFINE([HAVE_C11], [1], [Define to 1 if C11 is supported.])
    AC_MSG_NOTICE([C11 지원: CFLAGS: $CFLAGS])
], [
	AC_MSG_NOTICE([C11 지원안함: CFLAGS: $CFLAGS])
    AC_MSG_ERROR([c11 지원 없습니다.])
])

# C++ 컴파일러가 -std=c++17 플래그를 지원하는지 확인
AC_LANG(C++)
AC_COMPILE_IFELSE([  
    AC_LANG_SOURCE([[  // C++ 프로그램을 정의
        #include <iostream>
		#include <string_view>  // C++17에서 추가된 std::string_view 사용

		int main() {
			// C++17에서 추가된 static_assert로 지원 여부를 확인합니다.
			static_assert(true, "C++17 is supported.");

			// C++17에서 추가된 std::string_view 사용
			std::string_view message = "C++17 is supported.";

			// 메시지를 출력
			std::cout << message << std::endl;

			return 0;
		}
    ]])
], [
    CXXFLAGS="$CXXFLAGS -std=c++17"  # C++17 플래그 추가
    AC_DEFINE([HAVE_CPP17], [1], [Define to 1 if C++17 is supported.])
    AC_MSG_NOTICE([C++17 지원: CXXFLAGS: $CXXFLAGS])
], [
    AC_MSG_NOTICE([C++17 지원안함: CXXFLAGS: $CXXFLAGS])
    AC_MSG_ERROR([C++17 지원이 없습니다.])
])

# Cross-compiling 여부 체크
AC_CROSS_COMPILER

# Cross-compiling 체크 추가
AC_MSG_NOTICE([Assuming cross-compiling is enabled.])
AC_DEFINE([CROSS_COMPILING], [1], [Define if we are cross compiling])

# 다른 체크 매크로들
AC_CHECK_TOOL([CC], [x86_64-w64-mingw32-gcc], [gcc]) #14.2.0
AC_CHECK_TOOL([LD], [/mingw64/bin/ld.exe], [ld]) #2.43.1
AC_CHECK_TOOL([AR], [/mingw64/bin/ar.exe], [ar]) #2.43.1

# 윈도우 콘솔 관련 라이브러리 또는 헤더 파일 체크
#AC_CHECK_HEADERS([windows.h], 
#    [AC_DEFINE([HAVE_WINDOWS_CONSOLES], [1], [Define to 1 if Windows consoles are available.])],
#    [AC_DEFINE([HAVE_WINDOWS_CONSOLES], [0], [Define to 0 if Windows consoles are not available.])]
#)

# 매크로를 정의하고 구현 내용을 포함
AC_DEFUN([AC_LIBTOOL_PROG_CC_C_O], [dnl
  # 매크로의 구현 내용
])
AC_DEFUN([AC_LIBTOOL_SYS_HARD_LINK_LOCKS], [dnl
  # 매크로의 구현 내용
])
AC_DEFUN([AC_LIBTOOL_OBJDIR], [dnl
  # 매크로의 구현 내용
])

# 플랫폼별 시스템 헤더 설정
AC_DEFUN([CHECK_WINDOWS_CONSOLES], [
  AC_MSG_CHECKING([for Windows consoles])
  if test -f /mingw64/include/windows.h; then
    AC_DEFINE([HAVE_WINDOWS_CONSOLES], [1], [Define to 1 if you have Windows consoles.])
    AC_MSG_RESULT([yes])
  else
    AC_MSG_RESULT([no])
  fi
])

# 호출
CHECK_WINDOWS_CONSOLES


# Check for required system headers
#AC_CHECK_HEADERS([stdio.h stdlib.h wchar.h attributes.h])
AC_CHECK_HEADERS([wchar.h]) #attributes.h존재하지않음

# Check for the presence of getprogname function
#AC_CHECK_FUNCS([getprogname printf malloc])
AC_CHECK_FUNCS([getprogname printf malloc fsync], [GL_COND_OBJ_FSYNC=1])
#AC_CHECK_FUNCS([_get_osfhandle])
# 메모리 할당 함수 체크
AC_CHECK_FUNCS([xmalloc xrealloc rpl_stpcpy xalloc_die], [], [
    AC_MSG_ERROR([Failed to define necessary memory allocation functions.])
])

# Initialize Gnulib
# 모듈 정의: undefined reference to tparm, tputs, xmalloc, xrealloc, xgethostname, _gl_nothrow_get_osfhandle
#GNULIB_MODULES"([ncurses], # tparm, tputs
#    [terminfo], # tparm, tputs
#    [xmalloc],
#    [xrealloc], 
#    [xgethostname],
#    [_gl_nothrow_get_osfhandle]
#)"

# GNULIB 모듈 정의
GNULIB_MODULES="
    ncurses \
    terminfo \
	rpl_stpcpy \
	xalloc \
	xalloc_die \
    xmalloc \
    xrealloc \
    xgethostname \
    _gl_nothrow_get_osfhandle \
	fsync \
	getprogname \
	_get_osfhandle \
	strlcpy \
	argz \
	can-compile
"

AC_GNU_LIB_TOOL

m4_ifdef([GNULIB_INIT], [GNULIB_INIT])


m4_pattern_allow([^AC_GNU_LIB_TOOL$])
m4_pattern_allow([AC_CROSS_COMPILER])
m4_pattern_allow([GL_REQUIRE_VERSION]) # Gnulib의 최소 버전을 요구하는 매크로
m4_pattern_allow([GNULIB_MODULES]) # 허용 패턴 설정
m4_pattern_allow([AC_MSG_WARN]) # 경고 메시지
m4_pattern_allow([_LT_LIBOBJS]) # _LT_LIBOBJS 패턴 허용

AC_CHECK_LIB([ncurses], [tputs], [initscr]) # ncurses 라이브러리 링크 추가

m4_pattern_allow([gl_CC_GNULIB_WARNINGS])
#m4_include([m4/gnulib-common.m4]) #"C:\libidn2\gettext-0.22.5\libtextstyle\m4\gnulib-common.m4"
#m4_include([m4/gnulib-tool.m4]) #"C:\libidn2\gettext-0.22.5\libtextstyle\m4\gnulib-tool.m4"
m4_pattern_allow([AC_CHECK_FUNCS])
m4_pattern_allow([gl_INIT])
m4_pattern_allow([gl_EARLY])
m4_pattern_allow([gl_COMMON])
m4_pattern_allow([gl_PROG_AR_RANLIB])
m4_pattern_allow([AC_CONFIG_RPATH])
m4_pattern_allow([AC_CONFIG_LIBS])
m4_pattern_allow([AC_DEFINE])
m4_pattern_allow([gl_MODULES])
m4_pattern_allow([m4_ifndef])

# Early Gnulib configuration
gl_EARLY

# Initialize Gnulib
gl_INIT

# Add necessary Gnulib modules
gl_MODULES([xalloc])
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
gl_MODULES([xsize])
gl_MODULES([size_max])

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


# Check for fsync
# fsync가 사용 가능한지 확인하고, 그렇지 않은 경우 FlushFileBuffers를 사용하도록 설정
AC_COMPILE_IFELSE([AC_LANG_SOURCE([#include <unistd.h>
                                    int main() {
                                        int fd = 0; 
                                        fsync(fd);
                                        return 0;
                                    }])],
[AC_DEFINE([HAVE_FSYNC], [1], [Define to 1 if you have the fsync' function.])],
[AC_DEFINE([HAVE_FLUSH_FILE_BUFFERS], [1], [Define to 1 if using FlushFileBuffers on Windows.])])


# Check for compiler attributes
AC_DEFUN([CHECK_HAS_ATTRIBUTE], [
    AC_COMPILE_IFELSE([
        AC_LANG_PROGRAM([[#ifdef __cplusplus
                         #define _GL_HAS_ATTRIBUTE(x) __has_attribute(x)
                         #else
                         #define _GL_HAS_ATTRIBUTE(x) 0
                         #endif]], [])
    ], [
        AC_SUBST([_GL_HAS_ATTRIBUTE], [__has_attribute])
    ], [
        AC_SUBST([_GL_HAS_ATTRIBUTE], [0])
    ])
])
# Call the macro to check for attributes
CHECK_HAS_ATTRIBUTE

# Check if the compiler supports the __attribute__((returns_nonnull)) attribute
AC_MSG_CHECKING([whether the compiler supports __attribute__((returns_nonnull))])
AC_COMPILE_IFELSE(
    [AC_LANG_PROGRAM([[]], [[
        #ifdef __cplusplus
        void* test_returns_nonnull(void) __attribute__((returns_nonnull));
        #else
        void* test_returns_nonnull(void);
        #endif
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
 AC_DEFINE([HAVE_ATTRIBUTE_PURE], [1], [Define if compiler supports __attribute__((__pure__))])],
[AC_MSG_RESULT([no])
 AC_DEFINE([HAVE_ATTRIBUTE_PURE], [0], [Define if compiler does not support __attribute__((__pure__))])])


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
 AC_DEFINE([HAVE_ATTRIBUTE_NONNULL], [1], [Define if compiler supports __attribute__((nonnull))])],
[AC_MSG_RESULT([no])
 AC_DEFINE([HAVE_ATTRIBUTE_NONNULL], [0], [Define if compiler does not support __attribute__((nonnull))])])


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
 AC_DEFINE([HAVE_ATTRIBUTE_MALLOC], [1], [Define if compiler supports __attribute__((__malloc__))])],
[AC_MSG_RESULT([no])
 AC_DEFINE([HAVE_ATTRIBUTE_MALLOC], [0], [Define if compiler does not support __attribute__((__malloc__))])])


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

# ignoring macro define start
#define([DEFINE_MACRO], [m4_ifndef([$1], [AC_DEFINE([$1], [1], [$2])])])
#DEFINE_MACRO([gl_XSIZE], [Description of gl_XSIZE])
#aclocal-1.16: ignoring macro gl_XSIZE in /mingw64/share/aclocal/xsize.m4: 7
# ignoring macro define end
#aclocal-1.16: ignoring macro gl_XSIZE in /mingw64/share/aclocal/xsize.m4: 7
# config.h 생성결과
# /* Description of gl_XSIZE */
# #define gl_XSIZE 1
#aclocal-1.16: ignoring macro AM_LANGINFO_CODESET in /c/libidn2/m4/codeset.m4: 10

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


CPPFLAGS="$CPPFLAGS -I/mingw64/include -I/c/libidn2/gettext-0.22.5/libtextstyle/lib -DNEED_MACRO"
AC_SUBST([CPPFLAGS], ["$CPPFLAGS"])

AC_SUBST([LIBS], [-ltextstyle])

# 함수 등록
# 체크하고 없을 경우 오류출력 lib/xgethostname.h, lib/xgethostname.c 있음
# AC_CHECK_FUNC([XGETANAME], [], [AC_MSG_ERROR([XGETANAME not found])])

# 체크하고 없을 경우 선언하기
#AC_CHECK_FUNC([_get_osfhandle], [], [
#    AC_MSG_NOTICE([Defining _gl_nothrow_get_osfhandle as a wrapper for _get_osfhandle])
#    AC_DEFINE([GL_NOTHROW_GET_OSFHANDLE_NOT_FOUND], [1], [Define to 1 if _gl_nothrow_get_osfhandle is not available])
#
#    AC_LANG_PUSH([C])
#    AC_COMPILE_IFELSE([
#        AC_LANG_PROGRAM([
#            #include <unistd.h>
#            int _gl_nothrow_get_osfhandle(int fd) {
#                return _get_osfhandle(fd);
#            }
#        ])
#    ], [
#        # 성공적으로 컴파일된 경우에 대한 추가 작업
#    ], [
#        # 컴파일 실패 시 메시지
#        AC_MSG_ERROR([Failed to define _gl_nothrow_get_osfhandle])
#    ])
#    AC_LANG_POP
#])

AC_CHECK_FUNCS([_get_osfhandle],
 [AC_DEFINE([_GL_NOTHROW_GET_OSFHANDLE], [1], [Define if _get_osfhandle is available])],
 [AC_DEFINE([_GL_NOTHROW_GET_OSFHANDLE], [0], [Define if _get_osfhandle is not available])
  AC_MSG_WARN([_get_osfhandle not found. Defining _gl_nothrow_get_osfhandle as a no-op.])
	# Provide a fallback implementation
	AC_MSG_NOTICE([Providing a fallback implementation for _gl_nothrow_get_osfhandle])

	# Create the fallback code in conftest.c
	cat >> conftest.c <<END 
	#include <stdio.h>
	#include <stdlib.h>

	// Fallback implementation
	int _gl_nothrow_get_osfhandle(int fd) {
		fprintf(stderr, "Warning: _get_osfhandle is not available. Returning -1 as a fallback.\n");
		return -1; // Return -1 or any appropriate error code
	}
END
])

#AC_CHECK_FUNC([xgethostname], [], [
#    AC_MSG_NOTICE([Defining xgethostname as a placeholder])
#    AC_LANG_PUSH([C])
#    AC_COMPILE_IFELSE([
#        AC_LANG_PROGRAM([
#            #include <unistd.h>
#            int xgethostname(char *name, size_t len) {
#                return gethostname(name, len);
#            }
#        ])
#    ], [], [
#        AC_MSG_ERROR([Failed to define xgethostname])
#    ])
#    AC_LANG_POP
#])


AC_CHECK_FUNC([xmalloc], [], [
    AC_MSG_NOTICE([Defining xmalloc as a placeholder])
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([ 
        AC_LANG_PROGRAM([ 
            #include <stdlib.h>
            void *xmalloc(size_t size) {
                void *ptr = malloc(size);
                if (!ptr) {
                    exit(EXIT_FAILURE);
                }
                return ptr;
            }
        ])
    ], [], [
        AC_MSG_ERROR([Failed to define xmalloc])
    ])
    AC_LANG_POP
])

AC_CHECK_FUNC([xrealloc], [], [
    AC_MSG_NOTICE([Defining xrealloc as a placeholder])
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([ 
        AC_LANG_PROGRAM([ 
            #include <stdlib.h>
            void *xrealloc(void *ptr, size_t size) {
                void *new_ptr = realloc(ptr, size);
                if (!new_ptr) {
                    exit(EXIT_FAILURE);
                }
                return new_ptr;
            }
        ])
    ], [], [
        AC_MSG_ERROR([Failed to define xrealloc])
    ])
    AC_LANG_POP
])

AC_CHECK_FUNC([rpl_stpcpy], [], [
    AC_MSG_NOTICE([Defining rpl_stpcpy as a placeholder])
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([ 
        AC_LANG_PROGRAM([ 
            #include <string.h>
            char *rpl_stpcpy(char *dest, const char *src) {
                return stpcpy(dest, src);
            }
        ])
    ], [], [
        AC_MSG_ERROR([Failed to define rpl_stpcpy])
    ])
    AC_LANG_POP
])

AC_CHECK_FUNC([xalloc_die], [], [
    AC_MSG_NOTICE([Defining xalloc_die as a placeholder])
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([ 
        AC_LANG_PROGRAM([ 
            #include <stdio.h>
            void xalloc_die(void) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
        ])
    ], [], [
        AC_MSG_ERROR([Failed to define xalloc_die])
    ])
    AC_LANG_POP
])

AC_CHECK_FUNC([safe_write], [], [
    AC_MSG_NOTICE([Defining safe_write as a placeholder])
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([ 
        AC_LANG_PROGRAM([ 
            #include <unistd.h>
            ssize_t safe_write(int fd, const void *buf, size_t count) {
                ssize_t result = write(fd, buf, count);
                if (result < 0) {
                    // handle error
                }
                return result;
            }
        ])
    ], [], [
        AC_MSG_ERROR([Failed to define safe_write])
    ])
    AC_LANG_POP
])

AC_CHECK_FUNC([at_fatal_signal], [], [
    AC_MSG_NOTICE([Defining at_fatal_signal as a placeholder])
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([ 
        AC_LANG_PROGRAM([ 
            #include <signal.h>
            void at_fatal_signal(void (*handler)(int)) {
                signal(SIGTERM, handler);
            }
        ])
    ], [], [
        AC_MSG_ERROR([Failed to define at_fatal_signal])
    ])
    AC_LANG_POP
])

AC_CHECK_FUNC([styled_ostream_create], [], [
    AC_MSG_NOTICE([Defining styled_ostream_create as a placeholder])
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([ 
        AC_LANG_PROGRAM([ 
            void *styled_ostream_create(void) {
                return NULL; // placeholder implementation
            }
        ])
    ], [], [
        AC_MSG_ERROR([Failed to define styled_ostream_create])
    ])
    AC_LANG_POP
])

AC_CHECK_FUNC([styled_ostream_begin_use_class], [], [
    AC_MSG_NOTICE([Defining styled_ostream_begin_use_class as a placeholder])
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([ 
        AC_LANG_PROGRAM([ 
            void styled_ostream_begin_use_class(void) {
                // placeholder implementation
            }
        ])
    ], [], [
        AC_MSG_ERROR([Failed to define styled_ostream_begin_use_class])
    ])
    AC_LANG_POP
])

AC_CHECK_FUNC([styled_ostream_set_hyperlink], [], [
    AC_MSG_NOTICE([Defining styled_ostream_set_hyperlink as a placeholder])
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([ 
        AC_LANG_PROGRAM([ 
            void styled_ostream_set_hyperlink(void *stream, const char *url) {
                // placeholder implementation
            }
        ])
    ], [], [
        AC_MSG_ERROR([Failed to define styled_ostream_set_hyperlink])
    ])
    AC_LANG_POP
])

AC_CHECK_FUNC([file_ostream_create], [], [
    AC_MSG_NOTICE([Defining file_ostream_create as a placeholder])
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([ 
        AC_LANG_PROGRAM([ 
            void *file_ostream_create(const char *filename) {
                return NULL; // placeholder implementation
            }
        ])
    ], [], [
        AC_MSG_ERROR([Failed to define file_ostream_create])
    ])
    AC_LANG_POP
])

AC_CHECK_FUNC([html_styled_ostream_create], [], [
    AC_MSG_NOTICE([Defining html_styled_ostream_create as a placeholder])
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([ 
        AC_LANG_PROGRAM([ 
            void *html_styled_ostream_create(void) {
                return NULL; // placeholder implementation
            }
        ])
    ], [], [
        AC_MSG_ERROR([Failed to define html_styled_ostream_create])
    ])
    AC_LANG_POP
])

AC_CHECK_FUNC([get_fatal_signals], [], [
    AC_MSG_NOTICE([Defining get_fatal_signals as a placeholder])
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([ 
        AC_LANG_PROGRAM([ 
            void get_fatal_signals(void) {
                // placeholder implementation
            }
        ])
    ], [], [
        AC_MSG_ERROR([Failed to define get_fatal_signals])
    ])
    AC_LANG_POP
])




# Compiler and toolchain checks
#AC_GNU_LIBTOOL_WIN32 # LT_INIT대체
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_MKDIR_P

# Gnulib 초기화
GNULIB_PATH=gnulib
#AC_GNU_LIBTOOL # LT_INIT대체

# Host system type checks
AC_CANONICAL_HOST
echo "configure.ac: Configured host OS: $host_os"

# Windows-specific settings for mingw and Cygwin
#case "$host_os" in
#  mingw* | cygwin*) 
#    is_woe32=yes
#    ;;
#  *) 
#    is_woe32=no
#    ;;
#esac

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


# xgethostname 함수 확인
AC_CHECK_HEADERS([lib/xgethostname.h lib/xgetaname-impl.h])
AC_CHECK_FUNC([XGETANAME], [], [AC_MSG_ERROR([XGETANAME not found])])

# Check for specific headers and libraries
AC_CHECK_HEADERS([textstyle/woe32dll.h], [WOE32DLL=1], [WOE32DLL=0])

if test "$WOE32DLL" = "1"; then
  AM_LDFLAGS='-export-dynamic'
fi

# Set up paths for documentation tools
ac_aux_dir_abs=`cd $ac_aux_dir && pwd`
#AC_PATH_PROG([TEXI2DVI], [texi2dvi], [$ac_aux_dir_abs/missing texi2dvi])
#AC_PATH_PROG([DVIPS], [dvips], [$ac_aux_dir_abs/missing dvips])
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

# 패키지 설정
PKG_CHECK_MODULES(
    [ITL], 
    [libintl], 
    [have_libintl=yes], 
    [have_libintl=no]
)

AC_SUBST([ITL_CFLAGS])
AC_SUBST([ITL_LIBS])

PKG_CHECK_MODULES(
    [NCURSES], 
    [ncurses], 
    [have_ncurses=yes], 
    [have_ncurses=no]
)

AC_SUBST([NCURSES_CFLAGS])
AC_SUBST([NCURSES_LIBS])

PKG_CHECK_MODULES(
    [GLIB], 
    [glib-2.0 gobject-2.0], 
    [have_glib=yes], 
    [have_glib=no]
)

AC_SUBST([GLIB_CFLAGS])
AC_SUBST([GLIB_LIBS])

# 인클루드 경로와 라이브러리 경로 추가 : libtool이 자동으로 올바른 경로에서 libintl을 찾아 사용할 수 있도록 함
AC_SUBST([INTL_CFLAGS], [$INTL_CFLAGS])
AC_SUBST([INTL_LIBS], [$INTL_LIBS])

# Makefile에 전달할 변수 정의
#AC_SUBST([NCURSES_CFLAGS])
#AC_SUBST([NCURSES_LIBS])
AC_SUBST([NCURSES_CFLAGS], [$NCURSES_CFLAGS])
AC_SUBST([NCURSES_LIBS], [$NCURSES_LIBS])

# Create Makefiles and output configurations
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([doc/Makefile])
AC_CONFIG_FILES([lib/Makefile])
AC_CONFIG_FILES([lib/exported.sh])
AC_CONFIG_FILES([lib/textstyle/version.h:lib/textstyle/version.in.h])
AC_CONFIG_FILES([lib/textstyle/woe32dll.h:lib/textstyle/woe32dll.in.h])
AC_CONFIG_FILES([tests/Makefile])
AC_CONFIG_FILES([adhoc-tests/Makefile])


#빌드에 필요한 오브젝트 파일
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
AC_LIBOBJ([lt__alloc]) 
AC_LIBOBJ([lt__argz])
AC_LIBOBJ([lt_dlloader])
AC_LIBOBJ([lt_error])
AC_LIBOBJ([ltdl])
AC_LIBOBJ([slist])

AC_OUTPUT