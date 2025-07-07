cmake_minimum_required(VERSION 3.16)

project(accelerated_cpp VERSION 0.1.0 LANGUAGES CXX)

# 1. 设定C++标准为11，传统且简单
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 2. 默认Debug构建，传统写法，简单明了
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# 3. 生成compile_commands.json，方便IDE和静态分析工具使用
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 4. 根据Debug/Release分别设置编译选项，传统if写法，易懂无黑魔法
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_options(-g -O0 -Wall -Wextra -pedantic -fPIC)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  add_compile_options(-O2 -Wall -Wextra -pedantic -fPIC)
endif()

# 5. verbose开关，用传统option声明，默认关闭，想看详细就打开
option(VERBOSE_MAKEFILE "Enable verbose output" OFF)
set(CMAKE_VERBOSE_MAKEFILE ${VERBOSE_MAKEFILE})

# 6. cppcheck静态分析集成，方便执行全项目检查
find_program(CPPCHECK_EXE NAMES cppcheck)
if(CPPCHECK_EXE)
  add_custom_target(cppcheck_all
    COMMAND ${CPPCHECK_EXE}
      --enable=all
      --inconclusive
      --project=${CMAKE_BINARY_DIR}/compile_commands.json
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running cppcheck (this may take a while)..."
  )
endif()

# 7. 子目录模块管理，结构清晰
add_subdirectory(common)
add_subdirectory(demo)
add_subdirectory(homework)
