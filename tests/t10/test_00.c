
#include "../../lib/test_lib.h"
#include "../../libmx.h"

void mx_printint(int n) {
    printf("%d\n", n);
}

// Tests

void test_foreach() {
    // Given
    int arr[] = {1, 2, 3, 4, 5};

    // When
    mx_foreach(arr, 5, mx_printint);

    // Then
}
