#include "../s21_tests_runner.h"

START_TEST(sub_fail_size) {
  matrix_t a = {0}, b = {0}, res;
  int row = 2, col = 2;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col + 1, &b);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_sub_matrix(&a, &b, &res), CALCULATION_ERROR);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sub_fail_size2) {
  matrix_t a = {0}, b = {0}, res;
  int row = 2, col = 2;
  s21_create_matrix(row, col + 1, &a);
  s21_create_matrix(row, col, &b);

  for (int i = 0; i < b.rows; i++)
    for (int j = 0; j < b.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_sub_matrix(&a, &b, &res), CALCULATION_ERROR);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sub_fail_NULL) {
  matrix_t a = {0}, b = {0};
  int row = 2, col = 2;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &b);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_sub_matrix(&a, &b, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sub_fail_NULL2) {
  matrix_t a = {0};
  int row = 2, col = 2;
  s21_create_matrix(row, col, &a);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) a.matrix[i][j] = i + j;

  ck_assert_int_eq(s21_sub_matrix(&a, NULL, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(sub_fail_NULL_NULL) {
  matrix_t a = {0};
  int row = 2, col = 2;
  s21_create_matrix(row, col, &a);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) a.matrix[i][j] = i + j;

  ck_assert_int_eq(s21_sub_matrix(&a, NULL, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(sub) {
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

  ck_assert_int_eq(s21_sub_matrix(&a, &b, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = i + j - (i + j);
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sub1) {
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

  ck_assert_int_eq(s21_sub_matrix(&a, &b, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = i + j - (i + j);
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sub_rectangle) {
  matrix_t a = {0}, b = {0}, res, check = {0};
  int row = 2, col = 4;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &b);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j + 1;
      b.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_sub_matrix(&a, &b, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = (i + j + 1) - (i + j);
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sub_self) {
  matrix_t a = {0}, b = {0}, check = {0}, res;
  int row = 2, col = 4;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &b);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = i + j + 1;
    }

  ck_assert_int_eq(s21_sub_matrix(&a, &b, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = i + j - (i + j + 1);
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sub_self2) {
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

  ck_assert_int_eq(s21_sub_matrix(&a, &b, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = i + j - (i + j);
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sub_self_self) {
  matrix_t a = {0}, check = {0}, res;
  int row = 2, col = 4;
  s21_create_matrix(row, col, &a);
  s21_create_matrix(row, col, &check);

  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) a.matrix[i][j] = i + j;

  ck_assert_int_eq(s21_sub_matrix(&a, &a, &res), OK);
  for (int i = 0; i < a.rows; i++)
    for (int j = 0; j < a.columns; j++) {
      check.matrix[i][j] = i + j - (i + j);
    }
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&check);
  s21_remove_matrix(&res);
}
END_TEST

TCase *s21_ArithmeticTCaseSub() {
  TCase *tcase = tcase_create("s21_ArithmeticTCaseSub");

  tcase_add_test(tcase, sub_fail_size);
  tcase_add_test(tcase, sub_fail_size2);
  tcase_add_test(tcase, sub_fail_NULL);
  tcase_add_test(tcase, sub_fail_NULL2);
  tcase_add_test(tcase, sub_fail_NULL_NULL);
  tcase_add_test(tcase, sub);
  tcase_add_test(tcase, sub1);
  tcase_add_test(tcase, sub_rectangle);
  tcase_add_test(tcase, sub_self);
  tcase_add_test(tcase, sub_self_self);
  tcase_add_test(tcase, sub_self2);

  return tcase;
}