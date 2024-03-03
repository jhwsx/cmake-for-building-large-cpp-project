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
cmake_minimum_required(VERSION 3.23)

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

# option, 作为 BOOL 的简化
option(OPT1 "opt1 doc" OFF)
option(OPT2 "opt2 doc" ON)

# CMP0126 New in CMake 3.21

# 普通变量
set(NVAR1 "normal var1")

# 设置缓存变量覆盖同名普通变量的策略
# OLD 表示删除与缓存变量同名的普通变量
# NEW 表示不删除与缓存变量同名的普通变量，访问缓存变量要用 $CACHE{var_name}
cmake_policy(SET CMP0126 OLD)

# cache 变量
set(NVAR1 "cache var1" CACHE STRING "cache doc")

# 先查找普通变量，普通变量有则结束；如果普通变量没有再查找缓存变量
message("\${NVAR1} = ${NVAR1}")
# 直接查找缓存变量
message("\$CACHE{NVAR1} = $CACHE{NVAR1}")

#[[
OLD output:
${NVAR1} = cache var1
$CACHE{NVAR1} = cache var1
NEW output:
${NVAR1} = normal var1
$CACHE{NVAR1} = cache var1
]]

# cmake 命令行传递缓存变量
# cmake -B build -S . -D PARA1=para002 -D BUILD_SHARED_LIBS=ON
# 为什么说传递过去的是缓存变量呢？
# 第一次执行传可以看到打印，第二次不删 build 执行还可以看到打印。
message("\ncmake cmd pass cache variable:")
# 自定义的缓存变量
message("PARA1 = ${PARA1}")
# cmake 内置的缓存变量
set(BUILD_SHARED_LIBS OFF CACHE BOOL "build so or a")
message("BUILD_SHARED_LIBS = ${BUILD_SHARED_LIBS}")