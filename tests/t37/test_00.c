
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

#include <fcntl.h>

void test_mx_replace_substr_ex1() {
    // Given
    char str[] = "McDonalds";
    char sub[] = "alds";
    char replace[] = "uts";

    // When
    char *result = mx_replace_substr(str, sub, replace);

    // Then
    ASSERT_TRUE(strcmp("McDonuts", result) == 0);
    free(result);
}

void test_mx_replace_substr_ex2() {
    // Given
    char str[] = "Ururu turu";
    char sub[] = "ru";
    char replace[] = "ta";

    // When
    char *result = mx_replace_substr(str, sub, replace);

    // Then
    ASSERT_TRUE(strcmp("Utata tuta", result) == 0);
    free(result);
}

void test_mx_replace_substr_notfound() {
    // Given
    char str[] = "Now is the winter of our discontent";
    char sub[] = "ru";
    char replace[] = "ta";

    // When
    char *result = mx_replace_substr(str, sub, replace);

    // Then
    ASSERT_TRUE(strcmp("Now is the winter of our discontent", result) == 0);
    free(result);
}

void test_mx_replace_substr_empty_in() {
    // Given
    char str[] = "";
    char sub[] = "ru";
    char replace[] = "ta";

    // When
    char *result = mx_replace_substr(str, sub, replace);

    // Then
    ASSERT_TRUE(strcmp("", result) == 0);
    free(result);
}


void test_mx_replace_substr_many() {
    // Given
    char str[] = "Now is the winter of our discontent";
    char sub[] = " ";
    char replace[] = "_";

    // When
    char *result = mx_replace_substr(str, sub, replace);

    // Then
    ASSERT_TRUE(strcmp("Now_is_the_winter_of_our_discontent", result) == 0);
    free(result);
}

void test_mx_replace_substr_str0() {
    // Given
    char *str = 0;
    char sub[] = " ";
    char replace[] = "_";

    // When
    char *result = mx_replace_substr(str, sub, replace);

    // Then
    ASSERT_NULL(result);
}

void test_mx_replace_substr_str1() {
    // Given
    char str[] = "dfsfd";
    char *sub = 0;
    char replace[] = "_";

    // When
    char *result = mx_replace_substr(str, sub, replace);

    // Then
    ASSERT_NULL(result);
}
