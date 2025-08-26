#include "../s21_tests_main_runner.h"

Suite *s21_StringHSuite() {
  Suite *suite = suite_create("s21_string_h");
  suite_add_tcase(suite, s21_StringHTCaseMemchr());
  suite_add_tcase(suite, s21_StringHTCaseMemcmp());
  suite_add_tcase(suite, s21_StringHTCaseMemcpy());
  suite_add_tcase(suite, s21_StringHTCaseMemset());
  suite_add_tcase(suite, s21_StringHTCaseStrchr());
  suite_add_tcase(suite, s21_StringHTCaseStrspn());
  suite_add_tcase(suite, s21_StringHTCaseStrerror());
  suite_add_tcase(suite, s21_StringHTCaseStrlen());
  suite_add_tcase(suite, s21_StringHTCaseStrncat());
  suite_add_tcase(suite, s21_StringHTCaseStrncpy());
  suite_add_tcase(suite, s21_StringHTCaseStrncmp());
  suite_add_tcase(suite, s21_StringHTCaseStrpbrk());
  suite_add_tcase(suite, s21_StringHTCaseStrrchr());
  suite_add_tcase(suite, s21_StringHTCaseStrstr());
  suite_add_tcase(suite, s21_StringHTCaseStrtok());

  return suite;
};