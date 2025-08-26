#include "../s21_tests_main_runner.h"

START_TEST(test_s21_insert_1) {
  const char *src = "Hello, !";
  const char *str = "world";
  size_t start_index = 7;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_2) {
  const char *src = "";
  const char *str = "";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_3) {
  const char *src = "Hello, ";
  const char *str = "";
  size_t start_index = 7;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, "Hello, ");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_4) {
  const char *src = "";
  const char *str = "world";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, "world");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_5) {
  const char *src = "\0\n";
  const char *str = "\0";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, "\0\n");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_6) {
  const char *src = NULL;
  const char *str = NULL;
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_insert");
  tc_core = tcase_create("s21_Insert");

  tcase_add_test(tc_core, test_s21_insert_1);
  tcase_add_test(tc_core, test_s21_insert_2);
  tcase_add_test(tc_core, test_s21_insert_3);
  tcase_add_test(tc_core, test_s21_insert_4);
  tcase_add_test(tc_core, test_s21_insert_5);
  tcase_add_test(tc_core, test_s21_insert_6);

  suite_add_tcase(suite, tc_core);

  return suite;
}