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
]]

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