#405cmake_debug_release/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_debug_release)

#[[
Debug           -g
Release         -O3
RelWithDebInfo  -O2 -g
MinSizeRel      -Os

控制构建类型的方法
1. CMAKE_BUILD_TYPE 适用于 Linux，Mac，nmake, 不适用于 VS 项目
    Linux 下该变量默认为空，既不是 Debug 也不是 Release. 
    如何指定？
        set(CMAKE_BUILD_TYPE Debug)
        cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug                -g
        cmake -B build -S . -DCMAKE_BUILD_TYPE=Release              -O3 -DNDEBUG
        cmake -B build -S . -DCMAKE_BUILD_TYPE=RelWithDebInfo       -O2 -g -DNDEBUG
        cmake -B build -S . -DCMAKE_BUILD_TYPE=MinSizeRel           -Os -DNDEBUG
2. 在 VS 中，会自动生成 4 种构建类型，无法在生成阶段控制构建类型
    cmake --build build -v --config Release

3. 用 nmake
cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug -G "NMake Makefiles"
]]
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
add_library(slib STATIC src/slib.cpp)


# 归档输出路径，包括 windows 下的静态库 .lib 文件, 静态库的 pdb 文件和动态库的 .lib 地址文件, 动态库的 exp 文件, ;linux 和 macos 下的静态库 .a 文件
set(OUT_LIB_PATH ${CMAKE_SOURCE_DIR}/lib)
set(OUT_BIN_PATH ${CMAKE_SOURCE_DIR}/bin)
set(OUT_PDB_PATH ${CMAKE_SOURCE_DIR}/pdb)
set_target_properties(slib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${OUT_LIB_PATH}
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/debug
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUT_LIB_PATH}/release
    PDB_OUTPUT_DIRECTORY ${OUT_PDB_PATH}
    PDB_OUTPUT_DIRECTORY_DEBUG ${OUT_PDB_PATH}
)

# 动态库
add_library(dlib SHARED src/dlib.cpp include/dlib.h)
target_include_directories(dlib PUBLIC include)
# 指定动态库文件输出路径(只对 linux 和 macos 有效，对 windows 无效)
set_target_properties(dlib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUT_LIB_PATH}
    LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/debug
    LIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUT_LIB_PATH}/release
)
# 执行程序和windows的dll文件,动态库pdb文件输出路径
set_target_properties(dlib PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${OUT_BIN_PATH}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUT_BIN_PATH}/debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUT_BIN_PATH}/release
    DEBUG_POSTFIX "d"
    PDB_OUTPUT_DIRECTORY ${OUT_PDB_PATH}
    PDB_OUTPUT_DIRECTORY_DEBUG ${OUT_PDB_PATH}
)

# 执行程序
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE dlib slib)
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${OUT_BIN_PATH}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUT_BIN_PATH}/debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUT_BIN_PATH}/release
    PDB_OUTPUT_DIRECTORY ${OUT_PDB_PATH}
    PDB_OUTPUT_DIRECTORY_DEBUG ${OUT_PDB_PATH}
    DEBUG_POSTFIX "d"
)
