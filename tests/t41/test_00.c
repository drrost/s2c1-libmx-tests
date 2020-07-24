
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_memcmp";

// Tests

#include <fcntl.h>

void test_mx_memcmp_0() {
    // Given
    char s1[] = "aaa";
    char s2[] = "aaa";
    int len = 3;

    // When
    int resutl = mx_memcmp(s1, s2, len);

    // Then
    ASSERT_EQUALS(0, resutl);
}

void test_mx_memcmp_minus1() {
    // Given
    char s1[] = "aaa";
    char s2[] = "aab";
    int len = 3;

    // When
    int resutl = mx_memcmp(s1, s2, len);

    // Then
    ASSERT_EQUALS(-1, resutl);
}

void test_mx_memcmp_1() {
    // Given
    char s1[] = "aab";
    char s2[] = "aaa";
    int len = 3;

    // When
    int resutl = mx_memcmp(s1, s2, len);

    // Then
    ASSERT_EQUALS(1, resutl);
}

void test_mx_memcmp_minus() {
    // Given
    char s1[] = "aab";
    char s2[] = "aaa";
    int len = 3;
    s2[2] = (char)-420;

    // When
    int resutl = memcmp(s1, s2, len);

    // Then
    ASSERT_EQUALS(6, resutl);
}
