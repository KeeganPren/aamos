//!
//! AAMOS Task
//!
//! The Task is the basic unit of work in AAMOS.
//!
//! Copyright (c) 2024 Keegan Prendergast
//!

//! TaskState Enumeration...
enum TaskState { 
    READY,   //!< The task is ready to run.
    RUNNING, //!< The task is currently running.
    BLOCKED  //!< The task is blocked on an external event.
};

//!
//! Welcome to the Task class!
//!
//! These are the details.  I need to talk about the class here a lot.
//!
class Task {
    public:
        Task( void );

        //! Sets the new state of the task.
        //! @param newState is the new state of the task.
        void setState( TaskState newState );

        //! Provides the current state of the task.
        //! @return The current state of the task.
        TaskState getState( void );

        unsigned int getPriority( void );

        void setPriority( unsigned int newPriority );

    private:
        TaskState current_state;
        unsigned int priority;
};