#205cmake_math/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(cmake_math)

# https://cmake.org/cmake/help/latest/command/math.html#math
#[[
math(EXPR <variable> "<expression>" [OUTPUT_FORMAT <format>])
]]
set(exp "(3 * 10) + 5")
math(EXPR out ${exp})
message("${exp} = ${out}")

# 格式输出
math(EXPR out ${exp} OUTPUT_FORMAT DECIMAL)
message("${exp} = ${out}")
math(EXPR out ${exp} OUTPUT_FORMAT HEXADECIMAL)
message("${exp} = ${out}")

set(exp2 "2 << 4")
math(EXPR out2 ${exp2})
message("${exp2} = ${out2}")
math(EXPR out2 ${exp2} OUTPUT_FORMAT HEXADECIMAL)
message("${exp2} = ${out2}")
