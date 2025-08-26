#include "../s21_decimal.h"

/**
 * @brief Округляет value до ближайшего целого числа в сторону отрицательной
 * бесконечности.
 *
 * @param dcml округляемое число
 * @param result указатель, куда будет записан результат
 * @return int 0 - OK  1 - ошибка вычисления
 */
int s21_floor(s21_decimal dcml, s21_decimal *result) {
  int code = 0;
  s21_decimal dcml_one = {{1, 0, 0, 0}};
  s21_decimal dcml_zero = {{0, 0, 0, 0}};
  // Если указатель на decimal является NULL
  if (!result) {
    code = 1;
    // Проверяем, что value является корректными decimal
  } else if (!s21_IsCorrectDecimal(dcml)) {
    code = 1;
    *result = s21_GetIncorrectDecimal();
  } else {
    s21_ClearDecimal(result);
    int sign = s21_GetSign(dcml);
    s21_decimal fractional_part;
    s21_decimal dcml_unsigned = s21_Abs(dcml);
    s21_decimal dcml_unsigned_truncated;

    s21_truncate(dcml_unsigned, &dcml_unsigned_truncated);
    s21_sub(dcml_unsigned, dcml_unsigned_truncated, &fractional_part);
    // Если дробная часть была больше нуля и число было отрицательным, то
    // прибавляем 1
    if (sign == 1 && s21_is_greater(fractional_part, dcml_zero)) {
      s21_add(dcml_unsigned_truncated, dcml_one, &dcml_unsigned_truncated);
    }

    *result = dcml_unsigned_truncated;
    s21_SetSign(result, sign);
  }

  return code;
}
