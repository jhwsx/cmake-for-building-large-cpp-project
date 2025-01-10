#402target_compile_features/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(compile_features)

add_executable(main main.cpp)
target_compile_features(main PRIVATE cxx_std_17)
# target_compile_features(main PRIVATE cxx_std_23)

# 打印支持的特征数组
message("CMAKE_CXX_COMPILE_FEATURES: ${CMAKE_CXX_COMPILE_FEATURES}")

message("traverse list CMAKE_CXX_COMPILE_FEATURES:")
foreach(var IN LISTS CMAKE_CXX_COMPILE_FEATURES)
    message(${var}) 
endforeach()

# 判断某个特征是否支持
set(f1 cxx_std_23)
if (f1 IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    message("${f1} is supported")
    target_compile_features(main PRIVATE cxx_std_23)
else()
    message("${f1} is unsupported")
endif()
