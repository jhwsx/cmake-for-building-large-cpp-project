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
$<NOT:condition> $<AND:conditions>
$<OR:conditions>

字符串值生成器表达式之条件表达式
$<condition:true_string>
    condition条件满足，返回 true_string；否则返回空串。
$<IF:condition,true_string,false_string>
]]
# 给目标添加编译定义
target_compile_definitions(${PROJECT_NAME} PUBLIC "$<$<BOOL:ON>:TEST1=123>")