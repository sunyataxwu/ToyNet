# ===== homework/CMakeLists.txt =====
# 0. 本目录专属可执行文件列表
set(HW_LIST
    hw_3_2
    hw_3_3
    hw_3_4
    hw_3_5
)

# 1. 把每个习题源文件一次性批量生成可执行目标
foreach(hw ${HW_LIST})
    add_executable(${hw} ${hw}.cpp)

    # 2. 依赖 common 库（来自顶层 add_subdirectory(common)）
    target_link_libraries(${hw} PRIVATE common)

    # 3. 把可执行文件统一丢进 <repo>/bin，不污染全局
    set_target_properties(${hw} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
    )
endforeach()
