#204cmake_env/sub1/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(sub1)

# 设置子目录中的环境变量，在父模块中可以访问它
set(ENV{SUB_ENV} "sub env value")