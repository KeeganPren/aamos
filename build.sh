#!/bin/bash
#
# Copyright (c) 2025 Keegan Prendergast
# 

#Defaults
BUILD_DIR='build'
GEN_DOCS=unset
COVERAGE=unset

usage()
{
  echo "Usage: build.sh [ -b | --build-dir BUILD_DIR ] [ -d | --with-docs ] [ -c | --with-coverage]"
  exit 2
}

# Parse the command line arguments.
PARSED_ARGUMENTS=$(getopt -a -n build.sh -o b:dc --long build-dir:,with-docs,with-coverage -- "$@")
VALID_ARGUMENTS=$?
if [ "$VALID_ARGUMENTS" != "0" ]; then
  usage
fi

eval set -- "$PARSED_ARGUMENTS"
while :
do
  case "$1" in
    -b | --build-dir) BUILD_DIR="$2" ; shift 2;;
    -d | --with-docs) GEN_DOCS=1; shift;;
    -c | --with-coverage) COVERAGE=1; shift;;
    --) shift; break ;;
    *) echo "Unexpected option: $1"
       usage ;;
  esac
done

# Generate the build files
cmake -S . -B $BUILD_DIR

# Generate the build
cmake --build $BUILD_DIR

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