
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_strsplit";

// Tests

void test_mx_del_extra_1() {
    // Given
    char *s = "**Good bye,**Mr.*Anderson.****";

    // When
    char **arr = mx_strsplit(s, '*');

    // Then
    int size = 0;
    for (; arr[size]; size++) {}
    ASSERT_EQUALS(3, size);
    ASSERT_TRUE(strcmp(arr[0], "Good bye,") == 0);
    ASSERT_TRUE(strcmp(arr[1], "Mr.") == 0);
    ASSERT_TRUE(strcmp(arr[2], "Anderson.") == 0);

    // Clean up
    for (int i = 0; arr[i]; i++) {
        free(arr[i]);
    }
    free(arr);
}

void test_mx_del_extra_2() {
    // Given
    char *s = "Knock, knock,    Neo.   ";

    // When
    char **arr = mx_strsplit(s, ' ');

    // Then
    int size = 0;
    for (; arr[size]; size++) {}
    ASSERT_EQUALS(3, size);
    ASSERT_TRUE(strcmp(arr[0], "Knock,") == 0);
    ASSERT_TRUE(strcmp(arr[1], "knock,") == 0);
    ASSERT_TRUE(strcmp(arr[2], "Neo.") == 0);

    // Clean up
    for (int i = 0; arr[i]; i++) {
        free(arr[i]);
    }
    free(arr);
}

void test_mx_del_extra_null() {
    // Given
    char *s = 0;

    // When
    char **arr = mx_strsplit(s, ' ');

    // Then
    ASSERT_TRUE(arr == 0);
}
