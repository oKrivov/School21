#include "../s21_tests_runner.h"

#define PRINT_FORMAT "[число: %8X %8X %8X, коэффициент/знак: 0x%X]"

void test_from_float_to_decimal(float value, s21_decimal decimal_check);

START_TEST(test_from_float_to_decimal_unnormal1) {
  float f = 0.0;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_msg(code == ERROR_OK, "Conversion failed for 0.0");

  for (int i = 0; i < 4; i++) {
    ck_assert_msg(result.bits[i] == check.bits[i], "Bit mismatch at index %d",
                  i);
  }
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal2) {
  float f = -0.0;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_msg(code == ERROR_OK, "Conversion failed for -0.0");

  for (int i = 0; i < 4; i++) {
    ck_assert_msg(result.bits[i] == check.bits[i], "Bit mismatch at index %d",
                  i);
  }

  int sign_check = s21_GetSign(check);
  int sign_result = s21_GetSign(result);
  ck_assert_msg(sign_check == sign_result, "Sign mismatch: expected %d, got %d",
                sign_check, sign_result);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal3) {
  float f = INFINITY;
  s21_decimal result;
  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_msg(code == ERROR_CONVERT,
                "Expected conversion error for INFINITY");
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal4) {
  float f = -INFINITY;
  s21_decimal result;
  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_msg(code == ERROR_CONVERT,
                "Expected conversion error for -INFINITY");
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal5) {
  float f = NAN;
  s21_decimal result;
  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_msg(code == ERROR_CONVERT, "Expected conversion error for NAN");
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal6) {
  float f = -NAN;
  s21_decimal result;
  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_msg(code == ERROR_CONVERT, "Expected conversion error for -NAN");
}
END_TEST

START_TEST(test_from_float_to_decimal_incorrect1) {
  int code = s21_from_float_to_decimal(1.0f, NULL);
  ck_assert_int_eq(code, ERROR_CONVERT);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok1) {
  float f = 2.28401628E-19;
  // int f = 545706772;
  // 0.0000000000000000002284016
  s21_decimal decimal_check = {{2284016, 0x0, 0x0, 0x190000}};
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok2) {
  float f = -2.1349025E-18;
  // int f = -1575123157;
  // -0.000000000000000002134902
  s21_decimal decimal_check = {{2134902, 0x0, 0x0, 0x80180000}};
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok3) {
  float f = -0.000115481133;
  // int f = -1192087946;
  // -0.0001154811
  s21_decimal decimal_check = {{1154811, 0x0, 0x0, 0x800A0000}};
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok4) {
  float f = -3.9575282E-24;
  // -0.0000000000000000000000039575
  s21_decimal decimal_check = {{39575, 0x0, 0x0, 0x801C0000}};
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok5) {
  float f = 4.27844415E-17;
  // int f = 608521972;
  // 0.00000000000000004278444
  s21_decimal decimal_check = {{4278444, 0x0, 0x0, 0x170000}};
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok6) {
  float f = -12419649.0;
  // int f = -885161407;
  // -12419650
  s21_decimal decimal_check = {{12419650, 0x0, 0x0, 0x80000000}};
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok7) {
  float f = 0.100000001;
  // int f = 1036831949;
  // 0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok8) {
  float f = 1.0;
  // int f = 1065353216;
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok9) {
  float f = -1.0;
  // int f = -1082130432;
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok10) {
  float f = -1.00000012;
  // int f = -1082130431;
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_max) {
  float f = 79228162514264337593543950335.0f;  // Примерно 7.9228e+28
  s21_decimal result;

  ck_assert_msg(s21_from_float_to_decimal(f, &result) == ERROR_CONVERT,
                "Expected conversion error for %g", f);
}
END_TEST

START_TEST(test_from_float_to_decimal_min) {
  float f = 1e-28f;  // -(2^96 - 1)
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_overflow) {
  float f = 1E30;  // Число слишком велико
  // Ожидаем код ошибки 1
  s21_decimal result;
  ck_assert_msg(s21_from_float_to_decimal(f, &result) == ERROR_CONVERT,
                "Expected conversion error for %g", f);
}
END_TEST

START_TEST(test_from_float_to_decimal_underflow) {
  float f = -1E30;  // Число слишком велико по модулю
  // Ожидаем ошибку
  s21_decimal result;
  ck_assert_msg(s21_from_float_to_decimal(f, &result) == ERROR_CONVERT,
                "Expected conversion error for %g", f);
}
END_TEST

START_TEST(test_from_float_to_decimal_tiny) {
  float f = 1E-29;  // Меньше 1E-28
  // Ожидаем ошибку
  s21_decimal result;
  ck_assert_msg(s21_from_float_to_decimal(f, &result) == ERROR_CONVERT,
                "Expected conversion error for %g", f);
}
END_TEST

START_TEST(test_from_float_to_decimal_precision_loss) {
  float f = 1.123456789f;  // В `float` это представится как 1.123457
  s21_decimal decimal_check = {
      {1123457, 0x0, 0x0,
       0x60000}};  // Округляется до 1.123457 (6 знаков после запятой)
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_rounding) {
  float f = 0.09999999;  // Близко к 0.1, но не точно 0.1
  s21_decimal decimal_check = {
      {9999999, 0x0, 0x0, 0x80000}};  // Должно округлиться в 0.1
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_powers_of_10) {
  float f = 10000.0;
  s21_decimal decimal_check = {{10000, 0x0, 0x0, 0x0}};
  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

void test_from_float_to_decimal(float value, s21_decimal decimal_check) {
  s21_decimal result;

  // Вызываем тестируемую функцию
  int code = s21_from_float_to_decimal(value, &result);

  // Проверка кода возврата
  if (code != ERROR_OK) {
    printf("Ошибка: s21_from_float_to_decimal(%f) вернула %d\n", value, code);
    exit(1);  // Завершаем тест с ошибкой
  }

  // Проверка, что результат соответствует ожидаемому
  if (s21_is_not_equal(result, decimal_check)) {
    printf("Тест преобразования %.7g не пройден!\n", value);
    printf(" Ожидаемый результат:   " PRINT_FORMAT "\n",
           decimal_check.bits[HIGH], decimal_check.bits[1],
           decimal_check.bits[0], decimal_check.bits[SCALE_SIGN]);
    printf(" Фактический результат: " PRINT_FORMAT "\n", result.bits[HIGH],
           result.bits[1], result.bits[0], result.bits[SCALE_SIGN]);
    printf("%.7g\n", fabs(value));
    exit(1);
  }
}

TCase *s21_ConversionTCaseFromFloat() {
  TCase *tc_core = tcase_create("ConversionFromFloat");

  tcase_add_test(tc_core, test_from_float_to_decimal_incorrect1);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal1);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal2);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal3);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal4);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal5);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal6);

  tcase_add_test(tc_core, test_from_float_to_decimal_ok1);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok3);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok4);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok5);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok6);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok7);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok8);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok9);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok10);

  tcase_add_test(tc_core, test_from_float_to_decimal_max);
  tcase_add_test(tc_core, test_from_float_to_decimal_min);

  tcase_add_test(tc_core, test_from_float_to_decimal_overflow);
  tcase_add_test(tc_core, test_from_float_to_decimal_underflow);

  tcase_add_test(tc_core, test_from_float_to_decimal_tiny);
  tcase_add_test(tc_core, test_from_float_to_decimal_precision_loss);
  tcase_add_test(tc_core, test_from_float_to_decimal_rounding);
  tcase_add_test(tc_core, test_from_float_to_decimal_powers_of_10);

  return tc_core;
}
