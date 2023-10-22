enable_testing()
add_executable(ik-demo-tests
        main.cpp
        testing_utility.h
        ../src/math/vector_3.h
        ../src/math/vector_3.cpp
        test_vector_3.cpp
        ../src/math/vector_4.h
        ../src/math/vector_4.cpp
        test_vector_4.cpp
        ../src/math/matrix_4.h
        ../src/math/matrix_4.cpp
        test_matrix_4.cpp
        ../src/math/quaternion.h
        ../src/math/quaternion.cpp
        test_quaternion.cpp
)

target_link_libraries(ik-demo-tests gtest gtest_main)

