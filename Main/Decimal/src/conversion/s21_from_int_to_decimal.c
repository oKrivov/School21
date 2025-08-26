#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL) {
    return 1;
  }

  for (int i = 1; i < 4; i++) {
    dst->bits[i] = 0;
  }

  if (src < 0) {
    if (src != INT_MIN) {
      src = ~src;
      src++;
    }

    dst->bits[3] = MAX_LEFT_SHIFT;
  }

  dst->bits[0] = src;

  return 0;
}