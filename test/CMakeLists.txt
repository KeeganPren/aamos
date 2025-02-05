enable_testing( )

include_directories( ../src )

add_executable( TaskTest TaskTest.cpp ../src/Task.cpp )
add_executable( SchedulerTest SchedulerTest.cpp ../src/Scheduler.cpp )

target_link_libraries( TaskTest GTest::gtest_main )
target_link_libraries( SchedulerTest GTest::gtest_main )

include( GoogleTest )
gtest_discover_tests( TaskTest )
gtest_discover_tests( SchedulerTest )
