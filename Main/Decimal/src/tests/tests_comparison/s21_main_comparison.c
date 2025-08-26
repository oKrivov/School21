#include "../s21_tests_runner.h"

Suite *s21_ComparisonSuite() {
  Suite *suite = suite_create("s21_comparison");

  suite_add_tcase(suite, s21_ComparisonTCaseIsLess());
  suite_add_tcase(suite, s21_ComparisonTCaseIsLessOrEqual());
  suite_add_tcase(suite, s21_ComparisonTCaseIsGreater());
  suite_add_tcase(suite, s21_ComparisonTCaseIsGreaterOrEqual());
  suite_add_tcase(suite, s21_ComparisonTCaseIsEqual());
  suite_add_tcase(suite, s21_ComparisonTCaseIsNotEqual());

  return suite;
}