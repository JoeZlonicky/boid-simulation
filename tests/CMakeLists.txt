enable_testing()
add_executable(ik-demo-tests
        "main.cpp"
        "testing_utility.h"
        "test_vector_3.cpp"
        "test_vector_4.cpp"
        "test_point_3.cpp"
        "test_matrix_4.cpp"
)

target_link_libraries(ik-demo-tests gtest gtest_main)

