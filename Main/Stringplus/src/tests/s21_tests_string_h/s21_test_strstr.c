#include "../s21_tests_main_runner.h"

START_TEST(strstr_1) {
  char str1[10] = "123456789";
  char str2[10] = "456";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(strstr_2) {
  char str1[10] = "";
  char str2[10] = "456";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(strstr_3) {
  char str1[10] = "abcd";
  char str2[10] = "456";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(strstr_4) {
  char str1[10] = "12345678";
  char str2[10] = "abc";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(strstr_5) {
  char str1[10] = "12345678";
  char str2[10] = "4\0";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(strstr_6) {
  char str1[20] = "abcdefg";
  char str2[10] = "abc";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(strstr_7) {
  char str1[20] = "abcdefg";
  char str2[10] = "efg";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(strstr_8) {
  char str1[20] = "abcdefg";
  char str2[1] = "";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(strstr_9) {
  char str1[1] = "";
  char str2[10] = "abcdefg";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(strstr_10) {
  char str1[10] = "abcdefg";
  char str2[10] = "xyz";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

TCase *s21_StringHTCaseStrstr() {
  TCase *tcase = tcase_create("s21_StringHTCaseStrstr");
  tcase_add_test(tcase, strstr_1);
  tcase_add_test(tcase, strstr_2);
  tcase_add_test(tcase, strstr_3);
  tcase_add_test(tcase, strstr_4);
  tcase_add_test(tcase, strstr_5);
  tcase_add_test(tcase, strstr_6);
  tcase_add_test(tcase, strstr_7);
  tcase_add_test(tcase, strstr_8);
  tcase_add_test(tcase, strstr_9);
  tcase_add_test(tcase, strstr_10);

  return tcase;
}
