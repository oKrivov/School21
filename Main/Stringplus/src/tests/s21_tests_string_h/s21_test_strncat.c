#include "../s21_tests_main_runner.h"

START_TEST(strncat_1) {
  char dest[60] = "Hello";
  char copy_dest[60] = "Hello";
  char src[] = " world";
  int n = 10;
  strncat(dest, src, n);
  s21_strncat(copy_dest, src, n);
  ck_assert_str_eq(dest, copy_dest);
}
END_TEST

START_TEST(strncat_2) {
  char dest[15] = "";
  char copy_dest[15] = "";
  char src[] = " world";
  int n = sizeof(src);
  strncat(dest, src, n);
  s21_strncat(copy_dest, src, n);
  ck_assert_str_eq(dest, copy_dest);
}
END_TEST

START_TEST(strncat_3) {
  char dest[] = "This is a test string";
  char copy_dest[] = "This is a test string";
  char src[4] = "";
  int n = sizeof(src);

  strncat(dest, src, n);
  s21_strncat(copy_dest, src, n);
  ck_assert_str_eq(dest, copy_dest);
}
END_TEST

START_TEST(strncat_4) {
  char dest[20] = "Hello ";
  char copy_dest[20] = "Hello ";
  char src[] = "world";
  int n = sizeof(src);

  strncat(dest, src, n);
  s21_strncat(copy_dest, src, n);
  ck_assert_str_eq(dest, copy_dest);
}
END_TEST

START_TEST(strncat_5) {
  char dest[20] = "\0";
  char copy_dest[20] = "\0";
  char src[] = "!";
  int n = sizeof(src);

  strncat(dest, src, n);
  s21_strncat(copy_dest, src, n);
  ck_assert_str_eq(dest, copy_dest);
}
END_TEST

START_TEST(strncat_6) {
  char dest[20] = "12\0 56  8";
  char copy_dest[20] = "12\0 56  8";
  char src[] = "3\0 4";
  int n = sizeof(src);

  strncat(dest, src, n);
  s21_strncat(copy_dest, src, n);
  ck_assert_str_eq(dest, copy_dest);
}
END_TEST

START_TEST(strncat_7) {
  char dest[20] = "School\0 21";
  char copy_dest[20] = "School\0 21";
  char src[] = "21";
  int n = sizeof(src);

  strncat(dest, src, n);
  s21_strncat(copy_dest, src, n);
  ck_assert_str_eq(dest, copy_dest);
}
END_TEST

START_TEST(strncat_8) {
  char dest[256] = "School 21";
  char copy_dest[256] = "School 21";
  char src[] = "aaaaaaaaaaaaaaa";
  int n = sizeof(src);

  strncat(dest, src, n);
  s21_strncat(copy_dest, src, n);
  ck_assert_str_eq(dest, copy_dest);
}
END_TEST

START_TEST(strncat_9) {
  char dest[256] = "test string   ";
  char copy_dest[256] = "test string   ";
  char src[] = "-2";
  int n = sizeof(src);

  strncat(dest, src, n);
  s21_strncat(copy_dest, src, n);
  ck_assert_str_eq(dest, copy_dest);
}
END_TEST

START_TEST(strncat_10) {
  char dest[8] = "12345 ";
  char copy_dest[8] = "12345 ";
  char src[] = "6";
  int n = sizeof(src);

  strncat(dest, src, n);
  s21_strncat(copy_dest, src, n);
  ck_assert_str_eq(dest, copy_dest);
}
END_TEST

TCase *s21_StringHTCaseStrncat() {
  TCase *tcase = tcase_create("s21_StringHTCaseStrncat");
  tcase_add_test(tcase, strncat_1);
  tcase_add_test(tcase, strncat_2);
  tcase_add_test(tcase, strncat_3);
  tcase_add_test(tcase, strncat_4);
  tcase_add_test(tcase, strncat_5);
  tcase_add_test(tcase, strncat_6);
  tcase_add_test(tcase, strncat_7);
  tcase_add_test(tcase, strncat_8);
  tcase_add_test(tcase, strncat_9);
  tcase_add_test(tcase, strncat_10);

  return tcase;
}
