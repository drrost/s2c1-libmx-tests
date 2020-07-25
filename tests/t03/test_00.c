
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_print_strarr";

// Tests

void test_print_strarr_basic() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = "|";
    intercept_stdout();

    // When

    TRY
        mx_print_strarr(arr, delim);
    CATCH;

    // Then
    restore_stdout();
    ASSERT_EQUALS_STR("a|b|c\n", STDOUT_BUFF);
}

void test_print_strarr_arr_null() {
    // Given
    char **arr = 0;
    char *delim = "|";

    // When
    TRY
        mx_print_strarr(arr, delim);
    CATCH;

    // Then
}

void test_print_strarr_delim_null() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = 0;

    // When
    TRY
        mx_print_strarr(arr, delim);
    CATCH;

    // Then
}

void test_print_strarr_delim_empty() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = "";
    intercept_stdout();

    // When
    TRY
        mx_print_strarr(arr, delim);
    CATCH;

    // Then
    restore_stdout();
    ASSERT_EQUALS_STR("abc\n", STDOUT_BUFF)
}

void test_print_strarr_delim_newline() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = "\n";
    intercept_stdout();

    // When
    mx_print_strarr(arr, delim);

    // Then
    restore_stdout();
    ASSERT_EQUALS_STR("a\nb\nc\n", STDOUT_BUFF)
}

// delim with non printable symbols
