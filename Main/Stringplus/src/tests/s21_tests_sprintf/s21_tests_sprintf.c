#include "../s21_tests_main_runner.h"

Suite *s21_SprintfSuite() {
  Suite *suite = suite_create("s21_sprintf");

  suite_add_tcase(suite, s21_SprintfTcaseDefault());
  //  остальные suite (для спецификаторов)
  suite_add_tcase(suite, s21_SprintfTcaseSpPercent());
  suite_add_tcase(suite, s21_SprintfTcaseSpDI());
  suite_add_tcase(suite, s21_SprintfTcaseSpC());
  suite_add_tcase(suite, s21_SprintfTcaseSpU());
  suite_add_tcase(suite, s21_SprintfTcaseSpOX());
  suite_add_tcase(suite, s21_SprintfTcaseSpS());
  suite_add_tcase(suite, s21_SprintfTcaseSpFE());
  suite_add_tcase(suite, s21_SprintfTcaseSpP());
  suite_add_tcase(suite, s21_SprintfTcaseSpG());
  // suite_add_tcase(suite, s21_SprintfTcaseSpN());

  return suite;
}