#include "../s21_decimal.h"

int s21_is_not_equal(s21_decimal dec, s21_decimal dec_2) {
  int flag = 0;
  if (!(s21_IsZero(dec) && s21_IsZero(dec_2))) {
    for (int i = 0; i <= 3; i++)
      if (dec.bits[i] != dec_2.bits[i]) flag = 1;
  }
  return flag;
}