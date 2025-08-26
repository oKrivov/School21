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
  AddAritmeticSuitesIntoRunner(runner);
  AddBaseSuitesIntoRunner(runner);
  AddOperationsSuitesIntoRunner(runner);
}

void AddAritmeticSuitesIntoRunner(SRunner **runner) {
  srunner_add_suite(*runner, s21_ArithmeticSuite());
}
void AddBaseSuitesIntoRunner(SRunner **runner) {
  srunner_add_suite(*runner, s21_BaseSuite());
}
void AddOperationsSuitesIntoRunner(SRunner **runner) {
  srunner_add_suite(*runner, s21_OperationsSuite());
}