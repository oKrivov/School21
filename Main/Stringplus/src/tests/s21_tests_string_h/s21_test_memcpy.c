#include "../s21_tests_main_runner.h"

START_TEST(memcpy_1) {
  char dest[] = "Hello ";
  char copy_dest[] = "Hello ";
  char src[] = "world";
  int n = (int)strlen(src);

  memcpy(copy_dest, src, n);
  s21_memcpy(dest, src, n);
  ck_assert_str_eq(copy_dest, dest);
}
END_TEST

START_TEST(memcpy_2) {
  char dest[10] = "Hello";
  char copy_dest[10] = "Hello";
  char src[10] = "";
  int n = (int)strlen(dest);

  memcpy(copy_dest, src, n);
  s21_memcpy(dest, src, n);
  ck_assert_str_eq(copy_dest, dest);
}
END_TEST

START_TEST(memcpy_3) {
  char dest[256] = "";
  char copy_dest[256] = "";
  char src[] = "This is a test string";
  int n = (int)strlen(src);

  memcpy(copy_dest, src, n);
  s21_memcpy(dest, src, n);
  ck_assert_str_eq(copy_dest, dest);
}
END_TEST

START_TEST(memcpy_4) {
  char dest[] = "This is a test string";
  char copy_dest[] = "This is a test string";
  char src[] = "This is a test string";
  int n = 0;

  memcpy(copy_dest, src, n);
  s21_memcpy(dest, src, n);
  ck_assert_str_eq(copy_dest, dest);
}
END_TEST

START_TEST(memcpy_5) {
  char dest[] = "1234567890";
  char copy_dest[] = "1234567890";
  char src[] = "This is a test string";
  int n = 5;

  memcpy(copy_dest, src, n);
  s21_memcpy(dest, src, n);
  ck_assert_str_eq(copy_dest, dest);
}
END_TEST

START_TEST(memcpy_6) {
  char dest[] = "1234567890";
  char copy_dest[] = "1234567890";
  char src[] = "	Hello";
  int n = (int)strlen(src);

  memcpy(copy_dest, src, n);
  s21_memcpy(dest, src, n);
  ck_assert_str_eq(copy_dest, dest);
}
END_TEST

START_TEST(memcpy_7) {
  char dest[] = "\0";
  char copy_dest[] = "\0";
  char src[] = "This is a test string";
  int n = (int)strlen(copy_dest);

  memcpy(copy_dest, src, n);
  s21_memcpy(dest, src, n);
  ck_assert_str_eq(copy_dest, dest);
}
END_TEST

START_TEST(memcpy_8) {
  char dest[] = "\0";
  char copy_dest[] = "\0";
  char src[] = "This is a test string";
  int n = (int)strlen(dest);

  memcpy(copy_dest, src, n);
  s21_memcpy(dest, src, n);
  ck_assert_str_eq(copy_dest, dest);
}
END_TEST

START_TEST(memcpy_9) {
  char dest[] = "\0";
  char copy_dest[] = "\0";
  char src[] = "\0abc";
  int n = (int)strlen(src);

  memcpy(copy_dest, src, n);
  s21_memcpy(dest, src, n);
  ck_assert_str_eq(copy_dest, dest);
}
END_TEST

TCase *s21_StringHTCaseMemcpy() {
  TCase *tcase = tcase_create("s21_StringHTCaseMemcpy");
  tcase_add_test(tcase, memcpy_1);
  tcase_add_test(tcase, memcpy_2);
  tcase_add_test(tcase, memcpy_3);
  tcase_add_test(tcase, memcpy_4);
  tcase_add_test(tcase, memcpy_5);
  tcase_add_test(tcase, memcpy_6);
  tcase_add_test(tcase, memcpy_7);
  tcase_add_test(tcase, memcpy_8);
  tcase_add_test(tcase, memcpy_9);

  return tcase;
}
