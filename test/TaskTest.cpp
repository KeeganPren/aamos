//
// Copyright (c) 2024 Keegan Prendergast
//
#include <gtest/gtest.h>

#include "Task.hpp"

using namespace testing;

class TaskTests : public Test {
    public:
        Task task;
};

TEST_F( TaskTests, TaskInitialStateIsReady ) {
    EXPECT_EQ( task.getState( ), READY );
}

TEST_F( TaskTests, TaskStateCanBeSetAndQueried ) {
    task.setState( RUNNING );
    EXPECT_EQ( task.getState( ), RUNNING );

    task.setState( BLOCKED );
    EXPECT_EQ( task.getState( ), BLOCKED );

    task.setState( READY );
    EXPECT_EQ( task.getState( ), READY );
}

TEST_F( TaskTests, TaskInitialPriorityIs500 ) {
    EXPECT_EQ( task.getPriority( ), 500 );
}

TEST_F( TaskTests, TaskPriorityCanBeSetAndQueried ) {
    task.setPriority( 250 );
    EXPECT_EQ( task.getPriority( ), 250 );
}

TEST_F( TaskTests, TaskPriorityBetween1And1000Inclusive ) {
    task.setPriority( 1 );
    EXPECT_EQ( task.getPriority( ), 1 );

    task.setPriority( 1000 );
    EXPECT_EQ( task.getPriority( ), 1000 );

    task.setPriority( 0 );
    EXPECT_EQ( task.getPriority( ), 0xFFFF );

    task.setPriority( 1984 );
    EXPECT_EQ( task.getPriority( ), 0xFFFF );
}