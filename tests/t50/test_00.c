
#include "../../lib/test_lib.h"
#include "../../libmx.h"

#include <limits.h>

char *test_case_name = "mx_push_front";

// Tests

t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void free_list(t_list *list);

void test_mx_pop_front_3() {
    // Given
    char *paris = "Paris, mon amour";
    t_list *head = mx_create_node(paris);
    char *highway = "Highway to hell";
    mx_push_front(&head, highway);
    char *get_lucky = "Get Lucky";
    mx_push_front(&head, get_lucky);

    // When
    t_list *second_node = head->next;
    mx_pop_front(&head);

    // Then
    ASSERT_NULL(head->next->next);
    ASSERT_EQUALS(second_node, head);
    ASSERT_TRUE(strcmp(head->data, highway) == 0);

    free_list(head);
}

void test_mx_pop_front_1() {
    // Given
    char *paris = "Paris, mon amour";
    t_list *head = mx_create_node(paris);

    // When
    mx_pop_front(&head);

    // Then
    ASSERT_NULL(head);

    free_list(head);
}

void test_mx_pop_front_0() {
    // Given
    t_list *head = 0;

    // When
    mx_pop_front(&head);

    // Then
    ASSERT_NULL(head);

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
