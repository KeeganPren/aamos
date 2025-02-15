add_executable( aamos ApplicationMain.cpp Task.cpp Scheduler.cpp )

add_library( Task Task.cpp )
add_library( Scheduler Scheduler.cpp )