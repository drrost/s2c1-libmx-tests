
#include "../../lib/test_lib.h"
#include "../../libmx.h"

#include <limits.h>

// Tests

t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void free_list(t_list *list);

void test_mx_list_size_3() {
    // Given
    char *paris = "Paris, mon amour";
    t_list *head = mx_create_node(paris);
    char *highway = "Highway to hell";
    mx_push_front(&head, highway);
    char *get_lucky = "Get Lucky";
    mx_push_front(&head, get_lucky);

    // When
    int size = mx_list_size(head);

    // Then
    ASSERT_EQUALS(3, size);

    free_list(head);
}

void test_mx_list_size_1() {
    // Given
    char *paris = "Paris, mon amour";
    t_list *head = mx_create_node(paris);

    // When
    int size = mx_list_size(head);

    // Then
    ASSERT_EQUALS(1, size);

    free_list(head);
}

void test_mx_list_size_0() {
    // Given
    t_list *head = 0;

    // When
    int size = mx_list_size(head);

    // Then
    ASSERT_EQUALS(0, size);

    free_list(head);
}

// --

t_list *mx_create_node(void *data) {
    t_list *node = (t_list *) malloc(sizeof(t_list));
    node->data = data;
    node->next = 0;
    return node;
}

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
