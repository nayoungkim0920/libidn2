#!/bin/bash
# git update 하기
# c:\libidn2 폴더 > 우측마우스버튼 > 추가옵션표시 > open Git Bash Here

# Git 사용자 정보 설정 확인 및 필요 시 설정
if [ -z "$(git config --global user.name)" ]; then
    git config --global user.name "nayoungkim"
fi

if [ -z "$(git config --global user.email)" ]; then
    git config --global user.email "nayoungkim0920@gmail.comx"
fi

# Git 작업 파일 추가 및 커밋 메시지에 현재 날짜 설정
git add .
git commit -m "commit $(date +'%Y%m%d')"  # 오늘 날짜를 'YYYYMMDD' 형식으로 추가
git push origin master # 강제 업로드 시 --force
