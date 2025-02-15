//
// Copyright (c) 2024 Keegan Prendergast
//

#include "Task.hpp"

Task::Task( void ): current_state( TASK_READY ), priority( 500 ) { }

void Task::setState( TaskState newState ) {
    this->current_state = newState;
    return; 
}

TaskState Task::getState( void ) {
    return this->current_state;
}

unsigned int Task::getPriority( void ) {
    return this->priority;
}

void Task::setPriority( unsigned int newPriority ) {
    if( newPriority >= 1 && newPriority <= 1000 ) {
        this->priority = newPriority;
    }
    else {
        this->priority = 0xFFFF;
    }

    return;
}