#include "../s21_tests_main_runner.h"

#define N 1000

START_TEST(test_s21_sprintf_sp_n_1) {
  const char format[] = "%n";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int count = 0;
  int s21_count = 1;

  int standard = sprintf(sprintf_str, format, &count);
  int s21 = s21_sprintf(s21_sprintf_str, format, &s21_count);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_s21_sprintf_sp_n_2) {
  const char format[] = "Hello, %n";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int count = 0;
  int s21_count = 1;

  int standard = sprintf(sprintf_str, format, &count);
  int s21 = s21_sprintf(s21_sprintf_str, format, &s21_count);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_s21_sprintf_sp_n_3) {
  const char format[] = "русская %n раскладка";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int count = 0;
  int s21_count = 1;

  int standard = sprintf(sprintf_str, format, &count);
  int s21 = s21_sprintf(s21_sprintf_str, format, &s21_count);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_s21_sprintf_sp_n_4) {
  const char format[] = "%n 0\n\tabc";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int count = 0;
  int s21_count = 1;

  int standard = sprintf(sprintf_str, format, &count);
  int s21 = s21_sprintf(s21_sprintf_str, format, &s21_count);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_s21_sprintf_sp_n_5) {
  const char format[] = "%n%n%n";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int count1 = 0;
  int count2 = 0;
  int count3 = 0;

  int s21_count1 = 1;
  int s21_count2 = 1;
  int s21_count3 = 1;

  int standard = sprintf(sprintf_str, format, &count1, &count2, &count3);
  int s21 = s21_sprintf(s21_sprintf_str, format, &s21_count1, &s21_count2,
                        &s21_count3);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
  ck_assert_int_eq(count1, s21_count1);
  ck_assert_int_eq(count2, s21_count2);
  ck_assert_int_eq(count3, s21_count3);
}
END_TEST

START_TEST(test_s21_sprintf_sp_n_6) {
  const char format[] = "%n......%n//////%n";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int count1 = 0;
  int count2 = 0;
  int count3 = 0;

  int s21_count1 = 1;
  int s21_count2 = 1;
  int s21_count3 = 1;

  int standard = sprintf(sprintf_str, format, &count1, &count2, &count3);
  int s21 = s21_sprintf(s21_sprintf_str, format, &s21_count1, &s21_count2,
                        &s21_count3);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
  ck_assert_int_eq(count1, s21_count1);
  ck_assert_int_eq(count2, s21_count2);
  ck_assert_int_eq(count3, s21_count3);
}
END_TEST

TCase *s21_SprintfTcaseSpN() {
  TCase *tcase = tcase_create("s21_SprintfTcaseSpN");

  tcase_add_test(tcase, test_s21_sprintf_sp_n_1);
  tcase_add_test(tcase, test_s21_sprintf_sp_n_2);
  tcase_add_test(tcase, test_s21_sprintf_sp_n_3);
  tcase_add_test(tcase, test_s21_sprintf_sp_n_4);
  tcase_add_test(tcase, test_s21_sprintf_sp_n_5);
  tcase_add_test(tcase, test_s21_sprintf_sp_n_6);

  return tcase;
}