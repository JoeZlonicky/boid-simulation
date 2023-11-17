include_directories(../external/glad/include)
include_directories(.)

set(SIMULATION_SOURCE_FILES
        sim/simulation.cpp
        sim/boid_simulation.cpp
        sim/boid.cpp)

set(ENGINE_SOURCE_FILES
        engine/camera.cpp
        sim/boid_simulation.cpp
        engine/model.cpp
        engine/shader.cpp
        engine/window.cpp
)

set(MATH_SOURCE_FILES
        math/matrix_3.cpp
        math/matrix_4.cpp
        math/transform.cpp
        math/quaternion.cpp
        math/vector_3.cpp
        math/vector_4.cpp
)

add_executable(boid-sim
        main.cpp
        ../external/glad/src/glad.c
        ${SIMULATION_SOURCE_FILES}
        ${ENGINE_SOURCE_FILES}
        ${MATH_SOURCE_FILES}
)

target_link_libraries(boid-sim glfw ${OPENGL_gl_LIBRARY})