# 1. 定义共享库目标 common，暂不列出源码文件
add_library(common SHARED)

# 2. 公开头文件目录，供依赖 common 的目标使用
target_include_directories(common
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# 3. 指定库的源文件，方便IDE识别和项目管理
target_sources(common
    PRIVATE
        common.cpp
        num_sequence.cpp
        stack.cpp
        triangular.cpp
        triangular_iterator.cpp
        matrix.cpp
        mat.cpp
        audio_book.cpp
        lifo_stack.cpp
)

# 4. 指定库文件输出目录，避免默认输出路径污染其他目标
set_target_properties(common PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
)
