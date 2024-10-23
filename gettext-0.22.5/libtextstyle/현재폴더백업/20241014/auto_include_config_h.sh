#!/bin/bash

# 현재 디렉토리와 하위 디렉토리에서 .c 및 .h 파일 찾기
find . -name '*.c' -o -name '*.h' | while read -r file; do
  # 파일의 첫 번째 줄에 #include "config.h"가 포함되어 있는지 확인
  if grep -q '#include "config.h"' "$file"; then
    echo "$file에는 이미 #include \"config.h\"가 포함되어 있습니다."
  else
    echo "$file에 #include \"config.h\"를 추가합니다."
    # 임시 파일을 생성하여 #include "config.h"를 추가
    temp_file=$(mktemp)
    echo '#include "config.h"' > "$temp_file"
    cat "$file" >> "$temp_file"
    mv "$temp_file" "$file"
  fi
done
