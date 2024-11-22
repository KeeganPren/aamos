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

        //! Sets the new priority of the task.
        //! @param newPriority is an integer in [1..1000] representing the task's new priority.
        void setPriority( unsigned int newPriority );

        //! Provides the current priotiry of the task.
        //! @return The current priority of the task as an integer in [1..1000].
        unsigned int getPriority( void );



    private:
        TaskState current_state;
        unsigned int priority;
};