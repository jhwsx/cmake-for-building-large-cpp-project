#403target_object/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_object)

# a.cpp b.cpp => a.cpp.o b.cpp.o
# a.cpp.o b.cpp.o => libtesta.so
# main.cpp libtesta.so => main

# 添加 object 对象 testa_obj, 会生成 a.cpp.o b.cpp.o 
add_library(testa_obj OBJECT a.cpp b.cpp)
# 方法1：
# MSVC 忽略未知选项“-fPIC”
# if (NOT MSVC)
#     target_compile_options(testa_obj PRIVATE "-fPIC")
# endif()

# 方法2：
set_target_properties(testa_obj PROPERTIES POSITION_INDEPENDENT_CODE ON)

# 错误的写法
# add_library(testa SHARED testa_obj)
# 用生成器表达式来获取 object 对象
# relocation R_X86_64_PC32 against symbol `_ZSt4cout@@GLIBCXX_3.4' can not be used when making a shared object; recompile with -fPIC
add_library(testa SHARED $<TARGET_OBJECTS:testa_obj>) # add_library 会加 -fPIC

add_executable(main main.cpp)
target_link_libraries(main PRIVATE testa)
