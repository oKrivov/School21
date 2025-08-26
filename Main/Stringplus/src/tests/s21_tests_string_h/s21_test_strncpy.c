#include "../s21_tests_main_runner.h"

START_TEST(strncpy_1) {
  char dest1[] = "1234567890";
  char dest2[] = "1234567890";
  char src[] = "abcdef";
  int n = 4;

  strncpy(dest1, src, n);
  dest1[n] = '\0';
  s21_strncpy(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_2) {
  char dest1[10] = "1234567890";
  char dest2[10] = "1234567890";
  char src[10] = "abc";
  int n = 6;

  strncpy(dest1, src, n);
  dest1[n] = '\0';
  s21_strncpy(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_3) {
  char dest1[10] = "1234567890";
  char dest2[10] = "1234567890";
  char src[10] = "abc";
  int n = 3;

  strncpy(dest1, src, n);
  dest1[n] = '\0';
  s21_strncpy(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_4) {
  char dest1[10] = "12345678";
  char dest2[10] = "12345678";
  char src[10] = "abcdefgh";
  int n = 6;
  strncpy(dest1, src, n);
  dest1[n] = '\0';
  s21_strncpy(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_5) {
  char dest1[10] = "12345678";
  char dest2[10] = "12345678";
  char src[10] = "abcdefgh";
  int n = 0;

  s21_strncpy(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_6) {
  char dest1[6] = "123456";
  char dest2[6] = "123456";
  char src[10] = "abcdefgh";
  int n = 5;
  strncpy(dest1, src, n);
  dest1[n] = '\0';
  s21_strncpy(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_7) {
  char dest1[] = "123456";
  char dest2[] = "123456";
  char src[7] = "abcd";
  dest1[strlen(dest1)] = '\0';

  strncpy(dest1, src, strlen(dest1));
  s21_strncpy(dest2, src, strlen(dest2));

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_8) {
  char dest[10] = "123456789";
  char src[10] = "abcdefgh";
  int n = 10;
  char *expected = strncpy(dest, src, n);
  char *result = s21_strncpy(dest, src, n);

  ck_assert_str_eq(expected, result);
}
END_TEST

START_TEST(strncpy_9) {
  char dest1[10] = "";
  char dest2[10] = "";
  char src[10] = "abc\0defgh";
  int n = 3;
  strncpy(dest1, src, sizeof(dest1));
  s21_strncpy(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_10) {
  char dest1[10] = "1234567";
  char dest2[10] = "1234567";
  char src[10] = "abc\0defgh";
  int n = 5;
  strncpy(dest1, src, sizeof(dest1));
  dest1[n] = '\0';
  s21_strncpy(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

TCase *s21_StringHTCaseStrncpy() {
  TCase *tcase = tcase_create("s21_StringHTCaseStrncpy");
  tcase_add_test(tcase, strncpy_1);
  tcase_add_test(tcase, strncpy_2);
  tcase_add_test(tcase, strncpy_3);
  tcase_add_test(tcase, strncpy_4);
  tcase_add_test(tcase, strncpy_5);
  tcase_add_test(tcase, strncpy_6);
  tcase_add_test(tcase, strncpy_7);
  tcase_add_test(tcase, strncpy_8);
  tcase_add_test(tcase, strncpy_9);
  tcase_add_test(tcase, strncpy_10);

  return tcase;
}
