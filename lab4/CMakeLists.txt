cmake_minimum_required(VERSION 3.10)
project(lab4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB UTILS_SOURCE "utils/*.cpp")

add_executable(lab4 main.cpp ${UTILS_SOURCE})

add_custom_target(run
    COMMAND lab4
    DEPENDS lab4
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
