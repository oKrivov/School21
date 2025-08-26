#include "../s21_tests_main_runner.h"

START_TEST(memset_1) {
  char str[] = "Hello";
  char copy_str[] = "Hello";
  char c = '#';
  int n = 3;

  memset(str, c, n);
  s21_memset(copy_str, c, n);
  ck_assert_str_eq(str, copy_str);
}
END_TEST

START_TEST(memset_2) {
  char str[] = "1234567890";
  char copy_str[] = "1234567890";
  char c = '5';
  int n = 6;

  memset(str, c, n);
  s21_memset(copy_str, c, n);
  ck_assert_str_eq(str, copy_str);
}
END_TEST

START_TEST(memset_3) {
  char str[] = "Hello";
  char copy_str[] = "Hello";
  char c = 'z';
  int n = (int)strlen(str);

  memset(str, c, n);
  s21_memset(copy_str, c, n);
  ck_assert_str_eq(str, copy_str);
}
END_TEST

START_TEST(memset_4) {
  char str[] = "Hello";
  char copy_str[] = "Hello";
  char c = '#';
  int n = 1;

  memset(str, c, n);
  s21_memset(copy_str, c, n);
  ck_assert_str_eq(str, copy_str);
}
END_TEST

START_TEST(memset_5) {
  char str[] = "\0";
  char copy_str[] = "\0";
  char c = '#';
  int n = 1;

  memset(str, c, n);
  s21_memset(copy_str, c, n);
  ck_assert_str_eq(str, copy_str);
}
END_TEST

START_TEST(memset_6) {
  char str[] = "Hello";
  char copy_str[] = "Hello";
  char c = '#';
  int n = 3;

  memset(str, c, n);
  s21_memset(copy_str, c, n);
  ck_assert_str_eq(str, copy_str);
}
END_TEST

START_TEST(memset_7) {
  char str[] = "\0\0\0";
  char copy_str[] = "\0\0\0";
  char c = '\0';
  int n = 1;

  memset(str, c, n);
  s21_memset(copy_str, c, n);
  ck_assert_str_eq(str, copy_str);
}
END_TEST

START_TEST(memset_8) {
  char str[] = "Hello";
  char copy_str[] = "Hello";
  char c = '\0';
  int n = 3;

  memset(str, c, n);
  s21_memset(copy_str, c, n);
  ck_assert_str_eq(str, copy_str);
}
END_TEST

START_TEST(memset_9) {
  char str[] = "Hello";
  char copy_str[] = "Hello";
  char c = ' ';
  int n = (int)strlen(str);

  memset(str, c, n);
  s21_memset(copy_str, c, n);
  ck_assert_str_eq(str, copy_str);
}
END_TEST

START_TEST(memset_10) {
  char str[] = "Hello";
  char copy_str[] = "Hello";
  char c = 'h';
  int n = 1;

  memset(str, c, n);
  s21_memset(copy_str, c, n);
  ck_assert_str_eq(str, copy_str);
}
END_TEST

TCase *s21_StringHTCaseMemset() {
  TCase *tcase = tcase_create("s21_StringHTCaseMemset");
  tcase_add_test(tcase, memset_1);
  tcase_add_test(tcase, memset_2);
  tcase_add_test(tcase, memset_3);
  tcase_add_test(tcase, memset_4);
  tcase_add_test(tcase, memset_5);
  tcase_add_test(tcase, memset_6);
  tcase_add_test(tcase, memset_7);
  tcase_add_test(tcase, memset_8);
  tcase_add_test(tcase, memset_9);
  tcase_add_test(tcase, memset_10);

  return tcase;
}
