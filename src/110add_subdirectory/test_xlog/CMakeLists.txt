cmake_minimum_required(VERSION 3.20)

project(test_xlog)

# 添加可执行程序
add_executable(${PROJECT_NAME} test_xlog.cpp)

# 指定链接的库
target_link_libraries(${PROJECT_NAME} xlog)