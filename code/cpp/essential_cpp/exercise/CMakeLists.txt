set(BIN_OUTPUT_DIR "${PROJECT_SOURCE_DIR}/bin")

set(EXE_LIST
    ex_2_6
    ex_3_1
    ex_3_2
    ex_3_3
    ex_3_4
    ex_5_2
    ex_6_2
)

foreach(exe IN LISTS EXE_LIST)
    add_executable(${exe} "${exe}.cpp")
    target_link_libraries(${exe} PRIVATE common)
    # common库已经暴露了头文件路径，这里不必再写 target_include_directories

    set_target_properties(${exe} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
    )
endforeach()
