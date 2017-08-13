include_directories(${CMAKE_SOURCE_DIR}/tools/tests_framework)

set(TEST_SOURCES ${CMAKE_SOURCE_DIR}/tools/tests_framework/test.cpp)

add_executable(TestHashTable test_hash_table.cpp ${TEST_SOURCES})
add_executable(TestLinkedList test_linked_list.cpp ${TEST_SOURCES})

configure_file(test_all.sh ${CMAKE_CURRENT_BINARY_DIR}/test_all.sh COPYONLY)
