#include "../s21_tests_runner.h"

START_TEST(add_fail_size) {
  matrix_t a = {0}, b = {0}, res;
  int row = 2, col = 2;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col + 1, &b);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_sum_matrix(&a, &b, &res), CALCULATION_ERROR);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(add_fail_size2) {
  matrix_t a = {0}, b = {0}, res;
  int row = 2, col = 2;
  s21_create_matrix(row, col + 1, &a);
  s21_create_matrix(row, col, &b);

  for (int i = 0; i < b.rows; i++)
    for (int j = 0; j < b.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_sum_matrix(&a, &b, &res), CALCULATION_ERROR);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(add_fail_NULL) {
  matrix_t a = {0}, b = {0};
  int row = 2, col = 2;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &b);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_sum_matrix(&a, &b, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(add_fail_NULL2) {
  matrix_t a = {0};
  int row = 2, col = 2;
  s21_create_matrix(row, col, &a);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) a.matrix[i][j] = i + j;

  ck_assert_int_eq(s21_sum_matrix(&a, NULL, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(add) {
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

  ck_assert_int_eq(s21_sum_matrix(&a, &b, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = i + j + i + j;
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(add1) {
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

  ck_assert_int_eq(s21_sum_matrix(&a, &b, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = i + j + i + j;
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(add_rectangle) {
  matrix_t a = {0}, b = {0}, res, check = {0};
  int row = 2, col = 4;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &b);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_sum_matrix(&a, &b, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = i + j + i + j;
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(add_self) {
  matrix_t a = {0}, b = {0}, check = {0}, res;
  int row = 2, col = 4;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &b);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_sum_matrix(&a, &b, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = i + j + i + j;
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(add_self2) {
  matrix_t a = {0}, b = {0}, check = {0}, res;
  int row = 2, col = 4;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &b);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_sum_matrix(&a, &b, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = i + j + i + j;
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(add_self_self) {
  matrix_t a = {0}, check = {0}, res;
  int row = 2, col = 4;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) a.matrix[i][j] = i + j;

  ck_assert_int_eq(s21_sum_matrix(&a, &a, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = i + j + i + j;
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

TCase *s21_ArithmeticTCaseSum() {
  TCase *tcase = tcase_create("s21_ArithmeticTCaseSum");

  tcase_add_test(tcase, add_fail_size);
  tcase_add_test(tcase, add_fail_size2);
  tcase_add_test(tcase, add_fail_NULL);
  tcase_add_test(tcase, add_fail_NULL2);

  tcase_add_test(tcase, add);
  tcase_add_test(tcase, add1);
  tcase_add_test(tcase, add_rectangle);
  tcase_add_test(tcase, add_self);
  tcase_add_test(tcase, add_self2);
  tcase_add_test(tcase, add_self_self);

  return tcase;
}