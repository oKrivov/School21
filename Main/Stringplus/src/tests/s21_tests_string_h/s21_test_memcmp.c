#include "../s21_tests_main_runner.h"

START_TEST(memcmp_1) {
  char str1[] = "12345";
  char str2[] = "1234567890";
  int n = 4;
  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_2) {
  char str1[] = "Hello";
  char str2[] = "Hello world";
  int n = (int)strlen(str1);
  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_3) {
  char str1[] = "";
  char str2[] = "";
  int n = (int)strlen(str1);

  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_4) {
  char str1[10] = "1234567890";
  char str2[10] = "1234890";
  int n = 7;

  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_5) {
  char str1[] = "Hello";
  char str2[] = " world";
  int n = 1;
  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_6) {
  char str1[] = "  ";
  char str2[] = "1234890";
  int n = 2;
  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_7) {
  char str1[256] = "12345678901234567890";
  char str2[256] = "12348900987654321";
  int n = 17;
  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_8) {
  char str1[10] = "1234567890";
  char str2[10] = "1234890";
  int n = 7;
  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

/*
// segmentation fault
START_TEST(memcmp_9) {
  char *str1 = NULL;
  char str2[] = "1234890";
  int n = 1;
  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST
*/

START_TEST(memcmp_10) {
  char str1[] = "";
  char *str2 = NULL;
  int n = (int)strlen(str1);
  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  result = result > 0 ? 1 : result < 0 ? -1 : 0;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

TCase *s21_StringHTCaseMemcmp() {
  TCase *tcase = tcase_create("s21_StringHTCaseMemcmp");
  tcase_add_test(tcase, memcmp_1);
  tcase_add_test(tcase, memcmp_2);
  tcase_add_test(tcase, memcmp_3);
  tcase_add_test(tcase, memcmp_4);
  tcase_add_test(tcase, memcmp_5);
  tcase_add_test(tcase, memcmp_6);
  tcase_add_test(tcase, memcmp_7);
  tcase_add_test(tcase, memcmp_8);
  tcase_add_test(tcase, memcmp_10);
  //   tcase_add_test(tcase, memcmp_9); // segmentation fault

  return tcase;
}
