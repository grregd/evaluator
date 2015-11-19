
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set( TARGET_NAME_1 TestEvaluator )
set( TARGET_NAME_2 TestEvalExpression )
set( TARGET_NAME_3 TestTokenizer )

include_directories( ${CMAKE_SOURCE_DIR} ${GTEST_SOURCE_DIR}/include )

add_executable( ${TARGET_NAME_1}
    testeval.cc
    testparams.hh
    testparams.cc
    ${EESOURCES}
)

add_executable( ${TARGET_NAME_2}
    TestEvalExpression.hh
    TestEvalExpression.cc
    ${EESOURCES}
)

add_executable( ${TARGET_NAME_3}
    TestTokenizer.hh
    TestTokenizer.cc
    ${EESOURCES}
)

target_link_libraries( ${TARGET_NAME_1} gtest gtest_main )
target_link_libraries( ${TARGET_NAME_2} gtest gtest_main )
target_link_libraries( ${TARGET_NAME_3} gtest gtest_main )

add_test( ${TARGET_NAME_1} ${TARGET_NAME_1} )
add_test( ${TARGET_NAME_2} ${TARGET_NAME_2} )
add_test( ${TARGET_NAME_3} ${TARGET_NAME_3} )
