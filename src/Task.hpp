//
// Copyright (c) 2024 Keegan Prendergast
//

enum TaskState { READY, RUNNING, BLOCKED };

class Task {
    public:
        Task( void);
        void setState( TaskState );
        TaskState getState( void );

    private:
        TaskState current_state;
};