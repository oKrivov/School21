#include "../s21_decimal.h"

int s21_is_less(s21_decimal dec, s21_decimal dec2) {
  int flag = 0;
  int is_negat = (dec.bits[3] & ((unsigned)1 << 31)) ? 1 : 0;
  int is_negat_2 = (dec2.bits[3] & ((unsigned)1 << 31)) ? 1 : 0;
  int scale = s21_GetScale(dec), scale_2 = s21_GetScale(dec2);
  if (s21_is_equal(dec, dec2) != 1) {
    if (dec.bits[3] == 0 && dec2.bits[3] == 0) {
      flag = s21_NoScaleIsCompar(dec, dec2);
      if (flag == -1) flag = 0;
    } else if (((scale == 0) && (scale_2 == 0)) &&
               ((is_negat == 1) && (is_negat_2 == 1))) {
      flag = s21_NoScaleIsCompar(dec, dec2);
      if (flag == 1)
        flag = 0;
      else
        flag = 1;
    } else if ((is_negat == 0) && (is_negat_2 == 1))
      flag = 0;
    else if ((is_negat == 1) && (is_negat_2 == 0))
      flag = 1;
    else if (scale != 0 || scale_2 != 0) {
      flag = s21_IsLessScale(dec, dec2, is_negat, is_negat_2);
    }
  }
  return flag;
}

int s21_IsLessScale(s21_decimal dec, s21_decimal dec_2, int is_negat,
                    int is_negat_2) {
  int flag = 0;
  if (s21_GetScale(dec) == s21_GetScale(dec_2)) {
    flag = s21_NoScaleIsCompar(dec, dec_2);
    if (flag == -1) flag = 0;
  } else if (s21_GetScale(dec) != s21_GetScale(dec_2)) {
    flag = s21_ComparWithScale(dec, dec_2);
  }
  if ((flag == 0) && (is_negat == 1) && (is_negat_2 == 1))
    flag = 1;
  else if ((flag == 1) && (is_negat == 1) && (is_negat_2 == 1))
    flag = 0;
  return flag;
}
