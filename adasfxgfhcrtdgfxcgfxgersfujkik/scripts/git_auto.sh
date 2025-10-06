#!/bin/bash
echo -e "Commit Message: \c"
read commit_message
echo "Current branch:"
git branch
echo ""
git add .    #將所有~/catkin_ws裡面的東西存在.git/index暫存區，不用去了解git add
git commit -m "$commit_message"    #從Staging area 加到本地倉庫，不用去了解git commit
#使時git add和git commit一起使用
git push   #只推送當前的分支到遠端倉庫
#在某目錄下執行此腳本等同於在該目錄下執行git add、git commit、git push等

