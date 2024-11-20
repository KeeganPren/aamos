enable_testing( )

include_directories( ../src )

add_executable( TaskTest TaskTest.cpp ../src/Task.cpp )

target_link_libraries( TaskTest GTest::gtest_main )

include( GoogleTest )
gtest_discover_tests( TaskTest )
