
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_quicksort";

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

    ASSERT_EQUALS_STR("Raphael", arr[0]);
    ASSERT_EQUALS_STR("Leonardo", arr[1]);
    ASSERT_EQUALS_STR("Donatello", arr[2]);
    ASSERT_EQUALS_STR("Michelangelo", arr[3]);
}

void test_quick_sort_arr_example_1() {
    // Given
    char *arr[] = {"DMC", "Clint Eastwood", "Dr Brown", "Einstein", "Jessica", "Biff Tannen"};

    // When
    int result = mx_quicksort(arr, 0, 5);

    // Then
    ASSERT_EQUALS(2, result);

    ASSERT_EQUALS_STR("DMC", arr[0]);
    ASSERT_EQUALS_STR("Jessica", arr[1]);
    ASSERT_EQUALS_STR("Dr Brown", arr[2]);
    ASSERT_EQUALS_STR("Einstein", arr[3]);
    ASSERT_EQUALS_STR("Biff Tannen", arr[4]);
    ASSERT_EQUALS_STR("Clint Eastwood", arr[5]);
}
