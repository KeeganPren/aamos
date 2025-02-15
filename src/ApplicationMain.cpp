//
// Copyright (c) 2025 Keegan Prendergast
//

#include "Task.hpp"
#include "Scheduler.hpp"

int main( void ) {
    Task idleTask;
    Scheduler OS;

    OS.addTask( idleTask );
    OS.run( );

    return 0;
}