
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_strcat";

// Tests

void test_strcat() {
    // Given
    char *s1 = malloc(100);
    strcpy(s1, "abc");
    char *s2 = "Abc";

    // When
    char *s3 = mx_strcat(s1, s2);

    // Then
    ASSERT_TRUE(strcmp(s3, "abcAbc") == 0);
    ASSERT_EQUALS(s3, s1);

    free(s1);
}
