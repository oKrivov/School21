#include "../s21_tests_runner.h"

Suite *s21_OperationsSuite() {
  Suite *suite = suite_create("s21_operations");

  suite_add_tcase(suite, s21_OperationsTCaseComplements());
  suite_add_tcase(suite, s21_OperationsTCaseDeterminant());
  suite_add_tcase(suite, s21_OperationsTCaseTranspose());
  suite_add_tcase(suite, s21_OperationsTCaseInverse());

  return suite;
}