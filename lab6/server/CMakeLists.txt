cmake_minimum_required(VERSION 3.10)
project(server)

# Set the C++ standard and ensure it's required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Threads package, required for this project
find_package(Threads REQUIRED)
file(GLOB UTILS_SORUCES "../utils/*.cpp")
# If the pthreads paths are set, include and link them
if(DEFINED PTHREADS_INCLUDE_DIR AND DEFINED PTHREADS_LIBRARY_DIR)
    include_directories(${PTHREADS_INCLUDE_DIR})
    link_directories(${PTHREADS_LIBRARY_DIR})
endif()

# Add the server executable
add_executable(server server.cpp ${UTILS_SORUCES})

# Link the Threads library with the server executable
target_link_libraries(server PRIVATE Threads::Threads)

# Optionally, if you're explicitly using pthreads and need to set flags specifically for them
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(server PUBLIC "-pthread")
  target_link_libraries(server PUBLIC "-pthread")
endif()
