#208cmake_foreach_while/CMakeLists.txt
cmake_minimum_required(VERSION 3.20.0)
project(cmake_foreach_while)

# 遍历范围 从 0 开始，到 stop 结束
# foreach(<loop_var> RANGE <stop>)
set(out)
foreach(var RANGE 5)
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: 0 1 2 3 4 5 

# 遍历范围 从 start 开始，到 stop 结束
# foreach(<loop_var> RANGE <start> <stop> [<step>])
set(out "")
foreach(var RANGE 1 3)
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: 1 2 3

set(out "")
foreach(var RANGE 0 10 2)
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: 0 2 4 6 8 10
