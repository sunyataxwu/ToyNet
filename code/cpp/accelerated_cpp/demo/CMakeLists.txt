# ===== demo/CMakeLists.txt =====

# 章节分组：不依赖 common 和 依赖 common
set(CH_NO_COMMON  02 03)
set(CH_WITH_COMMON 04 05 06 07 11 12 13)

# 统一输出目录
set(DEMO_OUTPUT_DIR "${PROJECT_SOURCE_DIR}/bin")

# 生成不依赖 common 的可执行文件
foreach(ch IN LISTS CH_NO_COMMON)
    set(tgt ch_${ch})
    add_executable(${tgt} chapter_${ch}.cpp)

    set_target_properties(${tgt} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${DEMO_OUTPUT_DIR}"
    )
endforeach()

# 生成依赖 common 的可执行文件
foreach(ch IN LISTS CH_WITH_COMMON)
    set(tgt ch_${ch})
    add_executable(${tgt} chapter_${ch}.cpp)

    target_link_libraries(${tgt} PRIVATE common)  # 自动继承头文件路径等信息

    set_target_properties(${tgt} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${DEMO_OUTPUT_DIR}"
    )
endforeach()
