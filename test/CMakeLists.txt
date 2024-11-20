enable_testing( )

add_executable( foo test.cxx )

target_link_libraries( foo GTest::gtest_main )

include( GoogleTest )
gtest_discover_tests( foo )
