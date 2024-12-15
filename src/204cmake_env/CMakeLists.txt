#204cmake_env/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(cmake_env)

# 环境变量特点：
# 1. 全局无缓存变量，和全局属性很类似。
# 2. 全局属性可以加说明，但是环境变量不可以。
# 3. 全局属性使用有些复杂，而环境变量则简单一些。
# 4. 环境变量只影响当前的 CMake 进程，不影响调用 CMake 的进程，也不影响整个系统环境，也不
#    影响后续构建或者测试进程的环境。

# 三种环境变量
# 1. CMake 预置环境变量
message("CMAKE_INCLUDE_PATH = $ENV{CMAKE_INCLUDE_PATH}")
message("CMAKE_PREFIX_PATH = $ENV{CMAKE_PREFIX_PATH}")

# 2. 自定义环境变量
# 设置环境变量
set(ENV{MYENV} "test env value")
# 访问环境变量
message("MYENV = $ENV{MYENV}")

# 访问子模块 sub1 中设置的环境变量 SUB_ENV
add_subdirectory(sub1)
message("SUB_ENV = $ENV{SUB_ENV}")

# 3. 系统环境变量, 在 linux 命令行中输入 env 查看所有的环境变量
message("USER = $ENV{USER}")
message("PATH = $ENV{PATH}")
message("HOME = $ENV{HOME}")
