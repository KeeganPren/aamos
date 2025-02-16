#
# Copyright (c) 2025 Keegan Prendergast
# 

# Generate the build files
cmake -S . -B build

# Generate the build
cmake --build build

# Run the tests
cd build; ctest -T Test -T Coverage; cd ..

# Generate and cleanup to coverage data
lcov --directory build --capture --output-file coverage.info
lcov --remove coverage.info '/usr/*' --output-file coverage.info
genhtml -o coverage coverage.info

# Generate documentation
cd build; make doc; cd ..