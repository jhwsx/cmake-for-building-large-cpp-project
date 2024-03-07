#206cmake_string/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_string)

# 查找和替换
#[[
string(FIND <string> <substring> <output_variable> [REVERSE])
]]
# 取出 begin 和 end 之间的内容，去掉首尾空格, 把 make 改为 cmake，最后全部变大写
set(STR1 "  begin test make string end  ")
# 查找的开头字符串
set(BSTR "begin")
# 在 STR1 中查找 BSTR 的位置存入 b
string(FIND ${STR1} ${BSTR} b)
message("find BSTR positon in STR1: ${b}")
# output: find BSTR positon in STR1: 2
set(ESTR "end")
# 在 STR1 中查找 ESTR 的位置存入 e
string(FIND ${STR1} ${ESTR} e)
message("find ESTR positon in STR1: ${e}")
# output: find ESTR positon in STR1: 26

# 计算 "begin" 的长度 
#  string(LENGTH <string> <out-var>)
string(LENGTH ${BSTR} b_len)

# 计算 "begin" 尾部的位置
math(EXPR b_end "${b} + ${b_len}")
message("b_end: ${b_end}")

# 计算 "begin" 的尾部到 "end" 的开头的长度
math(EXPR sublen "${e} - ${b_end}")
message("sublen: ${sublen}")

# 取出 begin 和 end 之间的内容
# string(SUBSTRING <string> <begin> <length> <output_variable>)
string(SUBSTRING ${STR1} ${b_end} ${sublen} substr)
message("substr: [${substr}]")

# 去掉首尾的空格
# string(STRIP <string> <output_variable>)
string(STRIP ${substr} trimmedsubstr)
message("trimmedsubstr: [${trimmedsubstr}]")

# 把 make 变为 cmake
# string(REPLACE <match_string> <replace_string> <output_variable> <input> [<input>...])
string(REPLACE "make" "cmake" newsubstr ${trimmedsubstr})
message("newsubstr: [${newsubstr}]")

# 全部变为大写
# string(TOUPPER <string> <output_variable>)
string(TOUPPER ${newsubstr} out)
message("out: [${out}]")

#[[
output:
find BSTR positon in STR1: 2
find ESTR positon in STR1: 25
b_end: 7
sublen: 18
substr: [ test make string ]
trimmedsubstr: [test make string]
newsubstr: [test cmake string]
out: [TEST CMAKE STRING]
]]


