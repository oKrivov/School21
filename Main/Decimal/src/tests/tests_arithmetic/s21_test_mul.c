#include "../s21_tests_runner.h"

void test_mul(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_mul_fail1(s21_decimal decimal1, s21_decimal decimal2, int code_check);

START_TEST(test_mul_fail_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_mul(decimal1, decimal2, NULL);

  ck_assert_int_ne(code, 0);
}

START_TEST(test_mul_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(test_mul_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(test_mul_fail_manual4) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, ERROR_OK);
}
END_TEST

START_TEST(test_mul_fail_manual5) {
  // степень 28 (корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(test_mul_fail_manual6) {
  // Просто все единицы
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(test_mul_fail_manual7) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal2 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(test_mul_fail_manual8) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, ERROR_OK);
}
END_TEST

START_TEST(test_mul_fail_manual9) {
  // степень 28 (корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(test_mul_manual1) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7.8228162514264337593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0x1C0000}};
  // 61.978735728724164262422454727
  s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x1B0000}};
  test_mul(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_mul_manual2) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -0.8228162514264337593543950335
  s21_decimal decimal2 = {{0x4F63FFFF, 0xBB0D25CF, 0x1A962D2F, 0x801C0000}};
  // -6.5190219687391279469416894926
  s21_decimal check = {{0x23B23CAE, 0xEC60363A, 0xD2A415FA, 0x801C0000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual3) {
  // -7.000000000000025
  s21_decimal decimal1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -0.00000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x800E0000}};
  // 0.0000000000003500000000000012
  s21_decimal check = {{0x40B6C00C, 0xC6F3B, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual4) {
  // 79228162514265.1
  s21_decimal decimal1 = {{0x70D4257B, 0x2D093, 0x0, 0x10000}};
  // 78228162514264.5
  s21_decimal decimal2 = {{0x22618575, 0x2C77B, 0x0, 0x10000}};
  // 6197873572872488935063484519.0
  s21_decimal check = {{0xA1CDB406, 0x3FDA3F58, 0xC8439BCC, 0x10000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual5) {
  // 5.0
  s21_decimal decimal1 = {{0x32, 0x0, 0x0, 0x10000}};
  // 4.5
  s21_decimal decimal2 = {{0x2D, 0x0, 0x0, 0x10000}};
  // 22.50
  s21_decimal check = {{0x8CA, 0x0, 0x0, 0x20000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual6) {
  // -7.000000000000025
  s21_decimal decimal1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -0.0000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x800D0000}};
  // 0.0000000000035000000000000125
  s21_decimal check = {{0x8723807D, 0x7C5850, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual7) {
  // 7922816251426433759354395032.8
  s21_decimal decimal1 = {{0xFFFFFFF8, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -10.000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801B0000}};
  // overflow
  int code_check = 2;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul_manual8) {
  // -0.0000000000000025
  s21_decimal decimal1 = {{0x19, 0x0, 0x0, 0x80100000}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ERROR_OK);
  ck_assert(s21_is_equal(decimal_check, result) == 1);
}

START_TEST(test_mul1) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int code_check = 2;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul2) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 26409387504754779197847983442
  s21_decimal decimal_check = {{0x55555552, 0x55555555, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul3) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -26409387504754779197847983442
  s21_decimal decimal_check = {
      {0x55555552, 0x55555555, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul4) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int code_check = 1;

  test_mul_fail1(decimal1, decimal2, code_check);
}
END_TEST

START_TEST(test_mul5) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul6) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // overflow
  int code_check = 2;

  test_mul_fail1(decimal1, decimal2, code_check);
}
END_TEST

START_TEST(test_mul7) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -8803129166201954835059936825
  s21_decimal decimal_check = {
      {0x38E38E39, 0x55555555, 0x1C71C71C, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul8) {
  // -6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 8803129166201954835059936825
  s21_decimal decimal_check = {{0x38E38E39, 0x55555555, 0x1C71C71C, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul9) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -715827882.5
  s21_decimal decimal_check = {{0xAAAAAAA9, 0x1, 0x0, 0x80010000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul10) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 715827882.49999999999999999986
  s21_decimal decimal_check = {{0x1A27FFF2, 0xA936C5A3, 0xE74BE506, 0x140000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul11) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int code_check = 2;

  test_mul_fail1(decimal1, decimal2, code_check);
}
END_TEST

START_TEST(test_mul12) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul13) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul14) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul15) {
  // -8
  s21_decimal decimal1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -8
  s21_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul16) {
  // -8
  s21_decimal decimal1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 8
  s21_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul17) {
  // -8
  s21_decimal decimal1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -4.0
  s21_decimal decimal_check = {{0x28, 0x0, 0x0, 0x80010000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul18) {
  // -8
  s21_decimal decimal1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 4.0
  s21_decimal decimal_check = {{0x28, 0x0, 0x0, 0x10000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul19) {
  // -8
  s21_decimal decimal1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -3.9999999999999999999999999992
  s21_decimal decimal_check = {
      {0x3FFFFFF8, 0xF8940984, 0x813F3978, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul20) {
  // -8
  s21_decimal decimal1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 3.9999999999999999999999999992
  s21_decimal decimal_check = {{0x3FFFFFF8, 0xF8940984, 0x813F3978, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul21) {
  // -8
  s21_decimal decimal1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -4.0000000000000000000000000008
  s21_decimal decimal_check = {
      {0x40000008, 0xF8940984, 0x813F3978, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul22) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950327
  s21_decimal decimal_check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul23) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // -49784604.001688959238158904099
  s21_decimal decimal_check = {
      {0x40136B23, 0xBF8285B9, 0xA0DCDBF6, 0x80150000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul24) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 49784604.001688959238158904099
  s21_decimal decimal_check = {{0x40136B23, 0xBF8285B9, 0xA0DCDBF6, 0x150000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul25) {
  // -7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 186339899714.06192437020438652
  s21_decimal decimal_check = {{0xF079B07C, 0x741E2292, 0x3C35ACDC, 0x110000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul26) {
  // -7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 7055.820576069728775806815669
  s21_decimal decimal_check = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul27) {
  // -792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -396140812571321.68796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x800E0000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

START_TEST(test_mul28) {
  // -1.0000000000000000000000000001
  s21_decimal decimal1 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 6148914691236517205.0000000006
  s21_decimal decimal_check = {{0x8EA6B406, 0x55555554, 0xC6AEA155, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul29) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 11453246120
  s21_decimal decimal_check = {{0xAAAAAAA8, 0x2, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul30) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = ERROR_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul31) {
  // 26409387.504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -162389070814544768680495185.58
  s21_decimal decimal_check = {
      {0x9C3D3FDE, 0xD33DA3EB, 0x34788254, 0x80020000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul32) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 0.0000000000000000000000000079
  s21_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul33) {
  // -0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul34) {
  // 0.0000000000000000000000000010
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -0.0000000000007922816251426434
  s21_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul35) {
  // -7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -3527.9102880348643879034078352
  s21_decimal decimal_check = {{0xD70C490, 0x4F88C777, 0x71FE309F, 0x80190000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul36) {
  // -26409387498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 26409387498605864508043122002
  s21_decimal decimal_check = {{0x55555552, 0x0, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul37) {
  // -26409387.498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -186339899714.06192437020438652
  s21_decimal decimal_check = {
      {0xF079B07C, 0x741E2292, 0x3C35ACDC, 0x80110000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul38) {
  // -0.0000000000000025
  s21_decimal decimal1 = {{0x19, 0x0, 0x0, 0x80100000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -0.00000000000000125
  s21_decimal decimal_check = {{0x7D, 0x0, 0x0, 0x80110000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul39) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul40) {
  // -400435217312910.10886274103770
  s21_decimal decimal1 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int code_check = ERROR_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul41) {
  // -57476540395758265626.742442133
  s21_decimal decimal1 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x80090000}};
  // 7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -405544156365694122530650.07150
  s21_decimal decimal_check = {
      {0xCE81D02E, 0xDA391347, 0x8309D38C, 0x80050000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul42) {
  // -6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 162389070738926464946696025.64
  s21_decimal decimal_check = {{0x932B7F04, 0x6A4C9F42, 0x34788254, 0x20000}};

  test_mul(decimal1, decimal2, decimal_check);
}
START_TEST(test_mul43) {
  // -26409387
  s21_decimal decimal1 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // 20923672051380999118065.508859
  s21_decimal decimal_check = {{0x3BF421FB, 0xB95D0366, 0x439BA7E6, 0x60000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul44) {
  // 0
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  // 0
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  // Ожидаемый результат: 0
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul45) {
  // 1431655762
  s21_decimal decimal1 = {{0x55C59C1E, 0, 0, 0}};
  // 0
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  // Ожидаемый результат: 0
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul46) {
  s21_decimal decimal = {{0x12345678, 0, 0, 0}};
  int digit = 5;  // Остаток при уменьшении экспоненты
  s21_decimal decimal_check = {{0x12345678, 0, 0, 0}};

  int result = s21_BankRound(&decimal, digit);

  ck_assert_int_eq(result,
                   0);  // Ожидаем, что результат округления будет
                        // успешным (возвращаемое значение должно быть 0)

  ck_assert_mem_eq(&decimal, &decimal_check, sizeof(s21_decimal));
}

START_TEST(test_mul47) {
  s21_decimal decimal = {{0x12345678, 0x23456789, 0x34567890, 0}};
  int digit = 5;  // Остаток при уменьшении экспоненты
  s21_decimal decimal_check = {{0x12345678, 0x23456789, 0x34567890, 0}};

  int result = s21_BankRound(&decimal, digit);
  ck_assert_int_eq(result, 0);  // Поверка успешного выполнения функции
  ck_assert_mem_eq(&decimal, &decimal_check,
                   sizeof(s21_decimal));  // Проверка результата
}

START_TEST(test_mul48) {
  // -7922816251426433759354395032.7
  s21_decimal decimal1 = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -10.000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul49) {
  // 6148914689804861440
  s21_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 49191317518438891520
  s21_decimal decimal_check = {{0x0, 0xAAAAAAA8, 0x2, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul50) {
  // -26409387.504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // 0.0000000660234687618869479946
  s21_decimal decimal_check = {{0xE9B5CA0A, 0xCA98CE50, 0x23, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul51) {
  // 1.0000000000000000000000000001
  s21_decimal decimal1 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x80090000}};
  // -57476540395758265626.742442139
  s21_decimal decimal_check = {
      {0xD42B489B, 0x339BF28D, 0xB9B77ADA, 0x80090000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul52) {
  // -57476540395758265626.742442133
  s21_decimal decimal1 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x80090000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 1517920227390853308343951696.3
  s21_decimal decimal_check = {{0xEFFE4D23, 0x19328376, 0x310BF11C, 0x10000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul53) {
  // -7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int code_check = ERROR_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul54) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 49784604.001688959238158904099
  s21_decimal decimal_check = {{0x40136B23, 0xBF8285B9, 0xA0DCDBF6, 0x150000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul55) {
  // Пример, когда округление не требуется
  s21_decimal decimal = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  int digit = 3;  // остаток от деления
  int result = s21_BankRound(&decimal, digit);

  s21_decimal expected = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F,
                           0x180000}};  // Ожидаемая часть без изменений
  ck_assert_int_eq(result, 0);
  ck_assert_mem_eq(&decimal, &expected, sizeof(s21_decimal));
}

START_TEST(test_mul56) {
  // Простое вычитание без переполнения
  s21_decimal val1 = {{5, 0, 0, 0}};      // 5
  s21_decimal val2 = {{3, 0, 0, 0}};      // 3
  s21_decimal expected = {{2, 0, 0, 0}};  // 2

  s21_decimal result;
  int ret = s21_Msub(val1, val2, &result);

  ck_assert_int_eq(ret, 0);  // Без переполнения
  ck_assert_uint_eq(result.bits[0],
                    expected.bits[0]);  // Проверяем младший разряд
}

START_TEST(test_mul57) {
  // Вычитание с заимствованием
  s21_decimal val1 = {{0, 1, 0, 0}};             // 2^32
  s21_decimal val2 = {{1, 0, 0, 0}};             // 1
  s21_decimal expected = {{UINT_MAX, 0, 0, 0}};  // 2^32 - 1

  s21_decimal result;
  int ret = s21_Msub(val1, val2, &result);

  ck_assert_int_eq(ret, 0);  // Без переполнения
  ck_assert_uint_eq(result.bits[0],
                    expected.bits[0]);  // Проверяем младший разряд
}

void test_mul(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  if (code == ERROR_OK && s21_is_not_equal(result, check)) {
    printf("Expected: %u %u %u %u\n", check.bits[0], check.bits[1],
           check.bits[2], check.bits[3]);
    printf("Result: %u %u %u %u\n", result.bits[0], result.bits[1],
           result.bits[2], result.bits[3]);
  }
  ck_assert_msg(code == ERROR_OK, "s21_mul returned %d", code);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}

void test_mul_fail1(s21_decimal decimal1, s21_decimal decimal2,
                    int code_check) {
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, code_check);
}

TCase *s21_AritmeticTCaseMul() {
  TCase *tcase = tcase_create("s21_AritmeticTCaseMul");

  tcase_add_test(tcase, test_mul_fail_manual1);
  tcase_add_test(tcase, test_mul_fail_manual2);
  tcase_add_test(tcase, test_mul_fail_manual3);
  tcase_add_test(tcase, test_mul_fail_manual4);
  tcase_add_test(tcase, test_mul_fail_manual5);
  tcase_add_test(tcase, test_mul_fail_manual6);
  tcase_add_test(tcase, test_mul_fail_manual7);
  tcase_add_test(tcase, test_mul_fail_manual8);
  tcase_add_test(tcase, test_mul_fail_manual9);

  tcase_add_test(tcase, test_mul_manual1);
  tcase_add_test(tcase, test_mul_manual2);
  tcase_add_test(tcase, test_mul_manual3);
  tcase_add_test(tcase, test_mul_manual4);
  tcase_add_test(tcase, test_mul_manual5);
  tcase_add_test(tcase, test_mul_manual6);
  tcase_add_test(tcase, test_mul_manual7);
  tcase_add_test(tcase, test_mul_manual8);

  tcase_add_test(tcase, test_mul1);
  tcase_add_test(tcase, test_mul2);
  tcase_add_test(tcase, test_mul3);
  tcase_add_test(tcase, test_mul4);
  tcase_add_test(tcase, test_mul5);
  tcase_add_test(tcase, test_mul6);
  tcase_add_test(tcase, test_mul7);
  tcase_add_test(tcase, test_mul8);
  tcase_add_test(tcase, test_mul9);
  tcase_add_test(tcase, test_mul10);
  tcase_add_test(tcase, test_mul11);
  tcase_add_test(tcase, test_mul12);
  tcase_add_test(tcase, test_mul13);
  tcase_add_test(tcase, test_mul14);
  tcase_add_test(tcase, test_mul15);
  tcase_add_test(tcase, test_mul16);
  tcase_add_test(tcase, test_mul17);
  tcase_add_test(tcase, test_mul18);
  tcase_add_test(tcase, test_mul19);
  tcase_add_test(tcase, test_mul20);
  tcase_add_test(tcase, test_mul21);
  tcase_add_test(tcase, test_mul22);
  tcase_add_test(tcase, test_mul23);
  tcase_add_test(tcase, test_mul24);
  tcase_add_test(tcase, test_mul25);
  tcase_add_test(tcase, test_mul26);
  tcase_add_test(tcase, test_mul27);
  tcase_add_test(tcase, test_mul28);
  tcase_add_test(tcase, test_mul29);
  tcase_add_test(tcase, test_mul30);
  tcase_add_test(tcase, test_mul31);
  tcase_add_test(tcase, test_mul32);
  tcase_add_test(tcase, test_mul33);
  tcase_add_test(tcase, test_mul34);
  tcase_add_test(tcase, test_mul35);
  tcase_add_test(tcase, test_mul36);
  tcase_add_test(tcase, test_mul37);
  tcase_add_test(tcase, test_mul38);
  tcase_add_test(tcase, test_mul39);
  tcase_add_test(tcase, test_mul40);
  tcase_add_test(tcase, test_mul41);
  tcase_add_test(tcase, test_mul42);
  tcase_add_test(tcase, test_mul43);
  tcase_add_test(tcase, test_mul44);
  tcase_add_test(tcase, test_mul45);
  tcase_add_test(tcase, test_mul46);
  tcase_add_test(tcase, test_mul47);
  tcase_add_test(tcase, test_mul48);
  tcase_add_test(tcase, test_mul49);
  tcase_add_test(tcase, test_mul50);
  tcase_add_test(tcase, test_mul51);
  tcase_add_test(tcase, test_mul52);
  tcase_add_test(tcase, test_mul53);
  tcase_add_test(tcase, test_mul54);
  tcase_add_test(tcase, test_mul55);
  tcase_add_test(tcase, test_mul56);
  tcase_add_test(tcase, test_mul57);

  return tcase;
}
