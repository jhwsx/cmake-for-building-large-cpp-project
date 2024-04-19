# 209cmake_macro/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_macro)

# 定义一个基础的宏
macro(my_macro)
    message("in my macro") 
    set(RET 1)
endmacro()

# 宏名称大小写不敏感，尽量用小写
# 调用时会将宏函数的代码复制过来
my_macro()
My_macro()
message("RET = ${RET}")

# 定义一个固定参数数目的宏演示宏参数传递: 不可以传递少于参数个数的参数
macro(foo arg1 arg2)
    message("arg1 = ${arg1} arg2 = ${arg2}")
endmacro()
# foo() # error: foo Macro invoked with incorrect arguments for macro named: foo
# foo(1) # foo Macro invoked with incorrect arguments for macro named: foo
foo(1 2)
foo(1 2 3)

# 定义一个固定参数数目的宏演示宏参数不是变量
macro(foo1 arg1 arg2)
    if(arg1)
        message("arg1 is matched")
    endif() 
    if(${arg1})
        message("\$\{arg1\} is matched")
    endif()
endmacro()
foo1(TRUE 2)

# 定义一个可变参数的宏
macro(foo2)
    # 参数数量
    message("ARGC = ${ARGC}")
    # 参数list
    message("ARGN = ${ARGN}")
    # 遍历 ARGN，因为 ARGN 不是 cmake 变量，只能取值使用
    foreach(var IN ITEMS ${ARGN})
        message("var = ${var}")
    endforeach()
    # 获取指定位置的参数
    message(ARGV0 = ${ARGV0})
    message(ARGV1 = ${ARGV1})
    message(ARGV2 = ${ARGV2})
    message(ARGV3 = ${ARGV3})
    
endmacro()
# foo2()
# foo2(1)
# foo2(1 TRUE)
# foo2(1 TRUE "hello")
foo2(1 TRUE "hello" 3.14)

#[[
in my macro
in my macro
RET = 1
arg1 = 1 arg2 = 2
arg1 = 1 arg2 = 2
${arg1} is matched
ARGC = 4
ARGN = 1;TRUE;hello;3.14
var = 1
var = TRUE
var = hello
var = 3.14
ARGV0=1
ARGV1=TRUE
ARGV2=hello
ARGV3=3.14
]]