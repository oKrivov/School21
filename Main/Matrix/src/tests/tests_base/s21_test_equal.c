#include "../s21_tests_runner.h"

START_TEST(eq_fail_NULL) {
  matrix_t a = {0}, b = {0};
  int rows = 1, cols = 1;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &a), OK);
  ck_assert_int_eq(s21_create_matrix(rows, cols, &b), OK);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      b.matrix[i][j] = i + j;
      a.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_eq_matrix(NULL, &b), FAILURE);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_fail_size) {
  matrix_t a = {0}, b = {0};
  int rows = 2, cols = 1;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &a), OK);
  ck_assert_int_eq(s21_create_matrix(rows + 1, cols, &b), OK);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      b.matrix[i][j] = i + j;
      a.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_eq_matrix(&a, &b), FAILURE);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_fail_size2) {
  matrix_t a = {0}, b = {0};
  int rows = 2, cols = 1;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &a), OK);
  ck_assert_int_eq(s21_create_matrix(rows, cols + 1, &b), OK);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      b.matrix[i][j] = i + j;
      a.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_eq_matrix(&a, &b), FAILURE);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_fail_diff_value) {
  matrix_t a = {0}, b = {0};
  int rows = 2, cols = 1;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &a), OK);
  ck_assert_int_eq(s21_create_matrix(rows, cols + 1, &b), OK);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      b.matrix[i][j] = i + j;
      a.matrix[i][j] = i + j + 1;
    }

  ck_assert_int_eq(s21_eq_matrix(&a, &b), FAILURE);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_fail_diff_value2) {
  matrix_t a = {0}, b = {0};
  int rows = 2, cols = 1;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &a), OK);
  ck_assert_int_eq(s21_create_matrix(rows, cols + 1, &b), OK);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      b.matrix[i][j] = i + j;
      a.matrix[i][j] = i + j;
    }
  a.matrix[0][0] = -10;
  ck_assert_int_eq(s21_eq_matrix(&a, &b), FAILURE);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_fail_small) {
  matrix_t a = {0}, b = {0};
  int rows = 2, cols = 2;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &a), OK);
  ck_assert_int_eq(s21_create_matrix(rows, cols, &b), OK);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      b.matrix[i][j] = 0;
      a.matrix[i][j] = 0;
    }
  a.matrix[0][0] = 0.0001;
  ck_assert_int_eq(s21_eq_matrix(&a, &b), FAILURE);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq1) {
  matrix_t a = {0}, b = {0};
  int rows = 1, cols = 1;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &a), OK);
  ck_assert_int_eq(s21_create_matrix(rows, cols, &b), OK);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      b.matrix[i][j] = i + j;
      a.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_eq_matrix(&a, &b), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}

START_TEST(eq_square) {
  matrix_t a = {0}, b = {0};
  int rows = 2, cols = 2;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &a), OK);
  ck_assert_int_eq(s21_create_matrix(rows, cols, &b), OK);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      b.matrix[i][j] = i + j;
      a.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_eq_matrix(&a, &b), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_rectangle) {
  matrix_t a = {0}, b = {0};
  int rows = 2, cols = 3;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &a), OK);
  ck_assert_int_eq(s21_create_matrix(rows, cols, &b), OK);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      b.matrix[i][j] = i + j;
      a.matrix[i][j] = i + j;
    }

  ck_assert_int_eq(s21_eq_matrix(&a, &b), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_same) {
  matrix_t a = {0};
  int rows = 2, cols = 3;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &a), OK);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) a.matrix[i][j] = i + j;

  ck_assert_int_eq(s21_eq_matrix(&a, &a), SUCCESS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(eq_small) {
  matrix_t a = {0}, b = {0};
  int rows = 2, cols = 2;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &a), OK);
  ck_assert_int_eq(s21_create_matrix(rows, cols, &b), OK);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      b.matrix[i][j] = 0;
      a.matrix[i][j] = 0;
    }
  a.matrix[0][0] = 0.00000001;
  ck_assert_int_eq(s21_eq_matrix(&a, &b), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

TCase *s21_BaseTCaseEqual() {
  TCase *tcase = tcase_create("s21_BaseTCaseEqual");

  tcase_add_test(tcase, eq_fail_NULL);
  tcase_add_test(tcase, eq_fail_size);
  tcase_add_test(tcase, eq_fail_size2);
  tcase_add_test(tcase, eq_fail_diff_value);
  tcase_add_test(tcase, eq_fail_diff_value2);
  tcase_add_test(tcase, eq1);
  tcase_add_test(tcase, eq_square);
  tcase_add_test(tcase, eq_rectangle);
  tcase_add_test(tcase, eq_same);
  tcase_add_test(tcase, eq_fail_small);
  tcase_add_test(tcase, eq_small);

  return tcase;
}