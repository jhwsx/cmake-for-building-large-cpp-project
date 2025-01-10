#401cmake_target_include/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_target_include)

# 静态库
add_library(A STATIC a.cpp)

#[[
target_include_directories(<target> [SYSTEM] [AFTER|BEFORE]
   <INTERFACE|PUBLIC|PRIVATE> [items1...]
   [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
指定目标要使用的包含目录
target 必须是由命令创建的，不能是 alias target
SYSTEM 告诉编译器这里的路径可能是系统路径，解决一些平台的警告信息
AFTER|BEFORE 指定这里包含的路径放在已有路径列表的后面还是前面
INTERFACE|PUBLIC|PRIVATE 控制参数流转
    PRIVATE 只有目标自己用
    PUBLIC 依赖目标者和目标自己都用
    INTERFACE 只有依赖目标者用
]]
# PUBLIC 改变 INCLUDE_DIRECTORIES INTERFACE_INCLUDE_DIRECTORIES
target_include_directories(A PUBLIC "/A_PUBLIC")
# PRIVATE 改变 INCLUDE_DIRECTORIES
target_include_directories(A PRIVATE "/A_PRIVATE")
# INTERFACE 改变 INTERFACE_INCLUDE_DIRECTORIES
target_include_directories(A INTERFACE "/A_INTERFACE")

# 分别用 PRIVATE PUBLIC INTERFACE，查看程序输出
target_compile_definitions(A INTERFACE VAR_A=1)

# 调试属性方法
# 1.可以使用 cmake --build build -v 查看 cmake 输出里面的信息

# 2.使用 cmake_print_properties
# message(STATUS "use cmake_print_properties:")
# include(CMakePrintHelpers)
# cmake_print_properties(TARGETS A PROPERTIES
#     INCLUDE_DIRECTORIES # 当前目标所使用的属性
#     INTERFACE_INCLUDE_DIRECTORIES # 依赖当前目标所使用的属性
# )

# 3.使用 cmake 的调试目标属性(cmake 原生调试方式)
# set(CMAKE_DEBUG_TARGET_PROPERTIES INCLUDE_DIRECTORIES INTERFACE_INCLUDE_DIRECTORIES)

# 静态库 B, 依赖静态库 A
add_library(B STATIC b.cpp)
target_link_libraries(B PUBLIC A)
target_include_directories(B PUBLIC "/B_PUBLIC")

# 这种方式不能打印继承的属性
# include(CMakePrintHelpers)
# cmake_print_properties(TARGETS B PROPERTIES
#     INCLUDE_DIRECTORIES # 当前目标所使用的属性
#     INTERFACE_INCLUDE_DIRECTORIES # 依赖当前目标所使用的属性
# )

# 使用 cmake 的调试目标属性, 可以看到 B 继承的属性
set(CMAKE_DEBUG_TARGET_PROPERTIES INCLUDE_DIRECTORIES INTERFACE_INCLUDE_DIRECTORIES)

# main -> B -> A
add_executable(main main.cpp)
target_link_libraries(main PUBLIC B)
