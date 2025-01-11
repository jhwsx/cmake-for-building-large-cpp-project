#404cmake_version/CMakeLists.txt
# 只在 Linux 中演示
cmake_minimum_required(VERSION 3.22)
project(cmake_version)

# 带版本号的库
option(NO_SONAME_OPTION "no soname" OFF)
#[[
lrwxrwxrwx 1 wangzhichao wangzhichao    10 1月  10 23:39 liba.so -> liba.so.12
-rwxrwxr-x 1 wangzhichao wangzhichao 16576 1月  10 23:39 liba.so.1.0.1
lrwxrwxrwx 1 wangzhichao wangzhichao    13 1月  10 23:39 liba.so.12 -> liba.so.1.0.1
]]
add_library(a SHARED a.cpp)

# VERSION 大版本
# SOVERSION so 版本
# NO_SONAME 控制是否生成符号连接
set_target_properties(a PROPERTIES VERSION "1.0.1" SOVERSION "12" NO_SONAME ${NO_SONAME_OPTION})

# 带版本号的程序
add_executable(main main.cpp)
target_link_libraries(main PRIVATE a)
# lrwxrwxrwx 1 wangzhichao wangzhichao    10 1月  11 10:44 main -> main-2.0.1
# -rwxrwxr-x 1 wangzhichao wangzhichao 16976 1月  11 10:44 main-2.0.1
set_target_properties(main PROPERTIES VERSION "2.0.1")
