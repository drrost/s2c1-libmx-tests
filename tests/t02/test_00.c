
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_printstr";

// Tests

void test_print_string() {
    // Given
    INTERCEPT_STDOUT;
    char *s = "aBcD";

    // When
    mx_printstr(s);

    // Then
    RESTORE_STDOUT;
    ASSERT_TRUE(strcmp("aBcD", buf) == 0)
}
