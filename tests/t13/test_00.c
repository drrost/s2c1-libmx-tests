
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_quick_sort_arr_0() {
    // Given
    char **arr = 0;

    // When
    int result = mx_quicksort(arr, 0, 0);

    // Then
    ASSERT_EQUALS(-1, result);
}

void test_quick_sort_arr_example_0() {
    // Given
    char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};

    // When
    int result = mx_quicksort(arr, 0, 3);

    // Then
    ASSERT_EQUALS(2, result);
}
