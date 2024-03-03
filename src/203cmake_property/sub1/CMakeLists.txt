#203cmake_property/sub1/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(sub1)

# 在子目录中设置全局属性
set_property(GLOBAL PROPERTY SUB1_GLOBAL "sub1 global val")

# 在子目录中设置目录属性 DIR1
set_property(DIRECTORY . PROPERTY DIR1 "sub1 dir1")