#include "../s21_tests_runner.h"

START_TEST(determinant_fail_NULL_NULL) {
  ck_assert_int_eq(s21_determinant(NULL, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_fail_NULL) {
  matrix_t a = {0};
  ck_assert_int_eq(s21_determinant(&a, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_fail_calc) {
  matrix_t a = {0};
  s21_create_matrix(1, 2, &a);
  double res = 0;
  ck_assert_int_eq(s21_determinant(&a, &res), CALCULATION_ERROR);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant1) {
  matrix_t a = {0};
  double res = 0;
  int row = 1, col = 1;
  s21_create_matrix(row, col, &a);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) a.matrix[i][j] = i + j + 1;
  ck_assert_int_eq(s21_determinant(&a, &res), OK);
  ck_assert_double_eq(res, 1);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant2) {
  matrix_t a = {0};
  double res = 0;
  int row = 2, col = 2;
  s21_create_matrix(row, col, &a);
  a.matrix[0][0] = 4;
  a.matrix[0][1] = 2;
  a.matrix[1][0] = 2;
  a.matrix[1][1] = 1;
  ck_assert_int_eq(s21_determinant(&a, &res), OK);
  ck_assert_double_eq(res, 0);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant3) {
  matrix_t a = {0};
  double res = 0;
  int row = 3, col = 3;
  s21_create_matrix(row, col, &a);
  a.matrix[0][0] = 2;
  a.matrix[0][1] = 5;
  a.matrix[0][2] = 7;

  a.matrix[1][0] = 6;
  a.matrix[1][1] = 3;
  a.matrix[1][2] = 4;

  a.matrix[2][0] = 5;
  a.matrix[2][1] = -2;
  a.matrix[2][2] = -3;
  ck_assert_int_eq(s21_determinant(&a, &res), OK);
  ck_assert_double_eq(res, -1);
  s21_remove_matrix(&a);
}
END_TEST

TCase *s21_OperationsTCaseDeterminant() {
  TCase *tcase = tcase_create("s21_OperationsTCaseDeterminant");

  tcase_add_test(tcase, determinant_fail_NULL_NULL);
  tcase_add_test(tcase, determinant_fail_NULL);
  tcase_add_test(tcase, determinant_fail_calc);
  tcase_add_test(tcase, determinant1);
  tcase_add_test(tcase, determinant2);
  tcase_add_test(tcase, determinant3);

  return tcase;
}