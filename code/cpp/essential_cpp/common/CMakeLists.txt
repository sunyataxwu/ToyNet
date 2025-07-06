# 1. 定义库目标，先不列源码
add_library(common SHARED)

# 2. 头文件路径只暴露给依赖 common 的目标
target_include_directories(common
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# 3. 源文件明确告诉目标，方便IDE识别和管理
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

# 4. 独立设置库输出目录，避免影响其他目标
set_target_properties(common PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
)
