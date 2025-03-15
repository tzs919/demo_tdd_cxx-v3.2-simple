测试驱动开发（C++）DEMO，使用的是已经编译的gtest库

1、初始配置，生成makefile构建环境
cmake -G "Unix Makefiles" -S . -B build

2、编译
cmake --build build

3、运行测试
ctest --test-dir build      
