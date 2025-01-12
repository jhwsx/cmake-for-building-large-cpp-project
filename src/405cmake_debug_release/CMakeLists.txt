#405cmake_debug_release/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_debug_release)

#[[
Debug           -g
Release         -O3
RelWithDebInfo  -O2 -g
MinSizeRel      -Os

控制构建类型的方法
1. CMAKE_BUILD_TYPE 适用于 Linux，Mac，不适用于 VS 项目
    Linux 下该变量默认为空，既不是 Debug 也不是 Release. 
    如何指定？
        set(CMAKE_BUILD_TYPE Debug)
        cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug                -g
        cmake -B build -S . -DCMAKE_BUILD_TYPE=Release              -O3 -DNDEBUG
        cmake -B build -S . -DCMAKE_BUILD_TYPE=RelWithDebInfo       -O2 -g -DNDEBUG
        cmake -B build -S . -DCMAKE_BUILD_TYPE=MinSizeRel           -Os -DNDEBUG
]]
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
add_library(slib STATIC src/slib.cpp)
