#include "../s21_tests_main_runner.h"

#define N 1000

START_TEST(test_s21_sprintf_sp_feE_1) {
  const char format[] = "%f";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, FLT_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_feE_2) {
  const char format[] = "%e";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, FLT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_feE_3) {
  const char format[] = "%E";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, FLT_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_feE_4) {
  const char format[] = "Hello, %Lf!";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, LDBL_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, LDBL_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_feE_5) {
  const char format[] = "Hello, %Le!";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, LDBL_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, LDBL_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_feE_6) {
  const char format[] = "Hello, %LE!";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, LDBL_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, LDBL_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_feE_7) {
  const char format[] = "Hello, %.10f!";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, DBL_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, DBL_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_feE_8) {
  const char format[] = "Hello, %.10e!";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, DBL_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, DBL_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_feE_9) {
  const char format[] = "Hello, %.10E!";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, DBL_MAX);
  int s21 = s21_sprintf(s21_sprintf_str, format, DBL_MAX);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_feE_10) {
  const char format[] = "%-12f%-130Lf \thello %-1e%-3LE";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard =
      sprintf(sprintf_str, format, FLT_MIN, LDBL_MIN, FLT_MIN, LDBL_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MIN, LDBL_MIN, FLT_MIN,
                        LDBL_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_feE_11) {
  const char format[] = "h %+fe%+Le %+El \n%#010el%#020LEo%#05f";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, FLT_MIN, LDBL_MIN, FLT_MIN,
                         FLT_MIN, LDBL_MIN, FLT_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MIN, LDBL_MIN, FLT_MIN,
                        FLT_MIN, LDBL_MIN, FLT_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_feE_12) {
  const char format[] = "рус h % .0fe% .10Lel % .10LE\n%-12.13El%-132.13Lfo";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int standard = sprintf(sprintf_str, format, FLT_MIN, LDBL_MIN, LDBL_MIN,
                         FLT_MIN, LDBL_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MIN, LDBL_MIN, LDBL_MIN,
                        FLT_MIN, LDBL_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_feE_13) {
  const char format[] = "h %+-12.2fe%+-13.10Lel \n%*.13El%-132.*Lfo";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  int number1 = 0;
  int number2 = 10;

  int standard = sprintf(sprintf_str, format, FLT_MIN, LDBL_MIN, number1,
                         FLT_MIN, number2, LDBL_MIN);
  int s21 = s21_sprintf(s21_sprintf_str, format, FLT_MIN, LDBL_MIN, number1,
                        FLT_MIN, number2, LDBL_MIN);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

TCase *s21_SprintfTcaseSpFE() {
  TCase *tcase = tcase_create("s21_SprintfTcaseSpFE");

  tcase_add_test(tcase, test_s21_sprintf_sp_feE_1);
  tcase_add_test(tcase, test_s21_sprintf_sp_feE_2);
  tcase_add_test(tcase, test_s21_sprintf_sp_feE_3);
  tcase_add_test(tcase, test_s21_sprintf_sp_feE_4);
  tcase_add_test(tcase, test_s21_sprintf_sp_feE_5);
  tcase_add_test(tcase, test_s21_sprintf_sp_feE_6);
  tcase_add_test(tcase, test_s21_sprintf_sp_feE_7);
  tcase_add_test(tcase, test_s21_sprintf_sp_feE_8);
  tcase_add_test(tcase, test_s21_sprintf_sp_feE_9);
  tcase_add_test(tcase, test_s21_sprintf_sp_feE_10);
  tcase_add_test(tcase, test_s21_sprintf_sp_feE_11);
  tcase_add_test(tcase, test_s21_sprintf_sp_feE_12);
  tcase_add_test(tcase, test_s21_sprintf_sp_feE_13);
  return tcase;
}