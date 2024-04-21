# 210cmake_function/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_function)

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
