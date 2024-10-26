#!/bin/sh

# Test in the POSIX locale.
LC_ALL=C     ${CHECKER} ./test-wcrtomb${EXEEXT} 1 || exit 1
LC_ALL=POSIX ${CHECKER} ./test-wcrtomb${EXEEXT} 1 || exit 1

# Test in an ISO-8859-1 or ISO-8859-15 locale.
: "${LOCALE_FR=fr_FR}"
if test $LOCALE_FR != none; then
  LC_ALL=$LOCALE_FR \
  ${CHECKER} ./test-wcrtomb${EXEEXT} 2 \
  || exit 1
fi

# Test whether a specific UTF-8 locale is installed.
: "${LOCALE_EN_UTF8=en_US.UTF-8}"
: "${LOCALE_FR_UTF8=fr_FR.UTF-8}"
if test "$LOCALE_EN_UTF8" != none || test $LOCALE_FR_UTF8 != none; then
  # It's sufficient to test in one of the two locales.
  if test $LOCALE_FR_UTF8 != none; then
    testlocale=$LOCALE_FR_UTF8
  else
    testlocale="$LOCALE_EN_UTF8"
  fi
  LC_ALL="$testlocale" \
  ${CHECKER} ./test-wcrtomb${EXEEXT} 3 \
  || exit 1
fi

# Test whether a specific EUC-JP locale is installed.
: "${LOCALE_JA=ja_JP}"
if test $LOCALE_JA != none; then
  LC_ALL=$LOCALE_JA \
  ${CHECKER} ./test-wcrtomb${EXEEXT} 4 \
  || exit 1
fi

# Test whether a specific GB18030 locale is installed.
: "${LOCALE_ZH_CN=zh_CN.GB18030}"
if test $LOCALE_ZH_CN != none; then
  LC_ALL=$LOCALE_ZH_CN \
  ${CHECKER} ./test-wcrtomb${EXEEXT} 5 \
  || exit 1
fi

exit 0