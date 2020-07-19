
#include "../../lib/test_lib.h"
#include "../../libmx.h"

#include <limits.h>

// Tests

void test_mx_create_node() {
    // Given
    char *s = "";

    // When
    t_list *node = mx_create_node(s);

    // Then
    ASSERT_NOT_NULL(node);
    ASSERT_EQUALS(node->data, s);
    ASSERT_EQUALS(0, node->next);

    free(node);
}
