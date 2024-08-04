#401cmake_target_include/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_target_include)

#这里使用 file 来写一个文件
file(WRITE a.cpp [=[
#include <iostream>
void A() 
{
    std::cout << "in A A_VAR=" << A_VAR << '\n';
}
]=]
)

# 静态库
add_library(A STATIC a.cpp)

# PUBLIC 改变 INCLUDE_DIRECTORIES INTERFACE_INCLUDE_DIRECTORIES
target_include_directories(A PUBLIC "/A_PUBLIC")
# PRIVATE 改变 INCLUDE_DIRECTORIES
target_include_directories(A PRIVATE "/A_PRIVATE")
# INTERFACE 改变 INTERFACE_INCLUDE_DIRECTORIES
target_include_directories(A INTERFACE "/A_INTERFACE")

# 设定 A 库的宏
#[[
target_compile_definitions(<target>
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
]]
target_compile_definitions(A PUBLIC A_VAR=1)

# 调试属性方法
# 1.可以使用 cmake --build build -v 查看 cmake 输出里面的信息

# 2.使用 cmake_print_properties
message(STATUS "use cmake_print_properties:")
include(CMakePrintHelpers)
cmake_print_properties(TARGETS A PROPERTIES
    INCLUDE_DIRECTORIES # 当前目标所使用的属性
    INTERFACE_INCLUDE_DIRECTORIES # 依赖当前目标所使用的属性
)

# 3.使用 cmake 的调试目标属性
# set(CMAKE_DEBUG_TARGET_PROPERTIES INCLUDE_DIRECTORIES INTERFACE_INCLUDE_DIRECTORIES)

file(WRITE B.cpp [=[
#include <iostream>
void A();
void B(){
    A();
    std::cout << "in B A_VAR=" << A_VAR << '\n'; 
    // std::cout << "in B STATIC=" << STATIC << '\n'; // error: ‘STATIC’ was not declared in this scope
}
]=]
)

# 静态库 B
add_library(B STATIC B.cpp)
target_link_libraries(B PUBLIC A)
target_include_directories(B PUBLIC "/B_PUBLIC")

# 设定 B 库的宏，STATIC 库标识，编译 B 库时不需要这个标识，依赖 B 库时需要这个标识
target_compile_definitions(B INTERFACE STATIC=1)

# 这种方式不能打印继承的属性
include(CMakePrintHelpers)
cmake_print_properties(TARGETS B PROPERTIES
    INCLUDE_DIRECTORIES # 当前目标所使用的属性
    INTERFACE_INCLUDE_DIRECTORIES # 依赖当前目标所使用的属性
)

# 使用 cmake 的调试目标属性, 可以看到 B 继承的属性
set(CMAKE_DEBUG_TARGET_PROPERTIES INCLUDE_DIRECTORIES INTERFACE_INCLUDE_DIRECTORIES)

file(WRITE main.cpp [=[
#include <iostream>
void B();

int main()
{
    B();
    std::cout << "in main STATIC=" << STATIC << '\n';
    return 0;
}
]=]
)

# main -> B -> A
add_executable(main main.cpp)
target_link_libraries(main PUBLIC B)
