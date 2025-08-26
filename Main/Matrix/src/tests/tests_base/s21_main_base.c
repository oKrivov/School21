#include "../s21_tests_runner.h"

Suite *s21_BaseSuite() {
  Suite *suite = suite_create("s21_base");

  suite_add_tcase(suite, s21_BaseTCaseCreate());
  suite_add_tcase(suite, s21_BaseTCaseEqual());
  suite_add_tcase(suite, s21_BaseTCaseRemove());

  return suite;
}