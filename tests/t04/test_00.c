
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_printint";

// Tests

void test_print_int_25() {
    // Given
    int n = 25;
    intercept_stdout();

    // When
    mx_printint(n);

    // Then
    restore_stdout();
    ASSERT_EQUALS_STR("25", STDOUT_BUFF);
}

void test_print_int_2147483647() {
    // Given
    int n = 2147483647;
    intercept_stdout();

    // When
    mx_printint(n);

    // Then
    restore_stdout();
    ASSERT_STDOUT_EQUALS("2147483647");
}

void test_print_int_minus2147483648() {
    // Given
    int n = -2147483648;
    intercept_stdout();

    // When
    mx_printint(n);

    // Then
    restore_stdout();
    ASSERT_STDOUT_EQUALS("-2147483648")
}

void test_print_int_minus12345() {
    // Given
    int n = -12345;
    intercept_stdout();

    // When
    mx_printint(n);

    // Then
    restore_stdout();
    ASSERT_STDOUT_EQUALS("-12345");
}
