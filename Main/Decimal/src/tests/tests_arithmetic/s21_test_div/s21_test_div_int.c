#include "../../s21_tests_runner.h"

START_TEST(test_s21_arithmetic_div_int_1) {  // на 1
  s21_decimal value_1 = {
      .bits[0] = 10, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 1, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, 10);
}
END_TEST

START_TEST(test_s21_arithmetic_div_int_2) {  // само на себя
  s21_decimal value_1 = {
      .bits[0] = 1234, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 1234, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_arithmetic_div_int_3) {  //++
  s21_decimal value_1 = {
      .bits[0] = 81, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 3, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, 27);
}
END_TEST

START_TEST(test_s21_arithmetic_div_int_4) {  // --
  s21_decimal value_1 = {
      .bits[0] = 1200, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_2 = {
      .bits[0] = 25, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, 48);
}
END_TEST

START_TEST(test_s21_arithmetic_div_int_5) {  // -+
  s21_decimal value_1 = {
      .bits[0] = 289, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_2 = {
      .bits[0] = 17, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, -17);
}
END_TEST

START_TEST(test_s21_arithmetic_div_int_6) {  // +-
  s21_decimal value_1 = {
      .bits[0] = 190, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 19, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, -10);
}
END_TEST

START_TEST(test_s21_arithmetic_div_int_7) {  // на 10 (с остатком)
  s21_decimal value_1 = {
      .bits[0] = 3838, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 10, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 383.8f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_div_int_8) {  // на 10 (без остатка)
  s21_decimal value_1 = {
      .bits[0] = 3800, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 10, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, 380);
}
END_TEST

START_TEST(
    test_s21_arithmetic_div_int_9) {  // result десятичная дробь (exp = 1)
  s21_decimal value_1 = {
      .bits[0] = 1234, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 4, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 308.5f, 1e-6);
}
END_TEST

START_TEST(
    test_s21_arithmetic_div_int_10) {  // result десятичная дробь (exp = 2)
  s21_decimal value_1 = {
      .bits[0] = 35, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 4, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 8.75f, 1e-6);
}
END_TEST

START_TEST(
    test_s21_arithmetic_div_int_11) {  // result десятичная дробь (exp = 3)
  s21_decimal value_1 = {
      .bits[0] = 19, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 8, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 2.375f, 1e-6);
}
END_TEST

TCase *s21_AritmeticTCaseDivInt() {
  TCase *tcase = tcase_create("s21_AritmeticTCaseDivInt");

  tcase_add_test(tcase, test_s21_arithmetic_div_int_1);
  tcase_add_test(tcase, test_s21_arithmetic_div_int_2);
  tcase_add_test(tcase, test_s21_arithmetic_div_int_3);
  tcase_add_test(tcase, test_s21_arithmetic_div_int_4);
  tcase_add_test(tcase, test_s21_arithmetic_div_int_5);
  tcase_add_test(tcase, test_s21_arithmetic_div_int_6);
  tcase_add_test(tcase, test_s21_arithmetic_div_int_7);
  tcase_add_test(tcase, test_s21_arithmetic_div_int_8);
  tcase_add_test(tcase, test_s21_arithmetic_div_int_9);
  tcase_add_test(tcase, test_s21_arithmetic_div_int_10);
  tcase_add_test(tcase, test_s21_arithmetic_div_int_11);

  return tcase;
}