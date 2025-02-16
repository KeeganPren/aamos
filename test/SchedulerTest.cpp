//
// Copyright (c) 2025 Keegan Prendergast
//
#include <gtest/gtest.h>

#include "Task.hpp"
#include "Scheduler.hpp"

using namespace testing;

class SchedulerTests : public Test {
    public:
        Task task;
        Scheduler scheduler;
};

TEST_F( SchedulerTests, SchedulerInitialStateIsReady ) {
    EXPECT_EQ( scheduler.getState( ), SCHEDULER_READY );
}
TEST_F( SchedulerTests, SchedulerTaskCanBeAdded ) {
    EXPECT_EQ( scheduler.addTask( task ), 1 );
}

TEST_F( SchedulerTests, SchedulerCanBeStarted ) {
    EXPECT_EQ( scheduler.run( ), SCHEDULER_RUNNING );
}