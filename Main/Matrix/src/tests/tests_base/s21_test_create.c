#include "../s21_tests_runner.h"

START_TEST(create_fail) {
  int code = s21_create_matrix(1, 1, NULL);

  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_fail_below_zero_row) {
  matrix_t a = {0};

  int code = s21_create_matrix(-1, 1, &a);

  ck_assert_int_eq(code, INCORRECT_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(create_fail_below_zero_col) {
  matrix_t a = {0};

  int code = s21_create_matrix(1, -1, &a);

  ck_assert_int_eq(code, INCORRECT_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(create_fail_below_zero) {
  matrix_t a = {0};

  int code = s21_create_matrix(-1, -1, &a);

  ck_assert_int_eq(code, INCORRECT_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(create_fail_below_zero_null) {
  int code = s21_create_matrix(-1, -1, NULL);

  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(create1) {
  matrix_t a = {0};

  int code = s21_create_matrix(1, 1, &a);

  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(a.rows, 1);
  ck_assert_int_eq(a.columns, 1);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(create2) {
  matrix_t a = {0};

  int code = s21_create_matrix(2, 1, &a);

  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(a.rows, 2);
  ck_assert_int_eq(a.columns, 1);
  s21_remove_matrix(&a);
}
END_TEST

TCase *s21_BaseTCaseCreate() {
  TCase *tcase = tcase_create("s21_BaseTCaseCreate");

  tcase_add_test(tcase, create_fail);
  tcase_add_test(tcase, create_fail_below_zero_row);
  tcase_add_test(tcase, create_fail_below_zero_col);
  tcase_add_test(tcase, create_fail_below_zero);
  tcase_add_test(tcase, create_fail_below_zero_null);
  tcase_add_test(tcase, create1);
  tcase_add_test(tcase, create2);

  return tcase;
}