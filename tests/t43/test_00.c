
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_memrchr";

// Tests

#include <fcntl.h>

void test_mx_memrchr() {
    // Given
    char str[] = "abcdefj";
    int c = 'd';
    size_t n = strlen(str);

    // When
    char *result = mx_memrchr(str, c, n);

    // Then
    ASSERT_EQUALS_STR("defj", result);
}

void test_mx_memchr_notfound() {
    // Given
    char str[] = "abcdefj";
    int c = 'p';
    size_t n = strlen(str);

    // When
    char *result = mx_memrchr(str, c, n);

    // Then
    ASSERT_EQUALS(0, result);
}

void test_mx_memchr_minus() {
    // Given
    char str[] = "abcd\\fj";
    int c = -420;
    size_t n = strlen(str);

    // When
    char *result = mx_memrchr(str, c, n);

    // Then
    ASSERT_EQUALS_STR("\\fj", result);
}

void  test_mx_memchr_ex1() {
    // Given
    char str[] = "Trinity";
    int c = 'i';
    size_t n = strlen(str);

    // When
    char *result = mx_memrchr(str, c, n);

    // Then
    ASSERT_EQUALS_STR("ity", result);
}

void  test_mx_memchr_ex2() {
    // Given
    char str[] = "Trinity";
    int c = 'M';
    size_t n = strlen(str);

    // When
    char *result = mx_memrchr(str, c, n);

    // Then
    ASSERT_NULL(result);
}
