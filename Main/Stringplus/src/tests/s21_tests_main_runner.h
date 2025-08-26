#ifndef TESTS_RUN_H
#define TESTS_RUN_H

#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_string.h"

// tests for string.h
Suite *s21_StringHSuite();

TCase *s21_StringHTCaseMemcmp();
TCase *s21_StringHTCaseMemchr();
TCase *s21_StringHTCaseMemcpy();
TCase *s21_StringHTCaseMemset();
TCase *s21_StringHTCaseStrchr();
TCase *s21_StringHTCaseStrspn();
TCase *s21_StringHTCaseStrerror();
TCase *s21_StringHTCaseStrlen();
TCase *s21_StringHTCaseStrncat();
TCase *s21_StringHTCaseStrncpy();
TCase *s21_StringHTCaseStrncmp();
TCase *s21_StringHTCaseStrpbrk();
TCase *s21_StringHTCaseStrrchr();
TCase *s21_StringHTCaseStrstr();
TCase *s21_StringHTCaseStrtok();

// tests for s21_printf
Suite *s21_SprintfSuite();

TCase *s21_SprintfTcaseDefault();
// остальные(спецификаторы)
TCase *s21_SprintfTcaseSpPercent();
TCase *s21_SprintfTcaseSpDI();
TCase *s21_SprintfTcaseSpC();
TCase *s21_SprintfTcaseSpU();
TCase *s21_SprintfTcaseSpOX();
TCase *s21_SprintfTcaseSpS();
TCase *s21_SprintfTcaseSpFE();
TCase *s21_SprintfTcaseSpP();
TCase *s21_SprintfTcaseSpG();
// TCase *s21_SprintfTcaseSpN();

// tests for s21_sscanf
Suite *s21_Sscanf_Suite(void);

// tests for s21_string_cs
Suite *s21_insert_suite();
Suite *s21_to_lower_suite();
Suite *s21_to_upper_suite();
Suite *s21_trim_suite();

// run tests
void RunAllTests();

void AddAllSuitesIntoRunner(SRunner **runner);
void AddStringHSuitesIntoRunner(SRunner **runner);
void AddSscanfSuitesIntoRunner(SRunner **runner);
void AddStringCSSuitesIntoRunner(SRunner **runner);

#endif