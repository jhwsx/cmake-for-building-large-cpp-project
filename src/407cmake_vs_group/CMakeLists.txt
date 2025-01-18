#407cmake_vs_group/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(cmake_vs_group)
#[[
https://cmake.org/cmake/help/latest/command/source_group.html

source_group(<name> [FILES <src>...] [REGULAR_EXPRESSION <regex>])
source_group(TREE <root> [PREFIX <prefix>] [FILES <src>...])
]]

add_executable(main main.cpp a.cpp b.cpp a.h b.h)

# a.cpp b.cpp 在 vs 中显示在 src 目录中
source_group(src FILES a.cpp b.cpp)
# b.h 在 vs 中显示在 include 目录中
source_group(include FILES b.h)
# root 后面的 src 路径会去掉 root 的内容，显示剩下的路径
source_group(TREE . PREFIX include/inc FILES a.h)
