# 统一可执行文件输出目录
set(BIN_OUTPUT_DIR "${PROJECT_SOURCE_DIR}/bin")

# 创建单独的可执行文件 goodgay_build
add_executable(goodgay_build goodgay.cpp build.cpp)
set_target_properties(goodgay_build PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${BIN_OUTPUT_DIR}"
)

# 批量生成章节程序的可执行目标
set(CHAPTERS 02 03 04 05 06)

foreach(chapter IN LISTS CHAPTERS)
    set(target chapter_${chapter})
    add_executable(${target} chapter_${chapter}.cpp)

    # 链接 common 库，自动继承头文件路径
    target_link_libraries(${target} PRIVATE common)

    # 设置可执行文件输出目录
    set_target_properties(${target} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${BIN_OUTPUT_DIR}"
    )
endforeach()
