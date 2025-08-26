#include "../s21_tests_runner.h"

Suite *s21_ArithmeticSuite() {
  Suite *suite = suite_create("s21_arithmetic");

  suite_add_tcase(suite, s21_ArithmeticTCaseSum());
  suite_add_tcase(suite, s21_ArithmeticTCaseSub());
  suite_add_tcase(suite, s21_ArithmeticTCaseMultNumber());
  suite_add_tcase(suite, s21_ArithmeticTCaseMultMatrix());

  return suite;
}