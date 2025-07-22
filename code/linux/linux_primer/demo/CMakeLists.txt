# ===== demo/CMakeLists.txt =====

# 添加可执行程序
add_executable(demo_test test.c)

# 可选：如果需要链接库，可以在这里添加 target_link_libraries(demo_test xxx)
set_target_properties(demo_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
