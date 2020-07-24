
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_binary_search";

// Tests

void test_binary_search() {
    // Given
    char *arr[] = {"222", "Abcd", "aBc", "ab", "az", "z"};
    int count= 0;

    // When
    int result = mx_binary_search(arr, 6, "ab", &count);

    // Then
    ASSERT_EQUALS(3, result);
    ASSERT_EQUALS(3, count);
}

void test_binary_search_2() {
    // Given
    char *arr[] = {"222", "Abcd", "aBc", "ab", "az", "z"};
    int count= 0;

    // When
    int result = mx_binary_search(arr, 6, "aBc", &count);

    // Then
    ASSERT_EQUALS(2, result);
    ASSERT_EQUALS(1, count);
}

void test_binary_search_3() {
    // Given
    char *arr[] = {"222", "abcd", "aBc", "ab", "az", "z"};
    int count= 0;

    // When
    int result = mx_binary_search(arr, 6, "aBz", &count);

    // Then
    ASSERT_EQUALS(-1, result);
    ASSERT_EQUALS(0, count);
}
