
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

char *test_case_name = "mx_printchar";

void test_print_a() {
    // Given
    INTERCEPT_STDOUT;

    // When
    mx_printchar('a');

    // Then
    RESTORE_STDOUT;
    ASSERT_EQUALS('a', buf[0]);
}

void test_print_b() {
    // Given
    INTERCEPT_STDOUT;

    // When
    mx_printchar('b');

    // Then
    RESTORE_STDOUT;
    ASSERT_EQUALS('b', buf[0]);
}
