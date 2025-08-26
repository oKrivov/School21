#include "../s21_tests_main_runner.h"

START_TEST(strrchr_1) {
  char str[] = "1234567840";
  char c = '4';

  ck_assert_ptr_eq(strrchr(str, (int)c), s21_strrchr(str, (int)c));
}
END_TEST

START_TEST(strrchr_2) {
  char str[10] = "";
  char c = '4';

  ck_assert_ptr_eq(strrchr(str, (int)c), s21_strrchr(str, (int)c));
}
END_TEST

START_TEST(strrchr_3) {
  char str[] = "1234567890";
  char c = '\0';
  ck_assert_ptr_eq(strrchr(str, (int)c), s21_strrchr(str, (int)c));
}
END_TEST

START_TEST(strrchr_4) {
  char str[] = "1234567890";
  char c = 'a';

  ck_assert_ptr_eq(strrchr(str, (int)c), s21_strrchr(str, (int)c));
}
END_TEST

START_TEST(strrchr_5) {
  char str[] = "1234567890";
  char c = '1';

  ck_assert_ptr_eq(strrchr(str, (int)c), s21_strrchr(str, (int)c));
}
END_TEST

START_TEST(strrchr_6) {
  char str[] = "1234567890";
  char c = '4';

  ck_assert_ptr_eq(strrchr(str, (int)c), s21_strrchr(str, (int)c));
}
END_TEST

START_TEST(strrchr_7) {
  char str[10] = "Hello";
  char c = 'l';

  ck_assert_ptr_eq(strrchr(str, (int)c), s21_strrchr(str, (int)c));
}
END_TEST

START_TEST(strrchr_8) {
  char str[] = "\01234567890";
  char c = '0';

  ck_assert_ptr_eq(strrchr(str, (int)c), s21_strrchr(str, (int)c));
}
END_TEST

START_TEST(strrchr_9) {
  char str[] = "Hello, world, ";
  char c = ',';

  ck_assert_ptr_eq(strrchr(str, (int)c), s21_strrchr(str, (int)c));
}
END_TEST

START_TEST(strrchr_10) {
  char str[] = "S\0eeeeee";
  char c = 'e';

  ck_assert_ptr_eq(strrchr(str, (int)c), s21_strrchr(str, (int)c));
}
END_TEST

TCase *s21_StringHTCaseStrrchr() {
  TCase *tcase = tcase_create("s21_StringHTCaseStrrchr");
  tcase_add_test(tcase, strrchr_1);
  tcase_add_test(tcase, strrchr_2);
  tcase_add_test(tcase, strrchr_3);
  tcase_add_test(tcase, strrchr_4);
  tcase_add_test(tcase, strrchr_5);
  tcase_add_test(tcase, strrchr_6);
  tcase_add_test(tcase, strrchr_7);
  tcase_add_test(tcase, strrchr_8);
  tcase_add_test(tcase, strrchr_9);
  tcase_add_test(tcase, strrchr_10);

  return tcase;
}
