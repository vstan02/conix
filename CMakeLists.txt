cmake_minimum_required(VERSION 3.17)
project(conix C)

set(CMAKE_C_STANDARD 11)

set(
    CONIX_SOURCES
    src/conix.c
    src/option.c
    src/list.c
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(conix include/conix.h ${CONIX_SOURCES})

add_executable(demo demo/main.c)
target_link_libraries(demo conix)
