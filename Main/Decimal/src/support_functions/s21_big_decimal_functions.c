#include "../s21_decimal.h"

int s21_SubBigDecimal(s21_big_decimal big_value_1, s21_big_decimal big_value_2,
                      s21_big_decimal *big_result) {
  int error_code = -1;

  s21_NormalizeBigDecimal(&big_value_1, &big_value_2);

  int sign_1 = s21_GetSignBigDecimal(big_value_1);
  int sign_2 = s21_GetSignBigDecimal(big_value_2);

  if ((sign_1 && sign_2) || (!sign_1 && !sign_2)) {         // -- или ++
    if (s21_IsEqualBigDecimal(big_value_1, big_value_2)) {  // равны
      error_code = 0;
    } else if (s21_IsGreaterModuleBigDecimal(big_value_1,
                                             big_value_2)) {  // первое больше
      s21_SubBitsBigDecimal(big_value_1, big_value_2, big_result);
    } else {  // второе больше
      s21_SubBitsBigDecimal(big_value_2, big_value_1, big_result);
      sign_1 = sign_1 ? 0 : MAX_LEFT_SHIFT;
    }
  } else {  // -+ или +-
    s21_AddBitsBigDecimal(big_value_1, big_value_2, big_result);
  }

  if (error_code < 0) {
    s21_SetSignBigDecimal(big_result, sign_1);
    s21_SetExpBigDecimal(big_result, s21_GetExpBigDecimal(big_value_1));

    error_code = s21_GetErrorCodeBigDecimal(big_result);
  }

  return error_code;
}

int s21_DivBigDecimal(s21_big_decimal big_value_1, s21_big_decimal big_value_2,
                      s21_big_decimal *big_result) {
  int error_code = -1;

  if (s21_IsZeroBigDecimal(big_value_2)) {
    error_code = 3;
  } else if (s21_IsZeroBigDecimal(big_value_1)) {
    error_code = 0;
  } else {
    int sign_1 = s21_GetSignBigDecimal(big_value_1);
    int sign_2 = s21_GetSignBigDecimal(big_value_2);

    if (sign_1) {
      big_value_1.bits[7] ^= MAX_LEFT_SHIFT;
    }

    if (sign_2) {
      big_value_2.bits[7] ^= MAX_LEFT_SHIFT;
    }

    s21_DivBitsBigDecimal(big_value_1, big_value_2, big_result);

    if (!((sign_1 && sign_2) || (!sign_1 && !sign_2))) {
      s21_SetSignBigDecimal(big_result, MAX_LEFT_SHIFT);
    }

    error_code = s21_GetErrorCodeBigDecimal(big_result);
  }

  return error_code;
}

int s21_GetExpBigDecimal(s21_big_decimal value) {
  return value.bits[7] & 0b00000000111111110000000000000000;
}

void s21_SetExpBigDecimal(s21_big_decimal *value, int exp) {
  value->bits[7] = s21_GetSignBigDecimal(*value) | exp;
}

int s21_GetSignBigDecimal(s21_big_decimal value) {
  return (value.bits[7] & MAX_LEFT_SHIFT) ? MAX_LEFT_SHIFT : 0;
}

void s21_SetSignBigDecimal(s21_big_decimal *result, int sign) {
  if (sign) {
    result->bits[7] |= sign;
  } else {
    int exp = s21_GetExpBigDecimal(*result);
    result->bits[7] = 0;
    s21_SetExpBigDecimal(result, exp);
  }
}

int s21_GetBitBigDecimal(s21_big_decimal value,
                         int bit_number) {  // bit_number [0; 255]
  return (value.bits[bit_number / 32] & (1u << (bit_number % 32))) ? 1 : 0;
}

void s21_SetBitBigDecimal(s21_big_decimal *result, int bit_number, int bit) {
  result->bits[bit_number / 32] |= (unsigned)bit << (bit_number % 32);
}

/**
 * @brief Приводит числа к одной экспоненте.
 *
 * @param value_1 Указатель на первое число.
 * @param value_2 Указатель на второе число.
 *
 * Функция умножает меньшее число (с большей экспонентой) на 10 столько
 * раз, на сколько большая экспонента превосходит меньшую, чтобы нормализовать
 * числа (привести к одной экспоненте).
 */
void s21_NormalizeBigDecimal(s21_big_decimal *value_1,
                             s21_big_decimal *value_2) {
  int exp_1 = s21_GetExpBigDecimal(*value_1);
  int exp_2 = s21_GetExpBigDecimal(*value_2);

  if (exp_1 != exp_2) {
    int delta_exp = 0;
    s21_big_decimal *greater_value = NULL;
    if (exp_1 > exp_2) {
      greater_value = value_2;
      delta_exp = (exp_1 - exp_2) >> 16;
      s21_SetExpBigDecimal(greater_value, exp_1);
    } else {
      greater_value = value_1;
      delta_exp = (exp_2 - exp_1) >> 16;
      s21_SetExpBigDecimal(greater_value, exp_2);
    }

    for (int i = 0; i < delta_exp; i++) {
      s21_MultiplyingByTenBigDecimal(greater_value);
    }
  }
}

void s21_MultiplyingByTenBigDecimal(s21_big_decimal *value) {
  s21_big_decimal temp1 = *value;
  s21_big_decimal temp2 = temp1;
  s21_ShiftBitsBigDecimal(&temp1, 3);
  s21_ShiftBitsBigDecimal(&temp2, 1);
  s21_AddBitsBigDecimal(temp1, temp2, value);
}

/**
 * @brief Сдвигает биты структуры s21_big_decimal.
 *
 * @param value Указатель на структуру, биты которой будут сдвинуты.
 * @param shift Сдвиг (то, на сколько необходимо сдвинуть число).
 *
 * Функция сдвигает биты в элементах структуры s21_big_decimal на shift.
 */
void s21_ShiftBitsBigDecimal(s21_big_decimal *value, int shift) {
  if (shift) {
    int begining = shift / 32;

    if (begining < 7) {
      int reserve_last_element = value->bits[7];

      int max_index = 7;

      if (shift > 31) {
        shift %= 32;

        s21_MoveStartPointBigDecimal(value, begining);

        max_index = 8;
      }

      for (int i = begining, overflow = 0; shift && i < max_index; i++) {
        int minus = 0;
        // если 31-й бит 1, то при сдвиге биты будут заполнятся не 0, а 1
        if (value->bits[i] < 0) {
          minus = 1;
          value->bits[i] ^= MAX_LEFT_SHIFT;
        }

        int temp = value->bits[i];
        value->bits[i] = (int)((unsigned)value->bits[i] << shift);
        value->bits[i] |= overflow;
        overflow = temp >> (32 - shift);

        // возвращаю измененный ранее (31-й) бит
        if (minus) {
          overflow ^= 1 << (shift - 1);
        }
      }

      if (max_index == 8) {
        value->bits[7] = reserve_last_element;
      }
    } else {
      for (int i = 0; i < 7; i++) {
        value->bits[i] = 0;
      }
    }
  }
}

/**
 * @brief Сдвигает элементы структуры s21_big_decimal.
 *
 * @param value Указатель на структуру, элементы которой будут сдвинуты.
 * @param begining Новое положение 0-го элемента.
 *
 * Функция сдвигает элементы структуры таким образом, что 0-й элемент теперь
 * элемент [begining], последующие элементы за ним.
 */
void s21_MoveStartPointBigDecimal(s21_big_decimal *value, int begining) {
  s21_big_decimal temp_value = *value;

  for (int i = 0, start_index = begining; start_index < 8; i++, start_index++) {
    value->bits[start_index] = temp_value.bits[i];
  }

  for (int i = 0; i < begining; i++) {
    value->bits[i] = 0;
  }
}

/**
 * @brief Находит большее число
 *
 * @param value_1 Первое число.
 * @param value_2 Второе число.
 *
 * Функция сравнивает числа, не проверяя знак и экспоненту, выявляя большее.
 */
int s21_IsGreaterModuleBigDecimal(s21_big_decimal value_1,
                                  s21_big_decimal value_2) {
  int greater = 0;
  for (int i = 223; i >= 0; i--) {
    int bit_1 = s21_GetBitBigDecimal(value_1, i);
    int bit_2 = s21_GetBitBigDecimal(value_2, i);
    if (bit_1 != bit_2) {
      if (bit_1 > bit_2) {
        greater = 1;
      }
      break;
    }
  }

  return greater;
}

int s21_IsEqualBigDecimal(s21_big_decimal value_1, s21_big_decimal value_2) {
  return value_1.bits[0] == value_2.bits[0] &&
         value_1.bits[1] == value_2.bits[1] &&
         value_1.bits[2] == value_2.bits[2] &&
         value_1.bits[3] == value_2.bits[3] &&
         value_1.bits[4] == value_2.bits[4] &&
         value_1.bits[5] == value_2.bits[5] &&
         value_1.bits[6] == value_2.bits[6] &&
         value_1.bits[7] == value_2.bits[7];
}

int s21_IsZeroBigDecimal(s21_big_decimal value) {
  return value.bits[0] == value.bits[1] && value.bits[1] == value.bits[2] &&
         value.bits[2] == value.bits[3] && value.bits[3] == value.bits[4] &&
         value.bits[4] == value.bits[5] && value.bits[5] == value.bits[6] &&
         value.bits[6] == 0;
}

void s21_AddBitsBigDecimal(s21_big_decimal value_1, s21_big_decimal value_2,
                           s21_big_decimal *result) {
  result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] =
      result->bits[4] = result->bits[5] = result->bits[6] = 0;

  for (int i = 0, overflow = 0; i < 32 * 7; i++) {
    int bit = s21_GetBitBigDecimal(value_1, i) +
              s21_GetBitBigDecimal(value_2, i) + overflow;
    overflow = bit / 2;
    bit %= 2;
    s21_SetBitBigDecimal(result, i, bit);
  }
}

void s21_SubBitsBigDecimal(s21_big_decimal value_1, s21_big_decimal value_2,
                           s21_big_decimal *result) {
  result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] =
      result->bits[4] = result->bits[5] = result->bits[6] = 0;

  for (int i = 0, reserve_memory = 0; i < 32 * 7; i++) {
    int bit = s21_GetBitBigDecimal(value_1, i) -
              s21_GetBitBigDecimal(value_2, i) - reserve_memory;
    if (bit < 0) {
      bit *= -1;
      reserve_memory = 1;
    } else {
      reserve_memory = 0;
    }
    bit %= 2;
    s21_SetBitBigDecimal(result, i, bit);
  }
}

void s21_DivBitsBigDecimal(s21_big_decimal remainder, s21_big_decimal divider,
                           s21_big_decimal *big_result) {
  s21_NormalizeBigDecimal(&remainder, &divider);

  int exp = 0;
  int shift = s21_GetShiftBigDecimal(remainder, divider);

  while (!s21_IsZeroBigDecimal(remainder) && exp < 30) {
    s21_big_decimal div_result = {};
    s21_DivBitsWithRemainderBigDecimal(&remainder, divider, shift, &div_result);
    if (!s21_IsZeroBigDecimal(remainder) || exp > 0) {
      s21_MultiplyingByTenBigDecimal(big_result);
      exp++;

      s21_MultiplyingByTenBigDecimal(&remainder);
      shift = s21_GetShiftBigDecimal(remainder, divider);
    }
    s21_AddBitsBigDecimal(*big_result, div_result, big_result);
  }

  if (exp > 0) {
    exp--;
    s21_SetExpBigDecimal(big_result, exp << 16);
  }
}

/**
 * @brief Побитовое деление с остатком
 *
 * @param remainder Указатель на остаток деления.
 * @param divider Делитель.
 * @param shift Сдвиг (то, на сколько необходимо сдвинуть делитель).
 * @param div_result Указатель на деления.
 */
void s21_DivBitsWithRemainderBigDecimal(s21_big_decimal *remainder,
                                        s21_big_decimal divider, int shift,
                                        s21_big_decimal *div_result) {
  for (s21_big_decimal temp_divider = divider, temp_remainder = {}; shift >= 0;
       shift--) {
    s21_ShiftDividerBigDecimal(&divider, temp_divider, shift);

    while (s21_IsGreaterModuleBigDecimal(divider, *remainder) &&
           !s21_IsZeroBigDecimal(*remainder) && shift >= 0) {
      shift--;
      if (shift >= 0) {
        s21_ShiftDividerBigDecimal(&divider, temp_divider, shift);
        s21_ShiftBitsBigDecimal(div_result, 1);
      }
    }

    s21_ResetBigDecimal(&temp_remainder);
    if (!s21_IsZeroBigDecimal(*remainder) && shift >= 0) {
      s21_SubBigDecimal(*remainder, divider, &temp_remainder);
      *remainder = temp_remainder;
      div_result->bits[0] |= 1;
    }

    if (shift > 0) {
      s21_ShiftBitsBigDecimal(div_result, 1);
    }
  }
}

void s21_ShiftDividerBigDecimal(s21_big_decimal *divider,
                                s21_big_decimal reserve_divider, int shift) {
  *divider = reserve_divider;
  s21_ShiftBitsBigDecimal(divider, shift);
}

/**
 * @brief Получает сдвиг.
 *
 * @param divisor Делимое.
 * @param divider Делитель.
 *
 * @return Возвращает число, на которое необходимо сдвинуть делитель,
 * чтобы разряды операндов соответствовали друг другу.
 */
int s21_GetShiftBigDecimal(s21_big_decimal divisor, s21_big_decimal divider) {
  int bit_difference =
      s21_GetBitCountBigDecimal(divisor) - s21_GetBitCountBigDecimal(divider);
  if (bit_difference < 0) {
    bit_difference = 0;
  }
  return bit_difference;
}

/**
 * @brief Получает количество битов в числе.
 *
 * @param value Число
 *
 * Функция необходима для подсчета сдвига делителя.
 *
 * @return Возвращает количество битов в числе.
 */
int s21_GetBitCountBigDecimal(s21_big_decimal value) {
  int bit_number = -1;
  for (int i = 0; i < 32 * 7; i++) {
    if (s21_GetBitBigDecimal(value, i)) {
      bit_number = i;
    }
  }
  return bit_number;
}

void s21_BankRoundBigDecimal(s21_big_decimal *big_result) {
  int sign = s21_GetSignBigDecimal(*big_result);
  if (sign) {
    s21_SetSignBigDecimal(big_result, 0);
  }
  s21_big_decimal cut = {};
  s21_CutBigDecimal(*big_result, &cut);

  s21_big_decimal fractional_part = {};
  s21_SubBigDecimal(*big_result, cut, &fractional_part);

  s21_big_decimal null_point_five = {{5, 0, 0, 0, 0, 0, 0, 1 << 16}};  // 0,5
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};                    // 1

  s21_ResetBigDecimal(big_result);
  if (s21_IsGreaterModuleBigDecimal(fractional_part, null_point_five) ||
      (s21_IsEqualBigDecimal(fractional_part, null_point_five) &&
       s21_GetBitBigDecimal(cut,
                            0))) {  // нечетное число всегда заканчивается 1
    s21_AddBitsBigDecimal(cut, one, big_result);
  } else {
    for (int i = 0; i < 3; i++) {
      big_result->bits[i] = cut.bits[i];
    }
  }
  big_result->bits[7] = cut.bits[7];
  s21_SetSignBigDecimal(big_result, sign);
}

/**
 * @brief Обрезает дробную часть big_decimal.
 *
 * @param value Число, которое нужно сократить.
 * @param result Указатель на результат сокращения.
 *
 * Функция делит число на 10 до тех пор, пока оно не останется без дробной
 * части или мантисса не будет помещаться в s21_decimal.
 */
void s21_CutBigDecimal(s21_big_decimal value, s21_big_decimal *result) {
  int exp = s21_GetExpBigDecimal(value) / (1 << 16);

  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_SetExpBigDecimal(&value, 0);

  int shift = -1;
  while (exp) {
    exp--;
    if (shift != -1) {
      s21_ResetBigDecimal(result);
    }
    shift = s21_GetShiftBigDecimal(value, ten);
    s21_DivBitsWithRemainderBigDecimal(&value, ten, shift, result);

    if (!result->bits[3] && !result->bits[4] && !result->bits[5] &&
        !result->bits[6] && !result->bits[7] && exp) {
      s21_SetExpBigDecimal(result, exp << 16);
      break;
    }

    for (int i = 0; i < 8; i++) {
      value.bits[i] = result->bits[i];
    }
  }
}

/**
 * @brief Обнуляет big_decimal.
 *
 * @param value Указатель на число.
 */
void s21_ResetBigDecimal(s21_big_decimal *value) {
  for (int i = 0; i < 8; i++) {
    value->bits[i] = 0;
  }
}

/**
 * @brief Получает код ошибки.
 *
 * @param big_result Результат арифметической операции.
 *
 * Функция проверяет, больше ли результат максимально возможного числа
 * типа s21_decimal. На основании проверки выдает код ошибки.
 *
 * @return 0 - OK;
 * 1 - число слишком велико или равно бесконечности;
 * 2 - число слишком мало или равно отрицательной бесконечности;
 * 3 - деление на 0.
 */
int s21_GetErrorCodeBigDecimal(s21_big_decimal *big_result) {
  int error = 0;
  // выходит за пределы 79228162514264337593543950335
  if (big_result->bits[3] || big_result->bits[4] || big_result->bits[5] ||
      big_result->bits[6]) {
    s21_big_decimal the_biggest_one = {{-1, -1, -1, 0, 0, 0, 0, 0}};
    int sign = s21_GetSignBigDecimal(*big_result);

    s21_NormalizeBigDecimal(big_result, &the_biggest_one);
    if (s21_IsGreaterModuleBigDecimal(*big_result, the_biggest_one) && !sign) {
      error = 1;
    } else if (s21_IsGreaterModuleBigDecimal(*big_result, the_biggest_one) &&
               sign) {
      error = 2;
    }
  }
  return error;
}

/**
 * @brief Получает результат.
 *
 * @param big_result Результат арифметической операции типа s21_big_decimal.
 * @param result Результат арифметической операции типа s21_decimal.
 *
 * Записывает результат типа s21_big_decimal в s21_decimal.
 */
void s21_GetResultFromBigDecimal(s21_big_decimal big_result,
                                 s21_decimal *result) {
  for (int i = 0; i < 3; i++) {
    result->bits[i] = big_result.bits[i];
  }
  result->bits[3] = big_result.bits[7];
}