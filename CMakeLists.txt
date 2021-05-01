cmake_minimum_required(VERSION 3.16)
project(math_server)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_MACOSX_RPATH 1)

#add_subdirectory(lib/drogon)
add_subdirectory(lib/googletest)
