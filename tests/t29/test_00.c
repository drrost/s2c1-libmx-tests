
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_count_words";

// Tests

void test_count_words_ex1() {
    // Given
    char s1[]= "  follow  *   the  white rabbit ";

    // When
    int count = mx_count_words(s1, '*');

    // Then
    ASSERT_EQUALS(2, count);
}

void test_count_words_ex2() {
    // Given
    char s1[]= "  follow  *   the  white rabbit ";

    // When
    int count = mx_count_words(s1, ' ');

    // Then
    ASSERT_EQUALS(5, count);
}

void test_count_words_ex3() {
    // Given

    // When
    int count = mx_count_words(NULL, ' ');

    // Then
    ASSERT_EQUALS(-1, count);
}
