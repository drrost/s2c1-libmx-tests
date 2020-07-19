
#include "../../lib/test_lib.h"
#include "../../libmx.h"

#include <limits.h>

// Tests

void test_mx_push_front() {
    // Given
    char *s = "";
    t_list *node = mx_create_node(s);
    t_list *old_head = node;

    // When
    char *highway = "Highway to hell";
    mx_push_front(&node, highway);

    // Then
    ASSERT_NOT_NULL(node);
    ASSERT_TRUE(strcmp(node->data, highway) == 0);
    ASSERT_EQUALS(old_head, node->next);

    free(node->next);
    free(node);
}

void test_mx_push_front_0() {
    // Given
    t_list *node = 0;

    // When
    char *highway = "Highway to hell";
    mx_push_front(&node, highway);

    // Then
    ASSERT_NOT_NULL(node);
    ASSERT_TRUE(strcmp(node->data, highway) == 0);

    free(node);
}

void test_mx_push_front_0_0() {
    // Given
    t_list **node = 0;

    // When
    char *highway = "Highway to hell";
    mx_push_front(node, highway);

    // Then
    ASSERT_NULL(node);

    free(node);
}
