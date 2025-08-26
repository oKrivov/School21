#include "../s21_tests_runner.h"

START_TEST(mult_num_fail) {
  matrix_t a = {0}, check = {0};
  int row = 1, col = 4;
  double num = 0;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) a.matrix[i][j] = i + j;

  ck_assert_int_eq(s21_mult_number(&a, num, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&a);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_num_bad_arr) {
  matrix_t a = {0};
  double num = 0;
  a.matrix = calloc(2, sizeof(double *));

  ck_assert_int_eq(s21_mult_number(&a, num, &a), INCORRECT_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(mult_num_self) {
  matrix_t a = {0}, check = {0}, res;
  int row = 2, col = 4;
  double num = 0.0;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) a.matrix[i][j] = i + j;

  ck_assert_int_eq(s21_mult_number(&a, num, &res), OK);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = (i + j) * num;
    }

  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_num) {
  matrix_t a = {0}, check = {0}, res;
  int row = 2, col = 4;
  double num = 0;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) a.matrix[i][j] = i + j;

  ck_assert_int_eq(s21_mult_number(&a, num, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = (i + j) * num;
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_num2) {
  matrix_t a = {0}, check = {0}, res;
  int row = 2, col = 4;
  double num = 2;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) a.matrix[i][j] = i + j;

  ck_assert_int_eq(s21_mult_number(&a, num, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = (i + j) * num;
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&check);
  s21_remove_matrix(&res);
}
END_TEST

TCase *s21_ArithmeticTCaseMultNumber() {
  TCase *tcase = tcase_create("s21_ArithmeticTCaseMultNumber");

  tcase_add_test(tcase, mult_num_fail);
  tcase_add_test(tcase, mult_num_bad_arr);
  tcase_add_test(tcase, mult_num_self);
  tcase_add_test(tcase, mult_num);
  tcase_add_test(tcase, mult_num2);

  return tcase;
}