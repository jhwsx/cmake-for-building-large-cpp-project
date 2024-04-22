# 210cmake_function/sub1/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_function_sub1)
function(function_sub1)
    message("in sub1 function")
    math(EXPR sub1_var "${sub1_var} + 1")
    math(EXPR sub1_var2 "${sub1_var2} + 1")
    # 定义一个函数内部局部变量，作用域设置到父级, 作用域开放给调用者
    set(sub1_var ${sub1_var} PARENT_SCOPE)
    set(sub1_var2 ${sub1_var2} PARENT_SCOPE)
endfunction()

function_sub1()
function_sub1()
message("in sub1 sub1_var = ${sub1_var}")
set(sub1_var2 ${sub1_var2} PARENT_SCOPE) # 作用域开放给父目录
message("in sub1 sub1_var2= ${sub1_var2}")