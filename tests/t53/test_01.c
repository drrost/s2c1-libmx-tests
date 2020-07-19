
#include "../../lib/test_lib.h"
#include "../../libmx.h"

#include <limits.h>

#include "helpers.c"

// Tests

// -- IN
t_list *node_at(t_list *list, int index);

void test_node_at_0() {
    // Given
    t_list *head = create_list_str(4);

    // When
    t_list *node = node_at(head, 0);

    // Then
    ASSERT_EQUALS(node, head);
    free_list_fully(head);
}

void test_node_at_1() {
    // Given
    t_list *head = create_list_str(4);

    // When
    t_list *node = node_at(head, 1);

    // Then
    ASSERT_EQUALS(node, head->next);
    free_list_fully(head);
}

void test_node_at_2() {
    // Given
    t_list *head = create_list_str(4);

    // When
    t_list *node = node_at(head, 2);

    // Then
    ASSERT_EQUALS(node, head->next->next);
    free_list_fully(head);
}

void test_node_at_3() {
    // Given
    t_list *head = create_list_str(4);

    // When
    t_list *node = node_at(head, 3);

    // Then
    ASSERT_EQUALS(node, head->next->next->next);
    free_list_fully(head);
}
