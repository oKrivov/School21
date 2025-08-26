#include "../s21_tests_main_runner.h"

#define N 100

START_TEST(test_s21_sprintf_default_1) {
  const char format[] = "Hello, world!";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format);
  int s21 = s21_sprintf(s21_sprintf_str, format);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_default_2) {
  const char format[] = "   ";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format);
  int s21 = s21_sprintf(s21_sprintf_str, format);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_default_3) {
  const char format[] = "русская раскладка";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format);
  int s21 = s21_sprintf(s21_sprintf_str, format);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_default_4) {
  const char format[] = "0\n\tabc";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format);
  int s21 = s21_sprintf(s21_sprintf_str, format);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_default_5) {
  const char format[] = "1";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format);
  int s21 = s21_sprintf(s21_sprintf_str, format);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

TCase *s21_SprintfTcaseDefault() {
  TCase *tcase = tcase_create("s21_SprintfTcaseDefault");

  tcase_add_test(tcase, test_s21_sprintf_default_1);
  tcase_add_test(tcase, test_s21_sprintf_default_2);
  tcase_add_test(tcase, test_s21_sprintf_default_3);
  tcase_add_test(tcase, test_s21_sprintf_default_4);
  tcase_add_test(tcase, test_s21_sprintf_default_5);

  return tcase;
}