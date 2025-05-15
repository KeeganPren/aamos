//
// Copyright (c) 2025 Keegan Prendergast
//
#include <gtest/gtest.h>

#include "Task.hpp"
#include "Scheduler.hpp"

using namespace testing;

class SchedulerTests : public Test {
    public:
        Task task1;
        Task task2;
        Scheduler scheduler;
};

TEST_F( SchedulerTests, SchedulerInitialStateIsReady ) {
    EXPECT_EQ( scheduler.getState( ), SCHEDULER_READY );
}

TEST_F( SchedulerTests, SchedulerTasksCanBeAdded ) {
    EXPECT_EQ( scheduler.addTask( task1 ), 1 );
    EXPECT_EQ( scheduler.addTask( task2 ), 2 );
}

TEST_F( SchedulerTests, SchedulerCanBeStarted ) {
    EXPECT_EQ( scheduler.run( ), SCHEDULER_RUNNING );
}