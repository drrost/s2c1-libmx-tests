
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_strcpy";

// Tests

void test_strcpy() {
    // Given
    char s1[] = "abc";
    char s2[] = "000";

    // When
    char *s3 = mx_strcpy(s2, s1);

    // Then
    ASSERT_EQUALS(strcmp(s2, s1), 0);
    ASSERT_EQUALS(s2, s3);
}
