
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_sort_example_3() {
    // Given
    char *arr[] = {"abc", "xyz", "ghi", "def"};

    // When
    int result = mx_bubble_sort(arr, 4);

    // Then
    ASSERT_EQUALS(3, result);
}

void test_sort_example_4() {
    // Given
    char *arr[] = {"abc", "acb", "a"};

    // When
    int result = mx_bubble_sort(arr, 3);

    // Then
    ASSERT_EQUALS(2, result);
}
