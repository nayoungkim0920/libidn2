# 필요한 헤더 파일 리스트 (CFLAGS와 관련된 include 경로에서 확인)
HEADER_FILES=("stdio.h" "stdlib.h" "string.h" "unistd.h")

# CFLAGS 경로에서 헤더 파일 확인
for dir in /c/msys64/mingw64/include /mingw64/include /c/libidn2/gettext-0.22.5/libtextstyle/lib; do
  echo "Checking directory: $dir"
  for header in "${HEADER_FILES[@]}"; do
    if [ -f "$dir/$header" ]; then
      echo "  Found: $header"
    else
      echo "  Not found: $header"
    fi
  done
done

# 필요한 라이브러리 파일 리스트 (LDFLAGS와 관련된 lib 경로에서 확인)
LIBRARY_FILES=("libc.a" "libm.a" "libgcc.a" "libpthread.a")

# LDFLAGS 경로에서 라이브러리 파일 확인
for dir in /mingw64/lib /usr/lib /mingw64/bin; do
  echo "Checking directory: $dir"
  for lib in "${LIBRARY_FILES[@]}"; do
    if [ -f "$dir/$lib" ]; then
      echo "  Found: $lib"
    else
      echo "  Not found: $lib"
    fi
  done
done
