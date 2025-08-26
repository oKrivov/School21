#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int flag = 0;
  int first_digit = s21_GetFirstBitPosition(src);
  int por = 96;
  int bit = 0;
  int scale = s21_GetScale(src);
  *dst = 0;

  if ((scale >= 0) && (scale <= 28) && (s21_CheckTheThirdElem(src) == 0)) {
    for (int i = 2; i >= 0; i--) {
      for (int j = 31; j >= 0; j--) {
        if (por == first_digit) {
          bit = (src.bits[i] & ((unsigned)1 << j)) ? 1 : 0;
          *dst += bit * pow(2, first_digit - 1);
          first_digit--;
        }
        por--;
      }
    }
    bit = (src.bits[3] & ((unsigned)1 << 31)) ? 1 : 0;
    if (bit) *dst *= -1;
    *dst = *dst / pow(10, scale);
  } else
    flag = 1;

  return flag;
}

int s21_GetFirstBitPosition(s21_decimal dec) {
  int bit = 0;
  int first_digit = -1;
  int bit_pos = 96;
  for (int i = 2; i >= 0; i--) {
    for (int j = 31; j >= 0; j--) {
      bit = (dec.bits[i] & ((unsigned)1 << j)) ? 1 : 0;
      if ((first_digit == -1) && (bit)) first_digit = bit_pos;
      bit_pos--;
    }
  }
  return first_digit;
}

/**
 * @brief Проверяет 3 элемент децимала, есть ли биты с 0 до 15 и с 24 до 30
 *
 * @return 1 - есть ошибка, 0 - ошибки нет
 */
int s21_CheckTheThirdElem(s21_decimal dec) {
  int flag = 0;
  int bit = 0;

  for (int i = 30; (i >= 24) && (flag == 0); i--) {
    bit = (dec.bits[3] & (1 << i)) ? 1 : 0;
    if (bit) flag = 1;
  }

  for (int i = 15; (i >= 0) && (flag == 0); i--) {
    bit = (dec.bits[3] & (1 << i)) ? 1 : 0;
    if (bit) flag = 1;
  }

  return flag;
}
