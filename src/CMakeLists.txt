set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.h" "*.cpp")

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_lib PRIVATE drogon)