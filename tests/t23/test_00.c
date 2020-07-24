
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_strncpy";

// Tests

void test_strncpy() {
    // Given
    char s1[] = "abc";
    char s2[] = "000";

    // When
    char *s3 = mx_strncpy(s2, s1, 3);

    // Then
    ASSERT_EQUALS(strcmp(s2, s1), 0);
    ASSERT_EQUALS(s2, s3);
}

void test_strncpy_2() {
    // Given
    char s1[] = "abc";
    char s2[] = "000";

    // When
    char *s3 = mx_strncpy(s2, s1, 2);

    // Then
    ASSERT_EQUALS(strcmp(s2, "ab0"), 0);
    ASSERT_EQUALS(s2, s3);
}

void test_strncpy_zero() {
    // Given
    char s1[] = "abc";
    char s2[] = "000";

    // When
    char *s3 = mx_strncpy(s2, s1, 0);

    // Then
    ASSERT_EQUALS(strcmp(s2, "000"), 0);
    ASSERT_EQUALS(s2, s3);
}
