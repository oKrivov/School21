#include "../s21_tests_main_runner.h"

#define N 100
#define END_OF_STRING '\0'
#define TAB '\t'
#define ENTER '\n'
#define DEFAULT_SYMBOL 'a'

START_TEST(test_s21_sprintf_sp_c_1) {
  const char format[] = "%c";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, DEFAULT_SYMBOL);
  int s21 = s21_sprintf(s21_sprintf_str, format, DEFAULT_SYMBOL);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_c_2) {
  const char format[] = "русская раскладка  000%c ///";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, CHAR_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, CHAR_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_c_3) {
  const char format[] = "%-10c%2c\n%3c%4c%5c";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, CHAR_MAX, CHAR_MIN, TAB, ENTER,
                         END_OF_STRING);
  int s21 = s21_sprintf(s21_sprintf_str, format, CHAR_MAX, CHAR_MIN, TAB, ENTER,
                        END_OF_STRING);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_c_4) {
  const char format[] = "%-10c......%-2c//////%-1c";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard =
      sprintf(sprintf_str, format, CHAR_MAX, CHAR_MIN, DEFAULT_SYMBOL);
  int s21 =
      s21_sprintf(s21_sprintf_str, format, CHAR_MAX, CHAR_MIN, DEFAULT_SYMBOL);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

TCase *s21_SprintfTcaseSpC() {
  TCase *tcase = tcase_create("s21_SprintfTcaseSpC");

  tcase_add_test(tcase, test_s21_sprintf_sp_c_1);
  tcase_add_test(tcase, test_s21_sprintf_sp_c_2);
  tcase_add_test(tcase, test_s21_sprintf_sp_c_3);
  tcase_add_test(tcase, test_s21_sprintf_sp_c_4);

  return tcase;
}