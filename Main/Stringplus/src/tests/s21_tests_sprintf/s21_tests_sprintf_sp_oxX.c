#include "../s21_tests_main_runner.h"

#define N 1000

START_TEST(test_s21_sprintf_sp_oxX_1) {
  const char format[] = "%o";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, UINT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, UINT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_oxX_2) {
  const char format[] = "%x";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, UINT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, UINT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_oxX_3) {
  const char format[] = "%X";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, UINT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, UINT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_oxX_4) {
  const char format[] = "a b c d e %#llo letters %#llx /// %#llX f u";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard =
      sprintf(sprintf_str, format, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
  int s21 =
      s21_sprintf(s21_sprintf_str, format, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_oxX_5) {
  const char format[] = "a d s ddsdadad%.7lo letters %.6lx /// %.5lX asdasfwef";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, ULONG_MAX, ULONG_MAX, ULONG_MAX);
  int s21 =
      s21_sprintf(s21_sprintf_str, format, ULONG_MAX, ULONG_MAX, ULONG_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_oxX_6) {
  const char format[] = "jeis[pa[]daopfj %-1hodsadada %-2hxdsd %-3hXdsds";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, USHRT_MAX, USHRT_MAX, USHRT_MAX);
  int s21 =
      s21_sprintf(s21_sprintf_str, format, USHRT_MAX, USHRT_MAX, USHRT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_oxX_7) {
  const char format[] = "ss %-10.1hho %-5.5hhx ,,, %-20.2hhXadada";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, UCHAR_MAX, UCHAR_MAX, UCHAR_MAX);
  int s21 =
      s21_sprintf(s21_sprintf_str, format, UCHAR_MAX, UCHAR_MAX, UCHAR_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_oxX_8) {
  const char format[] = "%010hhobefore specifier %010hhx after %-13.0X";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, UCHAR_MAX, UCHAR_MAX, UINT_MAX);
  int s21 =
      s21_sprintf(s21_sprintf_str, format, UCHAR_MAX, UCHAR_MAX, UINT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_oxX_9) {
  const char format[] =
      "%-123hho before specifier %-20.2llx after %.0u%02u %-1X";
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

TCase *s21_SprintfTcaseSpOX() {
  TCase *tcase = tcase_create("s21_SprintfTcaseSpOX");

  tcase_add_test(tcase, test_s21_sprintf_sp_oxX_1);
  tcase_add_test(tcase, test_s21_sprintf_sp_oxX_2);
  tcase_add_test(tcase, test_s21_sprintf_sp_oxX_3);
  tcase_add_test(tcase, test_s21_sprintf_sp_oxX_4);
  tcase_add_test(tcase, test_s21_sprintf_sp_oxX_5);
  tcase_add_test(tcase, test_s21_sprintf_sp_oxX_6);
  tcase_add_test(tcase, test_s21_sprintf_sp_oxX_7);
  tcase_add_test(tcase, test_s21_sprintf_sp_oxX_8);
  tcase_add_test(tcase, test_s21_sprintf_sp_oxX_9);

  return tcase;
}