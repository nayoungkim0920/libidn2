# sys_sem_h.m4
# serial 1
dnl Copyright (C) 2023-2024 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl Written by Bruno Haible.

AC_DEFUN_ONCE([gl_SYS_SEM_H],
[
  AC_CHECK_HEADERS_ONCE([sys/sem.h])
  dnl For now, we provide a <sys/sem.h> wrapper only if the system already has
  dnl a <sys/sem.h>.
  if test $ac_cv_header_sys_sem_h = yes; then
    GL_GENERATE_SYS_SEM_H=true
    gl_CHECK_NEXT_HEADERS([sys/sem.h])
  else
    GL_GENERATE_SYS_SEM_H=false
  fi
])