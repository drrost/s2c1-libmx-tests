
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_strnew_10() {
    // Given
    int n = 10;

    // When
    char *s = mx_strnew(n);

    // Then
    ASSERT_NOT_NULL(s);

    for (int i = 0; i <= 10; ++i) {
        ASSERT_EQUALS(s[i], 0);
    }

    free(s);
}

void test_strnew_0() {
    // Given
    int n = 0;

    // When
    char *s = mx_strnew(n);

    // Then
    ASSERT_NOT_NULL(s);
    free(s);
}

void test_strnew_minus_1() {
    // Given
    int n = -1;

    // When
    char *s = mx_strnew(n);

    // Then
    ASSERT_NULL(s);
}

#include <limits.h>

void test_strnew_much() {
    // Given
    int n = INT_MAX;
    int count = 65535;
    void *p[count];

    // When
    int i = 0;
    while (1) {
        char *s = mx_strnew(n);
        if (s == 0) {
            break;
        }
        p[i] = s;
        i++;
    }

    // Then
    for (int j = 0; j < i; j++) {
        free(p[j]);
    }
}
