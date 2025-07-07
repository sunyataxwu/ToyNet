# 统一可执行文件输出目录
set(BIN_OUTPUT_DIR "${PROJECT_SOURCE_DIR}/bin")

# 列出所有可执行目标（习题）
set(EXE_LIST
    ex_2_6
    ex_3_1
    ex_3_2
    ex_3_3
    ex_3_4
    ex_5_2
    ex_6_2
)

# 批量生成可执行文件，链接 common 库
foreach(exe IN LISTS EXE_LIST)
    add_executable(${exe} "${exe}.cpp")

    # 依赖 common，自动继承头文件路径等设置
    target_link_libraries(${exe} PRIVATE common)

    # 统一设置可执行文件输出目录
    set_target_properties(${exe} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${BIN_OUTPUT_DIR}"
    )
endforeach()
