#202cmake_cache/sub2/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(sub2)
message("in sub2")
message(STATUS "in sub2 VAR_NORMAL = ${VAR_NORMAL}")

# 子模块 sub2 不可以访问同级子模块 sub1 中的普通变量
message(STATUS "in sub2 VAR_SUB1_NORMAL = ${VAR_SUB1_NORMAL}")

# 子模块 sub2 可以访问同级子模块 sub1 中的缓存变量
message(STATUS "in sub2 VAR_SUB1_CACHE = ${VAR_SUB1_CACHE}")
