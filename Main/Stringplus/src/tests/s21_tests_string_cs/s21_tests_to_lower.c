#include "../s21_tests_main_runner.h"

START_TEST(test_s21_to_lower_1) {
  const char *str = "HELLO";
  char *result = s21_to_lower(str);
  ck_assert_pstr_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_2) {
  const char *str = "World";
  char *result = s21_to_lower(str);
  ck_assert_pstr_eq(result, "world");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_3) {
  const char *str = "world 1#453dkg;";
  char *result = s21_to_lower(str);
  ck_assert_pstr_eq(result, "world 1#453dkg;");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_4) {
  const char *str = "";
  char *result = s21_to_lower(str);
  ck_assert_pstr_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_5) {
  const char *str = NULL;
  char *result = s21_to_lower(str);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

Suite *s21_to_lower_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_to_lower");
  tc_core = tcase_create("s21_ToLower");

  tcase_add_test(tc_core, test_s21_to_lower_1);
  tcase_add_test(tc_core, test_s21_to_lower_2);
  tcase_add_test(tc_core, test_s21_to_lower_3);
  tcase_add_test(tc_core, test_s21_to_lower_4);
  tcase_add_test(tc_core, test_s21_to_lower_5);

  suite_add_tcase(suite, tc_core);

  return suite;
}