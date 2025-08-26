#include "../../s21_tests_runner.h"

START_TEST(test_s21_arithmetic_div_float_1) {  // на 1
  s21_decimal value_1 = {
      .bits[0] = 1234, .bits[1] = 0, .bits[2] = 0, .bits[3] = 3 << 16};
  s21_decimal value_2 = {
      .bits[0] = 1, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 1.234f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_div_float_2) {  // само на себя
  s21_decimal value_1 = {
      .bits[0] = 1234, .bits[1] = 0, .bits[2] = 0, .bits[3] = 2 << 16};
  s21_decimal value_2 = {
      .bits[0] = 1234, .bits[1] = 0, .bits[2] = 0, .bits[3] = 2 << 16};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, (float)1, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_div_float_3) {  // --
  s21_decimal value_1 = {
      .bits[0] = 1205,
      .bits[1] = 0,
      .bits[2] = 0,
      .bits[3] = 0b10000000000000010000000000000000};  // -120,5
  s21_decimal value_2 = {
      .bits[0] = 25, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 4.82f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_div_float_4) {  // -+
  s21_decimal value_1 = {
      .bits[0] = 289,
      .bits[1] = 0,
      .bits[2] = 0,
      .bits[3] = 0b10000000000000100000000000000000};  // -2,89
  s21_decimal value_2 = {
      .bits[0] = 17, .bits[1] = 0, .bits[2] = 0, .bits[3] = 2 << 16};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, (float)-17, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_div_float_5) {  // +-
  s21_decimal value_1 = {
      .bits[0] = 190, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {.bits[0] = 19,
                         .bits[1] = 0,
                         .bits[2] = 0,
                         .bits[3] = 0b10000000000000010000000000000000};  //-1,9
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, (float)-100, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_div_float_6) {  // float на int
  s21_decimal value_1 = {
      .bits[0] = 1255, .bits[1] = 0, .bits[2] = 0, .bits[3] = 1 << 16};
  s21_decimal value_2 = {
      .bits[0] = 5, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 25.1f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_div_float_7) {  // int на float
  s21_decimal value_1 = {
      .bits[0] = 9999, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 3333, .bits[1] = 0, .bits[2] = 0, .bits[3] = 3 << 16};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, (float)3000, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_div_float_8) {  // float на float
  s21_decimal value_1 = {
      .bits[0] = 1464, .bits[1] = 0, .bits[2] = 0, .bits[3] = 1 << 16};
  s21_decimal value_2 = {
      .bits[0] = 4, .bits[1] = 0, .bits[2] = 0, .bits[3] = 1 << 16};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, (float)366, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_div_float_9) {
  s21_decimal value_1 = {
      .bits[0] = 654, .bits[1] = 0, .bits[2] = 0, .bits[3] = 3 << 16};
  s21_decimal value_2 = {
      .bits[0] = 109, .bits[1] = 0, .bits[2] = 0, .bits[3] = 1 << 16};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 0.06f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_div_float_10) {
  s21_decimal value_1 = {
      .bits[0] = 2142, .bits[1] = 0, .bits[2] = 0, .bits[3] = 2 << 16};
  s21_decimal value_2 = {
      .bits[0] = 17, .bits[1] = 0, .bits[2] = 0, .bits[3] = 1 << 16};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 12.6f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_div_float_11) {
  s21_decimal value_1 = {
      .bits[0] = 1, .bits[1] = 2, .bits[2] = 0, .bits[3] = 10 << 16};
  s21_decimal value_2 = {
      .bits[0] = 10, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 0.0858993f, 1e-6);
}
END_TEST

TCase *s21_AritmeticTCaseDivFloat() {
  TCase *tcase = tcase_create("s21_AritmeticTCaseDivFloat");

  tcase_add_test(tcase, test_s21_arithmetic_div_float_1);
  tcase_add_test(tcase, test_s21_arithmetic_div_float_2);
  tcase_add_test(tcase, test_s21_arithmetic_div_float_3);
  tcase_add_test(tcase, test_s21_arithmetic_div_float_4);
  tcase_add_test(tcase, test_s21_arithmetic_div_float_5);
  tcase_add_test(tcase, test_s21_arithmetic_div_float_6);
  tcase_add_test(tcase, test_s21_arithmetic_div_float_7);
  tcase_add_test(tcase, test_s21_arithmetic_div_float_8);
  tcase_add_test(tcase, test_s21_arithmetic_div_float_9);
  tcase_add_test(tcase, test_s21_arithmetic_div_float_10);
  tcase_add_test(tcase, test_s21_arithmetic_div_float_11);

  return tcase;
}