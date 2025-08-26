#include "../s21_tests_main_runner.h"

START_TEST(strcspn_1) {
  char str1[] = "abcdefg";
  char str2[] = "xyz";

  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_2) {
  char str1[] = "abcdefg";
  char str2[] = "dea";

  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_3) {
  char str1[] = "abcdefg";
  char str2[] = "abc";

  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_4) {
  char str1[] = "";
  char str2[] = "abc";

  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_5) {
  char str1[] = "abcdefg";
  char str2[] = "";

  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_6) {
  char str1[] = "\0abc";
  char str2[] = "c";

  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_7) {
  char str1[] = "asd\0";
  char str2[] = "\0";

  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_8) {
  char str1[] = "asd\0";
  char str2[] = "\0a";

  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

TCase *s21_StringHTCaseStrspn() {
  TCase *tcase = tcase_create("s21_StringHTCaseStrspn");
  tcase_add_test(tcase, strcspn_1);
  tcase_add_test(tcase, strcspn_2);
  tcase_add_test(tcase, strcspn_3);
  tcase_add_test(tcase, strcspn_4);
  tcase_add_test(tcase, strcspn_5);
  tcase_add_test(tcase, strcspn_6);
  tcase_add_test(tcase, strcspn_7);
  tcase_add_test(tcase, strcspn_8);

  return tcase;
}
