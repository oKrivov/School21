#include "../../s21_tests_runner.h"

START_TEST(test_s21_arithmetic_sub_float_1) {  //++ (из большего меньшее)
  s21_decimal value_1 = {
      .bits[0] = 103, .bits[1] = 0, .bits[2] = 0, .bits[3] = 1 << 16};
  s21_decimal value_2 = {
      .bits[0] = 123, .bits[1] = 0, .bits[2] = 0, .bits[3] = 2 << 16};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 9.07f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_float_2) {  //++ (из меньшего большее)
  s21_decimal value_1 = {
      .bits[0] = 35267, .bits[1] = 0, .bits[2] = 0, .bits[3] = 4 << 16};
  s21_decimal value_2 = {
      .bits[0] = 103, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, -99.4733f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_float_3) {  //-- (из большего меньшее)
  s21_decimal value_1 = {.bits[0] = 2145,
                         .bits[1] = 0,
                         .bits[2] = 0,
                         .bits[3] = 0b10000000000000110000000000000000};
  s21_decimal value_2 = {.bits[0] = 123,
                         .bits[1] = 0,
                         .bits[2] = 0,
                         .bits[3] = 0b10000000000001000000000000000000};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, -2.1327f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_float_4) {  //-- (из меньшего большее)
  s21_decimal value_1 = {.bits[0] = 32412,
                         .bits[1] = 0,
                         .bits[2] = 0,
                         .bits[3] = 0b10000000000001000000000000000000};
  s21_decimal value_2 = {.bits[0] = 333,
                         .bits[1] = 0,
                         .bits[2] = 0,
                         .bits[3] = 0b10000000000000010000000000000000};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 30.0588f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_float_5) {  //+-
  s21_decimal value_1 = {
      .bits[0] = 99999, .bits[1] = 0, .bits[2] = 0, .bits[3] = 4 << 16};
  s21_decimal value_2 = {.bits[0] = 10001,
                         .bits[1] = 0,
                         .bits[2] = 0,
                         .bits[3] = 0b10000000000001000000000000000000};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, (float)11, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_float_6) {  //-+
  s21_decimal value_1 = {.bits[0] = 89013,
                         .bits[1] = 0,
                         .bits[2] = 0,
                         .bits[3] = 0b10000000000000100000000000000000};
  s21_decimal value_2 = {
      .bits[0] = 1256, .bits[1] = 0, .bits[2] = 0, .bits[3] = 4 << 16};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, -890.2556f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_float_7) {  // int - float
  s21_decimal value_1 = {
      .bits[0] = 9999, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 999, .bits[1] = 0, .bits[2] = 0, .bits[3] = 3 << 16};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 9998.001f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_float_8) {  // int - (-float)
  s21_decimal value_1 = {
      .bits[0] = 134, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {.bits[0] = 9506,
                         .bits[1] = 0,
                         .bits[2] = 0,
                         .bits[3] = 0b10000000000001000000000000000000};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 134.9506f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_float_9) {  // float - int
  s21_decimal value_1 = {
      .bits[0] = 768, .bits[1] = 0, .bits[2] = 0, .bits[3] = 2 << 16};
  s21_decimal value_2 = {
      .bits[0] = 2345, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, -2337.32f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_float_10) {  // float - (-int)
  s21_decimal value_1 = {
      .bits[0] = 653, .bits[1] = 0, .bits[2] = 0, .bits[3] = 3 << 16};
  s21_decimal value_2 = {
      .bits[0] = 12893, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 12893.653f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_float_11) {  // 0 - number
  s21_decimal value_1 = {
      .bits[0] = 0, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 120323, .bits[1] = 0, .bits[2] = 0, .bits[3] = 5 << 16};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, -1.20323f, 1e-6);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_float_12) {  // number - 0
  s21_decimal value_1 = {
      .bits[0] = 5738, .bits[1] = 0, .bits[2] = 0, .bits[3] = 3 << 16};
  s21_decimal value_2 = {
      .bits[0] = 0, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  float result = 0;
  s21_from_decimal_to_float(value_3, &result);
  ck_assert_float_eq_tol(result, 5.738f, 1e-6);
}
END_TEST

TCase *s21_AritmeticTCaseSubFloat() {
  TCase *tcase = tcase_create("s21_AritmeticTCaseSubFloat");

  tcase_add_test(tcase, test_s21_arithmetic_sub_float_1);
  tcase_add_test(tcase, test_s21_arithmetic_sub_float_2);
  tcase_add_test(tcase, test_s21_arithmetic_sub_float_3);
  tcase_add_test(tcase, test_s21_arithmetic_sub_float_4);
  tcase_add_test(tcase, test_s21_arithmetic_sub_float_5);
  tcase_add_test(tcase, test_s21_arithmetic_sub_float_6);
  tcase_add_test(tcase, test_s21_arithmetic_sub_float_7);
  tcase_add_test(tcase, test_s21_arithmetic_sub_float_8);
  tcase_add_test(tcase, test_s21_arithmetic_sub_float_9);
  tcase_add_test(tcase, test_s21_arithmetic_sub_float_10);
  tcase_add_test(tcase, test_s21_arithmetic_sub_float_11);
  tcase_add_test(tcase, test_s21_arithmetic_sub_float_12);

  return tcase;
}