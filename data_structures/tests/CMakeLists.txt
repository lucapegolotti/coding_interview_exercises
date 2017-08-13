add_executable(TestHashTable test_hash_table.cpp)
add_executable(TestLinkedList test_linked_list.cpp)

configure_file(test_all.sh ${CMAKE_CURRENT_BINARY_DIR}/test_all.sh COPYONLY)
