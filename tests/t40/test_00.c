
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

#include <fcntl.h>

void test_mx_memccpy() {
    // Given
    int len = 80;
    char *src = "This is the string: not copied";
    char dst[len];
    memset(dst, '\0', len);
    int c = ':';

    // When
    void *result = mx_memccpy(dst, src, c, len);

    // Then
    ASSERT_EQUALS(dst + 19, result);
    ASSERT_TRUE(strcmp("This is the string:", dst) == 0);
}

void test_mx_memccpy_notfound() {
    // Given
    int len = 80;
    char *src = "This is the string: not copied";
    char dst[len];
    memset(dst, '\0', len);
    int c = '.';

    // When
    void *result = mx_memccpy(dst, src, c, len);

    // Then
    ASSERT_EQUALS(0, result);
    ASSERT_EQUALS_STR("This is the string: not copied", dst);
}

void test_mx_memccpy_minus() {
    // Given
    int len = 80;
    char *src = "This is the string\\ not copied";
    char dst[len];
    memset(dst, '\0', len);
    int c = -420;

    // When
    void *result = mx_memccpy(dst, src, c, len);

    // Then
    ASSERT_EQUALS(dst + 19, result);
    ASSERT_TRUE(strcmp("This is the string\\", dst) == 0);
}

