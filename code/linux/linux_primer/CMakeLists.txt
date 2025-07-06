cmake_minimum_required(VERSION 3.16)

# 先定规格，再报家门
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(linux_primer VERSION 0.1.0 LANGUAGES C)

# 仅当需要全局 Verbose
set(CMAKE_VERBOSE_MAKEFILE ON)

# 分 Debug / Release
set(CMAKE_C_FLAGS_DEBUG   "-g -O0 -Wall -ggdb -fPIC")
set(CMAKE_C_FLAGS_RELEASE "-O2 -Wall -fPIC")

add_subdirectory(demo)
