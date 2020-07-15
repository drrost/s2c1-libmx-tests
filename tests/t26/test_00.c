
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_strstr_1() {
    // Given
    char s1[] = "abc";
    char s2[] = "a";

    // When
    char *s3 = mx_strstr(s1, s2);

    // Then
    ASSERT_EQUALS(strstr(s1, s2), s3);
}

void test_strstr_2() {
    // Given
    char s1[] = "abc";
    char s2[] = "b";

    // When
    char *s3 = mx_strstr(s1, s2);

    // Then
    ASSERT_EQUALS(strstr(s1, s2), s3);
}

void test_strstr_bc() {
    // Given
    char s1[] = "abc";
    char s2[] = "bc";

    // When
    char *s3 = mx_strstr(s1, s2);

    // Then
    ASSERT_EQUALS(strstr(s1, s2), s3);
}

void test_strstr_absent() {
    // Given
    char s1[] = "abc";
    char s2[] = "bcd";

    // When
    char *s3 = mx_strstr(s1, s2);

    // Then
    ASSERT_EQUALS(strstr(s1, s2), s3);
    ASSERT_NULL(s3);
}

void test_strstr_empty_needle() {
    // Given
    char s1[] = "abc";
    char s2[] = "";

    // When
    char *s3 = mx_strstr(s1, s2);

    // Then
    ASSERT_EQUALS(strstr(s1, s2), s3);
    ASSERT_EQUALS(s1, s3);
}

void test_strstr_longer() {
    // Given
    char s1[] = "abc";
    char s2[] = "b";

    // When
    char *s3 = mx_strstr(s1, s2);

    // Then
    ASSERT_EQUALS(strstr(s1, s2), s3);
}

// `mx_strncmp` related tests

int mx_strncmp(const char *s1, const char *s2, size_t n);

void test_strncmp_1() {
    // Given
    char s1[] = "abc";
    char s2[] = "abcd";
    int n = 3;

    // When
    int result = mx_strncmp(s1, s2, n);

    // Then
    ASSERT_EQUALS(strncmp(s1, s2, n), result);
}

void test_strncmp_2() {
    // Given
    char s1[] = "abcd";
    char s2[] = "abc";
    int n = 3;

    // When
    int result = mx_strncmp(s1, s2, n);

    // Then
    ASSERT_EQUALS(strncmp(s1, s2, n), result);
}

void test_strncmp_3() {
    // Given
    char s1[] = "abc";
    char s2[] = "abc";
    int n = 3;

    // When
    int result = mx_strncmp(s1, s2, n);

    // Then
    ASSERT_EQUALS(strncmp(s1, s2, n), result);
}

void test_strncmp_greather() {
    // Given
    char s1[] = "abcd";
    char s2[] = "abcd";
    int n = 5;

    // When
    int result = mx_strncmp(s1, s2, n);

    // Then
    ASSERT_EQUALS(strncmp(s1, s2, n), result);
}

void test_strncmp_empty() {
    // Given
    char s1[] = "abcd";
    char s2[] = "";
    int n = 5;

    // When
    int result = mx_strncmp(s1, s2, n);

    // Then
    ASSERT_EQUALS(strncmp(s1, s2, n), result);
}
