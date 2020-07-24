
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_pow";

// Tests

void test_pow_3_3() {
    // Given
    double n = 3.0;
    unsigned int pow = 3;

    // When
    double res = mx_pow(n, pow);

    // Then
    ASSERT_EQUALS(27.0, res);
}

void test_pow_25_3() {
    // Given
    double n = 2.5;
    unsigned int pow = 3;

    // When
    double res = mx_pow(n, pow);

    // Then
    ASSERT_EQUALS(15.625, res);
}

void test_pow_2_0() {
    // Given
    double n = 2.0;
    unsigned int pow = 0;

    // When
    double res = mx_pow(n, pow);

    // Then
    ASSERT_EQUALS(1.0, res);
}

void test_pow_minus3_3() {
    // Given
    double n = -3.0;
    unsigned int pow = 3;

    // When
    double res = mx_pow(n, pow);

    // Then
    ASSERT_EQUALS(-27.0, res);
}
