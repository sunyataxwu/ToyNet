# ===== demo/CMakeLists.txt =====
# 把可执行章节分两拨：不依赖 / 依赖 common
set(CH_NO_COMMON  02 03)
set(CH_WITH_COMMON 04 05 06 07 11 12 13)

# 输出统一放到 <repo>/bin，但“只管自己，不管别人”
foreach(ch ${CH_NO_COMMON})
    set(tgt ch_${ch})
    add_executable(${tgt} chapter_${ch}.cpp)

    set_target_properties(${tgt} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
    )
endforeach()

foreach(ch ${CH_WITH_COMMON})
    set(tgt ch_${ch})
    add_executable(${tgt} chapter_${ch}.cpp)

    target_link_libraries(${tgt} PRIVATE common)    # 头文件路径自动继承
    set_target_properties(${tgt} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
    )
endforeach()
