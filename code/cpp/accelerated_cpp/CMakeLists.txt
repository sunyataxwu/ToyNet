cmake_minimum_required(VERSION 3.16)

# —— 0. 可选：在命令行指定编译器更纯粹 ——  
# cmake -G Ninja -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug ..

# —— 1. 项目信息（先写编译器标准，再 project）——
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(accelerated_cpp VERSION 0.1.0 LANGUAGES CXX)

# —— 2. 生成 compile_commands.json，方便 LSP / 静态分析 ——  
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# —— 3. 构建类型：Debug / Release 分家 ——  
# * Debug：带符号 + 0 级优化
# * Release：O2 优化，不带调试符号
#   如果想要 “RelWithDebInfo” 也行，此处示范经典二分法
set(CMAKE_CXX_FLAGS_DEBUG   "-g -O0 -Wall -Wextra -pedantic -fPIC")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -Wall -Wextra -pedantic -fPIC")

# —— 4. Verbose 输出（只在需要时再开）——  
set(CMAKE_VERBOSE_MAKEFILE ON)

# —— 5. 静态分析：cppcheck ——  
find_program(CPPCHECK_EXE NAMES cppcheck)
if (CPPCHECK_EXE)
    # 把源码与头文件全都扫一遍；依赖 compile_commands.json
    add_custom_target(cppcheck_all
        COMMAND ${CPPCHECK_EXE}
            --enable=all            # 打开所有规则
            --inconclusive          # 连“可疑”也别放过
            --project=${CMAKE_BINARY_DIR}/compile_commands.json
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running cppcheck (this may take a while)..."
    )
endif()

# —— 6. 子目录 ——  
add_subdirectory(common)
add_subdirectory(demo)
add_subdirectory(homework)
