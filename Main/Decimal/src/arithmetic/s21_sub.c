#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_code = -1;

  if (result == NULL) {
    return error_code;
  }

  result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;

  s21_big_decimal big_value_1 = {{value_1.bits[0], value_1.bits[1],
                                  value_1.bits[2], 0, 0, 0, 0,
                                  value_1.bits[3]}};
  s21_big_decimal big_value_2 = {{value_2.bits[0], value_2.bits[1],
                                  value_2.bits[2], 0, 0, 0, 0,
                                  value_2.bits[3]}};
  s21_big_decimal big_result = {};

  error_code = s21_SubBigDecimal(big_value_1, big_value_2, &big_result);

  if (!error_code) {
    if (big_result.bits[3] || big_result.bits[4] || big_result.bits[5] ||
        big_result.bits[6]) {
      s21_BankRoundBigDecimal(&big_result);
    }

    s21_GetResultFromBigDecimal(big_result, result);
  }

  return error_code;
}