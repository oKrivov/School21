#include "s21_tests_runner.h"

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
  AddConversionSuitesIntoRunner(runner);
  AddAritmeticSuitesIntoRunner(runner);
  AddComparisonSuitesIntoRunner(runner);
  AddOtherFunctionsSuitesIntoRunner(runner);
}

void AddConversionSuitesIntoRunner(SRunner **runner) {
  srunner_add_suite(*runner, s21_ConversionSuite());
}

void AddAritmeticSuitesIntoRunner(SRunner **runner) {
  srunner_add_suite(*runner, s21_AritmeticSuite());
}

void AddComparisonSuitesIntoRunner(SRunner **runner) {
  srunner_add_suite(*runner, s21_ComparisonSuite());
}

void AddOtherFunctionsSuitesIntoRunner(SRunner **runner) {
  srunner_add_suite(*runner, s21_OtherFunctionsSuite());
}
