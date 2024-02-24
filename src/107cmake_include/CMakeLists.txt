# 107cmake_include/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("cmake_include")

message("begin include")

include("cmake/test_cmake.cmake")
# 再次 include，仍会进入
include("cmake/test_cmake.cmake") 
# 不存在且不加 OPTIONAL, 报错：include could not find requested file:
include("cmake/test_unexisted.cmake" OPTIONAL) 
# 记录 include 结果
include("cmake/test_unexisted.cmake" OPTIONAL RESULT_VARIABLE ret)
message("ret: ${ret}") # output: ret: NOTFOUND
include("cmake/test_cmake.cmake" RESULT_VARIABLE ret)
message("ret: ${ret}") # output: ret: /home/wangzhichao/workspace/cs/cmake_code/src/107cmake_include/cmake/test_cmake.cmake

message("end include")