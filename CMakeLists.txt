cmake_minimum_required(VERSION 3.17)
project(conix C)

set(CMAKE_C_STANDARD 11)

set(CONIX_SOURCES src/conix.c src/list.c src/set.h src/set.c)

set(CONIX_TESTS test/list_test.c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(conix ${CONIX_SOURCES})

add_executable(demo demo/main.c)
target_link_libraries(demo conix)

add_executable(test test/main.c ${CONIX_TESTS})
target_link_libraries(test conix)

# GTK3
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)

include_directories(${GLIB_INCLUDE_DIRS})
link_directories(${GLIB_LIBRARY_DIRS})

add_definitions(${GLIB_CFLAGS_OTHER})

target_link_libraries(test ${GLIB_LIBRARIES})
