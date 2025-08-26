#include "../s21_tests_main_runner.h"

START_TEST(strlen_1) {
  char string[] = "Hello\0world";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_2) {
  char string[] = "\0\0";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_3) {
  char string[] = "??$#@!@*";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_4) {
  char string[1024] =
      "This is a long string with more than 100 characters. It should be long "
      "enough to test the s21_strlen function properly.";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_5) {
  char string[10] = "\0 Hello";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_6) {
  char string[] = " ";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_7) {
  char string[15] = "Hello world";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_8) {
  char string[] = "Hello world";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_9) {
  char string[10] = "";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

// START_TEST(strlen_Null) {
//   char *string = NULL;
//   ck_assert_int_eq(strlen(string), s21_strlen(string));
// }
// END_TEST

TCase *s21_StringHTCaseStrlen() {
  TCase *tcase = tcase_create("s21_StringHTCaseStrlen");
  tcase_add_test(tcase, strlen_1);
  tcase_add_test(tcase, strlen_2);
  tcase_add_test(tcase, strlen_3);
  tcase_add_test(tcase, strlen_4);
  tcase_add_test(tcase, strlen_5);
  tcase_add_test(tcase, strlen_6);
  tcase_add_test(tcase, strlen_7);
  tcase_add_test(tcase, strlen_8);
  tcase_add_test(tcase, strlen_9);
  // tcase_add_test(tcase, strlen_Null);
  return tcase;
}
