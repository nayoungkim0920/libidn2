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

AC_INIT([libtextstyle], [1.0], [bug-libtextstyle@example.com]) # 프로젝트 초기화
AC_USE_SYSTEM_EXTENSIONS

LT_CONFIG_LTDL_DIR([libltdl])
LT_INIT([win32-dll], [dlopen disable-static])
LTDL_INIT

AC_PREREQ([2.72])  # autoconf --version
AC_CAN_COMPILE

AM_GNU_GETTEXT_VERSION([0.22.5]) # gettext --version 0.22.5
AM_GNU_GETTEXT([external]) # gettext는 external 인자 없이 사용할 수 없음

# m4 패턴 허용
m4_pattern_allow([AC_CAN_COMPILE])
m4_pattern_allow([AC_GNU_LIB_TOOL])
m4_pattern_allow([AC_CROSS_COMPILER])
m4_pattern_allow([GL_REQUIRE_VERSION])
m4_pattern_allow([GNULIB_MODULES])
m4_pattern_allow([AC_MSG_WARN])
m4_pattern_allow([_LT_LIBOBJS])
m4_pattern_allow([gl_CC_GNULIB_WARNINGS])
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

# Libtool이 컴파일과 링크 작업을 처리할 수 있게 해주는 설정
AC_LANG([C])
AC_LANG([C++])
AC_LANG([CXX])

AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX

# GNULIB 초기화
gl_EARLY
gl_INIT

# GNULIB 관련 매크로 정의
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
    can-compile \
	m4
"

# GNULIB 모듈 활성화
gl_MODULES([xalloc])
gl_MODULES([xalloc-die])
gl_MODULES([xmalloca])
gl_MODULES([fsync])
gl_MODULES([xstrdup])
gl_MODULES([xsize])
gl_MODULES([size_max])

# AC_CONFIG_HEADERS 호출
#AC_CONFIG_HEADERS([config.h.in:config.h lib/argz.h.in:lib/argz.h])
AC_CONFIG_HEADERS([config.h lib/argz.h])
#echo "error config.h.in path: $(pwd)/config.h.in"
#echo "error config.h path: $(pwd)/config.h"
#echo "error lib/argz.h.in path: $(pwd)/lib/argz.h.in"
#echo "error lib/argz.h path: $(pwd)/lib/argz.h"


# Libtool AR, RANLIB 설정 (gl_PROG_AR_RANLIB 호출)
gl_PROG_AR_RANLIB

# 아카이브 툴 확인 (AM_PROG_AR 호출)
#AM_PROG_AR #gl_PROG_AR_RANLIB과 충돌

IT_PROG_INTLTOOL([0.51.0]) # intltool의 버전을 확인하고 필요한 경우 설치

GTK_DOC_CHECK([1.34])  # Gtkdoc 버전 요구 사항을 설정합니다.

AC_ARG_WITH([libintl-prefix],
            [AS_HELP_STRING([--with-libintl-prefix=DIR],
                            [Specify the installation directory of libintl])],
            [libintl_prefix="$withval"], [libintl_prefix="$libintl_prefix"])

AC_CANONICAL_HOST

AC_CHECK_HEADERS([
	stdlib.h 
	stdio.h 
	xalloc.h 
	string.h 
	unistd.h 
	stdint.h 
	wchar.h
	lib/xgethostname.h 
	lib/xgetaname-impl.h
])

AC_CHECK_HEADERS([textstyle/woe32dll.h], [WOE32DLL=1], [WOE32DLL=0])

GNULIB_PATH=gnulib
AC_CANONICAL_HOST
echo "configure.ac: Configured host OS: $host_os"
#output : configure.ac: Configured host OS: mingw32
# 호스트 OS가 mingw32인지 확인하고 관련 플래그와 조건을 설정
#if test "$host_os" = "mingw32"; then
if test "$host_os" in  mingw* | cygwin*; then
    # mingw32가 감지되면 WOE32DLL과 WOE32를 활성화
    AM_CONDITIONAL([WOE32DLL], true)
    AM_CONDITIONAL([WOE32], true)
    echo "WOE32DLL과 WOE32가 활성화되었습니다."
    # mingw32에서 동적 내보내기(export-dynamic)를 위해 LDFLAGS 설정
    # LDFLAGS="$LDFLAGS -no-undefined -export-dynamic"
	# LDFLAGS="$LDFLAGS -export-dynamic"

    # MinGW에서 불필요한 버전 확인 옵션 및 링커 옵션 제거
    AC_MSG_NOTICE([Configuring for MinGW environment])

    # MinGW에서 비호환 옵션을 피하기 위해 LDFLAGS 수정
    LDFLAGS=$(echo "$LDFLAGS" | sed 's/-no-undefined//g; s/-export-dynamic//g')

    # 컴파일러 버전 확인 시 불필요한 옵션을 피하도록 설정
    # autoconf 기본 매크로로 인해 비호환 옵션이 시도되는 것을 방지
    CC="$CC --version"
    CXX="$CXX --version"

else
    # mingw32가 아닌 경우 WOE32DLL과 WOE32를 비활성화
    AM_CONDITIONAL([WOE32DLL], false)
    AM_CONDITIONAL([WOE32], false)
    echo "WOE32DLL과 WOE32가 비활성화되었습니다."
    # non-mingw32 시스템에서는 정의되지 않은 심볼을 허용하지 않도록 LDFLAGS 설정
    # LDFLAGS="$LDFLAGS -no-undefined"
fi

# AC_CONFIG_SUBDIRS([libltdl]) # LT_CONFIG_LTDL_DIR([libltdl])
AC_CONFIG_SRCDIR([lib/color.c])  # Primary source file
AC_CONFIG_AUX_DIR([build-aux])  # Auxiliary files directory (config.rpath, install-sh, config.guess, config.sub, ltmain.sh)
# 컴파일러 설정
AC_PROG_INSTALL
#output:checking for a BSD-compatible install... /usr/bin/install -c
AC_PROG_MKDIR_P
#output:checking for a race-free mkdir -p... /usr/bin/mkdir -p
AC_CONFIG_MACRO_DIRS([m4] [../m4] [gnulib-m4])
. $srcdir/version.sh
gl_INIT_PACKAGE([libtextstyle], [$VERSION_NUMBER])
AM_INIT_AUTOMAKE([1.13 silent-rules]) #gl_INIT_PACKAGE보다 먼저 선언되면 안됨
#AC_PROG_LIBTOOL # 동적 라이브러리 및 정적 라이브러리 생성을 관리 => LT_INIT
AM_PROG_CC_C_O # C 컴파일러를 체크하고, -c 및 -o 옵션이 잘 동작하는지 확인
#output:checking whether build environment is sane... yes
#output:checking for x86_64-w64-mingw32-strip... no
#output:checking for strip... strip
#output:checking for gawk... gawk
#output:checking whether make sets $(MAKE)... yes
#output:checking whether make supports nested variables... yes

LT_LANG([C])
LT_LANG([C++])
LT_LANG([Windows Resource])

m4_ifdef([AX_PREFIX_CONFIG_H], [AX_PREFIX_CONFIG_H])

# C11 지원 확인
AC_LANG_PUSH([C])
AC_COMPILE_IFELSE([  
   AC_LANG_SOURCE([[  /* C11에서 도입된 _Alignas 사용 */
       #include <stdio.h>
       #include <stdlib.h>
       #include <stdalign.h>

       int main(void) {
           /* C11에서 도입된 _Alignas를 사용하여 16바이트 정렬된 변수 선언 */
           _Alignas(16) char buffer[32];  /* 16바이트 정렬된 배열 */

           /* static_assert로 C11 지원 여부 확인 */
           _Static_assert(1, "C11 is supported.");  /* 항상 참인 조건 */

           printf("C11 is supported.\n");  /* 출력 메시지 */
           return 0;  /* 성공 */
       }
   ]])
], [
   #CFLAGS="$CFLAGS -std=c11"  # C11 플래그 추가 # ./configure CFLAGS="-std=c11"
   AC_DEFINE([HAVE_C11], [1], [Define to 1 if C11 is supported.])
], [
   AC_MSG_ERROR([C11 지원이 없습니다.])
])

# C++17 지원 확인
AC_LANG_PUSH([C++])
AC_COMPILE_IFELSE([
   AC_LANG_SOURCE([[
       #include <iostream>
       #include <string_view>

       int main() {
           static_assert(true, "C++17 is supported.");
           std::string_view message = "C++17 is supported.";
           std::cout << message << std::endl;
           return 0;
       }
   ]])
], [
   CXXFLAGS="$CXXFLAGS -std=c++17"
   AC_DEFINE([HAVE_CPP17], [1], [Define to 1 if C++17 is supported.])
], [
   AC_MSG_ERROR([C++17 지원이 없습니다.])
])
AC_LANG_POP


AC_CROSS_COMPILER # command not found
AC_DEFINE([CROSS_COMPILING], [1], [Define if we are cross compiling])

AC_CHECK_TOOL([CC], [x86_64-w64-mingw32-gcc], [gcc]) #14.2.0
AC_CHECK_TOOL([LD], [/mingw64/bin/ld.exe], [ld]) #2.43.1
AC_CHECK_TOOL([AR], [/mingw64/bin/ar.exe], [ar]) #2.43.1
AC_DEFUN([AC_LIBTOOL_PROG_CC_C_O], [dnl])

AC_DEFUN([AC_LIBTOOL_SYS_HARD_LINK_LOCKS], [dnl])
AC_DEFUN([AC_LIBTOOL_OBJDIR], [dnl])
AC_DEFUN([CHECK_WINDOWS_CONSOLES], [
  if test -f /mingw64/include/windows.h; then
    AC_DEFINE([HAVE_WINDOWS_CONSOLES], [1], [Define to 1 if you have Windows consoles.])
    AC_MSG_RESULT([yes])
  else
    AC_MSG_RESULT([no])
  fi
])
CHECK_WINDOWS_CONSOLES
#output:checking for Windows consoles... yes

AC_COMPILE_IFELSE(
   [AC_LANG_PROGRAM([[]], [[
       void* xmalloc(size_t size) __attribute__((__alloc_size__(1)));
   ]])],
   [AC_DEFINE([_GL_HAS_ATTRIBUTE_ALLOC_SIZE], [1], [Define if compiler supports __attribute__((__alloc_size__))])],
   [AC_DEFINE([_GL_HAS_ATTRIBUTE_ALLOC_SIZE], [0], [Define if compiler does not support __attribute__((__alloc_size__))])]
)

# AC_COMPILE_IFELSE([AC_LANG_SOURCE([#include <unistd.h>
#                                    int main() {
#                                        int fd = 0; 
#                                        fsync(fd);
#                                        return 0;
#                                    }])],
# [AC_DEFINE([HAVE_FSYNC], [1], [Define to 1 if you have the fsync' function.])],
# [AC_DEFINE([HAVE_FLUSH_FILE_BUFFERS], [1], [Define to 1 if using FlushFileBuffers on Windows.])])

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

CHECK_HAS_ATTRIBUTE

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
if test "$HAVE_ATTRIBUTE_PURE" = 1; then
   AC_DEFINE([_GL_ATTRIBUTE_PURE], [__attribute__((__pure__))], [Define to use __attribute__((__pure__))])
else
   AC_DEFINE([_GL_ATTRIBUTE_PURE], [], [Define as empty if __attribute__((__pure__)) is not supported])
fi

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

AC_COMPILE_IFELSE(
   [AC_LANG_PROGRAM([[]], [[__attribute__((noreturn)) void x();]])],
   [AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_NORETURN], [__attribute__((noreturn))], [Define for attribute noreturn])],
   [AC_DEFINE_UNQUOTED([_GL_ATTRIBUTE_NORETURN], [], [Define for attribute noreturn])]
)

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
if test "$host_os" = "mingw32"; then
    AC_DEFINE([DLL_VARIABLE], [__declspec(dllexport)], [Define to __declspec(dllexport)])
else
    AC_DEFINE([DLL_VARIABLE], [], [Define to nothing for non-Windows platforms])
fi
AC_SUBST([DLL_VARIABLE]) # DLL_VARIABLE macro setting

AC_CHECK_TYPE([wchar_t],
 [HAVE_WCHAR_T=1],
 [HAVE_WCHAR_T=0]
)
AC_SUBST([HAVE_WCHAR_T])
AC_SUBST([LIBS], [-ltextstyle])

#AC_CHECK_FUNCS([getprogname printf malloc fsync], [GL_COND_OBJ_FSYNC=1])

AC_CHECK_FUNCS([xmalloc xrealloc rpl_stpcpy xalloc_die], [], [
    AC_MSG_ERROR([Failed to define necessary memory allocation functions.])
])

AC_CHECK_FUNCS([_get_osfhandle],
[AC_DEFINE([_GL_NOTHROW_GET_OSFHANDLE], [1], [Define if _get_osfhandle is available])],
[AC_DEFINE([_GL_NOTHROW_GET_OSFHANDLE], [0], [Define if _get_osfhandle is not available])
 AC_MSG_WARN([_get_osfhandle not found. Defining _gl_nothrow_get_osfhandle as a no-op.])
	# Provide a fallback implementation

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

AC_CHECK_FUNC([xmalloc], [], [
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

# libxml이 포함되어 있는지 확인 (libxml이 있을 경우에만 활성화)
AM_CONDITIONAL([INCLUDED_LIBXML], [test "x$have_libxml" = "xyes"])

# Automake에서 사용할 GL 관련 매크로 정의
# 필요한 헤더와 기능을 포함하기 위해 조건을 true로 설정
AM_CONDITIONAL([GL_GENERATE_ALLOCA_H], true)        # alloca 헤더 생성
AM_CONDITIONAL([GL_GENERATE_ASSERT_H], true)        # assert 헤더 생성
AM_CONDITIONAL([GL_COND_OBJ_CLOSE], true)           # 객체 닫기 처리
AM_CONDITIONAL([GL_COND_OBJ_DUP2], true)            # 객체 복제 처리
AM_CONDITIONAL([GL_GENERATE_ERRNO_H], true)         # errno 헤더 생성
AM_CONDITIONAL([GL_COND_OBJ_ERROR], true)           # 오류 처리
AM_CONDITIONAL([GL_COND_OBJ_FCNTL], true)           # 파일 제어 처리
AM_CONDITIONAL([GL_COND_OBJ_FSTAT], true)           # 파일 상태 처리
AM_CONDITIONAL([GL_COND_OBJ_GETDTABLESIZE], true)   # 파일 디스크립터 테이블 크기 가져오기
AM_CONDITIONAL([GL_COND_OBJ_GETPROGNAME], true)      # 프로그램 이름 가져오기
AM_CONDITIONAL([GL_GENERATE_LIMITS_H], true)        # limits 헤더 생성
AM_CONDITIONAL([GL_COND_OBJ_MSVC_INVAL], true)      # MSVC 무효 값 처리
AM_CONDITIONAL([GL_COND_OBJ_MSVC_NOTHROW], true)    # MSVC 예외 처리 없음
AM_CONDITIONAL([GL_COND_OBJ_OPEN], true)            # 파일 열기 처리
AM_CONDITIONAL([GL_COND_OBJ_STAT], true)            # 파일 상태 확인
AM_CONDITIONAL([GL_GENERATE_STDCKDINT_H], true)      # 표준 ckdint 헤더 생성
AM_CONDITIONAL([GL_GENERATE_STDDEF_H], true)        # 표준 정의 헤더 생성
AM_CONDITIONAL([GL_GENERATE_STDINT_H], true)        # 표준 정수형 헤더 생성
AM_CONDITIONAL([GL_COND_OBJ_STDIO_READ], true)      # 표준 입출력 읽기 처리
AM_CONDITIONAL([GL_COND_OBJ_STDIO_WRITE], true)     # 표준 입출력 쓰기 처리
AM_CONDITIONAL([GL_COND_OBJ_STRERROR], true)        # strerror 처리
AM_CONDITIONAL([GL_COND_OBJ_STRERROR_OVERRIDE], true)  # strerror 오버라이드 처리

AC_CHECK_FUNC([XGETANAME], [], [AC_MSG_ERROR([XGETANAME not found])])

# if test "$WOE32DLL" = "1"; then
#   AM_LDFLAGS='-export-dynamic'
# fi
ac_aux_dir_abs=`cd $ac_aux_dir && pwd`
AC_PATH_PROG([PERL], [perl], [$ac_aux_dir_abs/missing perl])
#output : checking for perl... /usr/bin/perl
AC_ARG_ENABLE([namespacing],
  [  --disable-namespacing   build a library that exports undesired symbols],
  [:], [enable_namespacing=yes])
if test "$enable_namespacing" != no; then
  NAMESPACING=yes
else
  NAMESPACING=
fi
AC_SUBST([NAMESPACING])
AC_PROG_AWK
#output : checking for gawk... (cached) gawk
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

# PKG_CHECK_MODULES(
#     [GLIB], 
#     [glib-2.0 gobject-2.0], 
#     [have_glib=yes], 
#     [have_glib=no]
# )

PKG_CHECK_MODULES([GLIB], [glib-2.0 >= 2.10.0 gobject-2.0 >= 2.10.0], 
    [have_glib=yes], 
    [have_glib=no])

if test "x$have_glib" = "xno"; then
    AC_MSG_ERROR([GLib 2.10.0 or higher is required])
fi

AC_SUBST([GLIB_CFLAGS])
AC_SUBST([GLIB_LIBS])

AC_SUBST([INTL_CFLAGS], [$INTL_CFLAGS])
AC_SUBST([INTL_LIBS], [$INTL_LIBS])
AC_SUBST([NCURSES_CFLAGS], [$NCURSES_CFLAGS])
AC_SUBST([NCURSES_LIBS], [$NCURSES_LIBS])

AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([doc/Makefile])
AC_CONFIG_FILES([lib/Makefile])
AC_CONFIG_FILES([lib/exported.sh])
AC_CONFIG_FILES([lib/textstyle/version.h:lib/textstyle/version.in.h])
AC_CONFIG_FILES([lib/textstyle/woe32dll.h:lib/textstyle/woe32dll.in.h])
AC_CONFIG_FILES([tests/Makefile])
AC_CONFIG_FILES([adhoc-tests/Makefile])
AC_CONFIG_FILES([po/Makefile.in])

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


# 컴파일러 경로 출력

AC_OUTPUT