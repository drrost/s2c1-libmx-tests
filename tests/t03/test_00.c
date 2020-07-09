
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_print_strarr_basic() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = "|";

    // When
    mx_print_strarr(arr, delim);

    // Then
}

void test_print_strarr_arr_null() {
    // Given
    char **arr = 0;
    char *delim = "|";

    // When
    mx_print_strarr(arr, delim);

    // Then
}

void test_print_strarr_delim_null() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = 0;

    // When
    mx_print_strarr(arr, delim);

    // Then
}

// arr null
// delim null
// empty delim
// delim with non printable symbols
