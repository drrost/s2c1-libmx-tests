
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_mx_file_to_str() {
    // Given
    const char *file_name = "matrix.txt";

    // When
    char *result = mx_file_to_str(file_name);

    // Then
    ASSERT_EQUALS_STR("Matrix", result);
    ASSERT_EQUALS(6, strlen(result));

    free(result);
}

void test_mx_file_to_str_2() {
    // Given
    const char *file_name = "matrix2.txt";

    // When
    char *result = mx_file_to_str(file_name);

    // Then
//    printf("result: \"%s\"\n", result);
    ASSERT_TRUE(strcmp(result, "Matrix\nMatrix") == 0);
    ASSERT_EQUALS(13, strlen(result));

    free(result);
}

void test_mx_file_to_str_unexists() {
    // Given
    const char *file_name = "absent.txt";

    // When
    char *result = mx_file_to_str(file_name);

    // Then
    ASSERT_EQUALS(0, result);

    free(result);
}
