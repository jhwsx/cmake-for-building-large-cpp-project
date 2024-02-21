cmake_minimum_required(VERSION 3.20)

project(xlog)

# 指定头文件查找路径
include_directories("xlog")

# 添加动态库
add_library(xlog SHARED xlog/xlog.cpp)

# 添加可执行程序
add_executable(test_xlog test_xlog/test_xlog.cpp)

# 指定链接的库
target_link_libraries(test_xlog xlog)