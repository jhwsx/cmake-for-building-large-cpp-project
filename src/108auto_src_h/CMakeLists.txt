# 108auto_src_h/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("auto_src_h")

# 添加头文件查找路径
include_directories("./include")

# 查找目录中的所有源文件。aux_source_directory(<dir> <variable>)
# 收集指定目录下所有源文件的名称，并将列表存储在提供的 <variable> 中。
aux_source_directory("." M_SRC)
aux_source_directory("./src" SRC)
add_executable(${PROJECT_NAME} ${M_SRC} ${SRC})