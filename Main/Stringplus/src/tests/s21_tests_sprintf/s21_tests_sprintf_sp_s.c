#include "../s21_tests_main_runner.h"

#define N 1000

START_TEST(test_s21_sprintf_sp_s_1) {
  const char format[] = "%s";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  char* string = "Hello, world! 1, 2, 3...";

  int standard = sprintf(sprintf_str, format, string);
  int s21 = s21_sprintf(s21_sprintf_str, format, string);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_s_2) {
  const char format[] = "%s";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  char* string = "";

  int standard = sprintf(sprintf_str, format, string);
  int s21 = s21_sprintf(s21_sprintf_str, format, string);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_s_3) {
  const char format[] = "%s";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  char* string = "\0";

  int standard = sprintf(sprintf_str, format, string);
  int s21 = s21_sprintf(s21_sprintf_str, format, string);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_s_4) {
  const char format[] = "Я рад вас видеть! %s'm glad to see you!";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  char* string = "I";

  int standard = sprintf(sprintf_str, format, string);
  int s21 = s21_sprintf(s21_sprintf_str, format, string);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_s_5) {
  const char format[] = "%123s%2s\n%3s%4s%s";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  char* string1 = "School21";
  char* string2 = "is";
  char* string3 = "\n\t";
  char* string4 = "a programming";
  char* string5 = "school";

  int standard =
      sprintf(sprintf_str, format, string1, string2, string3, string4, string5);
  int s21 = s21_sprintf(s21_sprintf_str, format, string1, string2, string3,
                        string4, string5);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

START_TEST(test_s21_sprintf_sp_s_6) {
  const char format[] = "%-30.0s%-2s\n%-10.3s%-4s%-5s%-.4s";
  char sprintf_str[N] = {};
  char s21_sprintf_str[N] = {};

  char* string1 = "Time, he is waiting in the wings";
  char* string2 = "\nHe speaks of senseless things";
  char* string3 = "\n\tHis script is you and me, boy";
  char* string4 = "\nTime, he flexes like a whore";
  char* string5 = "\nFalls wanking to the floor";
  char* string6 = "\nHis trick is you and me, boy";

  int standard = sprintf(sprintf_str, format, string1, string2, string3,
                         string4, string5, string6);
  int s21 = s21_sprintf(s21_sprintf_str, format, string1, string2, string3,
                        string4, string5, string6);

  ck_assert_pstr_eq(sprintf_str, s21_sprintf_str);
  ck_assert_int_eq(standard, s21);
}
END_TEST

TCase* s21_SprintfTcaseSpS() {
  TCase* tcase = tcase_create("s21_SprintfTcaseSpS");

  tcase_add_test(tcase, test_s21_sprintf_sp_s_1);
  tcase_add_test(tcase, test_s21_sprintf_sp_s_2);
  tcase_add_test(tcase, test_s21_sprintf_sp_s_3);
  tcase_add_test(tcase, test_s21_sprintf_sp_s_4);
  tcase_add_test(tcase, test_s21_sprintf_sp_s_5);
  tcase_add_test(tcase, test_s21_sprintf_sp_s_6);
  return tcase;
}