
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_print_int_25() {
    // Given
    int n = 25;
    INTERCEPT_STDOUT;

    // When
    mx_printint(n);

    // Then
    RESTORE_STDOUT;
    ASSERT_TRUE(strcmp("25", buf) == 0);
}

void test_print_int_2147483647() {
    // Given
    int n = 2147483647;
    INTERCEPT_STDOUT;

    // When
    mx_printint(n);

    // Then
    RESTORE_STDOUT;
    ASSERT_STDOUT_EQUALS("2147483647");
}

void test_print_int_minus2147483648() {
    // Given
    int n = -2147483648;
    INTERCEPT_STDOUT;

    // When
    mx_printint(n);

    // Then
    RESTORE_STDOUT;
    ASSERT_STDOUT_EQUALS("-2147483648")
}

void test_print_int_minus12345() {
    // Given
    int n = -12345;
    INTERCEPT_STDOUT;

    // When
    mx_printint(n);

    // Then
    RESTORE_STDOUT;
    ASSERT_STDOUT_EQUALS("-12345");
}
