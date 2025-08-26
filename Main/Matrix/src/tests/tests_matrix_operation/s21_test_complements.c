#include "../s21_tests_runner.h"

START_TEST(calc_complements_fail_NULL) {
  matrix_t m = {0}, check = {0};
  int row = 2, col = 2;
  s21_create_matrix(row, col, &m);
  s21_create_matrix(row, col, &check);

  ck_assert_int_eq(s21_calc_complements(&m, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(calc_complements_fail_NULL2) {
  matrix_t m = {0}, check = {0};
  int row = 2, col = 2;
  s21_create_matrix(row, col, &m);
  s21_create_matrix(row, col, &check);

  ck_assert_int_eq(s21_calc_complements(NULL, &m), INCORRECT_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(calc_complements_fail_size) {
  matrix_t m = {0};
  int row = 2, col = 2;
  s21_create_matrix(row + 1, col, &m);

  ck_assert_int_eq(s21_calc_complements(&m, &m), CALCULATION_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(calc_complements_self) {
  matrix_t m = {0}, check = {0}, res;
  int row = 3, col = 3;
  s21_create_matrix(row, col, &m);
  s21_create_matrix(row, col, &check);

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][0] = 0;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;

  ck_assert_int_eq(s21_calc_complements(&m, &res), OK);
  check.matrix[0][0] = 0;
  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(calc_complements_default) {
  matrix_t m = {0}, res, check = {0};
  int row = 3, col = 3;
  s21_create_matrix(row, col, &m);
  s21_create_matrix(row, col, &check);

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][0] = 0;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;

  ck_assert_int_eq(s21_calc_complements(&m, &res), OK);
  check.matrix[0][0] = 0;
  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(calc_complements_one) {
  matrix_t m = {0}, res, check = {0};
  int row = 1, col = 1;
  s21_create_matrix(row, col, &m);
  s21_create_matrix(row, col, &check);

  m.matrix[0][0] = 5;

  ck_assert_int_eq(s21_calc_complements(&m, &res), OK);
  check.matrix[0][0] = 5;

  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

TCase *s21_OperationsTCaseComplements() {
  TCase *tcase = tcase_create("s21_OperationsTCaseComplements");

  tcase_add_test(tcase, calc_complements_fail_NULL);
  tcase_add_test(tcase, calc_complements_fail_NULL2);
  tcase_add_test(tcase, calc_complements_fail_size);
  tcase_add_test(tcase, calc_complements_self);
  tcase_add_test(tcase, calc_complements_default);
  tcase_add_test(tcase, calc_complements_one);

  return tcase;
}