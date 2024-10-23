# fprintf-gnu.m4
# serial 1
dnl Copyright (C) 2023-2024 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_FPRINTF_GNU],
[
  AC_REQUIRE([gl_FUNC_FPRINTF_IS_POSIX])
  AC_REQUIRE([gl_PRINTF_DIRECTIVE_UPPERCASE_B])
  gl_cv_func_fprintf_gnu=no
  if test $gl_cv_func_fprintf_posix = yes; then
    case "$gl_cv_func_printf_directive_uppercase_b" in
      *yes)
        # fprintf is already POSIX compliant and GNU compatible.
        gl_cv_func_fprintf_gnu=yes
        ;;
    esac
  fi
  if test $gl_cv_func_fprintf_gnu = no; then
    gl_PREREQ_VASNPRINTF_WITH_GNU_EXTRAS
    gl_REPLACE_VASNPRINTF
    gl_REPLACE_FPRINTF
  fi
])
