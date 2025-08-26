#include "../s21_tests_runner.h"

START_TEST(transpose_fail_NULL) {
  ck_assert_int_eq(s21_transpose(NULL, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_fail_NULL2) {
  matrix_t a = {0};
  ck_assert_int_eq(s21_transpose(&a, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_check_sizes) {
  matrix_t a = {0}, b = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &a);
  ck_assert_int_eq(s21_transpose(&a, &b), OK);
  ck_assert_int_eq(b.columns, row);
  ck_assert_int_eq(b.rows, col);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(transpose_self) {
  matrix_t a = {0}, res;
  int row = 2, col = 3;
  s21_create_matrix(row, col, &a);
  ck_assert_int_eq(s21_transpose(&a, &res), OK);
  ck_assert_int_eq(res.columns, row);
  ck_assert_int_eq(res.rows, col);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose_res) {
  matrix_t a = {0}, b = {0}, check = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(col, row, &check);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) a.matrix[i][j] = i + j;
  ck_assert_int_eq(s21_transpose(&a, &b), OK);
  for (int i = 0; i < col; i++)
    for (int j = 0; j < row; j++) check.matrix[i][j] = i + j;
  ck_assert_int_eq(s21_eq_matrix(&b, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&check);
}
END_TEST

TCase *s21_OperationsTCaseTranspose() {
  TCase *tcase = tcase_create("s21_OperationsTCaseTranspose");

  tcase_add_test(tcase, transpose_fail_NULL);
  tcase_add_test(tcase, transpose_fail_NULL2);
  tcase_add_test(tcase, transpose_check_sizes);
  tcase_add_test(tcase, transpose_self);
  tcase_add_test(tcase, transpose_res);

  return tcase;
}