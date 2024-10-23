#!/bin/bash

# 현재 작업 디렉토리
TARGET_DIR="."

# LIBOBJS를 포함한 줄을 찾아서 모든 LIBOBJS를 콤마로 연결
grep -rn --exclude-dir=백업* "\<LIBOBJS\>" "$TARGET_DIR" | while read -r line; do
    # 줄이 주석으로 시작하거나 ':#'을 포함하는지 확인
    if [[ ! "$line" =~ ^# && ! "$line" =~ :# ]]; then
        # LIBOBJS의 모든 출현을 찾아서 배열에 저장
        IFS=',' read -ra occurrences <<< "$(echo "$line" | grep -o "LIBOBJS")"
        
        # 배열을 콤마로 연결하여 출력
        if [ ${#occurrences[@]} -gt 0 ]; then
            # 찾은 LIBOBJS들을 콤마로 연결
            joined=$(IFS=','; echo "${occurrences[*]}")
            
            # 원본 줄과 찾은 LIBOBJS 출력
            echo "원본: $line"
            echo "찾은 단어: $joined"
        fi
    fi
done
