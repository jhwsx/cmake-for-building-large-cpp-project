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

