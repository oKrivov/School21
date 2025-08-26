#include "s21_tests_main_runner.h"

int main() {
  RunAllTests();
  return 0;
}

void RunAllTests() {
  SRunner *runner = srunner_create(NULL);

  AddAllSuitesIntoRunner(&runner);

  srunner_run_all(runner, CK_NORMAL);

  srunner_ntests_failed(runner);

  srunner_free(runner);
}

void AddAllSuitesIntoRunner(SRunner **runner) {
  AddStringHSuitesIntoRunner(runner);
  AddSscanfSuitesIntoRunner(runner);
  AddStringCSSuitesIntoRunner(runner);

  srunner_add_suite(*runner, s21_SprintfSuite());
}

void AddStringHSuitesIntoRunner(SRunner **runner) {
  srunner_add_suite(*runner, s21_StringHSuite());
}

void AddSscanfSuitesIntoRunner(SRunner **runner) {
  srunner_add_suite(*runner, s21_Sscanf_Suite());
}

void AddStringCSSuitesIntoRunner(SRunner **runner) {
  srunner_add_suite(*runner, s21_insert_suite());
  srunner_add_suite(*runner, s21_to_lower_suite());
  srunner_add_suite(*runner, s21_to_upper_suite());
  srunner_add_suite(*runner, s21_trim_suite());
}
