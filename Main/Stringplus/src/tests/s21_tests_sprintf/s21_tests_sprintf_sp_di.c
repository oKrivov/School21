#include "../s21_tests_main_runner.h"

#define N 1000

START_TEST(test_s21_sprintf_sp_d_1) {
  const char format[] = "%d";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, INT_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, INT_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_d_2) {
  const char format[] = "%ld%lld";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, LONG_MIN, LLONG_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, LONG_MIN, LLONG_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_d_3) {
  const char format[] = "%hd";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, SHRT_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, SHRT_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_d_4) {
  const char format[] = "%hhd";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, CHAR_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, CHAR_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_d_5) {
  const char format[] = "before specifier %010hhd after %+i";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, CHAR_MIN, INT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, CHAR_MIN, INT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_d_6) {
  const char format[] = "%-123hhd before specifier %lli after %d% i";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};
  int standard =
      sprintf(sprintf_str, format, CHAR_MIN, LLONG_MAX, INT_MIN, INT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, CHAR_MIN, LLONG_MAX, INT_MIN,
                        INT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

TCase *s21_SprintfTcaseSpDI() {
  TCase *tcase = tcase_create("s21_SprintfTcaseSpDI");

  tcase_add_test(tcase, test_s21_sprintf_sp_d_1);
  tcase_add_test(tcase, test_s21_sprintf_sp_d_2);
  tcase_add_test(tcase, test_s21_sprintf_sp_d_3);
  tcase_add_test(tcase, test_s21_sprintf_sp_d_4);
  tcase_add_test(tcase, test_s21_sprintf_sp_d_5);
  tcase_add_test(tcase, test_s21_sprintf_sp_d_6);

  return tcase;
}