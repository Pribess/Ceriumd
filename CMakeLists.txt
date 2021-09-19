cmake_minimum_required(VERSION 3.0)

project(Ceriumd)

set(TARGET ceriumd)

file(GLOB SRC_FILES src/*.cpp)

add_executable(
    ${TARGET}
    ${SRC_FILES}
)

include_directories(src/)

if (APPLE)
    target_link_libraries(${TARGET})
elseif(UNIX)
    target_link_libraries(${TARGET})
elseif(MINGW)
    target_link_libraries(${TARGET})
endif()