
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_swap_char";

// Tests

void test_swap_chars() {
    // Given
    char str[] = "ONE";

    // When
    mx_swap_char(&str[0], &str[1]);
    mx_swap_char(&str[1], &str[2]);

    // Then
    ASSERT_TRUE(strcmp(str, "NEO") == 0)
}

void test_swap_chars_s1_0() {
    // Given
    char str[] = "ONE";

    // When
    mx_swap_char(0, &str[1]);

    // Then
    ASSERT_TRUE(strcmp(str, "ONE") == 0)
}

void test_swap_chars_s2_0() {
    // Given
    char str[] = "ONE";

    // When
    mx_swap_char(&str[1], 0);

    // Then
    ASSERT_TRUE(strcmp(str, "ONE") == 0)
}
