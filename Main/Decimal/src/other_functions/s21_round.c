#include "../s21_decimal.h"

/**
 * @brief Округляет dcml до ближайшего целого числа.
 *
 * Если число равноудаленно от обоих целых - используется округление до
 * ближайшего чётного
 *
 * @return int 0 - OK 1 - ошибка вычисления
 *
 */
int s21_round(s21_decimal dcml, s21_decimal *result) {
  int code = 0;

  if (!result) {
    code = 1;
  } else if (!s21_IsCorrectDecimal(dcml)) {
    code = 1;
    *result = s21_GetIncorrectDecimal();
  } else {
    s21_ClearDecimal(result);
    int sign = s21_GetSign(dcml);
    s21_decimal fractional_part;
    s21_decimal dcml_unsigned = s21_Abs(dcml);
    s21_decimal dcml_unsigned_truncated;
    // Убирается дробная чать
    s21_truncate(dcml_unsigned, &dcml_unsigned_truncated);

    // Вычисляется дробная часть
    s21_sub(dcml_unsigned, dcml_unsigned_truncated, &fractional_part);
    // Производится округление, исходя из дробной части
    dcml_unsigned_truncated =
        s21_RoundHandle(dcml_unsigned_truncated, fractional_part);
    *result = dcml_unsigned_truncated;
    // Возвращается знак
    s21_SetSign(result, sign);
  }
  return code;
}
