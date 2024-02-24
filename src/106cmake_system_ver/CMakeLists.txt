# 106cmake_system_ver/CMakeLists.txt

cmake_minimum_required(VERSION 3.20)

project(xlog)

# 1. 提供信息的变量 ${PROJECT_NAME} 对应 project() 里面的 name
# 2. 改变行为的变量 BUILD_SHARED_LIBS ON 表示动态库，OFF 表示静态库（默认), 这是一个缓存变量
set(BUILD_SHARED_LIBS OFF)
add_definitions(-Dxlog_STATIC)
# 3. 描述系统的变量
message("MSVC = " ${MSVC})
message("WIN32 = " ${WIN32})
message("UNIX = " ${UNIX})
message("CMAKE_SYSTEM_NAME = " ${CMAKE_SYSTEM_NAME})
# 4. 控制构建过程的变量 输出路径控制，是否生成 makefile 的颜色（CMAKE_COLOR_MAKEFILE, 默认是 ON）
set(CMAKE_COLOR_MAKEFILE OFF)
# 添加动态库，项目自带预处理变量 xlog_EXPORTS
add_library(${PROJECT_NAME} xlog.cpp xlog.h)
