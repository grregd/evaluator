
set( TARGET_NAME TestStaticDispatcher )

include_directories( ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/tests/gtest/gtest-1.7.0/include )

add_executable( ${TARGET_NAME}
    main.cc
    ${CMAKE_SOURCE_DIR}/src/staticdispatcher.hh
)

target_link_libraries( ${TARGET_NAME}
    gtest
    gtest_main )

add_test( ${TARGET_NAME} ${TARGET_NAME} )
