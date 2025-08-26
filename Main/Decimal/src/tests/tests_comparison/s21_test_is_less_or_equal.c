#include "../s21_tests_runner.h"

START_TEST(test_s21_comparison_is_less_or_equal_1) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 1234;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 45754754;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_2) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 89346346;
  dec.bits[1] = 89346346;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 89346346;
  dec_2.bits[1] = 89346346;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_3) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 89346346;
  dec.bits[1] = 89;
  dec.bits[2] = 123;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 89346346;
  dec_2.bits[1] = 89346346;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_4) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 893;
  dec.bits[1] = 89;
  dec.bits[2] = 0;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 89346346;
  dec_2.bits[1] = 89346346;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_5) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 89332325;
  dec.bits[1] = 89325;
  dec.bits[2] = 23532532;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 89346346;
  dec_2.bits[1] = 89346346;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_6) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};

  s21_decimal dec_2 = {{0, 0, 0, 0}};

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_7) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 214124;
  dec.bits[1] = 3242436;
  dec.bits[2] = 4;
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_8) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 214124;
  dec.bits[1] = 3242436;
  dec.bits[2] = 0;
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 21;
  dec_2.bits[1] = 324;
  dec_2.bits[2] = 0;
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_9) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFF;
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_10) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = 0;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFF;
  dec_2.bits[3] = 0;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_11) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0;
  dec.bits[3] = 0;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = 0;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_12) {
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

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_13) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 23423432;
  dec.bits[3] = 0;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 87556456;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = 0;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_14) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 214124;
  dec_2.bits[1] = 3242436;
  dec_2.bits[2] = 4;
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_15) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 214124;
  dec.bits[1] = 3242436;
  dec.bits[2] = 4;
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 214124;
  dec_2.bits[1] = 3242436;
  dec_2.bits[2] = 4;
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_16) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_17) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_18) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_19) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 1;
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 124124;
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_20) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 4;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 5;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_1) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 2141;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 2141;
  dec_2.bits[3] = 131072;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_2) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 2141;
  dec.bits[3] = 458752;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 23532623;
  dec_2.bits[3] = 458752;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_3) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 2141;
  dec.bits[3] = 458752;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 23532623;
  dec_2.bits[3] = 458752;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_4) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 2141;
  dec.bits[1] = 12312321;
  dec.bits[2] = 12;
  dec.bits[3] = 458752;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 23532623;
  dec_2.bits[1] = 75;
  dec_2.bits[3] = 458752;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_5) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFF;
  dec.bits[3] = 458752;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = 458752;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_6) {
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
  dec_2.bits[3] = 458752;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_7) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = 458752;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = 131072;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_8) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0;
  dec.bits[3] = 131072;  // 131072

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = 851968;  // 851968

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_9) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 3435235;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = 851968;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = 0;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_10) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = 851968;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = 0;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_11) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = 851968;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0;
  dec_2.bits[3] = 131072;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_12) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = (int)2148335616;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0;
  dec_2.bits[3] = (int)2147614720;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_13) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = (int)2147614720;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0;
  dec_2.bits[3] = (int)2148335616;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_14) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = (int)2147614720;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0;
  dec_2.bits[3] = 131072;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_15) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = 131072;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0;
  dec_2.bits[3] = (int)2147614720;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_16) {
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

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_17) {
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

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_18) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = (int)2149318656;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0;
  dec_2.bits[3] = (int)2149318656;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_19) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0;
  dec.bits[3] = (int)2149318656;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = (int)2149318656;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_20) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = (int)2149318656;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = (int)2149318656;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_21) {
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
  dec_2.bits[3] = 851968;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_or_equal_scale_22) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = 851968;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = 131072;

  flag = s21_is_less_or_equal(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

TCase *s21_ComparisonTCaseIsLessOrEqual() {
  TCase *tcase = tcase_create("s21_ComparisonTCaseIsLessOrEqual");

  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_1);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_2);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_3);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_4);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_5);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_6);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_7);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_8);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_9);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_10);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_11);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_12);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_13);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_14);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_15);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_16);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_17);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_18);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_19);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_20);

  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_1);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_2);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_3);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_4);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_5);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_6);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_7);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_8);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_9);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_10);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_11);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_12);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_13);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_14);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_15);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_16);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_17);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_18);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_19);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_20);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_21);
  tcase_add_test(tcase, test_s21_comparison_is_less_or_equal_scale_22);

  return tcase;
}
