#include "s21_string.h"

#include <stdio.h>
void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();

void s21_strlen_test_drc(char* test_val, size_t val);
void s21_strcmp_test_drc(char* test_val_1, char* test_val_2, int val);
void s21_strcpy_test_drc(char* test_copy_str, char* test_dst_str, char* val);
void s21_strcat_test_drc(char* test_dest_str, char* test_src_str, char* val);
void s21_strchr_test_drc(char* test_str, int c, int val);

int main() {
#ifdef STRLEN
    s21_strlen_test();
#endif
#ifdef STRCMP
    s21_strcmp_test();
#endif
#ifdef STRCPY
    s21_strcpy_test();
#endif
#ifdef STRCAT
    s21_strcat_test();
#endif
#ifdef STRCHR
    s21_strchr_test();
#endif

    return 0;
}

void s21_strlen_test() {
    char test_1[15] = "Hello, world!";
    char test_2[7] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    char* test_3 = "world!";
    char* test_fall_4 = NULL;
    char* test_fail_5 = "";

    s21_strlen_test_drc(test_1, 13), printf("\n");
    s21_strlen_test_drc(test_2, 6), printf("\n");
    s21_strlen_test_drc(test_3, 6), printf("\n");
    s21_strlen_test_drc(test_fall_4, 0), printf("\n");
    s21_strlen_test_drc(test_fail_5, 0), printf("\n");
};

void s21_strlen_test_drc(char* test_val, size_t val) {
    printf("Test input: %-20s : val %2zu : ", test_val, val);
    size_t res = s21_strlen(test_val);
    (res == val) ? printf("SUCCESS %2zu", res) : printf(" FAIL %2zu", res);
}

void s21_strcmp_test() {
    char test_1[15] = "Hello, world!";
    char test_2[15] = "Hello, world!";
    char test_3[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char test_4[7] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    char* test_5 = "world!";
    char* test_6 = "World!";
    char* test_fall_7 = NULL;
    char* test_fall_8 = NULL;
    char* test_fail_9 = "\0";
    char* test_fail_10 = "";

    s21_strcmp_test_drc(test_1, test_2, 0), printf("\n");
    s21_strcmp_test_drc(test_3, test_4, -33), printf("\n");
    s21_strcmp_test_drc(test_5, test_6, 32), printf("\n");
    s21_strcmp_test_drc(test_fall_7, test_fall_8, 0), printf("\n");
    s21_strcmp_test_drc(test_fail_9, test_fail_10, 0), printf("\n");
}

void s21_strcmp_test_drc(char* test_val_1, char* test_val_2, int val) {
    printf("Test input: test_val_1 = %-20s : test_val_2 = %-20s : ", test_val_1, test_val_2);
    int res = s21_strcmp(test_val_1, test_val_2);
    (res == val) ? printf("SUCCESS %3d", res) : printf("FAIL %3d", res);
}

void s21_strcpy_test() {
    char test_copy_str_1[15] = "hello, world!";
    char test_copy_str_2[8] = "world!";
    char test_copy_str_3[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    char test_copy_dst_1[8] = "Hello,!";
    char test_copy_dst_2[] = {"\0"};
    char* test_copy_dst_3 = NULL;

    s21_strcpy_test_drc(test_copy_str_1, test_copy_dst_1, "hello, "), printf("\n");
    s21_strcpy_test_drc(test_copy_str_2, test_copy_dst_2, "\0"), printf("\n");
    s21_strcpy_test_drc(test_copy_str_3, test_copy_dst_3, NULL), printf("\n");
}

void s21_strcpy_test_drc(char* test_copy_str, char* test_dst_str, char* val) {
    printf("Test input: test_copy_str = %-20s : test_dst_str = %-20s : ", test_copy_str, test_dst_str);
    s21_strcpy(test_copy_str, test_dst_str);
    int res = s21_strcmp(test_dst_str, val);
    (res == 0) ? printf("SUCCESS %s", test_dst_str) : printf("FAIL %s", test_dst_str);
}

void s21_strcat_test() {
    char test_src_str_1[8] = " world!";
    char test_src_str_2[7] = "hello!";
    char test_src_str_3[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    char test_dst_str_1[16] = "Hello,";
    char test_dst_str_2[100] = "";
    char* test_dst_str_3 = NULL;

    s21_strcat_test_drc(test_dst_str_3, test_src_str_3, NULL), printf("\n");
    s21_strcat_test_drc(test_dst_str_1, test_src_str_1, "Hello, world!"), printf("\n");
    s21_strcat_test_drc(test_dst_str_2, test_src_str_2, "hello!"), printf("\n");
}

void s21_strcat_test_drc(char* test_dest_str, char* test_src_str, char* val) {
    printf("Test input: test_dest_str = %-20s : test_src_str = %-20s : ", test_dest_str, test_src_str);
    char* res = s21_strcat(test_dest_str, test_src_str);
    (s21_strcmp(res, val) == 0) ? printf("SUCCESS %s", test_dest_str) : printf("FAIL %s", test_dest_str);
}

void s21_strchr_test() {
    char test_str_1[15] = "Hello, world!";
    char test_str_2[100] = "world";
    char* test_str_3 = NULL;

    char test_char_1 = 'l';
    char test_char_2 = 'd';
    char test_char_3 = 'o';

    s21_strchr_test_drc(test_str_1, test_char_1, 2), printf("\n");
    s21_strchr_test_drc(test_str_2, test_char_2, 4), printf("\n");
    s21_strchr_test_drc(test_str_3, test_char_3, 0x0), printf("\n");
}

void s21_strchr_test_drc(char* test_str, int c, int val) {
    printf("Test input: test_str = %-20s : desired_val = %-20c : ", test_str, c);
    char* res = s21_strchr(test_str, c);
    (res == &test_str[val]) ? printf("SUCCESS %p", res) : printf("FAIL %p", res);
}