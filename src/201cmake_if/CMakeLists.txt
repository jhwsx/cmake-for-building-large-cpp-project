#201cmake_if/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)

#[[
if(<常量>)#constant 常量
如果常量是1，ON，YES，TRUE,Y或非零数(包括浮点数)，则为真True。
如果常量是0，OFF，NO，FALSE，N，IGNORE，NOTFOUND，空字符串，或以-NOTFOUND结尾则为假False
命名布尔常量不区分大小写
]]
message("if constant example:")
if(1)
    message("1 is true")
endif()

if(ON)
    message("ON is true")
endif()

if(YES)
    message("YES is true")
endif()

if(TRUE)
    message("TRUE is true")
endif()

if(Y)
    message("Y is true")
endif()

if(-1)
    message("-1 is true")
endif()

if(0.1)
    message("0.1 is true")
endif()

if(0)
    message("0 is true")
else()
    message("0 is false") # false
endif()

if(OFF)
    message("OFF is true")
else()
    message("OFF is false") # false
endif()

if(NO)
    message("NO is true")
else()
    message("NO is false") # false
endif()

if(FALSE)
    message("FALSE is true")
else()
    message("FALSE is false") # false
endif()

if(N)
    message("N is true")
else()
    message("N is false") # false
endif()

if(IGNORE)
    message("IGNORE is true")
else()
    message("IGNORE is false") # false
endif()

if("")
    message("\"\" is true")
else()
    message("\"\" is false") # false
endif()

if()
    message("empty is true")
else()
    message("empty is false") # false
endif()

if(-NOTFOUND)
    message("-NOTFOUND is true")
else()
    message("-NOTFOUND is false")
endif()

#[[
if(<variable>)
如果给定一个定义为非假常量的值的变量，则为真否则为False，包括变量未定义时。
宏参数不是变量。环境变量if(ENV{some var})总是会评估为假。
]]
message("if variable example: ")
if(VAR_NOT_DEF)
    message("VAR_NOT_DEF is true")
else()
    message("VAR_NOT_DEF is false")
endif()

set(VAR1_TRUE TRUE)
if(VAR1_TRUE)
    message("VAR!_TRUE is true")
endif()

#[[
if(<string>)
带引号的字符串计算为 false,除非字符串的值是真正的常量之一
]]

message("if string example: ")
if("TRUE")
    message("\"TRUE\" is true")
endif()

if("ON")
    message("\"ON\" is true")
endif()

if("1")
    message("\"1\" is true")
endif()

if("test")
    message("\"test\" is true")
else()
    message("\"test\" is false")
endif()

#[[
逻辑运算符
if(NOT <condition>)如果条件不为真，则为真。

if(<cond1> AND <cond2>)如果两个条件都是真的，则为真。

if(<cond1>0R<cond2>)如果任一条件是真的，则为真

if((condition)AND(condition OR(condition))
首先评估括号内的条件，然后评估其余条件.
]]
message("if logic example:")

set(VAR_OFF OFF)
if(NOT VAR_OFF)
    message("NOT VAR_OFF is true")
endif()

if(TRUE AND ON)
    message("TRUE AND ON is true")
endif()

if(TRUE AND OFF)
    message("TRUE AND OFF is true")
else()
    message("TRUE AND OFF is false")
endif()

if(TRUE OR OFF)
    message("TRUE OR OFF is true")
endif()

if(TRUE AND (OFF OR ON))
    message("TRUE AND (OFF OR ON) is true")
endif()

message("if check and comparison example:")

set(VAR_DEF OFF)
if(DEFINED VAR_DEF)
    message("VAR_DEF is defined")
endif()

if(DEFINED VAR_NOT_DEF)
    message("VAR_NOT_DEF is defined")
else()
    message("VAR_NOT_DEF is not defined")
endif()

# 二元判断 EQUAL(判断数字相等) STREQUAL(判断字符串相等)
set(VAR1 123)
if (VAR1 EQUAL 123)
    message("VAR1 EQUAL 123 is true")
endif()
set(VAR2 "test")
if (VAR2 EQUAL "test")
    message("VAR2 EQUAL test is true")
else()
    message("VAR2 EQUAL test is false")
endif()

if (VAR2 STREQUAL "test")
    message("VAR2 STREQUAL test is true")
endif()

if (VAR1 STREQUAL 123)
    message("VAR1 STREQUAL 123 is true")
endif()

# MATCHES
set(STR1 "abcd1234")
if(STR1 MATCHES "[a-z]+")
    message("STR1 MATCHES \"[a-z]+\" is true")
endif()

if(STR1 MATCHES "^[a-z]+$")
    message("STR1 MATCHES \"^[a-z]+$\" is true")
else()
    message("STR1 MATCHES \"^[a-z]+$\" is false")
endif()