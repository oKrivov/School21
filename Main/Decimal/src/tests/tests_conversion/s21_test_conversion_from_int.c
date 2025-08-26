#include "../s21_tests_runner.h"

START_TEST(test_s21_coversion_from_int_1) {
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_from_int_to_decimal(12345, &result));

  ck_assert_int_eq(12345, result.bits[0]);
  ck_assert_int_eq(0, result.bits[1]);
  ck_assert_int_eq(0, result.bits[2]);
  ck_assert_int_eq(0, result.bits[3]);
}
END_TEST

START_TEST(test_s21_coversion_from_int_2) {
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_from_int_to_decimal(-9857, &result));

  ck_assert_int_eq(9857, result.bits[0]);
  ck_assert_int_eq(0, result.bits[1]);
  ck_assert_int_eq(0, result.bits[2]);
  ck_assert_int_eq(MAX_LEFT_SHIFT, result.bits[3]);
}
END_TEST

START_TEST(test_s21_coversion_from_int_3) {
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_from_int_to_decimal(INT_MAX, &result));

  ck_assert_int_eq(2147483647, result.bits[0]);
  ck_assert_int_eq(0, result.bits[1]);
  ck_assert_int_eq(0, result.bits[2]);
  ck_assert_int_eq(0, result.bits[3]);
}
END_TEST

START_TEST(test_s21_coversion_from_int_4) {
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_from_int_to_decimal(INT_MIN, &result));

  ck_assert_int_eq(2147483648, (unsigned)result.bits[0]);
  ck_assert_int_eq(0, result.bits[1]);
  ck_assert_int_eq(0, result.bits[2]);
  ck_assert_int_eq(MAX_LEFT_SHIFT, result.bits[3]);
}
END_TEST

START_TEST(test_s21_coversion_from_int_5) {
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_from_int_to_decimal(0, &result));

  ck_assert_int_eq(0, result.bits[0]);
  ck_assert_int_eq(0, result.bits[1]);
  ck_assert_int_eq(0, result.bits[2]);
  ck_assert_int_eq(0, result.bits[3]);
}
END_TEST

TCase *s21_ConversionTCaseFromInt() {
  TCase *tcase = tcase_create("s21_ConversionTCaseFromInt");

  tcase_add_test(tcase, test_s21_coversion_from_int_1);
  tcase_add_test(tcase, test_s21_coversion_from_int_2);
  tcase_add_test(tcase, test_s21_coversion_from_int_3);
  tcase_add_test(tcase, test_s21_coversion_from_int_4);
  tcase_add_test(tcase, test_s21_coversion_from_int_5);

  return tcase;
}