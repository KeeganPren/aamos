#
# Top level CMakeLists.txt file for AAMOS.
#
# Copyright (c) 2025 Keegan Prendergast
#
cmake_minimum_required( VERSION 3.25 )

project( AAMOS
	 	 VERSION 0.1.0
	 	 DESCRIPTION "Another AVR Microcontroller Operating System"
	 	 HOMEPAGE_URL "http://github.com/KeeganPren/aamos" )

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include( MultiConfigSetup )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_FLAGS "-Wall")
set( CMAKE_CXX_FLAGS_RELEASE "-O2 -Werror" )
set( CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fprofile-arcs -ftest-coverage" )

# Use Doxygen for documentation.
find_package( Doxygen )

doxygen_add_docs( doc src lib )

add_subdirectory( src )
add_subdirectory( test )

include( CTest )