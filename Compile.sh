#!/bin/bash
# usage:
#       ./Compile.sh Main.cpp
#       ./Compile.sh Main.cc
#       ./Compile.sh Main.c

if [ $# -eq 1 ];
then
    # 拆分文件名和拓展名
    basename="$1"
    filename="${basename%%.*}"
    extensionName="${basename#*.}"
    outputFilepath="./Debug/$filename.exe"

    # 删除已有可执行程序
    if [ -f $outputFilepath ];
    then
        rm $outputFilepath
    fi

    # 针对不同的源文件进行编译
    case $extensionName in
        "c")
            gcc $1 -o $outputFilepath -g -fexec-charset=gbk -Wall
        ;;
        "cpp" | "cc")
            g++ $1 -o $outputFilepath -g -fexec-charset=gbk -Wall
        ;;
        *)
            echo "Unknown input file!"
        ;;
    esac
# 未输入待编译文件，直接退出
else
    echo "Please input the file you want to compile!"
fi
