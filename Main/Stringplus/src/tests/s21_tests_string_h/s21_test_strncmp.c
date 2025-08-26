#include "../s21_tests_main_runner.h"

START_TEST(strncmp_1) {
  const char str1[] = "This is a test string";
  const char str2[] = "This is a test string";
  int n = (int)strlen(str1);
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_2) {
  const char str1[] = "";
  const char str2[] = "";
  int n = (int)strlen(str1);
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_3) {
  const char str1[] = "1234567890";
  const char str2[] = "12345098765";
  int n = 4;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_4) {
  const char str1[] = "1234567890";
  const char str2[] = "12345098765";
  int n = 10;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_5) {
  const char str1[] = "Hello";
  const char str2[] = "world";
  int n = 1;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_6) {
  const char str1[10] = "1";
  const char str2[] = "12345098765";
  int n = 10;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_7) {
  const char str1[10] = "Hello";
  const char str2[] = "";
  int n = 1;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_8) {
  const char str1[10] = "Hello";
  const char str2[] = "";
  int n = 1;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_9) {
  const char str1[] = "Hello";
  const char str2[] = "";
  int n = 1;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_10) {
  const char str1[256] = "1245678900987654321";
  const char str2[256] = "12345678765432123456789";
  int n = 256;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

TCase *s21_StringHTCaseStrncmp() {
  TCase *tcase = tcase_create("s21_StringHTCaseStrncmp");
  tcase_add_test(tcase, strncmp_1);
  tcase_add_test(tcase, strncmp_2);
  tcase_add_test(tcase, strncmp_3);
  tcase_add_test(tcase, strncmp_4);
  tcase_add_test(tcase, strncmp_5);
  tcase_add_test(tcase, strncmp_6);
  tcase_add_test(tcase, strncmp_7);
  tcase_add_test(tcase, strncmp_8);
  tcase_add_test(tcase, strncmp_9);
  tcase_add_test(tcase, strncmp_10);

  return tcase;
}