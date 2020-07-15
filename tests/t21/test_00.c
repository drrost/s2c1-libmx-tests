
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_strndup() {
    // Given
    char *s1 = "Hello, world!";

    // When
    char *s2 = mx_strndup(s1, 3);

    // Then
    ASSERT_TRUE(strcmp("Hel", s2) == 0);
    ASSERT_TRUE(s1 != s2);
    free(s2);
}

void test_strndup_zero() {
    // Given
    char *s1 = "Hello, world!";

    // When
    char *s2 = mx_strndup(s1, 0);

    // Then
    ASSERT_TRUE(strcmp("", s2) == 0);
    ASSERT_TRUE(s1 != s2);
    free(s2);
}

void test_strndup_minus() {
    // Given
    char *s1 = "Hello, world!";

    // When
    char *s2 = mx_strndup(s1, -1);

    // Then
    ASSERT_TRUE(strcmp(s1, s2) == 0);
    ASSERT_TRUE(s1 != s2);
    free(s2);
}

void test_strndup_greater_than_len() {
    // Given
    char *s1 = "Hello, world!";

    // When
    char *s2 = mx_strndup(s1, 1024);

    // Then
    ASSERT_TRUE(strcmp(s1, s2) == 0);
    ASSERT_TRUE(s1 != s2);
    free(s2);
}
