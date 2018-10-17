cmake_minimum_required(VERSION 3.12)
project(learning_opengl)

set(CMAKE_CXX_STANDARD 14)

find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

set(CMAKE_CXX_FLAGS "-framework OpenGL")

add_executable(learning_opengl main.cpp)
target_link_libraries(learning_opengl PRIVATE glfw glm GLEW::GLEW)
