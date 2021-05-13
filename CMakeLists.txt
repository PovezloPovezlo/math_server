cmake_minimum_required(VERSION 3.16)
project(math_server)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)


set(ENABLE_DROGON 1)

set(CMAKE_MACOSX_RPATH 1)

IF(ENABLE_DROGON)
    IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/lib/drogon)
        add_subdirectory(lib/drogon)
        message(STATUS "Drogon library found. You will be able to run web server")
    ELSE()
        message(WARNING "Drogon library not found. It will compile, but you will not be able to run web server")
    ENDIF()
ENDIF()

add_subdirectory(lib/googletest)