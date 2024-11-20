//
// Copyright (c) 2024 Keegan Prendergast
//

#include "Task.hpp"

Task::Task( void ): current_state(READY) { }

void Task::setState( TaskState newState ) {
    this->current_state = newState;
    return; 
}

TaskState Task::getState( void ) {
    return this->current_state;
}