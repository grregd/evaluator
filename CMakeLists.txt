message("CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")

cmake_minimum_required(VERSION 2.8)
enable_testing()

set( GTEST_SOURCE_DIR ${CMAKE_SOURCE_DIR}/tests/gtest/gtest-1.7.0 )
SET(CMAKE_CXX_FLAGS "-std=c++0x")

include_directories( ${CMAKE_SOURCE_DIR}/src )

set( EESOURCES
    ${CMAKE_SOURCE_DIR}/src/exprtoken.hh
    ${CMAKE_SOURCE_DIR}/src/evaluators.hh
    ${CMAKE_SOURCE_DIR}/src/evaluators.cc
    ${CMAKE_SOURCE_DIR}/src/operations.cc
    ${CMAKE_SOURCE_DIR}/src/operations.hh
    ${CMAKE_SOURCE_DIR}/src/operands.hh
    ${CMAKE_SOURCE_DIR}/src/operands.cc
    ${CMAKE_SOURCE_DIR}/src/Factory.hh
    ${CMAKE_SOURCE_DIR}/src/Factory.cc
    ${CMAKE_SOURCE_DIR}/src/Tokenizer.hh
    ${CMAKE_SOURCE_DIR}/src/Tokenizer.cc
)


add_executable( main
    main.cc
    ${EESOURCES}
#    operations.cc
#    operands.cc
#    evaluators.cc
)

add_subdirectory( tests )
