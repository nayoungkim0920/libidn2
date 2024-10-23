# Root 디렉토리의 Makefile.am
# 이 파일은 프로젝트의 최상위 디렉토리에서 Makefile을 설정합니다.

# Include subdirectories Makefile.am
SUBDIRS = gl gnulib lib m4 po src tests tmpwrk2270 unistring build-aux contrib doc examples fuzz gettext-0.19.8 gettext-0.19.8/os2

# Specify the directory for pkg-config files
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libidn2.pc

#m4 디렉토리는 AC_CONFIG_MACRO_DIRS에서 이미 포함되므로, 중복된 경로를 제거
#ACLOCAL_AMFLAGS = -I /usr/share/aclocal -I /c/libidn2/m4 
#export ACLOCAL_PATH="export ACLOCAL_PATH="/usr/share/aclocal:/c/libidn2/m4":$ACLOCAL_PATH"
##ACLOCAL_AMFLAGS = -I /mingw64/share/aclocal -I /usr/share/aclocal  -I m4 
# -I m4를 제거 configure.ac파일의  AC_CONFIG_MACRO_DIRS([m4]) #여기에서 찾음

# Automake options
AM_GNU_GETTEXT([external])

# Add warnings 추가 Makefile.am파일에서 설정하는게 일반적
#AM_CFLAGS = -Werror #m4/custom-macros.m4:44: warning: macro 'AM_CFLAGS' not found in library

# 추가
gtkdocdir = $(datadir)/gtk-doc/html #/c/libidn2/gtk-doc/html
gtkdoc_DATA = $(DOCS)
datadir = $(prefix)/share
