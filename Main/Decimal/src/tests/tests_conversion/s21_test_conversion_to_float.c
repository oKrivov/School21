#include "../s21_tests_runner.h"

START_TEST(test_s21_conversion_to_float_1) {
  int flag = 0;
  float f = 0;
  float test = 12345;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 12345;

  s21_from_decimal_to_float(dec, &f);
  if (f == test) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_2) {
  int flag = 0;
  float f = 0;
  float test = -92335;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 92335;
  dec.bits[3] = (int)2147483648;

  s21_from_decimal_to_float(dec, &f);
  if (f == test) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_3) {
  int flag = 0;
  float f = 0;
  float test = 18446744073709551616.0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[3] = 0;

  s21_from_decimal_to_float(dec, &f);

  if (f == test) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_4) {
  int flag = 0;
  float f = 0;
  float test = 1208925819614629174706176.0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFF;
  dec.bits[3] = 0;

  s21_from_decimal_to_float(dec, &f);

  if (f == test) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_5) {
  int flag = 0;
  float f = 0;
  float test = 79228162514264337593543950336.0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = 0;

  s21_from_decimal_to_float(dec, &f);

  if (f == test) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_6) {
  int flag = 0;
  float f = 0;
  float test = 4951760157141521099596496896.0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0;
  dec.bits[1] = 0;
  dec.bits[2] = 0xFFFFFFF;
  dec.bits[3] = 0;

  s21_from_decimal_to_float(dec, &f);

  if (f == test) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_error_1) {
  int flag = 0;
  float f = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 92335;
  dec.bits[3] = (int)3221225472;

  flag = s21_from_decimal_to_float(dec, &f);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_scale_1) {
  int flag = 0;
  float f = 0;
  float test = 6.25;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 625;
  dec.bits[3] = 131072;

  s21_from_decimal_to_float(dec, &f);
  if (f == test) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_scale_2) {
  int flag = 0;
  float f = 0;
  float test = 0.01;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 1;
  dec.bits[3] = 131072;

  s21_from_decimal_to_float(dec, &f);
  if (f == test) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_scale_3) {
  int flag = 0;
  float f = 0;
  float test = 720.575928;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 1325325;
  dec.bits[1] = 0xFFFFFF;
  dec.bits[3] = 917504;

  s21_from_decimal_to_float(dec, &f);

  if (test == f) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_scale_4) {
  int flag = 0;
  float f = 0;
  float test = 7205759;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFF;
  dec.bits[1] = 0xFFFFFF;
  dec.bits[3] = 655360;

  s21_from_decimal_to_float(dec, &f);

  if (test == f) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_scale_5) {
  int flag = 0;
  float f = 0;
  float test = 4951.760253;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFF;
  dec.bits[1] = 0xFFFFFFF;
  dec.bits[2] = 0xFFFFFFF;
  dec.bits[3] = 1572864;

  s21_from_decimal_to_float(dec, &f);

  if (test == f) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_scale_6) {
  int flag = 0;
  float f = 0;
  float test = 79228.1640625;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = 1572864;

  s21_from_decimal_to_float(dec, &f);

  if (test == f) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_scale_7) {
  int flag = 0;
  float f = 0;
  float test = 7.92281627655029296875;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = 1835008;

  s21_from_decimal_to_float(dec, &f);

  if (test == f) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_scale_8) {
  int flag = 0;
  float f = 0;
  float test = -7.92281627655029296875;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = (int)2149318656;

  s21_from_decimal_to_float(dec, &f);

  if (test == f) flag = 1;

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_conversion_to_float_error_scale_1) {
  int flag = 0;
  float f = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 1;
  dec.bits[3] = 131088;

  flag = s21_from_decimal_to_float(dec, &f);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

TCase *s21_ConversionTCaseToFloat() {
  TCase *tcase = tcase_create("s21_ConversionTCaseToFloat");

  tcase_add_test(tcase, test_s21_conversion_to_float_1);
  tcase_add_test(tcase, test_s21_conversion_to_float_2);
  tcase_add_test(tcase, test_s21_conversion_to_float_3);
  tcase_add_test(tcase, test_s21_conversion_to_float_4);
  tcase_add_test(tcase, test_s21_conversion_to_float_5);
  tcase_add_test(tcase, test_s21_conversion_to_float_6);

  tcase_add_test(tcase, test_s21_conversion_to_float_error_1);

  tcase_add_test(tcase, test_s21_conversion_to_float_scale_1);
  tcase_add_test(tcase, test_s21_conversion_to_float_scale_2);
  tcase_add_test(tcase, test_s21_conversion_to_float_scale_3);
  tcase_add_test(tcase, test_s21_conversion_to_float_scale_4);
  tcase_add_test(tcase, test_s21_conversion_to_float_scale_5);
  tcase_add_test(tcase, test_s21_conversion_to_float_scale_6);
  tcase_add_test(tcase, test_s21_conversion_to_float_scale_7);
  tcase_add_test(tcase, test_s21_conversion_to_float_scale_8);

  tcase_add_test(tcase, test_s21_conversion_to_float_error_scale_1);

  return tcase;
}
