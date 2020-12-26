cmake_minimum_required(VERSION 3.17)
project(conix C)

set(CMAKE_C_STANDARD 11)

set(
    CONIX_SOURCES
    src/conix.c
    src/list.c
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(conix ${CONIX_SOURCES})

add_executable(demo demo/main.c)
target_link_libraries(demo conix)

add_executable(test test/main.c test/list_test.c)
target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(test conix)

# GTK3
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(test ${GTK3_LIBRARIES})
