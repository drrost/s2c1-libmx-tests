
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_count_substr_1() {
    // Given
    char s1[] = "abc";
    char s2[] = "a";

    // When
    int i = mx_count_substr(s1, s2);

    // Then
    ASSERT_EQUALS(1, i);
}

void test_count_substr_2() {
    // Given
    char s1[] = "abc";
    char s2[] = "b";

    // When
    int i = mx_count_substr(s1, s2);

    // Then
    ASSERT_EQUALS(1, i);
}

void test_count_substr_3() {
    // Given
    char s1[] = "abc";
    char s2[] = "c";

    // When
    int i = mx_count_substr(s1, s2);

    // Then
    ASSERT_EQUALS(1, i);
}

void test_count_substr_4() {
    // Given
    char s1[] = "abc";
    char s2[] = "bc";

    // When
    int i = mx_count_substr(s1, s2);

    // Then
    ASSERT_EQUALS(1, i);
}

void test_count_substr_5() {
    // Given
    char s1[] = "abc";
    char s2[] = "ab";

    // When
    int i = mx_count_substr(s1, s2);

    // Then
    ASSERT_EQUALS(1, i);
}

void test_count_substr_6() {
    // Given
    char s1[] = "aaa";
    char s2[] = "a";

    // When
    int i = mx_count_substr(s1, s2);

    // Then
    ASSERT_EQUALS(3, i);
}

void test_count_substr_7() {
    // Given
    char s1[] = "aaa";
    char s2[] = "aa";

    // When
    int i = mx_count_substr(s1, s2);

    // Then
    ASSERT_EQUALS(2, i);
}

void test_count_substr_sub_empty() {
    // Given
    char s1[] = "aaa";
    char s2[] = "";

    // When
    int i = mx_count_substr(s1, s2);

    // Then
    ASSERT_EQUALS(0, i);
}

// Examples

void test_count_substr_ex1() {
    // Given
    char s1[] = "yo, yo, yo Neo";
    char s2[] = "yo";

    // When
    int i = mx_count_substr(s1, s2);

    // Then
    ASSERT_EQUALS(3, i);
}

void test_count_substr_ex2() {
    // Given
    char s1[] = "yo, yo, yo Neo";
    char *s2 = NULL;

    // When
    int i = mx_count_substr(s1, s2);

    // Then
    ASSERT_EQUALS(-1, i);
}

void test_count_substr_ex3() {
    // Given
    char *s1 = NULL;
    char s2[] = "yo";

    // When
    int i = mx_count_substr(s1, s2);

    // Then
    ASSERT_EQUALS(-1, i);
}
