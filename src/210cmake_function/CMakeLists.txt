# 210cmake_function/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_function)

message(STATUS "function basic:")
# function basic
macro(macro1 arg1 arg2)
    if(arg2)
        message("IN macro1 arg2 is TRUE")
    endif()
endmacro()

function(func1 arg1 arg2)
    message("IN function1 arg1 = ${arg1}, arg2 = ${arg2}")
    if(arg2)
        message("IN function1 arg2 is TRUE")
    endif()
    foreach(var IN LISTS ARGN) # 打印所有变参
        message("IN function1 var = ${var}")
    endforeach()
endfunction()
macro1(OFF TRUE "testmacro1")
func1(OFF TRUE "testfunc1" 1 2 3)

#[[
IN function1 arg1 = OFF, arg2 = TRUE
IN function1 arg2 is TRUE
IN function1 var = testfunc1
IN function1 var = 1
IN function1 var = 2
IN function1 var = 3
]]

message("\n")
message(STATUS "function variable scope:")
# function variable scope
function(fun_var arg1)
    # 访问的是局部变量 arg1
    message("in fun_var arg1 = ${arg1}")
    # 在函数内部可以访问 var1, 这点和 c 语言不太一样
    message("in fun_var var1 = ${var1}")
    # 在函数内部尝试修改 var1, 不会成功的，这是因为这行等效于设置一个 var1 的局部变量
    set(var1 "fun var1 value")
    # 设置函数内局部变量的作用域到父级（调用函数者，父目录）
    set(RET "1" PARENT_SCOPE)
endfunction()

# 在调用函数前设置一个变量 var1
set(var1 "main var1 value")
# 在调用函数前设置一个和 parameter 同名的变量
set(arg1 "main arg1")
fun_var(123)
message("main var1 = ${var1}")
message("RET = ${RET}")

add_subdirectory(sub1)
# 可以直接访问子目录中的函数
function_sub1()
message("in main sub1_var = ${sub1_var}")
message("in main sub1_var2 = ${sub1_var2}")

#[[
-- function variable scope:
in fun_var arg1 = 123
in fun_var var1 = main var1 value
main var1 = main var1 value
RET = 1
in sub1 function
in sub1 function
in sub1 sub1_var = 2
in sub1 sub1_var2= 2
in sub1 function
in main sub1_var = 1
in main sub1_var2 = 3
]]