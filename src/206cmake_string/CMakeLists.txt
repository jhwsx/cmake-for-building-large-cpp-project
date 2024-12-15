#206cmake_string/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_string)

# 查找和替换
message(STATUS "Search, Replace, Manipulation example:")
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
# output: find ESTR positon in STR1: 25

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
find BSTR position in STR1: 2
find ESTR position in STR1: 25
b_end: 7
sublen: 18
substr: [ test make string ]
trimmedsubstr: [test make string]
newsubstr: [test cmake string]
out: [TEST CMAKE STRING]
]]

message(STATUS "Append, Replace, Regex example:")

set(STR2 "TEST CMAKE STRING")
# 字符串追加
# string(APPEND <string_variable> [<input>...])
string(APPEND STR2 " append01" " append02")
message("STR2: [${STR2}]")

# 字符串替换
# string(REPLACE <match_string> <replace_string> <output_variable> <input> [<input>...])
string(REPLACE "append" "REPLACE" replacedStr2 ${STR2})
message("replacedStr2: [${replacedStr2}]")

# 正则表达式匹配
# string(REGEX MATCH <regular_expression> <output_variable> <input> [<input>...])
string(REGEX MATCH "[A-Z]+[0-9]+" out ${replacedStr2})
message("out: [${out}]")

#[[
output:
STR2: [TEST CMAKE STRING append01 append02]
replacedStr2: [TEST CMAKE STRING REPLACE01 REPLACE02]
out: [REPLACE01]
]]

message(STATUS "JSON example(cmake 3.19):")
# json
#[[
  string(JSON <out-var> [ERROR_VARIABLE <error-var>]
         {GET | TYPE | LENGTH | REMOVE}
         <json-string> <member|index> [<member|index> ...])
  string(JSON <out-var> [ERROR_VARIABLE <error-var>]
         MEMBER <json-string>
         [<member|index> ...] <index>)
  string(JSON <out-var> [ERROR_VARIABLE <error-var>]
         SET <json-string>
         <member|index> [<member|index> ...] <value>)
  string(JSON <out-var> [ERROR_VARIABLE <error-var>]
         EQUAL <json-string1> <json-string2>)
]]

set(tjson
[=[
{
    "webs":{
        "web":[
            {
                "name":"cmake",
                "url":"cmake.org.cn"
            },
            {
                "name":"ffmpeg",
                "url":"ffmpeg.club"
            }
        ]
    }
}
]=]
)
message("tjson: ${tjson}")
#[[
string(JSON <out-var> [ERROR_VARIABLE <error-variable>] GET <json-string> <member|index> [<member|index> ...])
]]
# 访问 webs -> web[0] -> name
string(JSON out_var ERROR_VARIABLE error_var GET ${tjson} webs web 0 name)
if(error_var)
    message("GET error: ${error_var}")
else()
    message("GET webs web 0 name: ${out_var}")
endif()

# 访问 webs -> web[1] -> url
string(JSON out_var ERROR_VARIABLE error_var GET ${tjson} webs web 1 url)
message("GET error: ${error_var}")
if(error_var)
    message("GET error: ${error_var}")
else()
    message("GET webs web 1 url: ${out_var}")
endif()

# 访问 webs -> web[2] 访问失败
string(JSON out_var ERROR_VARIABLE error_var GET ${tjson} webs web 2)
message("GET error: ${error_var}")
if(error_var)
    message("GET error: ${error_var}")
else()
    message("GET webs web 2: ${out_var}")
endif()

#[[
output:
webs web 0 name: cmake
error: NOTFOUND
webs web 1 url: ffmpeg.club
error: expected an index less than 2 got '2'
error: expected an index less than 2 got '2'
]]

set(twrongjson
[=[
{
    "webs":{
       12345 
    }
}
]=]
)

string(JSON out_var ERROR_VARIABLE error_var GET ${twrongjson} webs)
if(error_var)
    message("GET error: ${error_var}")
else()
    message("GET webs: ${out_var}")
endif()

#[[
output: 
error: failed parsing json string: * Line 3, Column 8
  Missing '}' or object member name.
]]

# 获取元素的类型
#[[
string(JSON <out-var> [ERROR_VARIABLE <error-variable>] TYPE <json-string> <member|index> [<member|index> ...])
]]
string(JSON out_var ERROR_VARIABLE error_var TYPE ${tjson} webs)
message("TYPE webs: ${out_var}")
# TYPE webs: OBJECT

# 获取 json 数组长度
#[[
string(JSON <out-var> [ERROR_VARIABLE <error-variable>] LENGTH <json-string> [<member|index> ...])
]]
string(JSON arr_len ERROR_VARIABLE error_var LENGTH ${tjson} webs web)
message("LENGTH web: ${arr_len}")
# LENGTH web: 2

# json 的增加和修改操作都是用 SET 命令
# json 的增加
#[[
string(JSON <out-var> [ERROR_VARIABLE <error-variable>] SET <json-string> <member|index> [<member|index> ...] <value>)
]]
string(JSON add_json ERROR_VARIABLE error_var SET ${tjson} webs web 2 [=[
{
    "name":"c",
    "url":"c.org"
}
]=])
message("SET add_json: ${add_json}")
#[[
SET add_json: {
  "webs" : 
  {
    "web" : 
    [
      {
        "name" : "cmake",
        "url" : "cmake.org.cn"
      },
      {
        "name" : "ffmpeg",
        "url" : "ffmpeg.club"
      },
      {
        "name" : "c",
        "url" : "c.org"
      }
    ]
  }
}
]]

# json 的修改
string(JSON modified_json ERROR_VARIABLE error_var SET ${tjson} webs web 1 [=[
{
    "name":"ffmpeg",
    "url":"ffmpeg.org"
}
]=])
message("SET modified_json: ${modified_json}")
#[[
SET modified_json: {
  "webs" : 
  {
    "web" : 
    [
      {
        "name" : "cmake",
        "url" : "cmake.org.cn"
      },
      {
        "name" : "ffmpeg",
        "url" : "ffmpeg.org"
      }
    ]
  }
}
]]

# json 的 删除
#[[
string(JSON <out-var> [ERROR_VARIABLE <error-variable>] REMOVE <json-string> <member|index> [<member|index> ...])
]]
string(JSON remove_json ERROR_VARIABLE error_var REMOVE ${tjson} webs web 0)
message("REMOVE remove_json: ${remove_json}")
string(JSON remove_json ERROR_VARIABLE error_var REMOVE ${remove_json} webs web)
message("REMOVE remove_json: ${remove_json}")
#[[
output:
REMOVE remove_json: {
  "webs" : 
  {
    "web" : 
    [
      {
        "name" : "ffmpeg",
        "url" : "ffmpeg.club"
      }
    ]
  }
}
REMOVE remove_json: {
  "webs" : {}
}
]]
# json 的比较
set(json1 [=[
{
    "name":"cmake",
    "url":"cmake.org.cn"
}
]=])

set(json2 [=[
{
    "name":"cmake",
    "url":"cmake.org.cn"
}
]=])

string(JSON out_var ERROR_VARIABLE error_var EQUAL ${json1} ${json2})
message("EQUAL out_var: ${out_var}")
# EQUAL out_var: ON
