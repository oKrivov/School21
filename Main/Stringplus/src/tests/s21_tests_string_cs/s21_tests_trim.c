#include "../s21_tests_main_runner.h"

START_TEST(test_s21_trim_1) {
  const char *src = "000Hello, world!111";
  const char *trim_chars = "01";
  char *result = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_2) {
  const char *src = "Hello, 0world!";
  const char *trim_chars = "0";
  char *result = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(result, "Hello, 0world!");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_3) {
  const char *src = "Hello, world!";
  const char *trim_chars = ", !";
  char *result = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(result, "Hello, world");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_4) {
  const char *src = "\n \n Hello, world! \n";
  const char *trim_chars = "\n";
  char *result = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(result, " \n Hello, world! ");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_5) {
  const char *src = "Hello, world!";
  const char *trim_chars = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_6) {
  const char *src = NULL;
  const char *trim_chars = NULL;
  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_trim");
  tc_core = tcase_create("s21_Trim");

  tcase_add_test(tc_core, test_s21_trim_1);
  tcase_add_test(tc_core, test_s21_trim_2);
  tcase_add_test(tc_core, test_s21_trim_3);
  tcase_add_test(tc_core, test_s21_trim_4);
  tcase_add_test(tc_core, test_s21_trim_5);
  tcase_add_test(tc_core, test_s21_trim_6);

  suite_add_tcase(suite, tc_core);

  return suite;
}