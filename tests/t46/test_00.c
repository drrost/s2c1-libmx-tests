
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_realloc";

// Tests

void test_realloc_null() {
    // Given
    char *s = 0;

    // When
    s = mx_realloc(s, 3);

    // Then
    ASSERT_NOT_NULL(s);
    free(s);
}

void test_realloc_same() {
    // Given
    int len = 16;
    char *s1 = realloc(0, len);

    // When
    char *s2 = mx_realloc(s1, len);

    // Then
    ASSERT_EQUALS(s1, s2);
    free(s2);
}

//void  test_realloc_minus_len() {
//    // Given
//    int len = 15;
//    char *s1 = malloc(len);
//
//    // When
//    char *result = mx_realloc(s1, -1);
//
//    // Then
//    ASSERT_NULL(result);
//    free(s1);
//}

void test_realloc_less() {
    // Given
    int len = 16;
    char *s1 = malloc(len);
    strcpy(s1, "abcdefjhi");

    // When
    char *result = mx_realloc(s1, len - 1);

    // Then
    ASSERT_EQUALS(s1, result);
    ASSERT_EQUALS_STR("abcdefjhi", result);
    free(s1);
}

void test_realloc_more() {
    // Given
    int len = 15;
    char *s1 = malloc(len);
    strcpy(s1, "abcdefjhi");

    // When
    char *result = mx_realloc(s1, len * 20);

    // Then
    ASSERT_EQUALS_STR("abcdefjhi", result);
    free(result);
}

