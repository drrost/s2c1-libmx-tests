
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_strdup";

// Tests

void test_strdup() {
    // Given
    char *s1 = "Hello, world!";

    // When
    char *s2 = mx_strdup(s1);

    // Then
    ASSERT_TRUE(strcmp(s1, s2) == 0);
    ASSERT_TRUE(s1 != s2);
    free(s2);
}

void test_strdup_empty() {
    // Given
    char *s1 = "";

    // When
    char *s2 = mx_strdup(s1);

    // Then
    ASSERT_TRUE(strcmp(s1, s2) == 0);
    ASSERT_TRUE(s1 != s2);
    free(s2);
}
