# 103message/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)

project(message)

#[[
message(arg1 arg2 arg3)
]]

message("参数1") # 测试 message
message("参数p1" "参数p2" #[[注释在message中]] "参数p3" 123 测试)