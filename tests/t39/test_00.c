
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_memcpy";

// Tests

#include <fcntl.h>

void test_mx_memcpy() {
    // Given
    char str1[] = "McDonalds";
    char str2[] = "aaaaaaaaa";
    int len = 5;

    // When
    void *result = mx_memcpy(str2, str1, len);

    // Then
    ASSERT_EQUALS(str2, result);
    ASSERT_TRUE(strcmp("McDonaaaa", result) == 0);
}

void test_mx_memcpy_over() {
    // Given
    char str1[] = "McDonalds";
    char str2[] = "aaaaaaaaa";
    int len = 15;

    // When
    void *result = mx_memcpy(str2, str1, len);

    // Then
    ASSERT_EQUALS(str2, result);
    ASSERT_TRUE(strcmp("McDonalds", result) == 0);
}
