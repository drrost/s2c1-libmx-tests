
#include "../../lib/test_lib.h"
#include "../../libmx.h"

#include <limits.h>

#include "helpers.c"

char *test_case_name = "mx_push_front";

// Tests

void test_mx_print_list() {
    int len = 10;
    char *tracks[len];
    for (int i = 0; i < len; i++) {
        tracks[i] = rd_random_str();
    }

    // Given
    t_list *head = 0;

    for (int i = 0; i < len; i++) {
        mx_push_front(&head, tracks[i]);
    }

    // When
//    mx_foreach_list(head, print_node);

    // Then
    free_array(tracks, len);
    free_list(head);
}

void test_mx_sort_list() {
    int len = 10;
    char *tracks[len];
    for (int i = 0; i < len; i++) {
        tracks[i] = rd_random_str();
    }

    // Given
    t_list *head = 0;

    for (int i = 0; i < len; i++) {
        mx_push_front(&head, tracks[i]);
    }

    // When
    mx_sort_list(head, compare_strings);

    // Then

//    mx_foreach_list(head, print);

    free_array(tracks, len);
    free_list(head);
}
