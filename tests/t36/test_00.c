
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_read_line";

// Tests

#include <fcntl.h>

void test_mx_file_to_str_2() {
    // Given
    const char *file_name = "fragment";
    int fd = open(file_name, O_RDONLY);
    ASSERT_TRUE(fd != -1);
    char *str = 0;

    // When
    int result = mx_read_line(&str, 20, 'f', fd);

    // Then
    ASSERT_EQUALS(25, result);
    ASSERT_TRUE(strcmp("The hotel was abandoned a", str) == 0);
    free(str);

    result = mx_read_line(&str, 35, 't', fd);
    ASSERT_TRUE(strcmp("", str) == 0);
    ASSERT_EQUALS(0, result);
    free(str);

    result = mx_read_line(&str, 4, '.', fd);

    ASSERT_TRUE(strcmp("er a fire licked its way across\nthe polyester carpeting, destroying several rooms as it\nspooled soot up the walls and ceiling, leaving patterns of\npermanent shadow", str) == 0);
    ASSERT_EQUALS(163, result);
    free(str);
    close(fd);
}

void test_mx_file_to_str_small() {
    // Given
    const char *file_name = "fragment_small";
    int fd = open(file_name, O_RDONLY);
    ASSERT_TRUE(fd != -1);
    char *str = 0;

    // When
    int result = mx_read_line(&str, 4, 'f', fd);

    // Then
    ASSERT_EQUALS(5, result);
    ASSERT_EQUALS_STR("abcde", str);
    free(str);

    result = mx_read_line(&str, 35, 'g', fd);
    ASSERT_EQUALS_STR("", str);
    ASSERT_EQUALS(0, result);
    free(str);

    result = mx_read_line(&str, 4, 'o', fd);
    ASSERT_EQUALS_STR("hijklmn", str);
    ASSERT_EQUALS(7, result);
    free(str);

    close(fd);
}

void test_mx_file_to_str_two() {
    // Given
    const char *file_name_orig = "fragment";
    const char *file_name_small = "fragment_small";
    int fd_1 = open(file_name_orig, O_RDONLY);
    int fd_2 = open(file_name_small, O_RDONLY);
    ASSERT_TRUE(fd_1 != -1);
    ASSERT_TRUE(fd_2 != -1);
    char *str = 0;

    // When
    int result = mx_read_line(&str, 20, 'f', fd_1);

    // Then
    ASSERT_EQUALS(25, result);
    ASSERT_EQUALS_STR("The hotel was abandoned a", str);
    free(str);

    result = mx_read_line(&str, 4, 'f', fd_2);

    ASSERT_EQUALS(5, result);
    ASSERT_EQUALS_STR("abcde", str);
    free(str);

    result = mx_read_line(&str, 35, 'g', fd_2);
    ASSERT_EQUALS_STR("", str);
    ASSERT_EQUALS(0, result);
    free(str);

    result = mx_read_line(&str, 35, 't', fd_1);
    ASSERT_TRUE(strcmp("", str) == 0);
    ASSERT_EQUALS(0, result);
    free(str);

    result = mx_read_line(&str, 4, 'o', fd_2);
    ASSERT_EQUALS_STR("hijklmn", str);
    ASSERT_EQUALS(7, result);
    free(str);

    result = mx_read_line(&str, 4, '.', fd_1);
    ASSERT_TRUE(strcmp("er a fire licked its way across\nthe polyester carpeting, destroying several rooms as it\nspooled soot up the walls and ceiling, leaving patterns of\npermanent shadow", str) == 0);
    ASSERT_EQUALS(163, result);
    free(str);

    close(fd_1);
    close(fd_2);
}

void test_mx_read_line_invalid_fd() {
    // Given
}
