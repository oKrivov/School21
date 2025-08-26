#include "../s21_tests_runner.h"

void test_add(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_add_fail(s21_decimal decimal1, s21_decimal decimal2, int check);

START_TEST(test_add_fail_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);  // Передаём указатель!
  ck_assert_int_ne(code, ERROR_OK);
}
END_TEST

START_TEST(test_add_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);
  ck_assert_int_ne(code, ERROR_OK);
}
END_TEST

START_TEST(test_add_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);
  ck_assert_int_ne(code, ERROR_OK);
}
END_TEST

START_TEST(test_add_fail_manual4) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);
  ck_assert_int_ne(code, ERROR_OK);
}
END_TEST

START_TEST(test_add_fail_manual5) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);
  ck_assert_int_ne(code, ERROR_OK);
}
END_TEST

START_TEST(test_add_fail_manual6) {
  // Просто все единицы
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);
  ck_assert_int_ne(code, ERROR_OK);
}
END_TEST

START_TEST(test_add_fail_manual7) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal2 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);
  ck_assert_int_ne(code, ERROR_OK);
}
END_TEST

START_TEST(test_add_fail_manual8) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);
  ck_assert_int_ne(code, ERROR_OK);
}
END_TEST

START_TEST(test_add_fail_manual9) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);
  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(test_add_manual1) {
  // 7.922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x1B0000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 11.884224377139650639031592551
  s21_decimal check = {{0x66666667, 0x66666666, 0x26666666, 0x1B0000}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // 79228162514264337593543950335
  s21_decimal decimal2 = s21_MaxValue();
  // overflow
  int check = 1;
  test_add_fail(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // 79228162514264337593543950334
  s21_decimal decimal2 = s21_MaxValue();
  // overflow
  int check = 1;
  test_add_fail(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = 1;
  test_add_fail(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add6) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add8) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // overflow
  int check = 1;
  test_add_fail(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add10) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int check = 1;
  test_add_fail(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // overflow
  int check = 1;
  test_add_fail(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  test_add_fail(decimal1, decimal2, ERROR_BIG);
}
END_TEST

START_TEST(test_add16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = s21_MaxValue();
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add18) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -1.0000000000000000000000000000
  s21_decimal check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add19) {
  // 0.5
  s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -0.5
  s21_decimal check = {{0x5, 0x0, 0x0, 0x80010000}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add20) {
  // -1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -2.9999999999999999999999999001
  s21_decimal check = {{0x2FFFFC19, 0xBA6F0723, 0x60EF6B1A, 0x801C0000}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add21) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // 26409394.922816251426433759354
  s21_decimal check = {{0x4965787A, 0x779DCBC0, 0x555556E7, 0x150000}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add22) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -26409379.077183748573566240646
  s21_decimal check = {{0x605A8786, 0x794A742A, 0x5555538C, 0x80150000}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add23) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add24) {
  //  649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 0.00000000000000000000
  s21_decimal check = {{0x0, 0x0, 0x0, 0x140000}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add25) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.5
  s21_decimal check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add26) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -34332203756181212957202378478
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x6EEEEEEE, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add27) {
  // 56124981125209321576924.010631
  s21_decimal decimal1 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7922760126445308550032818109.0
  s21_decimal check = {{0x4BB0FD62, 0x9636572A, 0xFFFF8926, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add28) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -26409387498605864508043122006
  s21_decimal check = {{0x55555556, 0x0, 0x55555555, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add29) {
  // 56124981125209321576924.010631
  s21_decimal decimal1 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 56124981125209347986311.509237
  s21_decimal check = {{0xF97E74F5, 0x553F2E45, 0xB5597F0B, 0x60000}};

  test_add(decimal1, decimal2, check);
}
START_TEST(test_add30) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7.4228162514264337593543950334
  s21_decimal check = {{0x77FFFFFE, 0xE0ED7ECF, 0xEFD818D0, 0x1C0000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add31) {
  // -1.0000000000000000000000000001
  s21_decimal decimal1 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387504754779197847983446
  s21_decimal check = {{0x55555556, 0x55555555, 0x55555555, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add32) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162508115422902307433130
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add33) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -1431655766
  s21_decimal check = {{0x55555556, 0x0, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add34) {
  // -26409387.498605864508043122005
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -52818774.498605864508043122005
  s21_decimal check = {{0xAA355555, 0xF8741FF5, 0xAAAAAA8E, 0x80150000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add35) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395025.6
  s21_decimal check = {{0xFFFFFFB0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add36) {
  // 3.6336660283201536
  s21_decimal decimal1 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950331
  s21_decimal check = {{0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add37) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -6148914691236517205
  s21_decimal check = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add38) {
  // -0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 6148914691236517205.0000000000
  s21_decimal check = {{0x8EA6B400, 0x55555554, 0xC6AEA155, 0xA0000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add39) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // -56124981125209321576924.010631
  s21_decimal check = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add40) {
  // -56124981125209321576924.010631
  s21_decimal decimal1 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -56124981125209321576924.010631
  s21_decimal check = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add41) {
  // Исходное значение: 1.0000000000
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};  // 1
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};  // 2
  s21_decimal expected = {
      {0x3, 0x0, 0x0, 0x0}};  // 3 (результат сложения 1 + 2)

  test_add(decimal1, decimal2, expected);
}

START_TEST(test_add42) {
  // -5.0000000000
  s21_decimal decimal1 = {{0x50000000, 0x0, 0x0, 0x801C0000}};
  // -3.0000000000
  s21_decimal decimal2 = {{0x30000000, 0x0, 0x0, 0x801C0000}};
  // -8.0000000000
  s21_decimal check = {{0x80000000, 0x0, 0x0, 0x801C0000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add43) {
  // Исходное значение: -1.0000000000
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};  // -1
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x801C0000}};  // -2
  s21_decimal expected = {
      {0x3, 0x0, 0x0, 0x801C0000}};  // -3 (результат сложения -1 + -2)

  test_add(decimal1, decimal2, expected);
}

START_TEST(test_add44) {
  // 999999999.9999999999
  s21_decimal decimal1 = {{0xF4240000, 0x0, 0x0, 0x0}};
  // 1.0000000000
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 1000000000.0000000000
  s21_decimal check = {{0xF4240001, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add45) {
  // 0x80000000 = 10000000000000000000000000000000
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};

  // Проверка бита на позиции 31 (самый старший бит)
  int bit31 = s21_GetBit(decimal, 31);
  ck_assert_int_eq(bit31, 1);  // Бит 31 должен быть установлен

  // Проверка бита на позиции 0 (самый младший бит)
  int bit0 = s21_GetBit(decimal, 0);
  ck_assert_int_eq(bit0, 0);  // Бит 0 должен быть сброшен
}

START_TEST(test_add46) {
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x0}};

  // Устанавливаем бит на позиции 0
  s21_SetBit(&decimal, 0, 1);
  int bit0 = s21_GetBit(decimal, 0);
  ck_assert_int_eq(bit0, 1);  // Бит 0 должен быть установлен

  // Устанавливаем бит на позиции 31
  s21_SetBit(&decimal, 31, 1);
  int bit31 = s21_GetBit(decimal, 31);
  ck_assert_int_eq(bit31, 1);  // Бит 31 должен быть установлен
}

START_TEST(test_add47) {
  // Начальное значение: 0x80000000
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};

  // Сбрасываем бит на позиции 31
  s21_SetBit(&decimal, 31, 0);
  int bit31 = s21_GetBit(decimal, 31);
  ck_assert_int_eq(bit31, 0);  // Бит 31 должен быть сброшен

  // Сбрасываем бит на позиции 0
  s21_SetBit(&decimal, 0, 0);
  int bit0 = s21_GetBit(decimal, 0);
  ck_assert_int_eq(bit0, 0);  // Бит 0 должен быть сброшен
}

START_TEST(test_add48) {
  // Нулевое значение
  s21_decimal zero = {{0x0, 0x0, 0x0, 0x0}};

  // Проверяем, что число действительно равно нулю
  int is_zero = s21_IsZeroAdd(zero);
  ck_assert_int_eq(is_zero, 1);  // Это число должно быть нулевым

  // Некоторое ненулевое значение
  s21_decimal non_zero = {{0x1, 0x0, 0x0, 0x0}};

  // Проверяем, что число не является нулем
  int is_non_zero = s21_IsZeroAdd(non_zero);
  ck_assert_int_eq(is_non_zero, 0);  // Это число не должно быть нулевым
}

START_TEST(test_add49) {
  // Нулевое значение
  s21_decimal zero = {{0x0, 0x0, 0x0, 0x0}};

  // Некоторое ненулевое значение
  s21_decimal non_zero = {{0x1, 0x0, 0x0, 0x0}};

  // Сравниваем их
  int compare_result = s21_Compare(zero, non_zero);
  ck_assert_int_eq(compare_result, -1);  // 0 должно быть меньше 1
}

void test_add(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);
  ck_assert_msg(code == ERROR_OK, "s21_add returned %d", code);
  if (code == ERROR_OK && s21_is_not_equal(result, check)) {
    printf("Test failed!\n");
    printf(" Expected:");
    s21_PrintDecimal(check);
    printf(" Actual:  ");
    s21_PrintDecimal(result);
  }
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}

void test_add_fail(s21_decimal decimal1, s21_decimal decimal2, int check) {
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, check);
}

TCase *s21_AritmeticTCaseAdd() {
  TCase *tcase = tcase_create("s21_AritmeticTCaseAdd");

  tcase_add_test(tcase, test_add_fail_manual1);
  tcase_add_test(tcase, test_add_fail_manual2);
  tcase_add_test(tcase, test_add_fail_manual3);
  tcase_add_test(tcase, test_add_fail_manual4);
  tcase_add_test(tcase, test_add_fail_manual5);
  tcase_add_test(tcase, test_add_fail_manual6);
  tcase_add_test(tcase, test_add_fail_manual7);
  tcase_add_test(tcase, test_add_fail_manual8);
  tcase_add_test(tcase, test_add_fail_manual9);

  tcase_add_test(tcase, test_add_manual1);
  tcase_add_test(tcase, test_add1);
  tcase_add_test(tcase, test_add2);
  tcase_add_test(tcase, test_add3);
  tcase_add_test(tcase, test_add4);
  tcase_add_test(tcase, test_add5);
  tcase_add_test(tcase, test_add6);
  tcase_add_test(tcase, test_add7);
  tcase_add_test(tcase, test_add8);
  tcase_add_test(tcase, test_add9);
  tcase_add_test(tcase, test_add10);
  tcase_add_test(tcase, test_add11);
  tcase_add_test(tcase, test_add12);
  tcase_add_test(tcase, test_add13);
  tcase_add_test(tcase, test_add14);
  tcase_add_test(tcase, test_add15);
  tcase_add_test(tcase, test_add16);
  tcase_add_test(tcase, test_add18);
  tcase_add_test(tcase, test_add19);
  tcase_add_test(tcase, test_add20);
  tcase_add_test(tcase, test_add21);
  tcase_add_test(tcase, test_add22);
  tcase_add_test(tcase, test_add23);
  tcase_add_test(tcase, test_add24);
  tcase_add_test(tcase, test_add25);
  tcase_add_test(tcase, test_add26);
  tcase_add_test(tcase, test_add27);
  tcase_add_test(tcase, test_add28);
  tcase_add_test(tcase, test_add29);
  tcase_add_test(tcase, test_add30);
  tcase_add_test(tcase, test_add31);
  tcase_add_test(tcase, test_add32);
  tcase_add_test(tcase, test_add33);
  tcase_add_test(tcase, test_add34);
  tcase_add_test(tcase, test_add35);
  tcase_add_test(tcase, test_add36);
  tcase_add_test(tcase, test_add37);
  tcase_add_test(tcase, test_add38);
  tcase_add_test(tcase, test_add39);
  tcase_add_test(tcase, test_add40);
  tcase_add_test(tcase, test_add41);
  tcase_add_test(tcase, test_add42);
  tcase_add_test(tcase, test_add43);
  tcase_add_test(tcase, test_add44);
  tcase_add_test(tcase, test_add45);
  tcase_add_test(tcase, test_add46);
  tcase_add_test(tcase, test_add47);
  tcase_add_test(tcase, test_add48);
  tcase_add_test(tcase, test_add49);

  return tcase;
}
