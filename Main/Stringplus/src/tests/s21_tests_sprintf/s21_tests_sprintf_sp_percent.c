#include "../s21_tests_main_runner.h"

#define N 100

START_TEST(test_s21_sprintf_sp_percent_1) {
  const char format[] = "%%";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format);
  int s21 = s21_sprintf(s21_sprintf_str, format);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_percent_2) {
  const char format[] = "Hello, %%";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format);
  int s21 = s21_sprintf(s21_sprintf_str, format);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_percent_3) {
  const char format[] = "русская %% раскладка";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format);
  int s21 = s21_sprintf(s21_sprintf_str, format);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_percent_4) {
  const char format[] = "%% 0\n\tabc";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format);
  int s21 = s21_sprintf(s21_sprintf_str, format);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_percent_5) {
  const char format[] = "%%%%%%";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format);
  int s21 = s21_sprintf(s21_sprintf_str, format);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_percent_6) {
  const char format[] = "%%......%%//////%%";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format);
  int s21 = s21_sprintf(s21_sprintf_str, format);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

TCase *s21_SprintfTcaseSpPercent() {
  TCase *tcase = tcase_create("s21_SprintfTcaseSpPercent");

  tcase_add_test(tcase, test_s21_sprintf_sp_percent_1);
  tcase_add_test(tcase, test_s21_sprintf_sp_percent_2);
  tcase_add_test(tcase, test_s21_sprintf_sp_percent_3);
  tcase_add_test(tcase, test_s21_sprintf_sp_percent_4);
  tcase_add_test(tcase, test_s21_sprintf_sp_percent_5);
  tcase_add_test(tcase, test_s21_sprintf_sp_percent_6);

  return tcase;
}