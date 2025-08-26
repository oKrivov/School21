#include "../s21_decimal.h"

s21_decimal s21_MaxValue() {
  s21_decimal result = {{0xFFFFFFFFU, 0xFFFFFFFFU, 0xFFFFFFFFU, 0x0}};
  return result;
}

int s21_IsZeroAdd(s21_decimal value) {
  return (value.bits[LOW] == 0 && value.bits[MIDDLE] == 0 &&
          value.bits[HIGH] == 0 && value.bits[SCALE_SIGN] == 0);
}

// Функция выполняет побитовое сравнение двух десятичных чисел.
// Сравнивает значения битов с самой высокой позиции до низкой и возвращает
// результат сравнения. Возвращает 1, если первое число больше, -1, если оно
// меньше, и 0, если числа равны.
int s21_Compare(s21_decimal a, s21_decimal b) {
  int result = 0;
  for (int i = HIGH; i >= LOW; i--) {
    if ((uint32_t)a.bits[i] != (uint32_t)b.bits[i]) {
      result = ((uint32_t)a.bits[i] > (uint32_t)b.bits[i]) ? 1 : -1;
      break;
    }
  }
  return result;
}

/**
 * @brief Делит число на 10 и уменьшает степень.
 *
 * @param dec Указатель на десятичное число.
 * @param left Остаток, который был получен при предыдущем делении.
 *
 * Функция делит число на 10, уменьшает значение каждого блока (bits[LOW],
 * bits[MIDDLE], bits[HIGH]) на 10 и округляет результат, если остаток ≥ 5.
 *
 * @return Остаток от последнего деления.
 */
int s21_DownscaleReal(s21_decimal *dec) {
  unsigned long tmp = 0UL;
  int skip = 1;
  for (int i = LOW; i <= HIGH; i++)
    if ((unsigned int)dec->bits[i] != UINT_MAX) skip = 0;
  if (!s21_IsZero(*dec))
    for (int n = HIGH; n >= LOW; n--) {
      unsigned *dword = (unsigned *)&dec->bits[n];
      tmp = tmp * 4294967296UL + *dword;
      *dword = tmp / 10;
      tmp = tmp % 10;
    }
  GET(dec, expo)--;
  unsigned long lqword =
      (unsigned long)dec->bits[LOW];  // сохраняем младший бит числа.
  if (!skip && ((tmp > 5) || (tmp == 5 && (!lqword || (lqword & 1)))))
    for (int i = LOW; i < HIGH; i++) {
      dec->bits[i] = (unsigned int)(dec->bits[i] + 1);
      if (dec->bits[i] != 0) break;
    }
  return (int)tmp;  // остаток от последнего деления на 10.
}

/**
 * @brief Уменьшает степень десятичного числа на 1.
 *
 * @param dec Указатель на десятичное число.
 *
 * Функция вызывает `s21_DownscaleReal`, чтобы уменьшить степень числа и вернуть
 * остаток от последнего деления.
 *
 * @return -1, если уменьшение невозможно, или остаток от деления.
 */
int s21_Downscale(s21_decimal *dec) {
  int ret;

  if (GET(dec, expo) == 0) {
    ret = -1;
  } else {
    ret = s21_DownscaleReal(dec);
  }

  return ret;
}

// Функция выравнивает масштабы двух десятичных чисел.
// Если масштабы чисел не совпадают, она корректирует их, увеличивая или
// уменьшая масштаб одного из чисел. Возвращает 1, если масштабы были
// одинаковыми, 0, если они были выровнены.
int s21_ScaleEqualize(s21_decimal *first, s21_decimal *second) {
  s21_decimal *big = NULL;
  s21_decimal *small = NULL;
  s21_decimal temp;
  s21_ClearDecimal(&temp);

  int out = 1;  // По умолчанию масштабы равны

  if (s21_GetScale(*first) != s21_GetScale(*second)) {
    if (s21_GetScale(*first) > s21_GetScale(*second)) {
      big = first;
      small = second;
    } else {
      big = second;
      small = first;
    }

    int scale_small = s21_GetScale(*small);
    int scale_big = s21_GetScale(*big);
    int newscale =
        scale_big - scale_small;  // на сколько нужно увеличить scale у small

    while (newscale) {
      s21_Copy(&temp, *small);      // Сохраняем копию small
      s21_ScaleIncrease(small, 1);  // Увеличиваем scale на 1

      if (!s21_GetBit(*small, 96)) {  // Проверяем переполнение
        s21_Copy(&temp, *small);
        scale_small++;
        newscale--;
      } else {
        s21_Copy(small, temp);  // Откатываем изменения, если переполнение
        break;
      }
    }

    int newscale2 =
        scale_big - scale_small;  // сколько раз надо уменьшить scale у big
    while (newscale2) {
      s21_Downscale(big);  // уменьшаем scale
      newscale2--;
    }

    out = 0;
  }

  return out;
}

int s21_SumOverflow(s21_decimal a, s21_decimal b) {
  return s21_GetSign(a) ==
             s21_GetSign(b) &&  // Если оба числа имеют одинаковый знак (
         s21_is_equal(a, s21_MaxValue()) &&
         !s21_IsZeroAdd(b);
}

// Увеличивает показатель степени на заданное значение
// value: указатель на десятичное число
// shift: приращение степени
void s21_ScaleIncrease(s21_decimal *value,
                       int shift)  // shift — на сколько позиций увеличить scale
{
  if ((s21_GetScale(*value) + shift) <= MAX_SCALE) {
    s21_SetScale(value, (s21_GetScale(*value) + shift));
    if (s21_MulByTen(value))  // фактическое умножение value на 10
    {
      s21_SetBit(value, 96, 1);
    }
  }
}

unsigned int s21_MulByTen(s21_decimal *dec) {
  unsigned long long carry = 0;
  for (int i = 0; i < 3; i++) {
    unsigned long long sum =
        10ULL * (unsigned long long)(uint32_t)dec->bits[i] + carry;
    dec->bits[i] = (unsigned int)sum;
    carry = sum >> 32;
  }
  return (unsigned int)carry;
}

// Копирует десятичное число (число, степень и знак)
void s21_Copy(s21_decimal *dst, s21_decimal src) {
  for (int i = LOW; i <= SCALE_SIGN; ++i) {
    dst->bits[i] = src.bits[i];
  }
}

// Вычисляет сумму десятичных чисел
// value_1: первое слагаемое
// value_2: второе слагаемое
// result: указатель для записи суммы
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = ERROR_OK;
  if (!result) {
    ret = 1;
  } else if (!s21_IsValidDecimal(value_1) || !s21_IsValidDecimal(value_2)) {
    ret = 1;
  } else if (s21_SumOverflow(value_1, value_2)) {
    ret = ERROR_BIG;
  } else if (s21_IsZeroAdd(value_2)) {
    s21_Copy(result, value_1);
    ret = ERROR_OK;
  } else {
    int sign_2 = s21_GetSign(value_2);
    s21_ScaleEqualize(&value_1, &value_2);  // Выравниваем scale у обоих чисел
    s21_SetSign(&value_2, sign_2);
    int sign_1 = s21_GetSign(value_1);
    *result = (s21_decimal){{0, 0, 0, 0}};
    unsigned long long carry = 0;
    if (sign_1 == sign_2) {
      for (int i = LOW; i < SCALE_SIGN; i++) {
        unsigned *dword1 = (unsigned *)&value_1.bits[i];
        const unsigned *dword2 = (unsigned *)&value_2.bits[i];
        unsigned *dword = (unsigned *)&result->bits[i];
        unsigned long long sum = (unsigned long long)*dword1 + *dword2 + carry;
        *dword = (unsigned int)sum;
        carry = sum >> 32;  // carry хранит перенос на следующий разряд.
      }
      if (carry) {
        ret = sign_1 ? ERROR_SMALL : ERROR_BIG;
      }
    } else {  // разные знаки
      if (s21_Compare(value_1, value_2) < 0) {
        s21_decimal temp = value_1;  // первым должно быть большее число
        value_1 = value_2;
        value_2 = temp;
        sign_1 = !sign_1;
      }
      for (int i = LOW; i < SCALE_SIGN; i++) {
        uint32_t val1 = (uint32_t)value_1.bits[i];
        uint32_t val2 = (uint32_t)value_2.bits[i] + carry;
        result->bits[i] = (uint32_t)(val1 - val2);
        carry = (val1 < val2) ? 1 : 0;
      }
    }
    if (!s21_IsValidDecimal(*result)) ret = 1;
    s21_SetSign(result, sign_1);
    s21_SetScale(result, s21_GetScale(value_1));
  }
  return ret;
}
