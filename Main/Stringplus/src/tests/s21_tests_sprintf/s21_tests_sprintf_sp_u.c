#include "../s21_tests_main_runner.h"

#define N 1000

START_TEST(test_s21_sprintf_sp_u_1) {
  const char format[] = "%u";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, UINT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, UINT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_u_2) {
  const char format[] = "%lu%llu";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, ULONG_MAX, ULLONG_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, ULONG_MAX, ULLONG_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_u_3) {
  const char format[] = "%hu";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, USHRT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, USHRT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_u_4) {
  const char format[] = "%hhu";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, UCHAR_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, UCHAR_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_u_5) {
  const char format[] = "before specifier %010hhu after %u";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, UCHAR_MAX, UINT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, UCHAR_MAX, UINT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_u_6) {
  const char format[] =
      "%-123hhu before specifier %-20.2llu after %.0u%02u %-1u";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, UCHAR_MAX, ULLONG_MAX, UINT_MAX,
                         UINT_MAX, UINT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, UCHAR_MAX, ULLONG_MAX,
                        UINT_MAX, UINT_MAX, UINT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

TCase *s21_SprintfTcaseSpU() {
  TCase *tcase = tcase_create("s21_SprintfTcaseSpU");

  tcase_add_test(tcase, test_s21_sprintf_sp_u_1);
  tcase_add_test(tcase, test_s21_sprintf_sp_u_2);
  tcase_add_test(tcase, test_s21_sprintf_sp_u_3);
  tcase_add_test(tcase, test_s21_sprintf_sp_u_4);
  tcase_add_test(tcase, test_s21_sprintf_sp_u_5);
  tcase_add_test(tcase, test_s21_sprintf_sp_u_6);

  return tcase;
}