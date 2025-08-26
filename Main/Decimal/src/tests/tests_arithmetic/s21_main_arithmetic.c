#include "../s21_tests_runner.h"

Suite *s21_AritmeticSuite() {
  Suite *suite = suite_create("s21_arithmetic");
  // add
  suite_add_tcase(suite, s21_AritmeticTCaseAdd());

  // sub
  suite_add_tcase(suite, s21_AritmeticTCaseSubInt());
  suite_add_tcase(suite, s21_AritmeticTCaseSubFloat());
  suite_add_tcase(suite, s21_AritmeticTCaseSubBigNumbers());

  // div
  suite_add_tcase(suite, s21_AritmeticTCaseDivInt());
  suite_add_tcase(suite, s21_AritmeticTCaseDivFloat());
  suite_add_tcase(suite, s21_AritmeticTCaseDivBigNumbers());

  // mul
  suite_add_tcase(suite, s21_AritmeticTCaseMul());

  return suite;
}
