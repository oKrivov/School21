#include "../s21_tests_main_runner.h"

#define N 1000

START_TEST(test_s21_sprintf_sp_gG_1) {
  const char format[] = "%g";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, FLT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_gG_2) {
  const char format[] = "%G";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, FLT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_gG_3) {
  const char format[] = "Hello, %Lg!";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, LDBL_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, LDBL_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_gG_4) {
  const char format[] = "Hello, %LG!";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, LDBL_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, LDBL_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_gG_5) {
  const char format[] = "%-12g%-130LG \thello %-1g%-3LG";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard =
      sprintf(sprintf_str, format, FLT_MAX, LDBL_MAX, FLT_MAX, LDBL_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MAX, LDBL_MAX, FLT_MAX,
                        LDBL_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_gG_6) {
  const char format[] = "h %+ge%+Lg %+G \n%#010gl%#020LGo%#05g";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, FLT_MAX, LDBL_MAX, FLT_MAX,
                         FLT_MAX, LDBL_MAX, FLT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MAX, LDBL_MAX, FLT_MAX,
                        FLT_MAX, LDBL_MAX, FLT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_gG_7) {
  const char format[] = "рус h % .0ge% .10LGl % .10Lg\n%-12.10Gl%-13.10Lgo";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, FLT_MIN, LDBL_MIN, LDBL_MIN,
                         FLT_MAX, LDBL_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MIN, LDBL_MIN, LDBL_MIN,
                        FLT_MAX, LDBL_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_gG_8) {
  const char format[] = "h %+-12.2ge%+-13.10LGl \n%*.10Gl%-13.*Lgo";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int number1 = 0;
  int number2 = 10;

  int standard = sprintf(sprintf_str, format, FLT_MIN, LDBL_MIN, number1,
                         FLT_MAX, number2, LDBL_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MIN, LDBL_MIN, number1,
                        FLT_MAX, number2, LDBL_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

TCase *s21_SprintfTcaseSpG() {
  TCase *tcase = tcase_create("s21_SprintfTcaseSpG");

  tcase_add_test(tcase, test_s21_sprintf_sp_gG_1);
  tcase_add_test(tcase, test_s21_sprintf_sp_gG_2);
  tcase_add_test(tcase, test_s21_sprintf_sp_gG_3);
  tcase_add_test(tcase, test_s21_sprintf_sp_gG_4);
  tcase_add_test(tcase, test_s21_sprintf_sp_gG_5);
  tcase_add_test(tcase, test_s21_sprintf_sp_gG_6);
  tcase_add_test(tcase, test_s21_sprintf_sp_gG_7);
  tcase_add_test(tcase, test_s21_sprintf_sp_gG_8);
  return tcase;
}