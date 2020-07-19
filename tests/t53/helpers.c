//
// Created by Rostyslav Druzhchenko on 23.04.2020.
//

#pragma once

// --

bool compare_strings(void *s1, void *s2) {
    return strcmp((const char *) s1, (const char *) s2) > 0;
}

void print_node(t_list *node) {
    printf("%s\n", node->data);
}

// --

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

void mx_foreach_list(t_list *list, void(*f)(t_list *node)) {
    if (list == 0 || f == 0) {
        return;
    }

    while (list) {
        f(list);
        list = list->next;
    }
}

void free_array(char **arr, int len) {
    for (int i = 0; i < len; i++) {
        free(arr[i]);
    }
}

t_list *create_list_str(int len) {
    char *strings[len];
    for (int i = 0; i < len; i++) {
        strings[i] = rd_random_str();
    }

    t_list *head = 0;

    for (int i = 0; i < len; i++) {
        mx_push_front(&head, strings[i]);
    }

    return head;
}

void free_list_fully(t_list *list) {
    t_list *node = list;
    while (1) {
        if (node == 0)
            return;
        t_list *old = node;
        node = node->next;
        free(old->data);
        free(old);
    }
}

void print_list_str(t_list *list) {
    mx_foreach_list(list, print_node);
}
