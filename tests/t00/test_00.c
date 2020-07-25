
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

char *test_case_name = "mx_printchar";

void test_print_a() {
    // Given
    intercept_stdout();

    // When
    mx_printchar('a');

    // Then
    restore_stdout();
    ASSERT_EQUALS('a', buf[0]);
}

void test_print_b() {
    // Given
    intercept_stdout();

    // When
    mx_printchar('b');

    // Then
    restore_stdout();
    ASSERT_EQUALS('b', buf[0]);
}
