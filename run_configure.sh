#!/bin/bash

# 로그 파일 설정
LOG_FILE="configure.log"

# ./configure 실행 및 로그 파일에 기록
./configure &> "$LOG_FILE"

# 로그 파일에서 ./configure 또는 : error로 시작하는 줄만 출력하고 중복 제거
grep -E '^./configure|^: error' "$LOG_FILE" | sort | uniq

