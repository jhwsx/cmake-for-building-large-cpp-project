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

# foreach(<loop_var> IN [LISTS [<lists>]] [ITEMS [<items>]])
# 遍历 list 数组
set(args "a" "b" "c" "d" "e")
set(out "")
foreach(var IN LISTS args) # 必须是这样的写法
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: a b c d e

set(out "")
foreach(var IN LISTS ${args})
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: 

set(out "")
foreach(var IN LISTS "1;2;3;4")
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: 

set(out "")
foreach(var IN LISTS 1;2;3;4)
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: 

set(out "")
foreach(var IN ITEMS args) # 必须要 ${args}, 即 list 里面的值
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: args

set(out "")
foreach(var IN ITEMS ${args}) 
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: a b c d e

set(out "")
foreach(var IN ITEMS "1;2;3;4") # 不可以用数组格式的字符串
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: 1234

set(out "")
foreach(var IN ITEMS 1;2;3;4)
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: 1 2 3 4

set(out "")
foreach(var IN ITEMS 1 2 3 4)
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: 1 2 3 4

# 按次序遍历多个 list
set(A 0 1 2 3)
set(B 4 5 6 7)
set(out "")
foreach(var IN LISTS A B)
    string(APPEND out ${var} " ")
endforeach()
message("out: ${out}") # out: 0 1 2 3 4 5 6 7

# 同步遍历多个 list
# foreach(<loop_var>... IN ZIP_LISTS <lists>)
set(list1 "1;2;3;4;5;6;7")
set(list2 "a;b;c;d;e;f;g")
set(out "")
foreach(var IN ZIP_LISTS list1 list2)
    string(APPEND out "${var_0}:${var_1}" " ")
endforeach()
message("out: ${out}") # out: 1:a 2:b 3:c 4:d 5:e 6:f 7:g 

set(out "")
foreach(var0 var1 IN ZIP_LISTS list2 list1)
    string(APPEND out "${var0}=${var1}" " ")
endforeach()
message("out: ${out}") # out: a=1 b=2 c=3 d=4 e=5 f=6 g=7

# break() continue()
# 计算 0 到 10 的奇数和
set(sum 0)
foreach(var RANGE 10)
    math(EXPR even "${var} % 2") 
    if(even EQUAL 0)
        continue()
    endif()
    math(EXPR sum "${sum} + ${var}")
endforeach()
message("odd sum: ${sum}") # 25

# 计算 0 到 10 的和
set(sum 0)
foreach(var RANGE 100)
    if(${var} GREATER 10)
        break()
    endif()
    math(EXPR sum "${sum} + ${var}")
endforeach()
message("sum: ${sum}") # 55

