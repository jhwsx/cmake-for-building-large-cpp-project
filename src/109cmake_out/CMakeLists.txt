cmake_minimum_required(VERSION 3.20)

project(xlog)

# 指定头文件查找路径
include_directories("xlog")

# 指定动态库文件输出路径(只对 linux 和 macos 有效，对 windows 无效)
# 默认路径在 -B build 目录下
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")

# 执行程序和windows的dll文件,动态库pdb文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")

# 归档输出路径，包括 windows 下的静态库 .lib 文件, 静态库的 pdb 文件和动态库的 .lib 地址文件, 动态库的 exp 文件, ;linux 和 macos 下的静态库 .a 文件
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")

# 添加动态库，项目自带预处理变量 xlog_EXPORTS
# add_library(xlog SHARED xlog/xlog.cpp)

# 添加静态库
set(BUILD_SHARED_LIBS OFF)
add_definitions(-Dxlog_STATIC)
add_library(xlog xlog/xlog.cpp)

# 添加可执行程序
add_executable(test_xlog test_xlog/test_xlog.cpp)

# 指定链接的库
target_link_libraries(test_xlog xlog)