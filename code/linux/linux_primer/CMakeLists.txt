cmake_minimum_required(VERSION 3.16)

# 设定C标准为C11，强制要求支持
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(linux_primer VERSION 0.1.0 LANGUAGES C)

# 全局开启Verbose输出，方便调试（根据需要开启）
set(CMAKE_VERBOSE_MAKEFILE ON)

# Debug和Release的编译选项区分
set(CMAKE_C_FLAGS_DEBUG   "-g -O0 -Wall -ggdb -fPIC")
set(CMAKE_C_FLAGS_RELEASE "-O2 -Wall -fPIC")

# 添加子目录
add_subdirectory(demo)
