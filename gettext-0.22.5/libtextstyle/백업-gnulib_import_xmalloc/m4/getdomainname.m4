# netdb->winsock2 수정
# getdomainname.m4
# serial 14
dnl Copyright (C) 2002-2003, 2008-2024 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_GETDOMAINNAME],
[ 
  AC_REQUIRE([gl_UNISTD_H_DEFAULTS])
  AC_REQUIRE([gl_SYS_SOCKET_H])dnl for HAVE_SYS_SOCKET_H

  dnl Persuade glibc <unistd.h> to declare getdomainname().
  AC_REQUIRE([AC_USE_SYSTEM_EXTENSIONS])

  dnl Where is getdomainname() defined?
  gl_CHECK_FUNCS_ANDROID([getdomainname], [[#include <unistd.h>]])
  
  if test $ac_cv_func_getdomainname = no; then
    AC_CACHE_CHECK([for getdomainname in -lnsl],
      [gl_cv_func_getdomainname_in_libnsl],
      [gl_cv_func_getdomainname_in_libnsl=no
       gl_saved_LIBS="$LIBS"
       LIBS="$LIBS -lnsl"
       AC_LINK_IFELSE(
         [AC_LANG_PROGRAM(
            [[#include <stddef.h>
              extern
              #ifdef __cplusplus
              "C"
              #endif
              int getdomainname (char *, size_t);
            ]],
            [[getdomainname(NULL, 0);]])],
         [gl_cv_func_getdomainname_in_libnsl=yes])
       LIBS="$gl_saved_LIBS"
      ])
  fi

  dnl What about the declaration?
  AC_CHECK_DECLS([getdomainname], , ,
    [[#include <sys/types.h>
      #ifdef HAVE_SYS_SOCKET_H
      #include <sys/socket.h>
      #endif
      #ifdef _WIN32
        #include <winsock2.h>
        #include <ws2tcpip.h>
      #else
        #include <netdb.h>
      #endif
      #include <unistd.h>
    ]])
  
  AC_CACHE_CHECK([for getdomainname's second argument type],
    [gl_cv_decl_getdomainname_argtype2],
    [if test $ac_cv_have_decl_getdomainname; then
       AC_COMPILE_IFELSE(
         [AC_LANG_PROGRAM(
            [[#include <sys/types.h>
              #ifdef HAVE_SYS_SOCKET_H
              #include <sys/socket.h>
              #endif
              #ifdef _WIN32
                #include <winsock2.h>
                #include <ws2tcpip.h>
              #else
                #include <netdb.h>
              #endif
              #include <unistd.h>
              extern
              #ifdef __cplusplus
              "C"
              #endif
              int getdomainname (char *, int);
            ]],
            [[]])],
         [gl_cv_decl_getdomainname_argtype2='int'],
         [gl_cv_decl_getdomainname_argtype2='size_t'])
     else
       gl_cv_decl_getdomainname_argtype2='int'
     fi
    ])

  if test $ac_cv_have_decl_getdomainname = no; then
    HAVE_DECL_GETDOMAINNAME=0
  fi

  if { test $ac_cv_func_getdomainname = yes \
       && test $gl_cv_decl_getdomainname_argtype2 != size_t; \
     } \
     || case "$gl_cv_onwards_func_getdomainname" in \
          future*) true ;; \
          *) false ;; \
        esac \
     || test "$gl_cv_func_getdomainname_in_libnsl" = yes; then
    REPLACE_GETDOMAINNAME=1
  fi
])

# Prerequisites of lib/getdomainname.c.
AC_DEFUN([gl_PREREQ_GETDOMAINNAME], [
  if test $ac_cv_func_getdomainname = yes; then
    AC_DEFINE([HAVE_GETDOMAINNAME], [1],
      [Define if the getdomainname() function is present and can be used.])
  fi
  AC_CHECK_HEADERS([sys/systeminfo.h])
  AC_CHECK_FUNCS([sysinfo])
])
