
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_print_strarr";

// Tests

void test_print_strarr_basic() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = "|";
    INTERCEPT_STDOUT;

    // When
    mx_print_strarr(arr, delim);

    // Then
    RESTORE_STDOUT;
    ASSERT_EQUALS_STR("a|b|c\n", buf);
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

void test_print_strarr_delim_empty() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = "";
    INTERCEPT_STDOUT;

    // When
    mx_print_strarr(arr, delim);

    // Then
    RESTORE_STDOUT;
    ASSERT_EQUALS_STR("abc\n", buf)
}

void test_print_strarr_delim_newline() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = "\n";
    INTERCEPT_STDOUT;

    // When
    mx_print_strarr(arr, delim);

    // Then
    RESTORE_STDOUT;
    ASSERT_TRUE(strcmp("a\nb\nc\n", buf) == 0);
}

// delim with non printable symbols
