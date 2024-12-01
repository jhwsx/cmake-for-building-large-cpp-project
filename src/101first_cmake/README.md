cmake -B build -S . -G "Ninja"
cmake --build build -j32
cmake --build build -?

cmake 命令实现程序的分步生成
查看目标：cmake --build build --target help
预处理：cmake --build build --target 101first_cmake.i
编译：cmake --build build --target 101first_cmake.s
汇编：cmake --build build --target 101first_cmake.o
链接：cmake --build build --target first_cmake
清理：cmake --build build --target clean
windows 下要使用 nmake, 指定 cmake -B build -S . -G "NMake Makefiles"