# cmake 帮我们加了 -Wl,-rpath,/home/wangzhichao/workspace/cs/cmake_code/src/102cmake_dynamic_lib/build libxlog.so 所以我们运行可执行程序时，才知道自己的动态库在哪里了。
/usr/bin/c++ CMakeFiles/test_xlog.dir/test_xlog/test_xlog.cpp.o -o test_xlog  -Wl,-rpath,/home/wangzhichao/workspace/cs/cmake_code/src/102cmake_dynamic_lib/build libxlog.so 
# 不同系统里面的静态库和动态库
|系统|静态库|动态库|
|---|---|---|
|Windows|xlog.lib or xlog_d.lib|xlog.lib(函数地址索引) 和 xlog.dll(函数二进制代码)|
|linux(ubuntu, Android, HarmonyOS)|libxlog.a|libxlog.so|
|macOS|libxlog.a|libxlog.dylib|

