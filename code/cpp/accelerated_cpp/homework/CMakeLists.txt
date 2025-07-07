# ===== homework/CMakeLists.txt =====

# 0. 本目录专属习题可执行文件列表
set(HW_LIST
    hw_3_2
    hw_3_3
    hw_3_4
    hw_3_5
)

# 1. 遍历列表，批量生成可执行目标
foreach(hw IN LISTS HW_LIST)
    add_executable(${hw} ${hw}.cpp)

    # 2. 依赖 common 库（确保顶层已 add_subdirectory(common)）
    target_link_libraries(${hw} PRIVATE common)

    # 3. 统一输出目录，避免产物分散
    set_target_properties(${hw} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
    )
endforeach()
