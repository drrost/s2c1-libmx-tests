
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_mx_strdel() {
    // Given
    char *str = malloc(18);

    // When
    mx_strdel(&str);

    // Then
    ASSERT_TRUE(str == 0);
}
