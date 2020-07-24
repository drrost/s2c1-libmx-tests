
#include "../../lib/test_lib.h"
#include "../../libmx.h"

char *test_case_name = "mx_del_strarr";

// Tests

char *xx_strnew(const int size);
char *xx_strdup(const char *str);
int xx_strlen(const char *s);
char *xx_strcpy(char *dst, const char *src);

void test_mx_del_extra_1() {
    // Given
    int n = 3;
    char **arr = (char **)malloc(sizeof(char *) * n + 1);
    arr[0] = xx_strdup("abc");
    arr[1] = xx_strdup("ABC");
    arr[2] = xx_strdup("XYZ");
    arr[3] = 0;

    // When
    mx_del_strarr(&arr);

    // Then
    ASSERT_TRUE(arr == 0);
}

void test_mx_del_extra_null() {

}

///

char *xx_strnew(const int size) {
    if (size < 0)
        return 0;
    char *result = malloc(size + 1);
    for (int i = 0; i <= size; i++) {
        result[i] = 0;
    }
    return result;
}

char *xx_strdup(const char *str) {
    int length = xx_strlen(str);
    char *result = xx_strnew(length);
    xx_strcpy(result, str);
    return result;
}

int xx_strlen(const char *s) {
    int result = 0;
    while (*(s++)) {
        result++;
    }
    return result;
}

char *xx_strcpy(char *dst, const char *src) {
    for (int i = 0; ; i++) {
        dst[i] = src[i];
        if (src[i] == '\0') {
            break;
        }
    }
    return dst;
}
