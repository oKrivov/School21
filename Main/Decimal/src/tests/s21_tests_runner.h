#ifndef TESTS_RUN_H
#define TESTS_RUN_H

#include <check.h>

#include "../s21_decimal.h"

#define OK 0
#define TOO_LARGE 1
#define TOO_SMALL 2
#define DIV_BY_ZERO 3

#define TEST_OK 1
#define TEST_FAIL 0

#define TEST_OTHER_ERROR 1
#define TEST_OTHER_OK 0

// tests for conversion
Suite *s21_ConversionSuite();

TCase *s21_ConversionTCaseFromInt();
TCase *s21_ConversionTCaseFromFloat();
TCase *s21_ConversionTCaseToInt();
TCase *s21_ConversionTCaseToFloat();

// tests for arithmetic
Suite *s21_AritmeticSuite();

// add
TCase *s21_AritmeticTCaseAdd();
// mul
TCase *s21_AritmeticTCaseMul();

// sub
TCase *s21_AritmeticTCaseSubInt();
TCase *s21_AritmeticTCaseSubFloat();
TCase *s21_AritmeticTCaseSubBigNumbers();

// div
TCase *s21_AritmeticTCaseDivInt();
TCase *s21_AritmeticTCaseDivFloat();
TCase *s21_AritmeticTCaseDivBigNumbers();

// tests for comparison
Suite *s21_ComparisonSuite();

TCase *s21_ComparisonTCaseIsLess();
TCase *s21_ComparisonTCaseIsLessOrEqual();
TCase *s21_ComparisonTCaseIsGreater();
TCase *s21_ComparisonTCaseIsGreaterOrEqual();
TCase *s21_ComparisonTCaseIsEqual();
TCase *s21_ComparisonTCaseIsNotEqual();

// tests for other_function
Suite *s21_OtherFunctionsSuite();
TCase *s21_NegateTCase();

TCase *s21_FloorTCase();
TCase *s21_RoundTCase();
TCase *s21_TruncateTCase();

// run tests
void RunAllTests();

void AddAllSuitesIntoRunner(SRunner **runner);
void AddConversionSuitesIntoRunner(SRunner **runner);
void AddAritmeticSuitesIntoRunner(SRunner **runner);
void AddComparisonSuitesIntoRunner(SRunner **runner);
void AddOtherFunctionsSuitesIntoRunner(SRunner **runner);

#endif
