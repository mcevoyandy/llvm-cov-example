#!/bin/bash
# Generate coverage reports
#
# Args: $1 - Path to the build directory. NOTE: Don't include the trailing slash!

echo -e "Generating HTML coverage reports..."

# Set variable to store the path to the build directory and current directory
echo -e "BUILD_DIR=$1"
BUILD_DIR="$1"
CURRENT_DIR=$(pwd)

# Run the unit tests to include in the report
cd $BUILD_DIR

# Set location where raw coverage data will be stored. NOTE: This should be set for each executable being run.
export LLVM_PROFILE_FILE="$BUILD_DIR/cool_stuff_unit_tests.profraw"
echo -e "LLVM_PROFILE_FILE=$LLVM_PROFILE_FILE"
./cool_stuff_unit_tests

export LLVM_PROFILE_FILE="$BUILD_DIR/other_stuff_unit_tests.profraw"
echo -e "LLVM_PROFILE_FILE=$LLVM_PROFILE_FILE"
./other_stuff_unit_tests

# Generate the HTML coverage reports
cd $BUILD_DIR

# To include multiple results from multiple tests, we need to merge the raw data files
llvm-profdata merge -sparse cool_stuff_unit_tests.profraw other_stuff_unit_tests.profraw -o default.profdata

# Then we must generate the HTML report pointing to the merged data file and the object files
llvm-cov show -instr-profile=default.profdata \
    -format=html -output-dir=html \
    -ignore-filename-regex="build" \
    -show-branches=count -show-regions \
    -show-mcdc-summary -show-mcdc \
    -object=./cool_stuff_unit_tests \
    -object=./other_stuff_unit_tests
echo -e "Coverage report generated at $BUILD_DIR/html/index.html"

# Return to where we started
cd $CURRENT_DIR
