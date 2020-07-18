
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

#include <fcntl.h>

void test_mx_memmem_2() {
    // Given
    char big[] = "abcdefjabcdefjabcdefjabcdelfj";
    int big_len = strlen(big);
    char little[] = "elf";
    int little_len = strlen(little);

    // When
    char *result = mx_memmem(big, big_len, little, little_len);

    // Then
    ASSERT_EQUALS_STR("elfj", result);
}

void test_mx_memmem_big_len_0() {
    // Given
    char big[] = "abcdefjabcdefjabcdefjabcdelfj";
    int big_len = 0;
    char little[] = "fja";
    int little_len = strlen(little);

    // When
    char *result = mx_memmem(big, big_len, little, little_len);

    // Then
    ASSERT_NULL(result);
}

void test_mx_memmem_little_len_0() {
    // Given
    char big[] = "abcdefjabcdefjabcdefjabcdelfj";
    int big_len = strlen(big);
    char little[] = "fja";
    int little_len = 0;

    // When
    char *result = mx_memmem(big, big_len, little, little_len);

    // Then
    ASSERT_NULL(result);
}

void test_mx_memmem_big_len_less_little_len() {
    // Given
    char big[] = "abc";
    int big_len = strlen(big);
    char little[] = "abcdefjabcdefjabcdefjabcdelfj";
    int little_len = strlen(little);

    // When
    char *result = mx_memmem(big, big_len, little, little_len);

    // Then
    ASSERT_NULL(result);
}

void test_mx_memmem_not_found() {
    // Given
    char big[] = "abcdefjabcdefjabcdefjabcdelfj";
    int big_len = strlen(big);
    char little[] = "ddd";
    int little_len = strlen(little);

    // When
    char *result = mx_memmem(big, big_len, little, little_len);

    // Then
    ASSERT_NULL(result);
}
