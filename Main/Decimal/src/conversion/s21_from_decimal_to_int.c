#include "../s21_decimal.h"

/**
 * @brief  Конвертирует dcml в int
 *
 * @param dcml конвертируемый decimal
 * @param *dst указатель, куда будет записан результат
 * @return int 0 - OK, 1 - Conversion Error
 */
int s21_from_decimal_to_int(s21_decimal dcml, int *dst) {
  int code = 0;
  s21_decimal max_int = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  s21_decimal min_int = {{0x80000000, 0x0, 0x0, 0x80000000}};

  if (!dst) {
    code = 1;
  } else if (!s21_IsCorrectDecimal(dcml)) {
    code = 1;
    *dst = 0;
  } else {
    *dst = 0;
    s21_decimal truncated_dcml = {};
    s21_truncate(dcml, &truncated_dcml);

    if (s21_is_less(truncated_dcml, min_int) == 1) {
      code = 1;
    } else if (s21_is_greater(truncated_dcml, max_int) == 1) {
      code = 1;
    } else {
      *dst = truncated_dcml.bits[0];
    }

    if (s21_GetSign(dcml) == 1) {
      *dst = -*dst;
    }
  }

  return code;
}
