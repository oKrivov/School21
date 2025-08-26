#include "../s21_tests_runner.h"

START_TEST(test_s21_comparison_is_equal_1) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 1234;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 45754754;

  flag = s21_is_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_equal_2) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};

  s21_decimal dec_2 = {{0, 0, 0, 0}};

  flag = s21_is_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_equal_3) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = 0;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = 0;

  flag = s21_is_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_equal_4) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_equal_5) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = 0;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_equal_scale_1) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFF;
  dec.bits[2] = 0;
  dec.bits[3] = 131072;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0;
  dec_2.bits[2] = 2412425;
  dec_2.bits[3] = 851968;

  flag = s21_is_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_equal_scale_2) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = 131072;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = 131072;

  flag = s21_is_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_equal_scale_3) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFF;
  dec.bits[3] = 131072;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = (int)2147614720;

  flag = s21_is_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_equal_scale_4) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[3] = (int)2149318656;

  flag = s21_is_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_equal_scale_5) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[3] = (int)2149318656;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[3] = (int)2149318656;

  flag = s21_is_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

TCase *s21_ComparisonTCaseIsEqual() {
  TCase *tcase = tcase_create("s21_ComparisonTCaseIsEqual");

  tcase_add_test(tcase, test_s21_comparison_is_equal_1);
  tcase_add_test(tcase, test_s21_comparison_is_equal_2);
  tcase_add_test(tcase, test_s21_comparison_is_equal_3);
  tcase_add_test(tcase, test_s21_comparison_is_equal_4);
  tcase_add_test(tcase, test_s21_comparison_is_equal_5);

  tcase_add_test(tcase, test_s21_comparison_is_equal_scale_1);
  tcase_add_test(tcase, test_s21_comparison_is_equal_scale_2);
  tcase_add_test(tcase, test_s21_comparison_is_equal_scale_3);
  tcase_add_test(tcase, test_s21_comparison_is_equal_scale_4);
  tcase_add_test(tcase, test_s21_comparison_is_equal_scale_5);

  return tcase;
}
