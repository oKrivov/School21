#include "../s21_tests_runner.h"

START_TEST(inverse_fail_NULL) {
  matrix_t m = {0}, check = {0};
  int row = 2, col = 2;
  s21_create_matrix(row, col, &m);
  s21_create_matrix(row, col, &check);

  ck_assert_int_eq(s21_inverse_matrix(&m, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(inverse_fail_NULL2) {
  matrix_t m = {0}, check = {0};
  int row = 2, col = 2;
  s21_create_matrix(row, col, &m);
  s21_create_matrix(row, col, &check);

  ck_assert_int_eq(s21_inverse_matrix(NULL, &m), INCORRECT_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(inverse_fail_size) {
  matrix_t m = {0};
  int row = 2, col = 2;
  s21_create_matrix(row + 1, col, &m);

  ck_assert_int_eq(s21_inverse_matrix(&m, &m), CALCULATION_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_self) {
  matrix_t res, m = {0}, check = {0};
  int row = 3, col = 3;
  s21_create_matrix(row, col, &m);
  s21_create_matrix(row, col, &check);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  ck_assert_int_eq(s21_inverse_matrix(&m, &res), OK);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = -1;
  check.matrix[0][2] = 1;
  check.matrix[1][0] = -38;
  check.matrix[1][1] = 41;
  check.matrix[1][2] = -34;
  check.matrix[2][0] = 27;
  check.matrix[2][1] = -29;
  check.matrix[2][2] = 24;
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(inverse_default) {
  matrix_t m = {0}, res, check = {0};
  int row = 3, col = 3;
  s21_create_matrix(row, col, &m);
  s21_create_matrix(row, col, &check);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  ck_assert_int_eq(s21_inverse_matrix(&m, &res), OK);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = -1;
  check.matrix[0][2] = 1;
  check.matrix[1][0] = -38;
  check.matrix[1][1] = 41;
  check.matrix[1][2] = -34;
  check.matrix[2][0] = 27;
  check.matrix[2][1] = -29;
  check.matrix[2][2] = 24;
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(inverse_one) {
  matrix_t m = {0}, res, check = {0};
  int row = 1, col = 1;
  s21_create_matrix(row, col, &m);
  s21_create_matrix(row, col, &check);

  m.matrix[0][0] = 2.0;

  ck_assert_int_eq(s21_inverse_matrix(&m, &res), OK);

  check.matrix[0][0] = 1 / 2.0;

  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

TCase *s21_OperationsTCaseInverse() {
  TCase *tcase = tcase_create("s21_OperationsTCaseInverse");

  tcase_add_test(tcase, inverse_fail_NULL);
  tcase_add_test(tcase, inverse_fail_NULL2);
  tcase_add_test(tcase, inverse_fail_size);
  tcase_add_test(tcase, inverse_self);
  tcase_add_test(tcase, inverse_default);
  tcase_add_test(tcase, inverse_one);

  return tcase;
}