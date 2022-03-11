cmake_minimum_required (VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)

project (escutils)

if(WIN32)

#use static runtime library for the entire project (because cryptopp)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

else()

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pthread")

endif()

include(libs.cmake)
add_subdirectory(src)
