#include "../s21_tests_main_runner.h"

START_TEST(memchr_1) {
  const char str[] = "This is a test string";
  char c = 's';
  int b = 10;
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, b),
                   memchr((const void *)str, (int)c, b));
}
END_TEST

START_TEST(memchr_2) {
  const char str[] = "1234567890";
  char c = '5';
  int b = 6;
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, b),
                   memchr((const void *)str, (int)c, b));
}
END_TEST

START_TEST(memchr_3) {
  const char str[] = "Hello world";
  char c = 'z';
  int b = (int)strlen(str);
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, b),
                   memchr((const void *)str, (int)c, b));
}
END_TEST

START_TEST(memchr_4) {
  const char str[] = "Hello world";
  char c = '0';
  int b = 1;
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, b),
                   memchr((const void *)str, (int)c, b));
}
END_TEST

START_TEST(memchr_5) {
  const char str[] = "\0";
  char c = '0';
  int b = 1;
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, b),
                   memchr((const void *)str, (int)c, b));
}
END_TEST

START_TEST(memchr_6) {
  const char str[] = "\0";
  char c = 's';
  int b = 1;
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, b),
                   memchr((const void *)str, (int)c, b));
}
END_TEST

START_TEST(memchr_7) {
  const char str[] = "\0\0\0";
  char c = '\0';
  int b = 3;
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, b),
                   memchr((const void *)str, (int)c, b));
}
END_TEST

START_TEST(memchr_8) {
  const char str[] = "Hello world";
  char c = ' ';
  int b = (int)strlen(str);
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, b),
                   memchr((const void *)str, (int)c, b));
}
END_TEST

START_TEST(memchr_9) {
  const char str[30] = "Hello world";
  char c = 'H';
  int b = 0;
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, b),
                   memchr((const void *)str, (int)c, b));
}
END_TEST

START_TEST(memchr_10) {
  const char str[30] = "\0Hello world";
  char c = 'e';
  int b = (int)strlen(str);
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, b),
                   memchr((const void *)str, (int)c, b));
}
END_TEST

START_TEST(memchr_11) {
  const char str[30] =
      "Hello "
      "world";
  char c = 'd';
  int b = (int)strlen(str);
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, b),
                   memchr((const void *)str, (int)c, b));
}
END_TEST

TCase *s21_StringHTCaseMemchr() {
  TCase *tcase = tcase_create("s21_StringHTCaseMemchr");
  tcase_add_test(tcase, memchr_1);
  tcase_add_test(tcase, memchr_2);
  tcase_add_test(tcase, memchr_3);
  tcase_add_test(tcase, memchr_4);
  tcase_add_test(tcase, memchr_5);
  tcase_add_test(tcase, memchr_6);
  tcase_add_test(tcase, memchr_7);
  tcase_add_test(tcase, memchr_8);
  tcase_add_test(tcase, memchr_9);
  tcase_add_test(tcase, memchr_10);
  tcase_add_test(tcase, memchr_11);

  return tcase;
}
