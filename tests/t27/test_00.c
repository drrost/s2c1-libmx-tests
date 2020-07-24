
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_get_substr_index";

// Tests

void test_get_substr_index1() {
    // Given
    char s1[] = "abc";
    char s2[] = "a";

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(0, i);
}

void test_get_substr_index2() {
    // Given
    char s1[] = "abc";
    char s2[] = "b";

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(1, i);
}

void test_get_substr_indexbc() {
    // Given
    char s1[] = "abc";
    char s2[] = "bc";

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(1, i);
}

void test_get_substr_indexabsent() {
    // Given
    char s1[] = "abc";
    char s2[] = "bcd";

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(-1, i);
}

void test_get_substr_indexempty_needle() {
    // Given
    char s1[] = "abc";
    char s2[] = "";

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(0, i);
}

void test_get_substr_index_longer() {
    // Given
    char s1[] = "abc";
    char s2[] = "abcd";

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(-1, i);
}

void test_get_substr_index_s1_0() {
    // Given
    char *s1 = 0;
    char s2[] = "abcd";

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(-2, i);
}

void test_get_substr_index_s2_0() {
    // Given
    char s1[] = "abcd";
    char *s2 = 0;

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(-2, i);
}

void test_get_substr_index_s1_s2_0() {
    // Given
    char *s1 = 0;
    char *s2 = 0;

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(-2, i);
}

// Examples

void test_get_substr_ex1() {
    // Given
    char s1[] = "McDonalds";
    char s2[] = "Don";

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(2, i);
}

void test_get_substr_ex2() {
    // Given
    char s1[] = "McDonalds Donuts";
    char s2[] = "on";

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(3, i);
}

void test_get_substr_ex3() {
    // Given
    char s1[] = "McDonalds";
    char s2[] = "Donatello";

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(-1, i);
}

void test_get_substr_ex4() {
    // Given
    char s1[] = "McDonalds";
    char *s2 = NULL;

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(-2, i);
}

void test_get_substr_ex5() {
    // Given
    char *s1 = NULL;
    char s2[] = "Donatello";

    // When
    int i = mx_get_substr_index(s1, s2);

    // Then
    ASSERT_EQUALS(-2, i);
}
