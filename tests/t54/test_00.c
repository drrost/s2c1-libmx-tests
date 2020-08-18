
#include "../../lib/test_lib.h"
#include "../../libmx.h"
#include "../../lib/rd_random.h"

#include <limits.h>
#include <stdlib.h>
#include <time.h>

char *test_case_name = "mx_list_comb_sort";

#define F_DELETE void(*)(void **)

void mx_list_delete_with_content(t_list **list, void(*delete)(void **data)) {
    while (*list) {
        void *data = (*list)->data;
        delete(&data);
        mx_pop_front(list);
    }
}

#define F_PRINTER void(*)(void *)

void mx_print_list(t_list *list, void(*printer)(void *data)) {
    while (list) {
        printer(list->data);
        mx_printline("");
        list = list->next;
    }
}

bool compare_strings(void *s1, void *s2) {
    return mx_strcmp((const char *) s1, (const char *) s2) > 0;
}

// Tests

void test_list_comb_sort() {
    // Given
    int n = 1500;
    t_list *list = 0;
    for (int i = 0; i < n; i++) {
        char *str = rd_random_str();
        mx_push_back(&list, str);
    }

    // When
    clock_t t = clock();
//    mx_sort_list(list, compare_strings);
    mx_list_comb_sort(list, compare_strings);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\nElapsed time: %f\n", time_taken);

//    mx_print_list(list, (F_PRINTER)mx_printstr);

    // Then
    mx_list_delete_with_content(&list, (F_DELETE)mx_strdel);
    ASSERT_NULL(list);
}
