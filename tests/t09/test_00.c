
#include "../../lib/test_lib.h"
#include "../../libmx.h"

#include <limits.h>

char *test_case_name = "mx_itoa";

// Tests

void test_itoa_1() {
    // Given
    int number = 1;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_TRUE(strcmp(string, "1") == 0);
    free(string);
}

void test_itoa_0() {
    // Given
    int number = 0;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_EQUALS_STR("0", string);
    free(string);
}

void test_itoa_9() {
    // Given
    int number = 9;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_TRUE(strcmp(string, "9") == 0);
    free(string);
}

void test_itoa_10() {
    // Given
    int number = 10;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_EQUALS_STR("10", string);
    free(string);
}

void test_itoa_12() {
    // Given
    int number = 12;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_EQUALS_STR("12", string);
    free(string);
}

void test_itoa_13() {
    // Given
    int number = 13;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_EQUALS_STR("13", string);
    free(string);
}

// Minus

void test_itoa_minus_1() {
    // Given
    int number = -1;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_EQUALS_STR("-1", string);
    free(string);
}

void test_itoa_minus_9() {
    // Given
    int number = -9;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_EQUALS_STR("-9", string);
    free(string);
}

void test_itoa_minus_10() {
    // Given
    int number = -10;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_EQUALS_STR("-10", string);
    free(string);
}

void test_itoa_minus_11() {
    // Given
    int number = -11;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_EQUALS_STR("-11", string);
    free(string);
}

// Longer

void test_itoa_minus_12345() {
    // Given
    int number = -12345;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_EQUALS_STR("-12345", string);
    free(string);
}

void test_itoa_98767() {
    // Given
    int number = 98767;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_EQUALS_STR("98767", string);
    free(string);
}

// Max/min

void test_itoa_INT_MAX() {
    // Given
    int number = INT_MAX;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_EQUALS_STR("2147483647", string);
    free(string);
}

void test_itoa_INT_MIN() {
    // Given
    int number = INT_MIN;

    // When
    char *string = mx_itoa(number);

    // Then
    ASSERT_EQUALS_STR("-2147483648", string);
    free(string);
}
