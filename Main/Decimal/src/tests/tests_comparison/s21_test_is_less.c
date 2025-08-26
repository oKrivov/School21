#include "../s21_tests_runner.h"

START_TEST(test_s21_comparison_is_less_1) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 1234;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 45754754;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_2) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 89346346;
  dec.bits[1] = 89346346;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 89346346;
  dec_2.bits[1] = 89346346;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_3) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 89346346;
  dec.bits[1] = 89;
  dec.bits[2] = 123;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 89346346;
  dec_2.bits[1] = 89346346;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_4) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 893;
  dec.bits[1] = 89;
  dec.bits[2] = 0;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 89346346;
  dec_2.bits[1] = 89346346;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_5) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 89332325;
  dec.bits[1] = 89325;
  dec.bits[2] = 23532532;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 89346346;
  dec_2.bits[1] = 89346346;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_6) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};

  s21_decimal dec_2 = {{0, 0, 0, 0}};

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_7) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 214124;
  dec.bits[1] = 3242436;
  dec.bits[2] = 4;
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_8) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_9) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_10) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_11) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_12) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_13) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_14) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_15) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_16) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_17) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 1234;
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 35346436;
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_18) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_19) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 1;
  dec.bits[3] = (int)2147483648;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 124124;
  dec_2.bits[3] = (int)2147483648;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_20) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 4;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 5;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_1) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 2141;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 2141;
  dec_2.bits[3] = 131072;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_2) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 2141;
  dec.bits[3] = 458752;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 23532623;
  dec_2.bits[3] = 458752;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_3) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 2141;
  dec.bits[3] = 458752;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 23532623;
  dec_2.bits[3] = 458752;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_4) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_5) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_6) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_7) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_8) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_9) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_10) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_11) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_12) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_13) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_14) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_15) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_16) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_17) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFF;
  dec.bits[2] = 0;
  dec.bits[3] = 131072;

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 2343;
  dec_2.bits[1] = 0;
  dec_2.bits[2] = 2412425;
  dec_2.bits[3] = 0;

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_18) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_19) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_20) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_21) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_22) {
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

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_23) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0xFFFFFFFF;
  dec.bits[3] = (int)2147614720;  // negate , scale = 2

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0;
  dec_2.bits[3] = (int)2147614720;  // negate , scale = 2

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_OK);
}
END_TEST

START_TEST(test_s21_comparison_is_less_scale_24) {
  int flag = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  dec.bits[0] = 0xFFFFFFFF;
  dec.bits[1] = 0xFFFFFFFF;
  dec.bits[2] = 0;
  dec.bits[3] = (int)2147614720;  // negate , scale = 2

  s21_decimal dec_2 = {{0, 0, 0, 0}};
  dec_2.bits[0] = 0xFFFFFFFF;
  dec_2.bits[1] = 0xFFFFFFFF;
  dec_2.bits[2] = 0xFFFFFFFF;
  dec_2.bits[3] = (int)2147614720;  // negate , scale = 2

  flag = s21_is_less(dec, dec_2);

  ck_assert_int_eq(flag, TEST_FAIL);
}
END_TEST

TCase *s21_ComparisonTCaseIsLess() {
  TCase *tcase = tcase_create("s21_ComparisonTCaseIsLess");

  tcase_add_test(tcase, test_s21_comparison_is_less_1);
  tcase_add_test(tcase, test_s21_comparison_is_less_2);
  tcase_add_test(tcase, test_s21_comparison_is_less_3);
  tcase_add_test(tcase, test_s21_comparison_is_less_4);
  tcase_add_test(tcase, test_s21_comparison_is_less_5);
  tcase_add_test(tcase, test_s21_comparison_is_less_6);
  tcase_add_test(tcase, test_s21_comparison_is_less_7);
  tcase_add_test(tcase, test_s21_comparison_is_less_8);
  tcase_add_test(tcase, test_s21_comparison_is_less_9);
  tcase_add_test(tcase, test_s21_comparison_is_less_10);
  tcase_add_test(tcase, test_s21_comparison_is_less_11);
  tcase_add_test(tcase, test_s21_comparison_is_less_12);
  tcase_add_test(tcase, test_s21_comparison_is_less_13);
  tcase_add_test(tcase, test_s21_comparison_is_less_14);
  tcase_add_test(tcase, test_s21_comparison_is_less_15);
  tcase_add_test(tcase, test_s21_comparison_is_less_16);
  tcase_add_test(tcase, test_s21_comparison_is_less_17);
  tcase_add_test(tcase, test_s21_comparison_is_less_18);
  tcase_add_test(tcase, test_s21_comparison_is_less_19);
  tcase_add_test(tcase, test_s21_comparison_is_less_20);

  tcase_add_test(tcase, test_s21_comparison_is_less_scale_1);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_2);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_3);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_4);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_5);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_6);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_7);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_8);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_9);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_10);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_11);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_12);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_13);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_14);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_15);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_16);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_17);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_18);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_19);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_20);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_21);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_22);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_23);
  tcase_add_test(tcase, test_s21_comparison_is_less_scale_24);

  return tcase;
}