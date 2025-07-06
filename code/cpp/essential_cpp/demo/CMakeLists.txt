# 1. 输出目录别乱全局设，统一给每个目标定制：
set(BIN_OUTPUT_DIR "${PROJECT_SOURCE_DIR}/bin")

# 2. 好基友一起创建，先不重复写重复的头文件路径
# common 库已经公开了头文件路径，这里不用额外 include_directories

# 3. 创建两个exe，goodgay_build单独处理
add_executable(goodgay_build goodgay.cpp build.cpp)
set_target_properties(goodgay_build PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
)

# 4. 章节程序列表，批量创建
set(CHAPTERS 02 03 04 05 06)

foreach(chapter ${CHAPTERS})
    set(target chapter_${chapter})
    add_executable(${target} chapter_${chapter}.cpp)

    target_link_libraries(${target} PRIVATE common)

    set_target_properties(${target} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
    )
endforeach()
