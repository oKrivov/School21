#include "../s21_tests_runner.h"

START_TEST(remove1) {
  matrix_t a = {0};

  s21_create_matrix(2, 1, &a);

  s21_remove_matrix(&a);
}
END_TEST

START_TEST(remove_NULL) { s21_remove_matrix(NULL); }
END_TEST

TCase *s21_BaseTCaseRemove() {
  TCase *tcase = tcase_create("s21_BaseTCaseRemove");
  tcase_add_test(tcase, remove1);
  tcase_add_test(tcase, remove_NULL);
  return tcase;
}