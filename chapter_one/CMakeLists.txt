include_directories(${CMAKE_SOURCE_DIR}/tools/printlog/)
include_directories(${CMAKE_SOURCE_DIR}/tools/tests_framework/)
include_directories(${CMAKE_SOURCE_DIR}/data_structures/)


set(TEST_SOURCES
${CMAKE_SOURCE_DIR}/tools/tests_framework/test.cpp
${CMAKE_SOURCE_DIR}/tools/printlog/printlog.cpp
)

add_executable(Ex1.1 ex1.cpp ${TEST_SOURCES})
add_executable(Ex1.2 ex2.cpp ${TEST_SOURCES})
add_executable(Ex1.3 ex3.cpp ${TEST_SOURCES})
add_executable(Ex1.4 ex4.cpp ${TEST_SOURCES})
add_executable(Ex1.5 ex5.cpp ${TEST_SOURCES})
add_executable(Ex1.6 ex6.cpp ${TEST_SOURCES})
add_executable(Ex1.7 ex7.cpp ${TEST_SOURCES})
add_executable(Ex1.8 ex8.cpp ${TEST_SOURCES})

configure_file(run_all.sh ${CMAKE_CURRENT_BINARY_DIR}/run_all.sh COPYONLY)
