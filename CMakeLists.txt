message("CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")

cmake_minimum_required(VERSION 2.8)
enable_testing()

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
)


add_executable( main 
    main.cc
    ${EESOURCES}
#    operations.cc
#    operands.cc
#    evaluators.cc
)

add_subdirectory( tests )
