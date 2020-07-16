
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_mx_strtrim() {
    // Given
    char *name = "\f My name... is Neo \t\n ";
    // When
    char *result = mx_strtrim(name);

    // Then
    ASSERT_TRUE(strcmp(result, "My name... is Neo") == 0);
    free(result);
}

void test_mx_strtrim_null() {
    // Given
    // When
    char *result = mx_strtrim(NULL);

    // Then
    ASSERT_TRUE(result == 0);
}

void test_mx_strtrim_() {
    char *result;

    result = mx_strtrim("name");
    ASSERT_TRUE(strcmp(result, "name") == 0);
    free(result);

    result = mx_strtrim("");
    ASSERT_TRUE(strcmp(result, "") == 0);
    free(result);

    result = mx_strtrim("name ");
    ASSERT_TRUE(strcmp(result, "name") == 0);
    free(result);

    result = mx_strtrim(" name");
    ASSERT_TRUE(strcmp(result, "name") == 0);
    free(result);

    result = mx_strtrim("na me");
    ASSERT_TRUE(strcmp(result, "na me") == 0);
    free(result);
}
