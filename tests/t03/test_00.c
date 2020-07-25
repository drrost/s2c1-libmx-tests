
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_print_strarr";

// SEGFAULT interception
#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

static sigjmp_buf point;

static void handler(int sig, siginfo_t *siginfo, void *p) {
    sig++;
    siginfo++;
    char *a = (char *) p;
    a++;
    longjmp(point, 1);
}

// Tests

#define TRY \
    struct sigaction sa; \
    memset(&sa, 0, sizeof(struct sigaction)); \
    sigemptyset(&sa.sa_mask); \
\
    sa.sa_flags = SA_NODEFER; \
    sa.sa_sigaction = handler; \
\
    sigaction(SIGSEGV, &sa, NULL); \
    if (setjmp(point) == 0) { \

#define CATCH \
    } else { \
    restore_stdout(); \
    char *s = (char *) malloc(1024); \
    sprintf(s, "     Segmentation fault: \"\033[1m%s()\033[0m\"\n", __func__); \
    test_print_fail(s); \
    free(s); \
    return; \
}

void test_print_strarr_basic() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = "|";
    intercept_stdout();

    // When

    TRY
        mx_print_strarr(arr, delim);
    CATCH;

    // Then
    restore_stdout();
    ASSERT_EQUALS_STR("a|b|c\n", STDOUT_BUFF);
}

void test_print_strarr_arr_null() {
    // Given
    char **arr = 0;
    char *delim = "|";

    // When
    TRY
        mx_print_strarr(arr, delim);
    CATCH;

    // Then
}

void test_print_strarr_delim_null() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = 0;

    // When
    TRY
        mx_print_strarr(arr, delim);
    CATCH;

    // Then
}

void test_print_strarr_delim_empty() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = "";
    intercept_stdout();

    // When
    TRY
        mx_print_strarr(arr, delim);
    CATCH;

    // Then
    restore_stdout();
    ASSERT_EQUALS_STR("abc\n", STDOUT_BUFF)
}

void test_print_strarr_delim_newline() {
    // Given
    char *arr[] = {"a", "b", "c", 0};
    char *delim = "\n";
    intercept_stdout();

    // When
    mx_print_strarr(arr, delim);

    // Then
    restore_stdout();
    ASSERT_EQUALS_STR("a\nb\nc\n", STDOUT_BUFF)
}

// delim with non printable symbols
