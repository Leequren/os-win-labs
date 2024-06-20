cmake_minimum_required(VERSION 3.10) 
set(CMAKE_C_COMPILER "C:\\MinGW64\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\\MinGW64\\bin\\g++.exe")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MainProject)    
option(BUILD_LAB1 "BUILD_LAB1" OFF)
option(BUILD_LAB2 "BUILD_LAB2" OFF)
option(BUILD_LAB3 "BUILD_LAB3" OFF)
option(BUILD_LAB4 "BUILD_LAB4" OFF)
option(BUILD_LAB5 "BUILD_LAB5" OFF)
option(BUILD_LAB6 "BUILD_LAB6" OFF)

if(BUILD_LAB1)
    add_subdirectory(lab1)
endif()

if(BUILD_LAB2)
    add_subdirectory(lab2)
endif()

if(BUILD_LAB3)
    add_subdirectory(lab3)
endif()

if(BUILD_LAB4)
    add_subdirectory(lab4)
endif()

if(BUILD_LAB5)
    add_subdirectory(lab5)
endif()

if(BUILD_LAB6)
    add_subdirectory(lab6)
endif()