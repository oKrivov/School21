#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int code = ERROR_OK;
  if (!dst) {
    code = ERROR_CONVERT;  // Проверка на NULL
  } else {
    s21_ClearDecimal(dst);   // Обнуляем decimal
    float absf = fabs(src);  // Работаем с модулем числа
    // Проверяем на NaN, Infinity, слишком большие и слишком маленькие значения
    if (isnan(src) || isinf(src) || absf >= (float)MAX_DECIMAL ||
        (absf < MIN_DECIMAL && src != 0.0f)) {
      code = ERROR_CONVERT;
    } else {
      char buffer[64];
      snprintf(
          buffer, sizeof(buffer), "%.7g",
          absf);  // форматирует float в строку с 7 значащими цифрами (%.7g).
      long double value = strtold(buffer, NULL);  // Переводим в long double
      int scale = 0;
      while (fmod(value, 1.0) != 0.0 && scale < 28) {
        value *= 10;
        scale++;
      }
      if (scale > MAX_SCALE) {
        code = ERROR_CONVERT;  // Ошибка, если scale слишком большой
      } else {
        uint64_t low =
            (uint64_t)fmod(value, UINT64_MAX + 1.0);  // младшие 64 бита
        uint32_t high =
            (uint32_t)(value / (UINT64_MAX + 1.0));  // Старшие 32 бита
        if (high > 0xFFFFFFFF) {
          code = ERROR_CONVERT;
        } else {
          dst->bits[LOW] = (uint32_t)(low & 0xFFFFFFFF);  // Младшие 32 бита
          dst->bits[MIDDLE] =
              (uint32_t)((low >> 32) & 0xFFFFFFFF);  // Средние 32 бита
          dst->bits[HIGH] = high;
          s21_SetScale(dst, scale);
          if (!(dst->bits[LOW] == 0 && dst->bits[MIDDLE] == 0 &&
                dst->bits[HIGH] == 0)) {
            int sign = signbit(src);  // Определяем знак числа
            s21_SetSign(dst, sign);
          }
        }
      }
    }
  }
  return code;
}
