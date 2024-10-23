#!/bin/sh
# This file is in the public domain.
#
# Script for regenerating all autogenerated files.

# Usage: ./autogen.sh [--skip-gnulib]

skip_gnulib=false
while :; do
  case "$1" in
    --skip-gnulib) skip_gnulib=true; shift;;
    *) break ;;
  esac
done

if test $skip_gnulib = false; then
  if test -n "$GNULIB_SRCDIR"; then
    test -d "$GNULIB_SRCDIR" || {
      echo "*** GNULIB_SRCDIR is set but does not point to an existing directory." 1>&2
      exit 1
    }
  fi
  # Now it should contain a gnulib-tool.
  GNULIB_TOOL="$GNULIB_SRCDIR/gnulib-tool"
  test -f "$GNULIB_TOOL" || {
    echo "*** gnulib-tool not found." 1>&2
    exit 1
  }
  GNULIB_MODULES='
    unistd
    get_ppid_of
  '
  $GNULIB_TOOL --lib=libgnu --source-base=lib --m4-base=gnulib-m4 --tests-base=tests \
    --with-tests \
    --import $GNULIB_MODULES
  mkdir -p build-aux
  $GNULIB_TOOL --copy-file build-aux/ar-lib; chmod a+x build-aux/ar-lib
  $GNULIB_TOOL --copy-file build-aux/config.guess; chmod a+x build-aux/config.guess
  $GNULIB_TOOL --copy-file build-aux/config.sub;   chmod a+x build-aux/config.sub
  $GNULIB_TOOL --copy-file build-aux/run-test; chmod a+x build-aux/run-test
  $GNULIB_TOOL --copy-file build-aux/test-driver.diff
fi

aclocal -I m4 -I gnulib-m4
autoconf
autoheader && touch config.h.in
automake -a -c
patch --quiet --forward --reject-file=/dev/null build-aux/test-driver < build-aux/test-driver.diff
rm -rf autom4te.cache
