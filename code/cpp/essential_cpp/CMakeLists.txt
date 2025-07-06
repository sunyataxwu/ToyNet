cmake_minimum_required(VERSION 3.16)

# —— 0. 先定标准，再报家门 ——  
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(essential_cpp VERSION 0.1.0 LANGUAGES CXX)

# —— 1. 生成 compile_commands.json，利于 LSP / 静态分析 ——  
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# —— 2. Debug / Release 分家，别混 -g + -O2 ——  
set(CMAKE_CXX_FLAGS_DEBUG   "-g -O0 -Wall -Wextra -pedantic -ggdb3 -fPIC")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -Wall -Wextra -pedantic         -fPIC")

# —— 3. 可选：静态分析（Cppcheck）——  
option(ENABLE_CPPCHECK "Run cppcheck static analysis" ON)

if (ENABLE_CPPCHECK)
    find_program(CPPCHECK_EXE NAMES cppcheck)
    if (CPPCHECK_EXE)
        add_custom_target(cppcheck_all
            COMMAND ${CPPCHECK_EXE} ...
        )
    endif()
    # 不显示警告，默认没装就静默跳过

endif()

# —— 4. 子目录 ——  
add_subdirectory(common)
add_subdirectory(exercise)
add_subdirectory(demo)
