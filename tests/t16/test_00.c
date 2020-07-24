
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_str_reverse";

// Tests

void test_reverse_string() {
    // Given
    char str[] = "game over";
    // When
    mx_str_reverse(str);

    // Then
    ASSERT_TRUE(strcmp(str, "revo emag") == 0)
}

void test_reverse_string_0() {
    // Given
    char *str = 0;
    // When
    mx_str_reverse(str);

    // Then
}
