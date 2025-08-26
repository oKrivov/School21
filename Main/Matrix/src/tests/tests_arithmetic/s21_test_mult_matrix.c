#include "../s21_tests_runner.h"

START_TEST(mul_matrix_fail_NULL) {
  matrix_t a = {0}, b = {0}, check = {0};
  int row = 1, col = 1;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &b);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_mult_matrix(&a, &b, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mul_matrix_fail_calc_error) {
  matrix_t a = {0}, b = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &b);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_mult_matrix(&a, &b, &a), CALCULATION_ERROR);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(mul_matrix1) {
  matrix_t a = {0}, b = {0}, res, check = {0};
  int row = 1, col = 1;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &b);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_mult_matrix(&a, &b, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = (i + j) * (i + j);
    }

  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mul_matrix_square) {
  matrix_t a = {0}, b = {0}, res, check = {0};
  int row = 2, col = 2;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &b);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_mult_matrix(&a, &b, &res), OK);

  check.matrix[0][0] = 1;
  check.matrix[0][1] = 2;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 5;
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mul_matrix_rect) {
  matrix_t a = {0}, b = {0}, res, check = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(col, row, &b);
  s21_create_matrix(row, col - 1, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) a.matrix[i][j] = i + j;
  b.matrix[0][0] = 0;
  b.matrix[0][1] = 1;
  b.matrix[1][0] = 1;
  b.matrix[1][1] = 2;
  b.matrix[2][0] = 2;
  b.matrix[2][1] = 3;

  ck_assert_int_eq(s21_mult_matrix(&a, &b, &res), OK);
  check.matrix[0][0] = 5;
  check.matrix[0][1] = 8;
  check.matrix[1][0] = 8;
  check.matrix[1][1] = 14;
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mul_matrix1_self) {
  matrix_t a = {0}, b = {0}, check = {0}, res;
  int row = 1, col = 1;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &b);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_mult_matrix(&a, &b, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = (i + j) * (i + j);
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&check);
  s21_remove_matrix(&res);
}
END_TEST

TCase *s21_ArithmeticTCaseMultMatrix() {
  TCase *tcase = tcase_create("s21_ArithmeticTCaseMultMatrix");

  tcase_add_test(tcase, mul_matrix_fail_NULL);
  tcase_add_test(tcase, mul_matrix_fail_calc_error);
  tcase_add_test(tcase, mul_matrix1);
  tcase_add_test(tcase, mul_matrix_square);
  tcase_add_test(tcase, mul_matrix_rect);
  tcase_add_test(tcase, mul_matrix1_self);

  return tcase;
}