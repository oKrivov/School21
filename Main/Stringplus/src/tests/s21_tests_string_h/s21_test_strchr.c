#include "../s21_tests_main_runner.h"

START_TEST(strchr_1) {
  char str[] = "1234567890";
  char c = '4';

  ck_assert_ptr_eq(strchr(str, (int)c), s21_strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_2) {
  char str[10] = "";
  char c = '4';

  ck_assert_ptr_eq(strchr(str, (int)c), s21_strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_3) {
  char str[] = "1234567890";
  char c = '\0';

  ck_assert_ptr_eq(strchr(str, (int)c), s21_strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_4) {
  char str[] = "1234567890";
  char c = 'a';

  ck_assert_ptr_eq(strchr(str, (int)c), s21_strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_5) {
  char str[] = "1234567890";
  char c = '1';

  ck_assert_ptr_eq(strchr(str, (int)c), s21_strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_6) {
  char str[] = "1234567890";
  char c = '4';

  ck_assert_ptr_eq(strchr(str, (int)c), s21_strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_7) {
  char str[10] = "Hello";
  char c = 'e';

  ck_assert_ptr_eq(strchr(str, (int)c), s21_strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_8) {
  char str[] = "\01234567890";
  char c = '4';

  ck_assert_ptr_eq(strchr(str, (int)c), s21_strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_9) {
  char str[] = "Hello, world";
  char c = ',';

  ck_assert_ptr_eq(strchr(str, (int)c), s21_strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_10) {
  char str[] = "S\0eeeeee";
  char c = 'e';

  ck_assert_ptr_eq(strchr(str, (int)c), s21_strchr(str, (int)c));
}
END_TEST

TCase *s21_StringHTCaseStrchr() {
  TCase *tcase = tcase_create("s21_StringHTCaseStrchr");
  tcase_add_test(tcase, strchr_1);
  tcase_add_test(tcase, strchr_2);
  tcase_add_test(tcase, strchr_3);
  tcase_add_test(tcase, strchr_4);
  tcase_add_test(tcase, strchr_5);
  tcase_add_test(tcase, strchr_6);
  tcase_add_test(tcase, strchr_7);
  tcase_add_test(tcase, strchr_8);
  tcase_add_test(tcase, strchr_9);
  tcase_add_test(tcase, strchr_10);

  return tcase;
}
