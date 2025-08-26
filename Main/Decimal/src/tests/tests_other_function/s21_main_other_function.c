#include "../s21_tests_runner.h"

Suite *s21_OtherFunctionsSuite() {
  Suite *suite = suite_create("s21_other_functions");

  TCase *tc_negate = s21_NegateTCase();
  suite_add_tcase(suite, tc_negate);
  suite_add_tcase(suite, s21_FloorTCase());
  suite_add_tcase(suite, s21_RoundTCase());
  suite_add_tcase(suite, s21_TruncateTCase());

  return suite;
}
