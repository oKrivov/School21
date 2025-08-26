#include "../s21_decimal.h"

int s21_GetBit(s21_decimal decl, int index) {
  int num_int =
      index / 32;  // Вычисляем, в каком числе (из массива bits) находится бит
  int num_bit = index % 32;  // Определяем позицию бита внутри 32-битного числа
  return ((unsigned)decl.bits[num_int] & (1U << num_bit)) >> num_bit;
}

void s21_SetBit(s21_decimal *decl, int index, int bit) {
  int num_int = index / 32;
  int num_bit = index % 32;
  if (bit == 1) {
    decl->bits[num_int] |= (1u << num_bit);  // Устанавливаем бит в 1
  } else {
    decl->bits[num_int] &= (~((1u) << num_bit));  // Сбрасываем бит в 0
  }
}

int s21_BankRound(
    s21_decimal *dec,
    int digit) {  // digit – остаток от деления на 10 при уменьшении экспоненты
  int ret = 0;    // код ошибки

  if (abs(digit) > 5 || (abs(digit) == 5 && GET_BIT(dec, 0))) {
    if (digit < 0) {  // округление вниз
      s21_Msub(*dec, (s21_decimal){{1U, 0U, 0U, 0U}}, dec);
    } else {  // округление вверх
      if (s21_Madd(*dec, (s21_decimal){{1U, 0U, 0U, 0U}}, dec)) {
        *dec = (s21_decimal){{0, 0, 0, dec->bits[3]}};

        if (GET(dec, expo) > 0) {
          s21_DownscaleRealMul(dec, 1);
          s21_Madd(*dec, (s21_decimal){{1, 0, 0, 0}}, dec);
        }
        ret = GET(dec, sign) + 1;
      }
    }
  }

  return ret;
}

int s21_GetSign(s21_decimal d) {
  return ((unsigned)d.bits[SCALE_SIGN] >> 31) & 0x1;
}

void s21_SetSign(s21_decimal *result, int sign) {
  if (sign) {
    result->bits[SCALE_SIGN] |= (1U << 31);
  } else {
    result->bits[SCALE_SIGN] &= ~(1U << 31);
  }
}

// Выводит значение в 16-ричном виде 4 блоками:
void s21_PrintDecimal(s21_decimal value) {
  printf("%8X %8X %8X %8X\n", value.bits[HIGH], value.bits[MIDDLE],
         value.bits[LOW], value.bits[SCALE_SIGN]);
}

int s21_GetScale(s21_decimal d) {
  return ((unsigned)d.bits[SCALE_SIGN] >> 16) & 0xFF;
}

// изменяет степень десятичного числа (scale), сохраняя при этом знак числа.
void s21_SetScale(s21_decimal *num, int scale) {
  num->bits[SCALE_SIGN] =
      (scale << 16) + ((unsigned)num->bits[SCALE_SIGN] & 0xFF000000);
}

// Обнуляет/очищает значение по указателю
void s21_ClearDecimal(s21_decimal *dcml) {
  for (int i = 0; i < 4; i++) {
    dcml->bits[i] = 0;
  }
}

int s21_IsValidDecimal(s21_decimal value) {
  int ret = 1;
  int scale = s21_GetScale(value);

  if (scale < 0 || scale > MAX_SCALE) {
    ret = 0;
  } else if (((unsigned)value.bits[SCALE_SIGN] >> 16) & 0x7F00) {
    ret = 0;
  } else if ((unsigned)value.bits[SCALE_SIGN] & 0xFF) {
    ret = 0;
  }

  return ret;
}
/**
 * @brief Сравнивает два десятичных числа.
 *
 * @param a Первое число.
 * @param b Второе число.
 *
 * Функция проверяет, равны ли два десятичных числа.
 *
 * @return 1, если числа равны, 0 — если нет.
 */

int s21_IsZero(s21_decimal value) {
  return ((unsigned)value.bits[LOW] == 0 && (unsigned)value.bits[MIDDLE] == 0 &&
          (unsigned)value.bits[HIGH] == 0);
}

/**
 * @brief Делает банковское округление
 *
 * @param integer_part целая часть
 * @param fractional_part дробная часть
 *
 */
s21_decimal s21_RoundHandle(s21_decimal integer_part,
                            s21_decimal fractional_part) {
  s21_decimal result;
  s21_decimal dcml_one = {{1, 0, 0, 0}};
  s21_decimal dcml_zero_point_five = {{5, 0, 0, 65536}};
  // Если дробная часть (fractional_part) < 0.5
  if (s21_is_less(fractional_part, dcml_zero_point_five)) {
    result = integer_part;
  } else {
    // Если дробная часть (fractional_part) >= 0.5, то увеличиваем целую часть
    // на 1
    s21_add(integer_part, dcml_one, &result);
  }

  return result;
}

/**
 *  @brief Функция возвращает некорректный decimal каждый бит которого заполнен
 * "1", кроме старшего бита, который "0"
 *
 * @return s21_decimal Некорректный decimal
 */
s21_decimal s21_GetIncorrectDecimal(void) {
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF}};

  return result;
}

/*
 * @brief Модуль числа
 *
 *  @return s21_decimal
 */
s21_decimal s21_Abs(s21_decimal dcml) {
  s21_decimal result = dcml;
  s21_SetSign(&result, 0);
  return result;
}
