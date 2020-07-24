
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_del_extra_spaces";

// Tests

void test_mx_del_extra() {
    // Given
    char *name = "\f   My name...     is  \r Neo   \t\n ";

    // When
    char *result = mx_del_extra_spaces(name);

    // Then
    ASSERT_TRUE(strcmp(result, "My name... is Neo") == 0);
    free(result);
}

void test_mx_del_extra_null() {
    // Given
    // When
    char *result = mx_del_extra_spaces(NULL);

    // Then
    ASSERT_TRUE(result == 0);
}
