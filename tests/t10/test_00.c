
#include "../../lib/test_lib.h"
#include "../../libmx.h"

void mx_printint(int n) {
    printf("%d\n", n);
}

// Tests

void test_foreach() {
    // Given
    int arr[] = {1, 2, 3, 4, 5};
    INTERCEPT_STDOUT;

    // When
    mx_foreach(arr, 5, mx_printint);

    // Then
    RESTORE_STDOUT;
    ASSERT_STDOUT_EQUALS("1\n2\n3\n4\n5\n");
}
