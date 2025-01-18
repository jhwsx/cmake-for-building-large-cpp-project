#406cmake_vs_multithreaded/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(test_vs)

add_library(slib STATIC slib.cpp)
#[[
MultiThreaded -MT
MultiThreadedDll -MD
MultiThreadedDebug -MTd
MultiThreadedDebugDll -MDd
]]
# 静态库使用 MT(静态导入运行时库) MultiThreaded，可以查看 slib 属性->C/C++->代码生成，运行时库用的是多线程（/MT）
# set_target_properties(slib PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded")
# 可以根据配置来选择 MT 还是 MTd
set_target_properties(slib PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
# main 默认用的运行时库是 MD，可以查看 main 属性->C/C++->代码生成，运行时库用的是多线程调试 DLL (/MDd)
add_executable(main main.cpp)
# main 指定用的运行时库是 MT，可以查看 main 属性->C/C++->代码生成，运行时库用的是多线程调试 DLL (/MDd)
# set_target_properties(main PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded")
# 可以根据配置来选择 MT 还是 MTd
set_target_properties(main PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
target_link_libraries(main PRIVATE slib)
