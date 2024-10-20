cmake_minimum_required(VERSION 3.20)

# 构建项目的名称
project(test_xlog)

# 指定头文件查找路径
include_directories("../xlog")

# 指定库文件查找路径 windows 自动找 ../xlog/build/Debug ../xlog/build/Release
link_directories("../xlog/build")

# 添加可执行文件
add_executable(test_xlog test_xlog.cpp)

# 指定加载的库
target_link_libraries(test_xlog xlog)