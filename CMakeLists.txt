cmake_minimum_required(VERSION 3.16)
project(CONIX C)

set(CMAKE_C_STANDARD 11)
set(CONIX_PUBLIC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CONIX_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CONIX_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

file(GLOB CONIX_PUBLIC "${CONIX_PUBLIC_DIR}/*.h")
file(GLOB CONIX_SOURCES "${CONIX_SOURCE_DIR}/*.c")
file(GLOB CONIX_TESTS "${CONIX_TEST_DIR}/*.c")

include_directories(${CONIX_PUBLIC_DIR})
include_directories(${CONIX_SOURCE_DIR})

add_library(conix ${CONIX_SOURCES})

find_package(PkgConfig)
pkg_check_modules(GLIB REQUIRED glib-2.0)

include_directories(${GLIB_INCLUDE_DIRS})
link_directories(${GLIB_LIBRARY_DIRS})

add_definitions(${GLIB_CFLAGS_OTHER})

add_executable(demo demo/main.c)
target_link_libraries(demo conix)

add_executable(test ${CONIX_TESTS})
target_link_libraries(test conix ${GLIB_LIBRARIES})

install(FILES ${CONIX_PUBLIC} DESTINATION include)
install(TARGETS conix ARCHIVE DESTINATION lib)
