//
// Copyright (c) 2024 Keegan Prendergast
//
#include <gtest/gtest.h>

#include "Task.hpp"

using namespace testing;

TEST( TaskTests, TaskInitialStateIsReady ) {
    Task task;

    EXPECT_EQ( task.getState( ), READY );
}

TEST( TaskTEST, TaskStateCanBeSetAndQueried ) {
    Task task;

    task.setState( RUNNING );
    EXPECT_EQ( task.getState( ), RUNNING );
}