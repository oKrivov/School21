#include "../s21_decimal.h"
#define MAX_BITS 128

/*
 * @brief Функция отбарасывает дробную часть, включая конечные нули
 * @return int   0 - Ok 1 - Error
 */
int s21_truncate(s21_decimal dcml, s21_decimal *result) {
  int return_code = 0;

  if (!result) {
    return_code = 1;
  } else if (!s21_IsCorrectDecimal(dcml)) {
    return_code = 1;
    *result = s21_GetIncorrectDecimal();
  } else {
    s21_ClearDecimal(result);
    int scale = s21_GetScale(dcml);
    s21_decimal tmp = dcml;
    tmp.bits[3] = 0;
    s21_decimal ten = {{10, 0, 0, 0}};

    for (; scale > 0; scale--) {
      tmp = s21_TruncateHandler(tmp, ten);
    }

    *result = tmp;

    if (s21_GetSign(dcml) == 1) {
      s21_SetSign(result, 1);
    }
  }
  return return_code;
}

/**
 * @brief Функция бинарного деления двоичных положительных целых чисел размера
 *128бит.
 */
s21_decimal s21_TruncateHandler(s21_decimal dcml_1, s21_decimal dcml_2) {
  s21_decimal res;

  // Рассчитываемый в алгоритме частичный остаток при расчетах
  s21_decimal partial_remainder = {};
  // Рассчитываемое в алгоритме частное
  s21_decimal quotient = {};

  if (s21_BinaryCompareInt128(dcml_1, dcml_2) == -1) {
    // Затем заполняем результаты для частного случая, когда делимое меньше
    // делителя
    partial_remainder = dcml_1;
  } else {
    // Рассчитываем предварительный сдвиг делителя
    int left_1 = s21_GetFirstBitPosition(dcml_1);
    int left_2 = s21_GetFirstBitPosition(dcml_2);
    int shift = left_1 - left_2;

    // сдвиг делителя
    s21_decimal shifted_devisor = s21_BinaryLeftShift(dcml_2, shift);

    // Делимое для промежуточных расчетов, на первом этапе равно decimal1
    s21_decimal dividend = dcml_1;

    // Флаг необходимости проводить вычитание.
    // На первой итерации всегда требуется вычитать
    int need_subtraction = 1;

    // Повторяем действия k+1 раз
    while (shift >= 0) {
      if (need_subtraction == 1) {
        partial_remainder = s21_BinarySubInt128(dividend, shifted_devisor);
      } else {
        partial_remainder = s21_BinaryAddInt128(dividend, shifted_devisor);
      }

      // Сдвигаем влево на 1 частное и записываем в младший бит результата 1,
      // если старший бит частичного остатка равен 1
      quotient = s21_BinaryLeftShift(quotient, 1);
      if ((s21_GetBit(partial_remainder, MAX_BITS - 1) == 0)) {
        s21_SetBit(&quotient, 0, 1);
      }

      // Рассчитываем делимое для следующей итерации цикла (сдвиг влево на 1
      // частичного остатка)
      dividend = s21_BinaryLeftShift(partial_remainder, 1);

      // Если старший бит частичного остатка равен 0, то на следующей итерации
      // необходимо проводить вычитание
      if ((s21_GetBit(partial_remainder, MAX_BITS - 1)) == 0) {
        need_subtraction = 1;
      } else {
        need_subtraction = 0;
      }
      shift--;
    }
    // Определяем, требуется ли коррекция остатка
    if (s21_GetBit(partial_remainder, MAX_BITS - 1)) {
      partial_remainder =
          s21_BinaryAddInt128(partial_remainder, shifted_devisor);
    }
    // Возвращаем на место частичный остаток
    partial_remainder =
        s21_BinaryRightShift(partial_remainder, left_1 - left_2);
  }
  // Заполняем переменные результата (частное )
  res = quotient;
  return res;
}

/**
 * @brief Битовый сдвиг влево для чисел типа int128 на << 1.
 *
 */
s21_decimal s21_BinaryOneLeftShiftInt128(s21_decimal dcml) {
  s21_decimal res = {};

  int hight_bit_0 = s21_IsSetBit(dcml.bits[0], 31);
  unsigned int res_0 = dcml.bits[0];
  res.bits[0] = (res_0 <<= 1);

  int hight_bit_1 = s21_IsSetBit(dcml.bits[1], 31);
  unsigned int res_1 = dcml.bits[1];
  res.bits[1] = (res_1 <<= 1);

  int hight_bit_2 = s21_IsSetBit(dcml.bits[2], 31);
  unsigned int res_2 = dcml.bits[2];
  res.bits[2] = (res_2 <<= 1);

  unsigned int res_3 = dcml.bits[3];
  res.bits[3] = (res_3 <<= 1);

  if (hight_bit_0) {
    s21_SetBit(&res, 32, 1);
  }
  if (hight_bit_1) {
    s21_SetBit(&res, 64, 1);
  }
  if (hight_bit_2) {
    s21_SetBit(&res, 96, 1);
  }

  return res;
}
/**
 * @brief Битовый сдвиг влево для чисел типа int128 на << Shift.
 *
 */
s21_decimal s21_BinaryLeftShift(s21_decimal dcml, int shift) {
  s21_decimal res = dcml;
  while (shift) {
    res = s21_BinaryOneLeftShiftInt128(res);
    shift--;
  }
  return res;
}
/**
 * @brief Битовый сдвиг вправо для чисел типа int128 на >> Shift.
 *
 */
s21_decimal s21_BinaryRightShift(s21_decimal dcml, int shift) {
  s21_decimal res = dcml;
  while (shift) {
    res = s21_BinaryOneRightShiftInt128(res);
    shift--;
  }
  return res;
}

/**
 * @brief Битовый сдвиг вправо для чисел типа int128 на >> 1.
 *
 */
s21_decimal s21_BinaryOneRightShiftInt128(s21_decimal dcml) {
  s21_decimal res = {};

  int b_3 = s21_IsSetBit(dcml.bits[3], 0);
  unsigned int res_3 = dcml.bits[3];
  res_3 = res_3 >> 1;
  res.bits[3] = res_3;

  int b_2 = s21_IsSetBit(dcml.bits[2], 0);
  unsigned int res_2 = dcml.bits[2];
  res_2 = res_2 >> 1;
  res.bits[2] = res_2;

  int b_1 = s21_IsSetBit(dcml.bits[1], 0);
  unsigned int res_1 = dcml.bits[1];
  res_1 = res_1 >> 1;
  res.bits[1] = res_1;

  unsigned int res_0 = dcml.bits[0];
  res_0 = res_0 >> 1;
  res.bits[0] = res_0;

  if (b_3) {
    s21_SetBit(&res, 95, 1);
  }
  if (b_2) {
    s21_SetBit(&res, 63, 1);
  }
  if (b_1) {
    s21_SetBit(&res, 31, 1);
  }

  return res;
}

/**
 * @brief Функция бинарного сложения двоичных положительных целых чисел размера
 * 128бит.
 *
 */
s21_decimal s21_BinaryAddInt128(s21_decimal dcml_1, s21_decimal dcml_2) {
  s21_decimal res = dcml_1;
  s21_decimal tmp = dcml_2;

  while (!s21_IsDcmlEqualZero(tmp)) {
    // Получаем все биты, где потребуется перенос единицы в следующий разряд
    s21_decimal overflow_bits = s21_BinaryAndInt128(res, tmp);
    // Сдвигаем полученное число на 1 влево
    overflow_bits = s21_BinaryLeftShift(overflow_bits, 1);
    // Получаем результат сложения битов, без учета переносов единиц в следующие
    // разряды
    res = s21_BinaryXorInt128(res, tmp);
    tmp = overflow_bits;
  }

  return res;
}

/*
 * @brief Функция бинарного вычитания двоичных положительных целых чисел
 * int128бит.
 * Вычитание происходит через сложение.
 * A - B = A + -B.
 * dcml_1 должен быть больше чем dcml_2.
 */
s21_decimal s21_BinarySubInt128(s21_decimal dcml_1, s21_decimal dcml_2) {
  s21_decimal res = {{0}};
  s21_decimal dcml_one = {{1, 0, 0, 0}};

  dcml_2 = s21_BinaryNotInt128(dcml_2);
  dcml_2 = s21_BinaryAddInt128(dcml_2, dcml_one);
  res = s21_BinaryAddInt128(dcml_1, dcml_2);

  return res;
}

/*
 * @brief Функция проверяет, установлен ли в числе number бит index.
 * @return int результат провреки:
 *          0 - бит не установлен.
 *          1 - бит установлен.
 */
int s21_IsSetBit(int number, int index) {
  unsigned int res = 1U << index;

  return (number & res) >> index;
}
/**
 * @brief Побитовое «и» для двоичных положительных целых чисел размера
 * 128бит
 */
s21_decimal s21_BinaryAndInt128(s21_decimal dcml_1, s21_decimal dcml_2) {
  s21_decimal res;
  res.bits[0] = dcml_1.bits[0] & dcml_2.bits[0];
  res.bits[1] = dcml_1.bits[1] & dcml_2.bits[1];
  res.bits[2] = dcml_1.bits[2] & dcml_2.bits[2];
  res.bits[3] = dcml_1.bits[3] & dcml_2.bits[3];
  return res;
}

/**
 * @brief Исключающее «или» для двоичных положительных целых чисел размера
 * 128бит
 */
s21_decimal s21_BinaryXorInt128(s21_decimal dcml_1, s21_decimal dcml_2) {
  s21_decimal res;
  res.bits[0] = dcml_1.bits[0] ^ dcml_2.bits[0];
  res.bits[1] = dcml_1.bits[1] ^ dcml_2.bits[1];
  res.bits[2] = dcml_1.bits[2] ^ dcml_2.bits[2];
  res.bits[3] = dcml_1.bits[3] ^ dcml_2.bits[3];
  return res;
}

s21_decimal s21_BinaryNotInt128(s21_decimal dcml) {
  s21_decimal res = {{0}};
  for (int i = 0; i < 4; i++) {
    res.bits[i] = ~dcml.bits[i];
  }
  return res;
}

/*
 * @brief Сравнивает побитово 2 числа int128
 *@return -1 - dcml_1 < dcml_2
 *
 * 0 - dcml_1 == dcml_2
 *
 * 1 - dcml_1 > dcml_2
 *
 */
int s21_BinaryCompareInt128(s21_decimal dcml_1, s21_decimal dcml_2) {
  int res = 0;
  for (int i = MAX_BITS - 1; i >= 0 && res == 0; i--) {
    int b_1 = s21_GetBit(dcml_1, i);
    int b_2 = s21_GetBit(dcml_2, i);
    if ((b_1 > b_2)) {
      res = 1;
    }
    if ((b_1 < b_2)) {
      res = -1;
    }
  }
  return res;
}

/*
 * @brief Функция проверяет является ли decimal '0', т.е. все биты выключены.
 * @return int 1 - все биты нули, 0 - не все биты нули
 */
int s21_IsDcmlEqualZero(s21_decimal dcml) {
  int res = 1;
  for (int i = 0; i < 128; i++) {
    if (s21_GetBit(dcml, i)) res = 0;
  }
  return res;
}

/*
 * @brief Проверяет коректен ли Decimal
 *
 * @return int 1 - OK, 0 - Not correct
 */
int s21_IsCorrectDecimal(s21_decimal dcml) {
  int code = 1;
  int scale = s21_GetScale(dcml);

  // Проверка Scale
  if (code && (scale > 28 || scale < 0)) {
    code = 0;
  }

  // Проверка битов dcml.bits[3] с 0 по 15
  for (int i = START_BIT_3; code && i <= (START_BIT_3 + 15); i++) {
    if (s21_GetBit(dcml, i)) {
      code = 0;
    }
  }
  // Проверка битов dcml.bits[3] с 24 по 30
  for (int i = START_BIT_3 + 24; code && i <= (START_BIT_3 + 30); i++) {
    if (s21_GetBit(dcml, i)) {
      code = 0;
    }
  }

  return code;
}
