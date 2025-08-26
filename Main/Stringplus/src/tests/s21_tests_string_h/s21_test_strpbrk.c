#include "../s21_tests_main_runner.h"

START_TEST(strpbrk_1) {
  char str1[10] = "123456789";
  char str2[10] = "123";

  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_2) {
  char str1[10] = "";
  char str2[10] = "xyz";
  if (NULL == strpbrk(str1, str2))
    ck_assert_ptr_null(s21_strpbrk(str1, str2));
  else
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_3) {
  char str1[10] = "12345678";
  char str2[10] = "xyz";
  if (NULL == strpbrk(str1, str2))
    ck_assert_ptr_null(s21_strpbrk(str1, str2));
  else
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_4) {
  char str1[10] = "12345678";
  char str2[10] = "";
  if (NULL == strpbrk(str1, str2))
    ck_assert_ptr_null(s21_strpbrk(str1, str2));
  else
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_5) {
  char str1[10] = "";
  char str2[10] = "";
  if (NULL == strpbrk(str1, str2))
    ck_assert_ptr_null(s21_strpbrk(str1, str2));
  else
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_6) {
  char str1[10] = "\0";
  char str2[10] = "\0";
  if (NULL == strpbrk(str1, str2))
    ck_assert_ptr_null(s21_strpbrk(str1, str2));
  else
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_7) {
  char str1[10] = "1234567890";
  char str2[10] = "07";
  if (NULL == strpbrk(str1, str2))
    ck_assert_ptr_null(s21_strpbrk(str1, str2));
  else
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_8) {
  char str1[10] = "1234567890";
  char str2[10] = "6";
  if (NULL == strpbrk(str1, str2))
    ck_assert_ptr_null(s21_strpbrk(str1, str2));
  else
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_9) {
  char str1[10] = "7";
  char str2[10] = "567890";
  if (NULL == strpbrk(str1, str2))
    ck_assert_ptr_null(s21_strpbrk(str1, str2));
  else
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_10) {
  char str1[10] = "7   8";
  char str2[10] = " ";
  if (NULL == strpbrk(str1, str2))
    ck_assert_ptr_null(s21_strpbrk(str1, str2));
  else
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

TCase *s21_StringHTCaseStrpbrk() {
  TCase *tcase = tcase_create("s21_StringHTCaseStrpbrk");
  tcase_add_test(tcase, strpbrk_1);
  tcase_add_test(tcase, strpbrk_2);
  tcase_add_test(tcase, strpbrk_3);
  tcase_add_test(tcase, strpbrk_4);
  tcase_add_test(tcase, strpbrk_5);
  tcase_add_test(tcase, strpbrk_6);
  tcase_add_test(tcase, strpbrk_7);
  tcase_add_test(tcase, strpbrk_8);
  tcase_add_test(tcase, strpbrk_9);
  tcase_add_test(tcase, strpbrk_10);

  return tcase;
}
