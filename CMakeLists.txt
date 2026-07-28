cmake_minimum_required(VERSION 3.28)
project(snake)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE snake_core)
