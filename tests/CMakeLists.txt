enable_testing()

include_directories(../src)

set (FILES_TO_TEST
        ../src/math/matrix_3.cpp
        ../src/math/matrix_4.cpp
        ../src/math/quaternion.cpp
        ../src/math/vector_3.cpp
        ../src/math/vector_4.cpp
)

set (TEST_FILES
        test_matrix_4.cpp
        test_quaternion.cpp
        test_vector_3.cpp
        test_vector_4.cpp
)

add_executable(ik-demo-tests
        main.cpp
        testing_utility.h
        ${FILES_TO_TEST}
        ${TEST_FILES}
)

target_link_libraries(ik-demo-tests gtest gtest_main)

