
#include "../../lib/test_lib.h"
#include "../../libmx.h"

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
//    printf("%s", str);
    ASSERT_TRUE(strcmp("er a fire licked its way across\nthe polyester carpeting, destroying several rooms as it\nspooled soot up the walls and ceiling, leaving patterns of\npermanent shadow", str) == 0);
    ASSERT_EQUALS(163, result);
    free(str);
}
