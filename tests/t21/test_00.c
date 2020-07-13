
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_strndup() {
    // Given
    char *s1 = "Hello, world!";

    // When
    char *s2 = mx_strndup(s1, 3);

    // Then
    ASSERT_TRUE(strcmp(s1, s2) == 0);
    ASSERT_TRUE(s1 != s2);
    free(s2);
}
