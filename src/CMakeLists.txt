set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.h" "*.cpp")

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

IF(ENABLE_DROGON)
    IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../lib/drogon)
        target_link_libraries(${BINARY}_run PUBLIC ${CMAKE_PROJECT_NAME}_lib drogon)
        target_link_libraries(${CMAKE_PROJECT_NAME}_lib PUBLIC drogon) # без этой строки CLion не понимает, что библиотека подключена
    ENDIF()
ENDIF()