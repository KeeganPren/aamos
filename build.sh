#!/bin/bash
#
# Copyright (c) 2025 Keegan Prendergast
# 

#Defaults
BUILD_DIR='build'
BUILD_TYPE='Debug'
TARGET='local'
GEN_DOCS=unset
COVERAGE=unset

usage()
{
  echo "Usage: build.sh [ -b | --build-dir BUILD_DIR ] [ -o | --output-target TARGET]
                [ -t | --build-type BUILD_TYPE] [ -d | --with-docs ] [ -c | --with-coverage]"
  exit 2
}

# Parse the command line arguments.
PARSED_ARGUMENTS=$(getopt -a -n build.sh -o b:o:t:dc --long build-dir:,output-target:,with-docs,with-coverage,build-type: -- "$@")
VALID_ARGUMENTS=$?
if [ "$VALID_ARGUMENTS" != "0" ]; then
  usage
fi

eval set -- "$PARSED_ARGUMENTS"
while :
do
  case "$1" in
    -b | --build-dir) BUILD_DIR="$2"; shift 2;;
    -o | --output-target) TARGET="$2"; shift 2;;
    -t | --build_type) BUILD_TYPE="$2"; shift 2;;
    -d | --with-docs) GEN_DOCS=1; shift;;
    -c | --with-coverage) COVERAGE=1; shift;;
    --) shift; break ;;
    *) echo "Unexpected option: $1"
       usage ;;
  esac
done

export CMAKE_BUILD_TYPE=$BUILD_TYPE

# Generate the build files
if [ $TARGET = 'local' ]; then
  cmake -S . -B $BUILD_DIR
elif [ $TARGET = 'avr' ]; then
  cmake -DCMAKE_TOOLCHAIN_FILE="avr-toolchain.cmake" -S . -B $BUILD_DIR
else
  echo "Invalid TARGET specified: $TARGET"
  exit 2
fi

# Generate the build
cmake --build $BUILD_DIR -v

# Run the tests
cd $BUILD_DIR; ctest -T Test -T Coverage; cd ..

# Generate and cleanup to coverage data
if [ $COVERAGE = 1 ]; then
    lcov --directory $BUILD_DIR --capture --output-file coverage.info
    lcov --remove coverage.info '/usr/*' "$(pwd)/$BUILD_DIR/_deps/*" --output-file coverage.info
    genhtml -o coverage coverage.info
fi

# Generate documentation
if [ $GEN_DOCS = 1 ]; then
    cd $BUILD_DIR; make doc; cd ..
fi