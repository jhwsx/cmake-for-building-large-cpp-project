#203cmake_property/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(cmake_property)
#[[
set_property(<GLOBAL                      |
              DIRECTORY [<dir>]           |
              TARGET    [<target1> ...]   |
              SOURCE    [<src1> ...]
                        [DIRECTORY <dirs> ...]
                        [TARGET_DIRECTORY <targets> ...] |
              INSTALL   [<file1> ...]     |
              TEST      [<test1> ...]
                        [DIRECTORY <dir>] |
              CACHE     [<entry1> ...]    >
             [APPEND] [APPEND_STRING]
             PROPERTY <name> [<value1> ...])

get_property(<variable>
             <GLOBAL             |
              DIRECTORY [<dir>]  |
              TARGET    <target> |
              SOURCE    <source>
                        [DIRECTORY <dir> | TARGET_DIRECTORY <target>] |
              INSTALL   <file>   |
              TEST      <test>
                        [DIRECTORY <dir>] |
              CACHE     <entry>  |
              VARIABLE           >
             PROPERTY <name>
             [SET | DEFINED | BRIEF_DOCS | FULL_DOCS])

define_property(<GLOBAL | DIRECTORY | TARGET | SOURCE |
                 TEST | VARIABLE | CACHED_VARIABLE>
                 PROPERTY <name> [INHERITED]
                 [BRIEF_DOCS <brief-doc> [docs...] ]
                 [FULL_DOCS <full-doc> [docs...] ]
                 [INITIALIZE_FROM_VARIABLE <variable>])
]]

message("global property example:")
# 全局属性，可以理解为一个没有缓存的全局变量
# 设置全局属性
set_property(GLOBAL PROPERTY TEST_GLOBAL "test global")
# 获取全局属性
get_property(val GLOBAL PROPERTY TEST_GLOBAL)
message("TEST_GLOBAL = ${val}")

# 访问子目录中的全局属性
add_subdirectory(sub1)
get_property(val GLOBAL PROPERTY SUB1_GLOBAL)
message("SUB1_GLOBAL = ${val}")

# APPEND APPEND_STRING
# APPEND 以数组方式添加
set_property(GLOBAL APPEND PROPERTY TEST_APPEND "append 001")
set_property(GLOBAL APPEND PROPERTY TEST_APPEND "append 002")
set_property(GLOBAL APPEND PROPERTY TEST_APPEND "append 003")
get_property(val GLOBAL PROPERTY TEST_APPEND)
message("TEST_APPEND = ${val}") # output: TEST_APPEND = append 001;append 002;append 003

# APPEND_STRING 字符串拼接
set_property(GLOBAL APPEND_STRING PROPERTY TEST_APPEND_STRING "append string 001")
set_property(GLOBAL APPEND_STRING PROPERTY TEST_APPEND_STRING "append string 002")
set_property(GLOBAL APPEND_STRING PROPERTY TEST_APPEND_STRING "append string 003")
get_property(val GLOBAL PROPERTY TEST_APPEND_STRING)
message("TEST_APPEND_STRING = ${val}") # output: TEST_APPEND_STRING = append string 001append string 002append string 003

message("define_property example:")
# get_property SET | DEFINED
set_property(GLOBAL PROPERTY P1 "p1")
get_property(isP1Set GLOBAL PROPERTY P1 SET)
message("isP1Set = ${isP1Set}")
if(isP1Set)
    message("P1 has been set")
else()
    message("P1 hasn't been set")
endif()

get_property(isP1Defined GLOBAL PROPERTY P1 DEFINED)
if(isP1Defined)
    message("P1 has been defined")
else()
    message("P1 hasn't been defined")
endif()

# 调用了 define_property 之后才可以看到被定义了
define_property(GLOBAL PROPERTY P1)
get_property(isP1Defined GLOBAL PROPERTY P1 DEFINED)
if(isP1Defined)
    message("P1 has been defined")
else()
    message("P1 hasn't been defined")
endif()

define_property(GLOBAL PROPERTY TEST_DEF BRIEF_DOCS "test def brief docs")
get_property(isTestDefDefined GLOBAL PROPERTY TEST_DEF DEFINED)
if(isTestDefDefined)
    message("TEST_DEF has been defined")
else()
    message("TEST_DEF hasn't been defined")
endif()
# 获取概要说明
get_property(briefDocs GLOBAL PROPERTY TEST_DEF BRIEF_DOCS)
message("TEST_DEF brief docs: ${briefDocs}")

message("\ndir property example: ")
# 目录属性
# 设置目录属性 DIR1
set_property(DIRECTORY . PROPERTY DIR1 "dir001")
get_property(val DIRECTORY . PROPERTY DIR1)
message("DIR1 = ${val}")
# 获取 sub1 目录设置的目录属性 DIR1
get_property(val DIRECTORY sub1 PROPERTY DIR1)
message("sub1 DIR1 = ${val}")

message("\nfile property example: ")

set_property(SOURCE main.cpp PROPERTY S1 "s1 value")
get_property(val SOURCE main.cpp PROPERTY S1)
message("SOURCE S1 = ${val}")

# cmake 传递变量给 c++
# cmake 预置属性 COMPILE_DEFINITIONS 传递预处理变量（宏变量）类似于 cmake -D PARA1=param1
set_property(SOURCE main.cpp PROPERTY COMPILE_DEFINITIONS "PARA1=1234")

add_executable(${PROJECT_NAME} main.cpp)

#[[
> ./cmake_property
test cmake property
PARA1 = 1234
]]

# 目标属性
# 目标必须已经存在
message("\ntarget property example:")
# 设置一个名字为 TVAR 的目标属性
set_property(TARGET ${PROJECT_NAME} PROPERTY TVAR "tval")
get_property(val TARGET ${PROJECT_NAME} PROPERTY TVAR)
message("TVAR = ${val}")

# 传递宏给 c++
set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_DEFINITIONS "PARA2=\"test_para2\"")
# 再传递一个宏给 c++，但是这样会覆盖掉上面一个
set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_DEFINITIONS "PARA3=\"test_para3\"")
#[[
output:
test cmake property
PARA1 = 1234
PARA3 = test_para3
]]
# 采用追加设置
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS "PARA4=\"test_para4\"")
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY COMPILE_DEFINITIONS "PARA5=\"test_para5\"")
#[[
output:
test cmake property
PARA1 = 1234
PARA3 = test_para3
PARA4 = test_para4
PARA5 = test_para5
]]
# 查看一下生成过程，看如何传递的。
