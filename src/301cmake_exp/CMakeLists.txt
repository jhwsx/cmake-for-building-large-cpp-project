#301cmake_exp/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(cmake_exp)
add_executable(${PROJECT_NAME} cmake_exp.cpp)

#[[
布尔生成器表达式之逻辑运算符
$<BOOL:string>
    转换 string 为 0 或者 1。评估 0 以下任何一项是否为真：
    string 是空的，
    string 是不区分大小写的, 等于 0，FALSE，OFF，N，NO，IGNORE，or NOTFOUND，or
    string 以后缀结尾 -NOTFOUND（区分大小写）。
    否则计算为 1。
$<NOT:condition> 
$<AND:conditions>
$<OR:conditions>

字符串值生成器表达式之条件表达式
$<condition:true_string>
    condition条件满足，返回 true_string；否则返回空串。
$<IF:condition,true_string,false_string>
]]
# 给目标添加编译定义
target_compile_definitions(${PROJECT_NAME} PUBLIC "$<$<BOOL:ON>:TEST1=123>")

# 测试生成表达式的方式
# 1. 利用 cmake 的错误来查看，只能查看到一部分生成表达式的错误
# 测试 $<BOOL:string> 是否得出正确的结果: 1
# target_include_directories(${PROJECT_NAME} PUBLIC "$<BOOL:ON>")
# 测试 $<AND:1,0> 是否得出正确的结果: 0
# target_include_directories(${PROJECT_NAME} PUBLIC "$<AND:1,0>")
# 测试 $<AND:1,1> 是否得出正确的结果: 1
# target_include_directories(${PROJECT_NAME} PUBLIC "$<AND:1,1>")
# 测试 $<OR:0,1> 是否得出正确的结果: 1
# target_include_directories(${PROJECT_NAME} PUBLIC "$<OR:0,1>")
# 测试 $<OR:0,0> 是否得出正确的结果: 0
# target_include_directories(${PROJECT_NAME} PUBLIC "$<OR:0,0>")
# 测试 $<NOT:1>
# set(LIB OFF)
# $<BOOL:$<LIB>> => 0
# $<NOT:$<BOOL:${LIB}>> => 1
# $<$<NOT:$<BOOL:${LIB}>>:STAITC> => STATIC
# target_include_directories(${PROJECT_NAME} PUBLIC "$<$<NOT:$<BOOL:${LIB}>>:STATIC>")

# 2. 生成一个自定义目标（官方），可以查看所有生成表达式的错误
set(LIB2 OFF)
# 在配置阶段阶段不处理生成器表达式，生成器表达式是在生成阶段处理的
message($<$<NOT:$<BOOL:${LIB2}>>:STATIC>)
message("CMAKE_COMMAND: ${CMAKE_COMMAND}") # /opt/cmake/bin/cmake
add_custom_target(gen COMMAND ${CMAKE_COMMAND} -E echo "$<$<NOT:$<BOOL:${LIB}>>:STATIC>")
#[[
如何运行？
cmake -B build -S .
cmake --build build --target gen
output:
STATIC
]]
