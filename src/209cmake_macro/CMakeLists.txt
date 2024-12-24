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
#[[
output:
in my macro
in my macro
RET = 1
]]

# 定义一个固定参数数目的宏演示宏参数传递: 不可以传递少于参数个数的参数
macro(foo arg1 arg2)
    message("arg1 = ${arg1} arg2 = ${arg2}")
endmacro()
# foo() # error: foo Macro invoked with incorrect arguments for macro named: foo
# foo(1) # foo Macro invoked with incorrect arguments for macro named: foo
foo(1 2)
foo(1 2 3)
#[[
output:
arg1 = 1 arg2 = 2
arg1 = 1 arg2 = 2
]]

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

#[[
output:
${arg1} is matched
]]

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

#[[
https://cmake.org/cmake/help/latest/command/cmake_parse_arguments.html#command:cmake_parse_arguments

解析函数或者宏的参数

cmake_parse_arguments(<prefix> <options> <one_value_keywords>
                      <multi_value_keywords> <args>...)
prefix 生成变量的前缀
options 可选的参数，设置了就是 TRUE 没有设置就是 FALSE，不用赋值
one_value_keywords 单个值的变量
multi_value_keywords 多个值的变量
args 参数数组，变量内容
<prefix>_UNPARSED_ARGUMENTS 表示未被使用的参数变量（ ${ARGN}里面）
<prefix>_KEYWORDS_MISSING_VALUES：定义了关键词，但是没有对应的值
]]

macro(my_parse)
    message("ARGN = ${ARGN}") 
    cmake_parse_arguments(
        "MY" # 生成变量的前缀
        "LOG_ENABLE;FILE_ENABLE" # option, 可选的参数
        "BIN;LIB" # 单个值的变量
        "TARGETS" # 多个值的变量
        ${ARGN} # 参数数组
    )
    message("MY_LOG_ENABLE = ${MY_LOG_ENABLE}")
    message("MY_FILE_ENABLE = ${MY_FILE_ENABLE}")
    message("MY_BIN = ${MY_BIN}")
    message("MY_LIB = ${MY_LIB}")
    message("MY_TARGETS = ${MY_TARGETS}")
    message("MY_UNPARSED_ARGUMENTS = ${MY_UNPARSED_ARGUMENTS}")
    message("MY_KEYWORDS_MISSING_VALUES = ${MY_KEYWORDS_MISSING_VALUES}")
endmacro()

my_parse(
    LOG_ENABLE
    FILE_ENABLE "filename1"
    BIN "mybin"
    LIB 
    TARGETS "target1" "target2" "target3"
    )

macro(my_install)
    message("ARGN = ${ARGN}") 
    set(options OPTIONAL FAST)
    set(oneValueArgs DESTINATION RENAME)
    set(multiValueArgs TARGETS CONFIGURATIONS)
    cmake_parse_arguments(arg_my_install "${options}" "${oneValueArgs}"
        "${multiValueArgs}" ${ARGN})
    message("arg_my_install_OPTIONAL = ${arg_my_install_OPTIONAL}")
    message("arg_my_install_FAST = ${arg_my_install_FAST}")
    message("arg_my_install_DESTINATION = ${arg_my_install_DESTINATION}")
    message("arg_my_install_RENAME = ${arg_my_install_RENAME}")
    message("arg_my_install_TARGETS = ${arg_my_install_TARGETS}")
    message("arg_my_install_CONFIGURATIONS = ${arg_my_install_CONFIGURATIONS}")
    message("arg_my_install_UNPARSED_ARGUMENTS = ${arg_my_install_UNPARSED_ARGUMENTS}")
    message("arg_my_install_KEYWORDS_MISSING_VALUES = ${arg_my_install_KEYWORDS_MISSING_VALUES}")
endmacro()
my_install(TARGETS foo bar DESTINATION bin OPTIONAL blub CONFIGURATIONS)

macro(my_special_install)
    message("ARGN = ${ARGN}") 
    set(options OPTIONAL FAST)
    set(oneValueArgs DESTINATION RENAME)
    set(multiValueArgs TARGETS CONFIGURATIONS)
    cmake_parse_arguments(arg_my_special_install "${options}" "${oneValueArgs}"
        "${multiValueArgs}" ${ARGN})
    message("arg_my_special_install_OPTIONAL = ${arg_my_special_install_OPTIONAL}")
    message("arg_my_special_install_FAST = ${arg_my_special_install_FAST}")
    message("arg_my_special_install_DESTINATION = ${arg_my_special_install_DESTINATION}")
    message("arg_my_special_install_RENAME = ${arg_my_special_install_RENAME}")
    message("arg_my_special_install_TARGETS = ${arg_my_special_install_TARGETS}")
    message("arg_my_special_install_CONFIGURATIONS = ${arg_my_special_install_CONFIGURATIONS}")
    message("arg_my_special_install_UNPARSED_ARGUMENTS = ${arg_my_special_install_UNPARSED_ARGUMENTS}")
    message("arg_my_special_install_KEYWORDS_MISSING_VALUES = ${arg_my_special_install_KEYWORDS_MISSING_VALUES}")
endmacro()
my_special_install(TARGETS barry DESTINATION sbin RENAME FAST)

macro(my_intro)
    set(options ADULT)
    set(oneValueArgs NAME AGE)
    set(multiValueArgs SCORES)

    cmake_parse_arguments(STUDENT "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    message("STUDENT_ADULT = ${STUDENT_ADULT}")
    message("STUDENT_NAME = ${STUDENT_NAME}")
    message("STUDENT_AGE = ${STUDENT_AGE}")
    message("STUDENT_SCORES = ${STUDENT_SCORES}")
endmacro()
set(SCORES 100 97 100 96)
my_intro(ADULT NAME peter AGE 18 SCORES ${SCORES})
