
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
add_executable(ch_02 chapter_02.cpp)
add_executable(ch_03 chapter_03.cpp)

include_directories(../common)

add_executable(ch_04 chapter_04.cpp)
target_link_libraries(ch_04 common)

add_executable(ch_05 chapter_05.cpp)
target_link_libraries(ch_05 common)

add_executable(ch_06 chapter_06.cpp)
target_link_libraries(ch_06 common)

add_executable(ch_07 chapter_07.cpp)
target_link_libraries(ch_07 common)

add_executable(ch_11 chapter_11.cpp)
target_link_libraries(ch_11 common)

add_executable(ch_12 chapter_12.cpp)
target_link_libraries(ch_12 common)

add_executable(ch_13 chapter_13.cpp)
target_link_libraries(ch_13 common)