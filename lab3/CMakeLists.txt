cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB UTILS_FILES "utils/*.cpp")

add_executable(lab3 main.cpp ${UTILS_FILES})

add_custom_target(run
    COMMAND lab3
    DEPENDS lab3
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
