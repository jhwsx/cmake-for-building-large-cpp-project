# 104testver/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)

project(test_ver)

# 设置 VAR1 变量
set(VAR1 "测试变量VAR1的值")
message("VAR1=" ${VAR1})
# 在字符串中引用
message("VAR1 in string: ${VAR1}")
# 转义 $
message("\${VAR1} = ${VAR1}")

# 嵌套访问
set(VAR2 "VAR1")
message("VAR2 = " ${VAR2})
message("VAR1 = " ${${VAR2}})

# 取消设置 VAR1 
unset(VAR1)
message("after unset, VAR1=" ${VAR1})