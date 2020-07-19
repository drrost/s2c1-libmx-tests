
#include "../../lib/test_lib.h"
#include "../../libmx.h"

#include <limits.h>

#include "helpers.c"

// Tests

t_list *node_at(t_list *list, int index);
void swap_nodes(t_list *list, int i, int j);

// -- IN

t_list *create_list_test(const char **arr, int size);

void test_swap_0_1() {
    // Given
    const char *arr[] = {"wFXKBniLxp", "rpVor", "HuH", "iSp", "VJroUIrd"};
    t_list *list = create_list_test(arr, 5);

    int i = 0;
    int j = 1;

     // When
    swap_nodes(list, i, j);

    // Then
    ASSERT_TRUE(strcmp(list->data, "rpVor") == 0);
    ASSERT_TRUE(strcmp(list->next->data, "wFXKBniLxp") == 0);

    free_list_fully(list);
}

void test_sort_list() {
    // Given
    const char *arr[] = {"wFXKBniLxp", "rpVor", "HuH", "iSp", "VJroUIrd"};
    t_list *list = create_list_test(arr, 5);

    // When
    print_list_str(list);
    mx_sort_list(list, compare_strings);
    puts("--");

    // Then
    print_list_str(list);
    free_list_fully(list);
}

// -- Private

t_list *create_list_test(const char **arr, int size) {
    t_list *head = 0;
    for (int i = 0; i < size; i++) {
        int len = strlen(arr[i]);
        char *new_str = (char *) malloc(sizeof(char *) * (len + 1));
        strcpy(new_str, arr[i]);
        mx_push_back(&head, new_str);
    }
    return head;
}

// swap:
// first - last
// first - second
// second - third
// second - forth
