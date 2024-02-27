cmake_minimum_required(VERSION 3.20)

project(xlog)

# 添加动态库，项目自带预处理变量 xlog_EXPORTS
add_library(${PROJECT_NAME} xlog.cpp xlog.h)
