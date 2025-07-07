# ===== common/CMakeLists.txt =====

# 1. 声明共享库目标 common
add_library(common SHARED)

# 2. 头文件路径 —— 暴露给链接 common 的目标（PUBLIC）
target_include_directories(common
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}   # common 目录下头文件（如 vec.hpp）
)

# 3. 源文件与头文件分开声明，明确所有权和可见性
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
        vec.hpp                       # 需要暴露给外部的头文件
)

# 4. 指定输出目录，避免污染其他目标
set_target_properties(common PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
)

# 5. （可选）安装配置，方便以后用 find_package 或发布
# install(TARGETS common
#         EXPORT accelerated_cppTargets
#         ARCHIVE DESTINATION lib
#         LIBRARY DESTINATION lib
#         RUNTIME DESTINATION bin)
# install(FILES vec.hpp DESTINATION include)
