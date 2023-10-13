enable_testing()
add_executable(ik-demo-tests
        "test_vector3.cpp"
        "main.cpp"
)

target_link_libraries(ik-demo-tests gtest gtest_main)

