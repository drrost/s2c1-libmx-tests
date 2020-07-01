#!/bin/bash

# Check mandatory files/folders exist
MANDATORY_FILES="src/ inc/ inc/libmx.h obj/ Makefile"
PATH_TO_SRC='../src/'
./scripts/check_files_exist.sh $PATH_TO_SRC "$MANDATORY_FILES"

# Check if only available files/folders are in the project

# Check there are no unavailable functions used
AVAILABLE_FUNCTIONS=(open write)
