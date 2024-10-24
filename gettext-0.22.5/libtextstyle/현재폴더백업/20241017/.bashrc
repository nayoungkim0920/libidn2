# To the extent possible under la
# copyright and related and neighboring rights to this software to the 
# public domain worldwide. This software is distributed without any warranty. w, the author(s) have dedicated all 
# You should have received a copy of the CC0 Public Domain Dedication along 
# with this software. 
# If not, see <https://creativecommons.org/publicdomain/zero/1.0/>. 

# ~/.bashrc: executed by bash(1) for interactive shells.

# The copy in your home directory (~/.bashrc) is yours, please
# feel free to customise it to create a shell
# environment to your liking.  If you feel a change
# would be benifitial to all, please feel free to send
# a patch to the msys2 mailing list.

# User dependent .bashrc file

# If not running interactively, don't do anything
[[ "$-" != *i* ]] && return

# Shell Options
#
# See man bash for more options...
#
# Don't wait for job termination notification
# set -o notify
#
# Don't use ^D to exit
# set -o ignoreeof
#
# Use case-insensitive filename globbing
# shopt -s nocaseglob
#
# Make bash append rather than overwrite the history on disk
# shopt -s histappend
#
# When changing directory small typos can be ignored by bash
# for example, cd /vr/lgo/apaache would find /var/log/apache
# shopt -s cdspell

# Completion options
#
# These completion tuning parameters change the default behavior of bash_completion:
#
# Define to access remotely checked-out files over passwordless ssh for CVS
# COMP_CVS_REMOTE=1
#
# Define to avoid stripping description in --option=description of './configure --help'
# COMP_CONFIGURE_HINTS=1
#
# Define to avoid flattening internal contents of tar files
# COMP_TAR_INTERNAL_PATHS=1
#
# Uncomment to turn on programmable completion enhancements.
# Any completions you add in ~/.bash_completion are sourced last.
# [[ -f /etc/bash_completion ]] && . /etc/bash_completion

# History Options
#
# Don't put duplicate lines in the history.
# export HISTCONTROL=$HISTCONTROL${HISTCONTROL+,}ignoredups
#
# Ignore some controlling instructions
# HISTIGNORE is a colon-delimited list of patterns which should be excluded.
# The '&' is a special pattern which suppresses duplicate entries.
# export HISTIGNORE=$'[ \t]*:&:[fb]g:exit'
# export HISTIGNORE=$'[ \t]*:&:[fb]g:exit:ls' # Ignore the ls command as well
#
# Whenever displaying the prompt, write the previous line to disk
# export PROMPT_COMMAND="history -a"

# Aliases
#
# Some people use a different file for aliases
# if [ -f "${HOME}/.bash_aliases" ]; then
#   source "${HOME}/.bash_aliases"
# fi
#
# Some example alias instructions
# If these are enabled they will be used instead of any instructions
# they may mask.  For example, alias rm='rm -i' will mask the rm
# application.  To override the alias instruction use a \ before, ie
# \rm will call the real rm not the alias.
#
# Interactive operation...
# alias rm='rm -i'
# alias cp='cp -i'
# alias mv='mv -i'
#
# Default to human readable figures
# alias df='df -h'
# alias du='du -h'
#
# Misc :)
# alias less='less -r'                          # raw control characters
# alias whence='type -a'                        # where, of a sort
# alias grep='grep --color'                     # show differences in colour
# alias egrep='egrep --color=auto'              # show differences in colour
# alias fgrep='fgrep --color=auto'              # show differences in colour
#
# Some shortcuts for different directory listings
# alias ls='ls -hF --color=tty'                 # classify files in colour
# alias dir='ls --color=auto --format=vertical'
# alias vdir='ls --color=auto --format=long'
# alias ll='ls -l'                              # long list
# alias la='ls -A'                              # all but . and ..
# alias l='ls -CF'                              #

# Umask
#
# /etc/profile sets 022, removing write perms to group + others.
# Set a more restrictive umask: i.e. no exec perms for others:
# umask 027
# Paranoid: neither group nor others have any perms:
# umask 077

# Functions
#
# Some people use a different file for functions
# if [ -f "${HOME}/.bash_functions" ]; then
#   source "${HOME}/.bash_functions"
# fi
#
# Some example functions:
#
# a) function settitle
# settitle () 
# { 
#   echo -ne "\e]2;$@\a\e]1;$@\a"; 
# }
# 
# b) function cd_func
# This function defines a 'cd' replacement function capable of keeping, 
# displaying and accessing history of visited directories, up to 10 entries.
# To use it, uncomment it, source this file and try 'cd --'.
# acd_func 1.0.5, 10-nov-2004
# Petar Marinov, http:/geocities.com/h2428, this is public domain
# cd_func ()
# {
#   local x2 the_new_dir adir index
#   local -i cnt
# 
#   if [[ $1 ==  "--" ]]; then
#     dirs -v
#     return 0
#   fi
# 
#   the_new_dir=$1
#   [[ -z $1 ]] && the_new_dir=$HOME
# 
#   if [[ ${the_new_dir:0:1} == '-' ]]; then
#     #
#     # Extract dir N from dirs
#     index=${the_new_dir:1}
#     [[ -z $index ]] && index=1
#     adir=$(dirs +$index)
#     [[ -z $adir ]] && return 1
#     the_new_dir=$adir
#   fi
# 
#   #
#   # '~' has to be substituted by ${HOME}
#   [[ ${the_new_dir:0:1} == '~' ]] && the_new_dir="${HOME}${the_new_dir:1}"
# 
#   #
#   # Now change to the new dir and add to the top of the stack
#   pushd "${the_new_dir}" > /dev/null
#   [[ $? -ne 0 ]] && return 1
#   the_new_dir=$(pwd)
# 
#   #
#   # Trim down everything beyond 11th entry
#   popd -n +11 2>/dev/null 1>/dev/null
# 
#   #
#   # Remove any other occurence of this dir, skipping the top of the stack
#   for ((cnt=1; cnt <= 10; cnt++)); do
#     x2=$(dirs +${cnt} 2>/dev/null)
#     [[ $? -ne 0 ]] && return 0
#     [[ ${x2:0:1} == '~' ]] && x2="${HOME}${x2:1}"
#     if [[ "${x2}" == "${the_new_dir}" ]]; then
#       popd -n +$cnt 2>/dev/null 1>/dev/null
#       cnt=cnt-1
#     fi
#   done
# 
#   return 0
# }
# 
# alias cd=cd_func

# 시스템 언어 설정
export LANG=ko_KR.UTF-8                     # 한국어 설정
export LC_ALL=ko_KR.UTF-8                    # 모든 로케일 설정을 한국어로

# C 컴파일러 설정
export CC=x86_64-w64-mingw32-gcc             # C 컴파일러
export CXX=x86_64-w64-mingw32-g++            # C++ 컴파일러
export CPP=/mingw64/bin/cpp                   # C++ 전처리기

# CFLAGS 초기화
export CFLAGS=""                              # CFLAGS 초기화
export CFLAGS="-I/c/msys64/mingw64/include"  # MSYS2 MinGW 64-bit 기본 include 디렉토리
export CFLAGS="$CFLAGS -I/mingw64/include"   # MinGW 기본 include 디렉토리
export CFLAGS="$CFLAGS -I/c/libidn2/gettext-0.22.5/libtextstyle/lib"  # libidn2의 gettext 라이브러리 헤더 파일 디렉토리
export CFLAGS="$CFLAGS -O2"                   # 최적화 레벨 2 설정

# CPPFLAGS 초기화
export CPPFLAGS=""                            # CPPFLAGS 초기화
export CPPFLAGS="-I/c/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/14.2.0/include/c++" 
export CPPFLAGS="$CPPFLAGS -O2"               # 최적화 레벨 2 설정

# CXXFLAGS 초기화
export CXXFLAGS=""                            # CXXFLAGS 초기화
export CXXFLAGS="-I/c/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/14.2.0/include/c++"
export CXXFLAGS="$CXXFLAGS -O2"               # 최적화 레벨 2 설정
export CXXFLAGS="$CXXFLAGS -DDEBUG"           # 디버그 모드 활성화
export CXXFLAGS="$CXXFLAGS -DVERSION=\"1.0.0\""  # 버전 정의

# 링커 및 아카이버 설정
export LD=/mingw64/bin/ld.exe                 # 링커
export AR=/mingw64/bin/ar.exe                 # 아카이버
export CXXDEPMODE=depmode=gcc                 # C++ 의존성 모드 설정
export PKG_CONFIG=/mingw64/bin/pkg-config     # pkg-config 경로 설정

# pkg-config 경로 설정
export PKG_CONFIG_PATH="/c/Program Files/GLib/lib/pkgconfig:/c/libidn2/gettext-0.22.5/gettext-runtime/intl:/mingw64/lib/pkgconfig:/usr/lib/pkgconfig" # pkg-config 검색 경로

# 기타 도구 경로 설정
export SED=/usr/bin/sed                       # sed 경로
export GREP=/usr/bin/grep                     # grep 경로
export FGREP=/usr/bin/fgrep                   # fgrep 경로
export EGREP=/usr/bin/egrep                   # egrep 경로

# 라이브러리 경로 설정
export LD_LIBRARY_PATH="/mingw64/lib:/usr/lib:/c/gnulib/lib" # 라이브러리 검색 경로
export LDFLAGS="-L/c/gnulib/lib -L/c/libidn2/gettext-0.22.5/libtextstyle/lib -L/mingw64/lib -L/usr/lib -Wl,-rpath,/mingw64/bin" # 링커 플래그
export LIBRARY_PATH="/c/gnulib/lib:/mingw64/lib" # 라이브러리 경로 설정

# gettext 및 libiconv 설정
export GETTEXT_PACKAGE=libidn2               # gettext 패키지 이름
export LIBICONV_DIR=/mingw64                  # libiconv 디렉토리 설정

# C++ 및 C 인클루드 경로 설정
export CXX_INCLUDE_PATH="/c/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/14.2.0/include/c++"  # C++ 인클루드 경로
export C_INCLUDE_PATH="/c/msys64/mingw64/include:/mingw64/include:/c/libidn2/gettext-0.22.5/libtextstyle/lib" # C 인클루드 경로
export CPLUS_INCLUDE_PATH="/c/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/14.2.0/include/c++" # C++ 인클루드 경로

# Ant 관련 설정
export ANT_HOME="/c/apache-ant-1.10.15"      # Ant 홈 디렉토리
export PATH="$ANT_HOME/bin:$PATH"             # Ant 바이너리 경로 추가

# Java 관련 설정
export JAVA_HOME="/c/Program Files/Java/jdk-21"  # Java 홈 디렉토리
export PATH="$JAVA_HOME/bin:$PATH"                # Java 바이너리 경로 추가

# Gnulib 경로 설정
export PATH="$PATH:/c/gnulib"                     # Gnulib 경로 추가
export GL_GNU_SOURCE=1                             # Gnulib 소스 버전 설정
export GL_REQUIRE_VERSION=2.0                      # Gnulib 요구 버전 설정

# M4 설정
export M4=/usr/bin/m4                              # M4 경로 설정

# ACLOCAL_PATH 설정
export ACLOCAL_PATH="/c/gnulib/lib:/c/libidn2/gettext-0.22.5/libtextstyle/lib/ltdl:/c/libidn2/gettext-0.22.5/libtextstyle/lib/ltdl/m4:/c/msys64/usr/share/aclocal:/usr/share/aclocal:/mingw64/share/aclocal:/c/libidn2/m4" # aclocal 검색 경로

# AUTOCONF_PATH 설정
export AUTOCONF_PATH="/c/libidn2/m4:/usr/share/aclocal:/mingw64/share/aclocal" # autoconf 검색 경로

# PATH 
export PATH="$PATH:/c/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/14.2.0/include/c++"
export PATH="$PATH:/c/msys64/mingw64/include:/mingw64/include:/c/libidn2/gettext-0.22.5/libtextstyle/lib"
export PATH="$PATH:/mingw64/bin" # MinGW-w64의 바이너리 디렉토리 추가
export PATH="$PATH:/c/msys64/mingw64/include"  # MinGW의 include 디렉토리 추가
export PATH="$PATH:/c/gnulib"  # Gnulib 디렉토리 추가
export PATH="$PATH:/c/msys64/mingw64/bin"  # 64비트 MinGW 도구의 바이너리 디렉토리 추가
export PATH="$PATH:/c/msys64/mingw32/bin"  # 32비트 MinGW 도구의 바이너리 디렉토리 추가 (필요한 경우)
export PATH="$PATH:/usr/bin"  # 시스템 기본 UNIX 도구 디렉토리 추가
export PATH="$PATH:/bin"  # 기본 UNIX 유틸리티 디렉토리 추가
export PATH="$PATH:/usr/share/aclocal"  # aclocal 매크로를 위한 디렉토리 추가
export PATH="$PATH:/mingw64/share/aclocal"  # MinGW 전용 aclocal 매크로 디렉토리 추가
export PATH="$PATH:/c/libidn2/autoconf-2.72/bin"  # libidn2용 Autoconf 바이너리 디렉토리 추가
export PATH="$PATH:/c/libidn2/libtool-2.4.6"  # libidn2용 Libtool 바이너리 디렉토리 추가
export PATH="$PATH:/c/Program Files/Java/jdk-21/bin"  # Java JDK 바이너리 디렉토리 추가
export PATH="$PATH:/c/Windows/System32"  # Windows System32 디렉토리 추가
export PATH="$PATH:/c/Windows"  # Windows 디렉토리 추가
export PATH="$PATH:/c/Windows/System32/Wbem"  # Windows WMI 디렉토리 추가
export PATH="$PATH:/c/Windows/System32/WindowsPowerShell/v1.0"  # Windows PowerShell 디렉토리 추가
export PATH="$PATH:/usr/bin/site_perl"  # Perl 사이트 디렉토리 추가
export PATH="$PATH:/usr/bin/vendor_perl"  # Perl 공급자 디렉토리 추가
export PATH="$PATH:/usr/bin/core_perl"  # Perl 기본 디렉토리 추가
export PATH="$PATH:/c/Users/nayou/AppData/Local/Programs/Python/Python312"  # Python 디렉토리 추가
export PATH="$PATH:/c/msys64/bin"  # MSYS2 바이너리 디렉토리 추가
export PATH="$PATH:/c/gnulib/lib"  # Gnulib 라이브러리 디렉토리 추가
export PATH="$PATH:/c/libidn2/gettext-0.22.5/libtextstyle/lib"  # libtextstyle을 위한 gettext 라이브러리 디렉토리 추가

# 기존 환경 변수 설정 ...

# C 컴파일러가 작동하지 않는 경우
if ! command -v $CC &> /dev/null; then
    echo "C 컴파일러가 설치되어 있지 않습니다."
    exit 1
fi

$CC --version || {
    echo "C 컴파일러 버전을 확인할 수 없습니다."
    exit 1
}

# C++ 컴파일러가 작동하지 않는 경우
if ! command -v $CXX &> /dev/null; then
    echo "C++ 컴파일러가 설치되어 있지 않습니다."
    exit 1
fi

$CXX --version || {
    echo "C++ 컴파일러 버전을 확인할 수 없습니다."
    exit 1
}

