#!/bin/bash

# 찾은 파일 목록
files=(
  ./lib/accept4.c
  ./lib/dup2.c
  ./lib/error.c
  ./lib/execute.c
  ./lib/fcntl.c
  ./lib/flock.c
  ./lib/fstat.c
  ./lib/ftruncate.c
  ./lib/ioctl.c
  ./lib/isapipe.c
  ./lib/isatty.c
  ./lib/lseek.c
  ./lib/msvc-nothrow.c
  ./lib/nonblocking.c
  ./lib/poll.c
  ./lib/read.c
  ./lib/select.c
  ./lib/spawn-pipe.c
  ./lib/stdio-read.c
  ./lib/stdio-write.c
  ./lib/term-ostream.c
  ./lib/utimens.c
  ./lib/w32sock.h
  ./lib/windows-spawn.c
  ./lib/write.c
)

# 각각의 파일을 검사하고 없을 경우 최상단에 #include <io.h> 추가
for file in "${files[@]}"
do
  if grep -q '<io.h>' "$file"; then
    echo "'<io.h>' exists in $file."
  else
    echo "'<io.h>' does NOT exist in $file. Adding it..."
    # 파일의 최상단에 #include <io.h> 추가
    sed -i '1i#include <io.h>' "$file"
  fi
done

echo "Check and update complete."
