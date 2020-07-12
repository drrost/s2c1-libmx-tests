
#include "../../lib/test_lib.h"
#include "../../libmx.h"

#include <limits.h>

// Tests

void test_sqrt_25() {
    // Given
    int n = 25;

    // When
    int result = mx_sqrt(n);

    // Then
    ASSERT_EQUALS(5, result);
}

void test_sqrt_3() {
    // Given
    int n = 3;

    // When
    int result = mx_sqrt(n);

    // Then
    ASSERT_EQUALS(0, result);
}

void test_sqrt_4() {
    // Given
    int n = 4;

    // When
    int result = mx_sqrt(n);

    // Then
    ASSERT_EQUALS(2, result);
}

void test_sqrt_max() {
    // Given
    int n = INT_MAX;

    // When
    int result = mx_sqrt(n);

    // Then
    ASSERT_EQUALS(0, result);
}

void test_sqrt_0() {
    // Given
    int n = 0;

    // When
    int result = mx_sqrt(n);

    // Then
    ASSERT_EQUALS(0, result);
}

void test_sqrt_1() {
    // Given
    int n = 1;

    // When
    int result = mx_sqrt(n);

    // Then
    ASSERT_EQUALS(1, result);
}

void test_sqrt_minus1() {
    // Given
    int n = -1;

    // When
    int result = mx_sqrt(n);

    // Then
    ASSERT_EQUALS(0, result);
}

void test_sqrt_min() {
    // Given
    int n = INT_MIN;

    // When
    int result = mx_sqrt(n);

    // Then
    ASSERT_EQUALS(0, result);
}
