cmake_minimum_required(VERSION 3.10)
project(lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB UTILS_SOURCES "utils/*.cpp")

add_executable(lab1
    main.cpp
    ${UTILS_SOURCES}
)

add_custom_target(run
    COMMAND lab1
    DEPENDS lab1
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
