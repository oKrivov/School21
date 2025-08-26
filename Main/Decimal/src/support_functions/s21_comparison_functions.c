#include "../s21_decimal.h"

int s21_NoScaleIsCompar(s21_decimal dec, s21_decimal dec_2) {
  int flag = -1;
  int cnt_dig = s21_GetFirstBitPositionWithSlot(dec);
  int cnt_dig_2 = s21_GetFirstBitPositionWithSlot(dec_2);

  if (cnt_dig > cnt_dig_2)
    flag = 0;
  else if (cnt_dig < cnt_dig_2)
    flag = 1;
  else
    flag = s21_NoScaleIsComparSameSize(dec, dec_2);

  return flag;
}

int s21_NoScaleIsComparSameSize(s21_decimal dec, s21_decimal dec_2) {
  int bit = 0, bit_2 = 0;
  int flag = -1;
  for (int i = 2; i >= 0; i--) {
    for (int j = 31; (j >= 0) && (flag == -1); j--) {
      bit = (dec.bits[i] & ((unsigned)1 << j)) ? 1 : 0;
      bit_2 = (dec_2.bits[i] & ((unsigned)1 << j)) ? 1 : 0;
      if ((bit == 1) && (bit_2 == 0))
        flag = 0;
      else if ((bit == 0) && (bit_2 == 1))
        flag = 1;
    }
  }
  return flag;
}

int s21_ComparWithScale(s21_decimal dec, s21_decimal dec_2) {
  s21_ScaleEqualize(&dec, &dec_2);
  return s21_NoScaleIsCompar(dec, dec_2);
}

int s21_GetFirstBitPositionWithSlot(s21_decimal dec) {
  int bit = -1;
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
