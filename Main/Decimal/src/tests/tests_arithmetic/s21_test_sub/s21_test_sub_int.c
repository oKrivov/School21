#include "../../s21_tests_runner.h"

START_TEST(test_s21_arithmetic_sub_int_1) {  // ++ из большего
  s21_decimal value_1 = {
      .bits[0] = 1234, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 432, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, 802);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_int_2) {  // ++ из меньшего
  s21_decimal value_1 = {
      .bits[0] = 52, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 19249, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, -19197);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_int_3) {  // -- из большего
  s21_decimal value_1 = {
      .bits[0] = 95478, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_2 = {
      .bits[0] = 78, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, -95400);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_int_4) {  // -- из меньшего
  s21_decimal value_1 = {
      .bits[0] = 12321, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_2 = {
      .bits[0] = 33333, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, 21012);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_int_5) {  // +-
  s21_decimal value_1 = {
      .bits[0] = 540950, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 3900, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, 544850);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_int_6) {  //-+
  s21_decimal value_1 = {
      .bits[0] = 40689, .bits[1] = 0, .bits[2] = 0, .bits[3] = MAX_LEFT_SHIFT};
  s21_decimal value_2 = {
      .bits[0] = 2094281, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, -2134970);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_int_7) {  // 0 - number
  s21_decimal value_1 = {
      .bits[0] = 0, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 995846, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, -995846);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_int_8) {  // number - 0
  s21_decimal value_1 = {
      .bits[0] = 12345, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 0, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, 12345);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_int_9) {  // 0 - 0
  s21_decimal value_1 = {
      .bits[0] = 0, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 0, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_arithmetic_sub_int_10) {  // number - number
  s21_decimal value_1 = {
      .bits[0] = 9505, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_2 = {
      .bits[0] = 9505, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal value_3 = {};

  ck_assert_int_eq(OK, s21_sub(value_1, value_2, &value_3));

  int result = 0;
  s21_from_decimal_to_int(value_3, &result);
  ck_assert_int_eq(result, 0);
}
END_TEST

TCase *s21_AritmeticTCaseSubInt() {
  TCase *tcase = tcase_create("s21_AritmeticTCaseSubInt");

  tcase_add_test(tcase, test_s21_arithmetic_sub_int_1);
  tcase_add_test(tcase, test_s21_arithmetic_sub_int_2);
  tcase_add_test(tcase, test_s21_arithmetic_sub_int_3);
  tcase_add_test(tcase, test_s21_arithmetic_sub_int_4);
  tcase_add_test(tcase, test_s21_arithmetic_sub_int_5);
  tcase_add_test(tcase, test_s21_arithmetic_sub_int_6);
  tcase_add_test(tcase, test_s21_arithmetic_sub_int_7);
  tcase_add_test(tcase, test_s21_arithmetic_sub_int_8);
  tcase_add_test(tcase, test_s21_arithmetic_sub_int_9);
  tcase_add_test(tcase, test_s21_arithmetic_sub_int_10);

  return tcase;
}