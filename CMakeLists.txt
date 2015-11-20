message("CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")

cmake_minimum_required(VERSION 2.8)
enable_testing()

set( GTEST_SOURCE_DIR ${CMAKE_SOURCE_DIR}/tests/gtest/gtest-1.7.0 )
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories( ${CMAKE_SOURCE_DIR}/src )

file( GLOB_RECURSE EESOURCES ${CMAKE_SOURCE_DIR}/src/*.hh ${CMAKE_SOURCE_DIR}/src/*.cc )

add_executable( main main.cc ${EESOURCES} )

add_subdirectory( tests )
