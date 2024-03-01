# 202cmake_cache/CMakeLists.txt
#[[
set(<variable> <value>... CACHE <type> <docstring> [FORCE])
	type
		BOOL
			ON/OFF 选择框
		FILEPATH
			文件选择
		PATH
			目录选择
		STRING
			字符串
		INTERNAL
			内部变量
	docstring
		变量说明
	FORCE 
		强制修改缓存，不设置第二次调用值不改
]]
cmake_minimum_required(VERSION 3.20)

project(cmake_cache)

# 设置一个字符串类型的缓存变量
# 在设置了之后，把这行注掉，再次执行，还会打出原来设置的值，这是因为记录在了 CMakeCache.txt 里面了。
set(VAR1 "CACHE VAR1 VALUE1-1" CACHE STRING "cache doc")
message("VAR1: ${VAR1}")

set(VAR1 "CACHE VAR1 VALUE1-2" CACHE STRING "cache doc")
message("VAR1: ${VAR1}")

# 强制修改缓存
set(VAR1 "CACHE VAR1 VALUE1-3 FORCE" CACHE STRING "cache doc" FORCE)
message("VAR1: ${VAR1}")
