#include "../s21_tests_main_runner.h"

START_TEST(strtok_1) {
  char str1[] = "- This, a sample string.";
  char str2[] = "- This, a sample string.";
  char *delim = " ,.-";

  char *s21_token = s21_strtok(str1, delim);
  char *std_token = strtok(str2, delim);
  while (s21_token != S21_NULL || std_token != NULL) {
    ck_assert_str_eq(s21_token, std_token);
    s21_token = s21_strtok(S21_NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_2) {
  char str1[] = "";
  char str2[] = "";
  char *delim = " ,.-";
  char *s21_token = s21_strtok(str1, delim);
  char *std_token = strtok(str2, delim);
  ck_assert_ptr_eq(s21_token, std_token);
}
END_TEST

START_TEST(strtok_3) {
  char str1[] = "This is a sample string.";
  char str2[] = "This is a sample string.";
  char *delim = "";
  char *s21_token = s21_strtok(str1, delim);
  char *std_token = strtok(str2, delim);
  while (s21_token != S21_NULL || std_token != NULL) {
    ck_assert_str_eq(s21_token, std_token);
    s21_token = s21_strtok(S21_NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_4) {
  char str[] = "   ";
  char *delim = " ";
  char *s21_token = s21_strtok(str, delim);
  char *std_token = strtok(str, delim);
  ck_assert_ptr_eq(s21_token, std_token);
}
END_TEST

START_TEST(strtok_5) {
  char str1[] = "This  is  a  sample  string.";
  char str2[] = "This  is  a  sample  string.";
  char *delim = " ";

  char *s21_token = s21_strtok(str1, delim);
  char *std_token = strtok(str2, delim);
  while (s21_token != S21_NULL || std_token != NULL) {
    ck_assert_str_eq(s21_token, std_token);
    s21_token = s21_strtok(S21_NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_6) {
  char str1[] = " This is a sample string. ";
  char str2[] = " This is a sample string. ";
  char *delim = " ";

  char *s21_token = s21_strtok(str1, delim);
  char *std_token = strtok(str2, delim);
  while (s21_token != S21_NULL || std_token != NULL) {
    ck_assert_str_eq(s21_token, std_token);
    s21_token = s21_strtok(S21_NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_7) {
  char str1[] = "This,is,a,sample,string.";
  char str2[] = "This,is,a,sample,string.";
  char *delim = ",";

  char *s21_token = s21_strtok(str1, delim);
  char *std_token = strtok(str2, delim);
  while (s21_token != S21_NULL || std_token != NULL) {
    ck_assert_str_eq(s21_token, std_token);
    s21_token = s21_strtok(S21_NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

TCase *s21_StringHTCaseStrtok() {
  TCase *tcase = tcase_create("s21_StringHTCaseStrtok");
  tcase_add_test(tcase, strtok_1);
  tcase_add_test(tcase, strtok_2);
  tcase_add_test(tcase, strtok_3);
  tcase_add_test(tcase, strtok_4);
  tcase_add_test(tcase, strtok_5);
  tcase_add_test(tcase, strtok_6);
  tcase_add_test(tcase, strtok_7);

  return tcase;
}
