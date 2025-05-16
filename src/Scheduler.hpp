//!
//! AAMOS Scheduler
//!
//! The Scheduler contains a list of tasks and is reposible for scheduling
//! the next task to run.
//!
//! Copyright (c) 2025 Keegan Prendergast
//!

#include "Task.hpp"

#include <list>



//!
//! Scheduler...
//!
//! The Devil is in the deails...
//!
class Scheduler {
    public:
        Scheduler( void );

        //!
        //! SchedulerState is an enumeration that defines the various states the Scheduler may be in.
        //!
        enum SchedulerState { 
            SCHEDULER_READY,    //!< The scheduler is ready to accept Tasks and then run.
            SCHEDULER_RUNNING   //!< The scheduler is running and swapping tasks according to priority.
        };

        //! Adds a Task to the scheduler for execution.
        //! @return The ID of the newly added task or SCHEDULER_ERROR.
        unsigned int addTask( Task newTask );

        //! Tells the scheduler to run with its current set of Tasks.
        //! @return The new state of the scheduler.
        SchedulerState run( void );

        //! Provides the current state of the scheduler.
        //! @return The current state of the scheduler.
        SchedulerState getState( void );
    
    private:
        SchedulerState current_state;
        std::list<Task> task_list;
};