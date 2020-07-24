
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_strlen";

// Tests

void test_print_one() {
    // Given
    char *s = "a";

    // When
    unsigned int len = mx_strlen(s);

    // Then
    ASSERT_EQUALS(strlen(s), len);
}

void test_print_empty() {
    // Given
    char *s = "";

    // When
    unsigned int len = mx_strlen(s);

    // Then
    ASSERT_EQUALS(strlen(s), len)
}

void test_print_long() {
    // Given
    char *s = "aadfasdfa asdf asdf asdf asdf asdf ";

    // When
    unsigned int len = mx_strlen(s);

    // Then
    ASSERT_EQUALS(strlen(s), len);
}

void test_print_rnd() {
    // Given
    char *s;

    // When
    for (int i = 0; i < 100; i++) {
        s = rd_random_str();
        unsigned int len = mx_strlen(s);

        // Then
        ASSERT_EQUALS(strlen(s), len);

        free(s);
    }
}
