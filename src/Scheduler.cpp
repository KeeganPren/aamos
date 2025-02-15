//
// Copyright (c) 2025 Keegan Prendergast
//

#include "Scheduler.hpp"

Scheduler::Scheduler( void ): current_state( SCHEDULER_READY ) { }

unsigned int Scheduler::addTask( Task newTask ) {
    return 0;
}

SchedulerState Scheduler::run( void ) {
    this->current_state = SCHEDULER_RUNNING;
    
    return this->current_state;
}

SchedulerState Scheduler::getState( void ) {
    return this->current_state;
}
