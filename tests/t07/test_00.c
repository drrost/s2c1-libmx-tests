
#include "../../lib/test_lib.h"
#include "../../libmx.h"

#include <limits.h>

char *test_case_name = "mx_nbr_to_hex";

// Tests

void test_mx_br_to_hex_1234567890() {
    // Given
    unsigned long in = 0x1234567890ABC;

    // When
    char *result = mx_nbr_to_hex(in);

    // Then
    ASSERT_EQUALS_STR("1234567890abc", result);

    free(result);
}

void test_mx_br_to_hex_1() {

    for (int i = 0; i < 1000; i++) {
        // Given
        int rnd_value = rd_random_int(0, INT_MAX);
        char standard_value[32];
        sprintf(standard_value, "%x", rnd_value);

        // When
        char *result = mx_nbr_to_hex(rnd_value);

        // Then
        ASSERT_TRUE(strcmp(result, standard_value) == 0);

        free(result);
    }
}

void test_mx_br_to_hex_0() {
    // Given
    unsigned long in = 0;

    // When
    char *result = mx_nbr_to_hex(in);

    // Then
    ASSERT_EQUALS_STR("0", result);

    free(result);
}

void test_mx_br_to_hex_52() {
    // Given
    unsigned long in = 52;

    // When
    char *result = mx_nbr_to_hex(in);

    // Then
    ASSERT_TRUE(strcmp(result, "34") == 0);

    free(result);
}

void test_mx_br_to_hex_1000() {
    // Given
    unsigned long in = 1000;

    // When
    char *result = mx_nbr_to_hex(in);

    // Then
    ASSERT_TRUE(strcmp(result, "3e8") == 0);

    free(result);
}
