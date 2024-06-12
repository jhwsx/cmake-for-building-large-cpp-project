#401cmake_target_include/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_target_include)

#这里使用 file 来写一个文件
file(WRITE a.cpp [=[
void A() {}
]=]
)

# 静态库
add_library(A STATIC a.cpp)

target_include_directories(A PUBLIC "/A_PUBLIC")
target_include_directories(A PRIVATE "/A_PRIVATE")
target_include_directories(A INTERFACE "/A_INTERFACE")

# 可以使用 cmake --build build -v 查看 cmake 输出里面的信息

# 使用 cmake_print_properties
message(STATUS "use cmake_print_properties:")
include(CMakePrintHelpers)
cmake_print_properties(TARGETS A PROPERTIES
    INCLUDE_DIRECTORIES # 当前目标所使用的属性
    INTERFACE_INCLUDE_DIRECTORIES # 依赖当前目标所使用的属性
)

# 使用 cmake 的调试目标属性
set(CMAKE_DEBUG_TARGET_PROPERTIES INCLUDE_DIRECTORIES INTERFACE_INCLUDE_DIRECTORIES)
