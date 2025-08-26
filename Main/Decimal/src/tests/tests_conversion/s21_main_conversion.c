#include "../s21_tests_runner.h"

Suite *s21_ConversionSuite() {
  Suite *suite = suite_create("s21_conversion");

  suite_add_tcase(suite, s21_ConversionTCaseFromInt());
  suite_add_tcase(suite, s21_ConversionTCaseFromFloat());
  suite_add_tcase(suite, s21_ConversionTCaseToInt());
  suite_add_tcase(suite, s21_ConversionTCaseToFloat());

  return suite;
}
