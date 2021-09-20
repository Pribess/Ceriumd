cmake_minimum_required(VERSION 3.0)

project(Ceriumd)

set(TARGET ceriumd)

set (CMAKE_CXX_STANDARD 20)

if(MINGW)
    add_compile_definitions(WIN32)
endif()


include_directories(src/)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

include_directories(deps/sqlite)
list(APPEND LIB_FILES deps/sqlite/sqlite3.c)


file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(
    ${TARGET}
    ${SRC_FILES}
    ${LIB_FILES}
)

if (APPLE)
    target_link_libraries(
    ${TARGET}
    ${OPENSSL_LIBRARIES}
    )
elseif(UNIX)
    target_link_libraries(
    ${TARGET}
    ${OPENSSL_LIBRARIES}
    )
elseif(MINGW)
    target_link_libraries(
    ${TARGET}
    )
endif()