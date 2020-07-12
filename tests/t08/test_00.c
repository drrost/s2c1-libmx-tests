
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_hex_to_nbr_C4() {
    // Given
    // When
    unsigned long result = mx_hex_to_nbr("C4");

    // Then
    ASSERT_EQUALS(196, result);
}

void test_hex_to_nbr_c4() {
    // Given
    // When
    unsigned long result = mx_hex_to_nbr("c4");

    // Then
    ASSERT_EQUALS(196, result);
}

void test_hex_to_nbr_FADE() {
    // Given
    // When
    unsigned long result = mx_hex_to_nbr("FADE");

    // Then
    ASSERT_EQUALS(64222, result);
}

void test_hex_to_nbr_ffffffffffff() {
    // Given
    // When
    unsigned long result = mx_hex_to_nbr("ffffffffffff");

    // Then
    ASSERT_EQUALS(281474976710655, result);
}


//mx_hex_to_nbr("C4"); // 196
//mx_hex_to_nbr("FADE"); //returns 64222
//mx_hex_to_nbr("ffffffffffff"); //returns 281474976710655
