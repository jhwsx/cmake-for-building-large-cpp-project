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

# CACHE 变量 vs 普通变量
# CACHE 变量的作用域是全局的，而且可以跨不同的执行
# 普通变量的作用域是自身所在的模块及其子模块
set(VAR_NORMAL "test normal")
message("in main")
message(STATUS "in main VAR_NORMAL = ${VAR_NORMAL}")
add_subdirectory(sub1)
add_subdirectory(sub2)
# 父模块无法访问 sub1 中的普通变量
message(STATUS "in main VAR_SUB1_NORMAL = ${VAR_SUB1_NORMAL}")
# 父模块可以访问 sub1 中的缓存变量
message(STATUS "in main VAR_SUB1_CACHE = ${VAR_SUB1_CACHE}")

#[[
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
]]
message("-----------test type using cmake-gui or ccmake-----------")

# BOOL 勾选
set(VAR_BOOL1 "ON" CACHE BOOL "VAR bool 001")
set(VAR_BOOL2 "OFF" CACHE BOOL "VAR bool 002")
message("VAR_BOOL1 = ${VAR_BOOL1}")
message("VAR_BOOL2 = ${VAR_BOOL2}")

# FILEPATH 选择文件
set(VAR_FILEPATH "filepath" CACHE FILEPATH "var filepath")
message("VAR_FILEPATH = ${VAR_FILEPATH}")

# PATH 选择目录
set(VAR_PATH "path" CACHE PATH "var path")
message("VAR_PATH = ${VAR_PATH}")

# 内部缓存变量，在 cmake-gui 或者 ccmake 中看不到
set(VAR_INTERNAL "path" CACHE INTERNAL "var internal")
message("VAR_INTERNAL = ${VAR_INTERNAL}")

