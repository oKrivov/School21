#include "../s21_tests_main_runner.h"

#define N 1000

START_TEST(test_s21_sprintf_sp_p_1) {
  const char format[] = "%p and %p both are pointers";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  char symbol = 'x';

  int *number = malloc(sizeof(int));

  int standard = sprintf(sprintf_str, format, &symbol, number);
  int s21 = s21_sprintf(s21_sprintf_str, format, &symbol, number);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);

  if (number) {
    free(number);
  }
}
END_TEST

START_TEST(test_s21_sprintf_sp_p_2) {
  const char format[] = "Я рад вас видеть! %p'm glad to see you!";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  char symbol = 'I';

  int standard = sprintf(sprintf_str, format, &symbol);
  int s21 = s21_sprintf(s21_sprintf_str, format, &symbol);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_p_3) {
  const char format[] = "%p";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  char *empty = NULL;

  int standard = sprintf(sprintf_str, format, empty);
  int s21 = s21_sprintf(s21_sprintf_str, format, empty);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_p_4) {
  const char format[] = "%-10p and %-3p both are pointers";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  char symbol = 'x';

  int *number = malloc(sizeof(int));

  int standard = sprintf(sprintf_str, format, &symbol, number);
  int s21 = s21_sprintf(s21_sprintf_str, format, &symbol, number);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);

  if (number) {
    free(number);
  }
}
END_TEST

TCase *s21_SprintfTcaseSpP() {
  TCase *tcase = tcase_create("s21_SprintfTcaseSpP");

  tcase_add_test(tcase, test_s21_sprintf_sp_p_1);
  tcase_add_test(tcase, test_s21_sprintf_sp_p_2);
  tcase_add_test(tcase, test_s21_sprintf_sp_p_3);
  tcase_add_test(tcase, test_s21_sprintf_sp_p_4);

  return tcase;
}