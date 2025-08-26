#include "../../s21_tests_runner.h"

// error 0, но требуется округление
START_TEST(test_s21_arithmetic_sub_big_numbers_1) {
  // 79228162514264337593543950335
  s21_decimal value_1 = {
      .bits[0] = -1, .bits[1] = -1, .bits[2] = -1, .bits[3] = 0};
  // 0.6
  s21_decimal value_2 = {
      .bits[0] = 6, .bits[1] = 0, .bits[2] = 0, .bits[3] = 1 << 16};
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &result));

  // 79228162514264337593543950334 (банковское округление, дробная часть <0,5)
  ck_assert_int_eq(-2, result.bits[0]);
  ck_assert_int_eq(-1, result.bits[1]);
  ck_assert_int_eq(-1, result.bits[2]);
  ck_assert_int_eq(0, result.bits[3]);
}
END_TEST

// error 0, но требуется округление
START_TEST(test_s21_arithmetic_sub_big_numbers_2) {
  // -79228162514264337593543950334
  s21_decimal value_1 = {
      .bits[0] = -2, .bits[1] = -1, .bits[2] = -1, .bits[3] = MAX_LEFT_SHIFT};
  // 0,5
  s21_decimal value_2 = {
      .bits[0] = 5, .bits[1] = 0, .bits[2] = 0, .bits[3] = 1 << 16};
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &result));

  // -79228162514264337593543950334 (банковское округление, целая часть
  // заканчивается на четное, а дробная часть =0,5)
  ck_assert_int_eq(-2, result.bits[0]);
  ck_assert_int_eq(-1, result.bits[1]);
  ck_assert_int_eq(-1, result.bits[2]);
  ck_assert_int_eq(MAX_LEFT_SHIFT, result.bits[3]);
}
END_TEST

// error 0, но требуется округление
START_TEST(test_s21_arithmetic_sub_big_numbers_3) {
  // 79228162514264337593543950334
  s21_decimal value_1 = {
      .bits[0] = -2, .bits[1] = -1, .bits[2] = -1, .bits[3] = 0};
  // 0,5
  s21_decimal value_2 = {
      .bits[0] = 5, .bits[1] = 0, .bits[2] = 0, .bits[3] = 1 << 16};
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &result));

  // -79228162514264337593543950334 (банковское округление (целая часть
  // заканчивается на нечетное, а дробная часть =0,5))
  ck_assert_int_eq(-2, result.bits[0]);
  ck_assert_int_eq(-1, result.bits[1]);
  ck_assert_int_eq(-1, result.bits[2]);
  ck_assert_int_eq(0, result.bits[3]);
}
END_TEST

// error 0, но требуется округление
START_TEST(test_s21_arithmetic_sub_big_numbers_4) {
  // 79228162514264337593543950335
  s21_decimal value_1 = {
      .bits[0] = -1, .bits[1] = -1, .bits[2] = -1, .bits[3] = 0};
  // 0,3
  s21_decimal value_2 = {
      .bits[0] = 3, .bits[1] = 0, .bits[2] = 0, .bits[3] = 1 << 16};
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &result));

  // 79228162514264337593543950335 (банковское округление (дробная часть >0,5))
  ck_assert_int_eq(-1, result.bits[0]);
  ck_assert_int_eq(-1, result.bits[1]);
  ck_assert_int_eq(-1, result.bits[2]);
  ck_assert_int_eq(0, result.bits[3]);
}
END_TEST

// error 1
START_TEST(test_s21_arithmetic_sub_big_numbers_5) {
  // 79228162514264337593543950335
  s21_decimal value_1 = {
      .bits[0] = -1, .bits[1] = -1, .bits[2] = -1, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 123, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal result = {};

  ck_assert_int_eq(TOO_LARGE, s21_sub(value_1, value_2, &result));
}
END_TEST

// error 2
START_TEST(test_s21_arithmetic_sub_big_numbers_6) {
  //-79228162514264337593543950335
  s21_decimal value_1 = {
      .bits[0] = -1, .bits[1] = -1, .bits[2] = -1, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_2 = {
      .bits[0] = 34032, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal result = {};

  ck_assert_int_eq(TOO_SMALL, s21_sub(value_1, value_2, &result));
}
END_TEST

TCase *s21_AritmeticTCaseSubBigNumbers() {
  TCase *tcase = tcase_create("s21_AritmeticTCaseSubBigNumbers");

  tcase_add_test(tcase, test_s21_arithmetic_sub_big_numbers_1);
  tcase_add_test(tcase, test_s21_arithmetic_sub_big_numbers_2);
  tcase_add_test(tcase, test_s21_arithmetic_sub_big_numbers_3);
  tcase_add_test(tcase, test_s21_arithmetic_sub_big_numbers_4);
  tcase_add_test(tcase, test_s21_arithmetic_sub_big_numbers_5);
  tcase_add_test(tcase, test_s21_arithmetic_sub_big_numbers_6);

  return tcase;
}