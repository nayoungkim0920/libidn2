# renameat.m4
# serial 5
dnl Copyright (C) 2009-2024 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

# See if we need to provide renameat replacement.

# Written by Eric Blake.

AC_DEFUN([gl_FUNC_RENAMEAT],
[
  AC_REQUIRE([gl_FUNC_OPENAT])
  AC_REQUIRE([gl_FUNC_RENAME])
  AC_REQUIRE([gl_STDIO_H_DEFAULTS])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_REQUIRE([gl_USE_SYSTEM_EXTENSIONS])
  AC_CHECK_HEADERS([linux/fs.h])
  AC_CHECK_FUNCS_ONCE([renameat])
  if test $ac_cv_func_renameat = no; then
    HAVE_RENAMEAT=0
  elif test $REPLACE_RENAME = 1; then
    dnl Solaris 9 and 10 have the same bugs in renameat as in rename.
    REPLACE_RENAMEAT=1
  fi
  gl_CHECK_FUNCS_ANDROID([renameat2], [[#include <stdio.h>]])
  if test $ac_cv_func_renameat2 = yes; then
    AC_CACHE_CHECK([whether renameat2 works],
      [gl_cv_func_renameat2_works],
      [AC_RUN_IFELSE(
         [AC_LANG_SOURCE([[
            #include <fcntl.h>
            #include <stdio.h>
            int main ()
            {
              /* This test fails on Cygwin 3.4.6.  */
              if (renameat2 (AT_FDCWD, "conftest.c", AT_FDCWD, "conftest.c",
                             RENAME_NOREPLACE) == 0)
                return 1;
              return 0;
            }
         ]])],
         [gl_cv_func_renameat2_works=yes],
         [gl_cv_func_renameat2_works=no],
         [case "$host_os" in
                     # Guess yes on Linux.
            linux*)  gl_cv_func_renameat2_works="guessing yes" ;;
                     # Guess no on Cygwin.
            cygwin*) gl_cv_func_renameat2_works="guessing no" ;;
                     # If we don't know, obey --enable-cross-guesses.
            *)       gl_cv_func_renameat2_works="$gl_cross_guess_normal" ;;
          esac
         ])
      ])
    case "$gl_cv_func_renameat2_works" in
      *yes)
        AC_DEFINE([HAVE_WORKING_RENAMEAT2], [1],
          [Define if the renameat2 function exists and it works.])
        ;;
    esac
  fi
])
