
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_get_char_index() {
    // Given
    char *s = "abc";

    // When
    int result = mx_get_char_index(s, 'b');

    // Then
    ASSERT_EQUALS(1, result);
}

void test_get_char_index_2() {
    // Given
    char *s = "abc";

    // When
    int result = mx_get_char_index(s, 'c');

    // Then
    ASSERT_EQUALS(2, result);
}

void test_get_char_index_char_not_exist() {
    // Given
    char *s = "abc";

    // When
    int result = mx_get_char_index(s, 'd');

    // Then
    ASSERT_EQUALS(-1, result);
}

void test_get_char_index_string_not_exist() {
    // Given
    char *s = 0;

    // When
    int result = mx_get_char_index(s, 'd');

    // Then
    ASSERT_EQUALS(-2, result);
}
