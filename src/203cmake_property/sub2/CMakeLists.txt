#203cmake_property/sub1/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(sub1)

message("in sub2")

get_property(val DIRECTORY .. PROPERTY DIR1)
message("DIR1 = ${val}")

# 在子目录中设置目录属性 DIR1
set_property(DIRECTORY . PROPERTY DIR1 "sub2 dir1")