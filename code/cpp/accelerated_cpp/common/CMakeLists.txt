# ===== common/CMakeLists.txt =====
# 1. 目标先行：声明共享库
add_library(common SHARED)

# 2. 头文件可见范围 —— 只暴露给链接到 common 的伙计
target_include_directories(common
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}       # vec.hpp 等头文件就在这
)

# 3. 把源文件塞给目标；重复 / 多余统统剔除
target_sources(common
    PRIVATE
        str.cpp
        str_util.cpp
        grade.cpp
        median.cpp
        student_info.cpp
        grammar.cpp
        core.cpp
        grad.cpp
        picture.cpp
        picture_derived.cpp
    PUBLIC
        vec.hpp                               # 外部目标需要 include 的头
)

# 4. 只改自己，不污染其他库的输出目录
set_target_properties(common PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
)

# 5. （可选）安装规则 —— 若以后要被 find_package 用到
# install(TARGETS common
#         EXPORT  accelerated_cppTargets
#         ARCHIVE DESTINATION lib
#         LIBRARY DESTINATION lib
#         RUNTIME DESTINATION bin)
# install(FILES vec.hpp DESTINATION include)
