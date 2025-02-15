# Download and setup GoogleTest
include( FetchContent )
FetchContent_Declare(
	googletest
	URL http://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set( gtest_force_shared_crt ON CACHE BOOL "" FORCE )
FetchContent_MakeAvailable(googletest)

enable_testing( )

include_directories( ../src )

add_executable( TaskTest TaskTest.cpp )
add_executable( SchedulerTest SchedulerTest.cpp )

target_link_libraries( TaskTest Task GTest::gtest_main )
target_link_libraries( SchedulerTest Scheduler Task GTest::gtest_main )

include( GoogleTest )
gtest_discover_tests( TaskTest )
gtest_discover_tests( SchedulerTest )

include( CTest )