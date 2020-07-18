
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

#include <fcntl.h>

void test_mx_memset() {
    // Given
    char str[] = "McDonalds";
    int c = 'a';
    int len = strlen(str);

    // When
    void *result = mx_memset(str, c, len);

    // Then
    ASSERT_EQUALS(str, result);
    for (int i = 0; i < len; i++) {
        ASSERT_EQUALS(c, str[i])
    }
}

void test_mx_memset_minus() {
    // Given
    char str[] = "McDonalds";
    int c = -420;
    int len = strlen(str);

    // When
    void *result = mx_memset(str, c, len);

    // Then
    ASSERT_EQUALS(str, result);
    for (int i = 0; i < len; i++) {
        ASSERT_EQUALS((unsigned char)c, str[i])
    }
}
