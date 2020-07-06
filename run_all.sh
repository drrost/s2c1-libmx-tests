#!/bin/bash

# Check mandatory files/folders exist
MANDATORY_FILES="src/ inc/ inc/libmx.h Makefile"
PATH_TO_SRC='../src/'
./scripts/check_files_exist.sh $PATH_TO_SRC "$MANDATORY_FILES"

# Check if only available files/folders are in the project

# Check there are no unavailable functions used
AVAILABLE_FUNCTIONS=(open write)

# ----

# Run the Makefile
ROOT_DIR=$(echo $PWD)
LIB_NAME="libmx.a"
LIB_INC_NAME="libmx.h"
cd ../src/
make
mv ./obj/$LIB_NAME $ROOT_DIR/
cp ./inc/$LIB_INC_NAME $ROOT_DIR/
make clean
cd $ROOT_DIR

# Run all the tests

TEST_FOLDERS=$(ls -d tests/t*/)

for FOLDER in $TEST_FOLDERS
do
    echo $FOLDER
    cd $FOLDER
    ./run.sh $PWD/$LIB_NAME
    cd ../..
done

# Utils pack
# tUtils
#   test_mx_printchar
#     ./run_tests.sh
#   test_mx_print_unicode
#     ./run_tests.sh
#   test_mx_print_str
#     ./run_tests.sh
#   test_mx_print_strarr
#     ./run_tests.sh

# Strings pack
# tStrings

# Memory pack
# tMemory

# List pack
# tList

# Every function has it own tests set.

#rm -f $LIB_NAME