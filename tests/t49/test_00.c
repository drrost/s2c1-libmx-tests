
#include "../../lib/test_lib.h"
#include "../../libmx.h"

#include <limits.h>

// Tests

void mx_push_front(t_list **list, void *data) {
    t_list *front = mx_create_node(data);
    front->next = *list;
    *list = front;
}

void free_list(t_list *list) {
    t_list *node = list;
    while (1) {
        if (node == 0)
            return;
        t_list *old = node;
        node = node->next;
        free(old);
    }
}

void test_mx_push_back() {
    // Given
    char *paris = "Paris, mon amour";
    t_list *head = mx_create_node(paris);
    char *highway = "Highway to hell";
    mx_push_front(&head, highway);
    char *get_lucky = "Get Lucky";

    // When

    mx_push_back(&head, get_lucky);

    // Then
    ASSERT_NOT_NULL(head->next->next);
    ASSERT_TRUE(strcmp(head->next->next->data, get_lucky) == 0);

    free_list(head);
}

void test_mx_push_front_0() {
    // Given
    t_list *node = 0;

    // When
    char *highway = "Highway to hell";
    mx_push_back(&node, highway);

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
    mx_push_back(node, highway);

    // Then
    ASSERT_NULL(node);

    free(node);
}
