# 103message/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)

project(message)

#[[
message(arg1 arg2 arg3)
]]

# 2.2 message 基础使用
message("参数1") # 测试 message
message("参数p1" "参数p2" #[[注释在message中]] "参数p3" 123 测试)
    
# 2.3 message 高级使用-指定日志级别
# CMake 进程退出，生成退出, 会打印 CMake 路径和行号，标准错误输出
# message(FATAL_ERROR "TEST FATAL ERROR")

# CMake 进程继续，生成退出(生成如 add_executable add_library) , 会打印 CMake 路径和行号，标准错误输出
message(SEND_ERROR "TEST SEND ERROR")
add_executable(test_message test_message.cpp)
message("after ERROR")

# WARNING 打印 CMake 路径和行号, 标准错误输出
message(WARNING "TEST WARNING")

# NOTICE 等同于 none，不打印 CMake 路径和行号, 标准错误输出
message(NOTICE "TEST NOTICE")
message("TEST none")

# STATUS 加前缀 --，这是用户可能感兴趣的日志, 标准输出
message(STATUS "TEST STATUS")

# VERBOSE 加前缀 --，默认不显示 用户需要的详细信息, 标准输出
message(VERBOSE "TEST VERBOSE")

# 设置日志级别
# cmake -B build -S . --log-level=VERBOSE

# 把标准输出重定向到文件
# cmake -S . -B build --log-level=VERBOSE >log.txt
# 控制台里面输出的是标准错误输出，文件里面的是标准输出

# 把所有输出重定向到文件
# cmake -S . -B build --log-level=VERBOSE >log.txt 2>&1

# DEBUG 加前缀 --, 默认不显示, 项目本身的开发人员使用的信息，标准输出
message(DEBUG "test DEBUG")

# TRACE 加前缀 --, 默认不显示，非常低级实现细节的细粒度信息，标准输出
message(TRACE "test TRACE")