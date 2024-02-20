cmake_minimum_required(VERSION 3.20)

# 构建项目的名称
project(xlog)

# 添加一个静态库
add_library(xlog STATIC xlog.cpp xlog.h)