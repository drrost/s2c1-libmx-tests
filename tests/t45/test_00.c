
#include "../../lib/test_lib.h"
#include "../../libmx.h"

// Tests

void test_a() {
    // https://riptutorial.com/c/example/2150/copying-overlapping-memory
    // https://www.student.cs.uwaterloo.ca/~cs350/common/os161-src-html/doxygen/html/memmove_8c_source.html
    char str[19] = "This is an example";
    char *result = mx_memmove(str + 7, str, 10);
    ASSERT_EQUALS_STR("This isThis is ane", str);
    ASSERT_EQUALS(str + 7, result);
}
