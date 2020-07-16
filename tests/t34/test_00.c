
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_strjoin() {
    // Given
    char *str1 = "Romani ";
    char *str2 = "ite domum";

    // When
    char *result = mx_strjoin(str1, str2);

    // Then
    ASSERT_TRUE(strcmp(result, "Romani ite domum") == 0);

    free(result);
}

void test_two_empty() {
    // Given
    char *str1 = "";
    char *str2 = "";

    // When
    char *result = mx_strjoin(str1, str2);

    // Then
    ASSERT_TRUE(strcmp(result, "") == 0);

    free(result);
}

void test_frist_0() {
    // Given
    char *str1 = 0;
    char *str2 = "";

    // When
    char *result = mx_strjoin(str1, str2);

    // Then
    ASSERT_TRUE(result == 0);

    free(result);
}

void test_second_0() {
    // Given
    char *str1 = "fsdf";
    char *str2 = 0;

    // When
    char *result = mx_strjoin(str1, str2);

    // Then
    ASSERT_TRUE(result == 0);

    free(result);
}

void test_both_0() {
    // Given
    char *str1 = 0;
    char *str2 = 0;

    // When
    char *result = mx_strjoin(str1, str2);

    // Then
    ASSERT_TRUE(result == 0);

    free(result);
}
