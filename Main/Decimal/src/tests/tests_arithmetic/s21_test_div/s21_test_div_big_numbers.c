#include "../../s21_tests_runner.h"

// error 0, банковское округление (<0,5)
START_TEST(test_s21_arithmetic_div_big_numbers_1) {
  // 10/3=3,33333333...
  s21_decimal value_1 = {
      .bits[0] = 10, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 3, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &result));
  // result = 3,333333

  ck_assert_int_eq(894784853, result.bits[0]);
  ck_assert_int_eq(-819591186, result.bits[1]);
  ck_assert_int_eq(1807003620, result.bits[2]);
  ck_assert_int_eq(28 << 16, result.bits[3]);
}
END_TEST

// error 0, банковское округление (>0,5)
START_TEST(test_s21_arithmetic_div_big_numbers_2) {
  // 10/6=1,666666...
  s21_decimal value_1 = {
      .bits[0] = 10, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_2 = {
      .bits[0] = 6, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &result));
  // result = 1,666667

  ck_assert_int_eq(447392427, result.bits[0]);
  ck_assert_int_eq(1737688055, result.bits[1]);
  ck_assert_int_eq(903501810, result.bits[2]);
  ck_assert_int_eq(-2145648640, result.bits[3]);
}
END_TEST

// error 0, банковское округление (=0,5, предыдущее четное)
START_TEST(test_s21_arithmetic_div_big_numbers_3) {
  // 5/11=0,4545454545...
  s21_decimal value_1 = {
      .bits[0] = 5, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 11, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &result));
  // result = 0,454545

  ck_assert_int_eq(1293370833, result.bits[0]);
  ck_assert_int_eq(-1478342938, result.bits[1]);
  ck_assert_int_eq(246409584, result.bits[2]);
  ck_assert_int_eq(28 << 16, result.bits[3]);
}
END_TEST

// error 0, банковское округление (=0,5, предыдущее нечетное)
START_TEST(test_s21_arithmetic_div_big_numbers_4) {
  // 32/9=3,555555...
  s21_decimal value_1 = {
      .bits[0] = 32, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 9, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal result = {};
  ck_assert_int_eq(OK, s21_div(value_1, value_2, &result));
  // 3,555556

  ck_assert_int_eq(-477218589, result.bits[0]);
  ck_assert_int_eq(-587899446, result.bits[1]);
  ck_assert_int_eq(1927470528, result.bits[2]);
  ck_assert_int_eq(28 << 16, result.bits[3]);
}
END_TEST

// error 1
START_TEST(test_s21_arithmetic_div_big_numbers_5) {
  // 79228162514264337593543950335/0,67
  s21_decimal value_1 = {
      .bits[0] = -1, .bits[1] = -1, .bits[2] = -1, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 67, .bits[1] = 0, .bits[2] = 0, .bits[3] = 2 << 16};
  s21_decimal result = {};
  ck_assert_int_eq(TOO_LARGE, s21_div(value_1, value_2, &result));
}
END_TEST

// error 2
START_TEST(test_s21_arithmetic_div_big_numbers_6) {
  // -79228162514264337593543950335/0,23
  s21_decimal value_1 = {
      .bits[0] = -1, .bits[1] = -1, .bits[2] = -1, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_2 = {
      .bits[0] = 23, .bits[1] = 0, .bits[2] = 0, .bits[3] = 2 << 16};
  s21_decimal result = {};
  ck_assert_int_eq(TOO_SMALL, s21_div(value_1, value_2, &result));
}
END_TEST

TCase *s21_AritmeticTCaseDivBigNumbers() {
  TCase *tcase = tcase_create("s21_AritmeticTCaseDivBigNumbers");

  tcase_add_test(tcase, test_s21_arithmetic_div_big_numbers_1);
  tcase_add_test(tcase, test_s21_arithmetic_div_big_numbers_2);
  tcase_add_test(tcase, test_s21_arithmetic_div_big_numbers_3);
  tcase_add_test(tcase, test_s21_arithmetic_div_big_numbers_4);
  tcase_add_test(tcase, test_s21_arithmetic_div_big_numbers_5);
  tcase_add_test(tcase, test_s21_arithmetic_div_big_numbers_6);

  return tcase;
}