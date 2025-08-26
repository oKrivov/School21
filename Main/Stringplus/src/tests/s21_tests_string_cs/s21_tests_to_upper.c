#include "../s21_tests_main_runner.h"

START_TEST(test_s21_to_upper_1) {
  const char *str = "hello";
  char *result = s21_to_upper(str);
  ck_assert_pstr_eq(result, "HELLO");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_2) {
  const char *str = "World";
  char *result = s21_to_upper(str);
  ck_assert_pstr_eq(result, "WORLD");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_3) {
  const char *str = "WORLD 1#453DKG;";
  char *result = s21_to_upper(str);
  ck_assert_pstr_eq(result, "WORLD 1#453DKG;");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_4) {
  const char *str = "";
  char *result = s21_to_upper(str);
  ck_assert_pstr_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_5) {
  const char *str = NULL;
  char *result = s21_to_upper(str);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_to_upper");
  tc_core = tcase_create("s21_ToUpper");

  tcase_add_test(tc_core, test_s21_to_upper_1);
  tcase_add_test(tc_core, test_s21_to_upper_2);
  tcase_add_test(tc_core, test_s21_to_upper_3);
  tcase_add_test(tc_core, test_s21_to_upper_4);
  tcase_add_test(tc_core, test_s21_to_upper_5);

  suite_add_tcase(suite, tc_core);

  return suite;
}