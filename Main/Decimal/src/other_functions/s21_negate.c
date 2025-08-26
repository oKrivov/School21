#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int status = 0;

  if (!result || !s21_IsValidDecimal(value)) {
    status = 1;
  } else {
    *result = value;  // Копируем значение

    if (s21_IsZero(value)) {
      result->bits[3] &= ~(1U << 31);  // Делаем 0 положительным
    } else {
      result->bits[3] ^= (1U << 31);  // Инвертируем знак
    }
  }

  return status;
}
