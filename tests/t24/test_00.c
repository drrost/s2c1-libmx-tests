
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_strcmp() {
    // Given
    char *s1 = "abc";
    char *s2 = "Abc";

    // When

    // Then
    ASSERT_EQUALS(mx_strcmp(s1, s2), strcmp(s1, s2));
}

void test_strcmp_abcd() {
    // Given
    char *s1 = "abc";
    char *s2 = "abcd";

    // When

    // Then
    ASSERT_EQUALS(mx_strcmp(s1, s2), strcmp(s1, s2));
}

void test_strcmp_abcd2() {
    // Given
    char *s1 = "abcd";
    char *s2 = "abc";

    // When

    // Then
    ASSERT_EQUALS(mx_strcmp(s1, s2), strcmp(s1, s2));
}
