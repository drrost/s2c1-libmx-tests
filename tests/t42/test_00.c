
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

#include <fcntl.h>

void test_mx_memchr() {
    // Given
    char str[] = "abcdefj";
    int c = 'd';
    size_t n = strlen(str);

    // When
    char *result = mx_memchr(str, c, n);

    // Then
    ASSERT_EQUALS_STR("defj", result);
}

void test_mx_memchr_notfound() {
    // Given
    char str[] = "abcdefj";
    int c = 'p';
    size_t n = strlen(str);

    // When
    char *result = mx_memchr(str, c, n);

    // Then
    ASSERT_EQUALS(0, result);
}

void test_mx_memchr_minus() {
    // Given
    char str[] = "abcd\\fj";
    int c = -420;
    size_t n = strlen(str);

    // When
    char *result = mx_memchr(str, c, n);

    // Then
    ASSERT_EQUALS_STR("\\fj", result);
}
