#!/bin/bash

# 매크로 이름 정의
macro="gl_MODULE_INDICATOR_FOR_TESTS"

# 매크로 정의 상태 확인
define_status=$(grep -i "AC_DEFUN(\[$macro\]" macro_definitions.txt)

# 매크로 호출 상태 확인
call_status=$(grep -i "$macro" macro_calls.txt | grep -v "AC_DEFUN")

# 결과 출력
echo "[macro]"
echo "$macro"
echo
echo "[define]"
if [ -n "$define_status" ]; then
    echo "$define_status"
else
    echo "N/A"
fi
echo
echo "[call]"
if [ -n "$call_status" ]; then
    echo "$call_status"
else
    echo "N/A"
fi
