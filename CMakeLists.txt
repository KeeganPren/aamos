#
# Copyright (c) 2024 Keegan Prendergast
#
cmake_minimum_required( VERSION 3.25 )

project( AAMOS
	 	 VERSION 0.1.0
	 	 DESCRIPTION "Another AVR Microcontroller Operating System"
	 	 HOMEPAGE_URL "http://github.com/KeeganPren/aamos" )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

find_package( Doxygen )

# Download and setup GoogleTest
include( FetchContent )
FetchContent_Declare(
	googletest
	URL http://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set( gtest_force_shared_crt ON CACHE BOOL "" FORCE )
FetchContent_MakeAvailable(googletest)

enable_testing( )

add_subdirectory( src )
add_subdirectory( test )