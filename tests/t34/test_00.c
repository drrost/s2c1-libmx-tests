
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_strjoin";

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
    ASSERT_TRUE(strcmp(str2, result) == 0);
    ASSERT_TRUE(str2 != result);


    free(result);
}

void test_second_0() {
    // Given
    char *str1 = "fsdf";
    char *str2 = 0;

    // When
    char *result = mx_strjoin(str1, str2);

    // Then
    ASSERT_TRUE(strcmp(str1, result) == 0);
    ASSERT_TRUE(str1 != result);

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

void test_strjoin_ex1() {
    // Given
    char str1[] = "this";
    char str2[] = "dodge ";

    // When
    char *result = mx_strjoin(str2, str1);

    // Then
    ASSERT_TRUE(strcmp("dodge this", result) == 0);

    free(result);
}

void test_strjoin_ex2() {
    // Given
    char str1[] = "this";
    char *str3 = 0;

    // When
    char *result = mx_strjoin(str1, str3);

    // Then
    ASSERT_TRUE(strcmp("this", result) == 0);

    free(result);
}

void test_strjoin_ex2_1() {
    // Given
    char *str1 = 0;
    char str2[] = "dodge ";

    // When
    char *result = mx_strjoin(str1, str2);

    // Then
    ASSERT_TRUE(strcmp(str2, result) == 0);
    ASSERT_TRUE(str2 != result);

    free(result);
}

void test_strjoin_ex3() {
    // Given
    char *str1 = 0;
    char *str2 = 0;

    // When
    char *result = mx_strjoin(str1, str2);

    // Then
    ASSERT_NULL(result);

    free(result);
}
