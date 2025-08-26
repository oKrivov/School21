#include "../s21_tests_main_runner.h"

START_TEST(strerror_1) {
  for (int i = 0; i < 40; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(strerror_greater_than_errnum) {
  ck_assert_str_eq(strerror(256), s21_strerror(256));
}
END_TEST

START_TEST(strerror_less_than_zero) {
  ck_assert_str_eq(strerror(-1), s21_strerror(-1));
}
END_TEST

TCase *s21_StringHTCaseStrerror() {
  TCase *tcase = tcase_create("s21_StringHTCaseStrerror");
  tcase_add_test(tcase, strerror_1);
  tcase_add_test(tcase, strerror_greater_than_errnum);
  tcase_add_test(tcase, strerror_less_than_zero);

  return tcase;
}
