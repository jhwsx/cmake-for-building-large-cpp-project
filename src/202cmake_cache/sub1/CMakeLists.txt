#202cmake_cache/sub1/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(sub1)
message("in sub1")

# 子模块可以访问父模块的普通变量
message(STATUS "in sub1 VAR_NORMAL = ${VAR_NORMAL}")

# 子模块 sub1 定义一个普通变量
set(VAR_SUB1_NORMAL "sub1 normal")
message(STATUS "in sub1 VAR_SUB1_NORMAL = ${VAR_SUB1_NORMAL}")

# 子模块 sub1 定义一个缓存变量
set(VAR_SUB1_CACHE "sub1 cache" CACHE STRING "sub1 cache doc")
message(STATUS "in sub1 VAR_SUB1_CACHE = ${VAR_SUB1_CACHE}")
