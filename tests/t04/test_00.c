
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_print_int_25() {
    // Given
    int n = 25;

    // When
    mx_printint(n);
    printf("\n");

    // Then
}

void test_print_int_2147483647() {
    // Given
    int n = 2147483647;

    // When
    mx_printint(n);
    printf("\n");

    // Then
}

void test_print_int_minus2147483648() {
    // Given
    int n = -2147483648;

    // When
    mx_printint(n);
    printf("\n");

    // Then
}

void test_print_int_minus12345() {
    // Given
    int n = -12345;

    // When
    mx_printint(n);
    printf("\n");

    // Then
}
