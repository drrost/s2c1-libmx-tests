
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_print_unicode";

// Tests

void test_print_unicode_ok() {
    // Given
    wchar_t wc = 'a';
    intercept_stdout();

    // When
    mx_print_unicode(wc);

    // Then
    restore_stdout();
    ASSERT_EQUALS('a', buf[0]);
}


void test_print_unicode_beta() {
    // Given
    wchar_t wc = 0x99D0;

    // When
    mx_print_unicode(wc);

    // Then
}

void test_print_unicode_A() {
    // Given
    wchar_t wc = 0x90D0;

    // When
    mx_print_unicode(wc);

    // Then
}
