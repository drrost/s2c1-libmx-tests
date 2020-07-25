
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_foreach";

void mx_printint(int n) {
    printf("%d\n", n);
}

// Tests

void test_foreach() {
    // Given
    int arr[] = {1, 2, 3, 4, 5};
    intercept_stdout();

    // When
    mx_foreach(arr, 5, mx_printint);

    // Then
    restore_stdout();
    ASSERT_STDOUT_EQUALS("1\n2\n3\n4\n5\n");
}
