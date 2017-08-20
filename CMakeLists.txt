cmake_minimum_required (VERSION 2.8.11)
project (Coding_interview)
set (CMAKE_CXX_STANDARD 11)

add_subdirectory (data_structures)
add_subdirectory (chapter_one)
add_subdirectory (chapter_two)

configure_file(run_all.sh ${CMAKE_CURRENT_BINARY_DIR}/run_all.sh COPYONLY)
