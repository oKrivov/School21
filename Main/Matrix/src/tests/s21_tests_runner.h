#ifndef TESTS_RUN_H
#define TESTS_RUN_H

#include <check.h>

#include "../s21_matrix.h"

// TEST FOR ARITHMETIC
Suite *s21_ArithmeticSuite();

TCase *s21_ArithmeticTCaseSum();
TCase *s21_ArithmeticTCaseSub();
TCase *s21_ArithmeticTCaseMultNumber();
TCase *s21_ArithmeticTCaseMultMatrix();

// TESTS FOR BASE
Suite *s21_BaseSuite();

TCase *s21_BaseTCaseCreate();
TCase *s21_BaseTCaseRemove();
TCase *s21_BaseTCaseEqual();

// TESTS FOR OPERATIONS
Suite *s21_OperationsSuite();

TCase *s21_OperationsTCaseInverse();
TCase *s21_OperationsTCaseTranspose();
TCase *s21_OperationsTCaseComplements();
TCase *s21_OperationsTCaseDeterminant();

// run tests
void RunAllTests();

void AddAllSuitesIntoRunner(SRunner **runner);
void AddAritmeticSuitesIntoRunner(SRunner **runner);
void AddBaseSuitesIntoRunner(SRunner **runner);
void AddOperationsSuitesIntoRunner(SRunner **runner);

#endif  // TESTS_RUN_H