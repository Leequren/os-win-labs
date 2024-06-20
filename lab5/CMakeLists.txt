cmake_minimum_required(VERSION 3.10)
project(lab5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab5 main.cpp)

add_custom_target(run
    COMMAND lab5
    DEPENDS lab5
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
