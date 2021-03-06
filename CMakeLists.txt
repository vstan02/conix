cmake_minimum_required(VERSION 3.16)
project(CONIX C)

set(CMAKE_C_STANDARD 11)

set(
    CONIX_SOURCES
    src/conix.c
    src/common.c
    src/options.c
    src/info.c
    src/handlers.c
)

set(
    CONIX_TESTS
    test/info_test.c
    test/handlers_test.c
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(conix ${CONIX_SOURCES})

find_package(PkgConfig)
pkg_check_modules(GLIB REQUIRED glib-2.0)

include_directories(${GLIB_INCLUDE_DIRS})
link_directories(${GLIB_LIBRARY_DIRS})

add_definitions(${GLIB_CFLAGS_OTHER})

add_executable(demo demo/main.c)
target_link_libraries(demo conix)

add_executable(test test/main.c ${CONIX_TESTS})
target_link_libraries(test conix ${GLIB_LIBRARIES})

install(FILES include/conix.h DESTINATION include)
install(TARGETS conix ARCHIVE DESTINATION lib)
