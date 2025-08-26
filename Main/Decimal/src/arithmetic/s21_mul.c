#include "../s21_decimal.h"

int s21_DownscaleRealMul(s21_decimal *dec, unsigned left) {
  unsigned long tmp = 0UL + left;
  if (!s21_IsZero(*dec) || left)
    for (int n = HIGH; n >= LOW; n--) {
      unsigned *dword = (unsigned *)&dec->bits[n];
      tmp = tmp * (UINT_MAX + 1UL) + *dword;
      *dword = (unsigned int)(tmp / 10);
      tmp = tmp % 10;
    }
  GET(dec, expo)--;
  return (int)tmp;
}

int s21_DownscaleMul(s21_decimal *dec) {
  return GET(dec, expo) == 0 ? -1 : s21_DownscaleRealMul(dec, 0);
}

// умножение двух s21_decimal, используя разрядное умножение, подобное умножению
// матриц.
int s21_DoubleSizeMul(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result, s21_decimal *leftovers) {
  int ret = 0;
  /* перемножаем все элементы мантисс множителей, как с матрицей */
  for (int i = LOW; i <= HIGH && !ret; i++) {
    /* переменная для переполнения элементов при умножении */
    unsigned long carry = 0;
    short lo_index = 0;
    unsigned *dword1 = (unsigned *)&value_1.bits[i];
    for (int j = LOW; j < SCALE_SIGN; j++) {
      unsigned *dword2 = (unsigned *)&value_2.bits[j];
      /* перемножаем биты мантиссы */  // получаем 64-битное unsigned long r
      unsigned long r = (unsigned long)*dword1 * (unsigned long)*dword2;
      /* добавляем остатки с прошлого круга */
      r += carry;
      /* переносим старшие биты в остатки на следующий круг */
      carry = r >> 32;
      /* обрезаем старшие биты */
      r &= UINT_MAX;
      /* заполняем элементы мантиссы результата с переносом переполнения в
       * старший элемент, если есть*/
      if (j + i <= HIGH) {
        unsigned *dword = (unsigned *)&result->bits[j + i];
        r += *dword, *dword = (unsigned)r;
      }
      /* если нет, то добавляем в децимал остатков */
      else {
        const unsigned *ldword = (unsigned *)&leftovers->bits[lo_index];
        unsigned *hdword = (unsigned *)&leftovers->bits[lo_index++];
        r += *ldword, *hdword = (unsigned)r;
      }
      /* добавляем в остатки на следующий круг добавившееся переполнение -
       * старшие биты*/
      carry += r >> 32;
      /* после перемножения последнего элемента второго множителя остатки уже
       * идут в децимал переполнения*/
      if (carry && j == HIGH) {
        /* чтобы попасть в нужный элемент мантиссы переполнения создаем
         * временный децимал*/
        s21_decimal tmp_dec = {{0}};
        tmp_dec.bits[i] = (unsigned)carry;
        /* если переполнится переполнения, то никакой экспоненты не хватит,
         * можно дальше не играть*/
        ret += s21_Madd(*leftovers, tmp_dec, leftovers);
      }
    }
  }
  return ret;
}

// выполняет нормализацию числа, понижая экспоненту
int s21_MergeDev(s21_decimal *dec, s21_decimal leftovers, int *left) {
  int ret = 0;
  while (!s21_IsZero(leftovers) && !ret) {
    /* если экспонента результата уже 0 то переполнение добавлять некуда, у
     * нас ошибка переполнения*/
    ret += (GET(dec, expo) == 0);
    if (!ret) {
      /*уменьшаем экспоненту переполнения поделив на 10*/
      *left = s21_DownscaleRealMul(&leftovers, 0);
      /* уменьшаем экспоненту результата делением на 10 и добавляем остатки от
       * деления переполнения в старший элемент результата */
      *left = s21_DownscaleRealMul(dec, *left);
    }
  }
  /*Нормализуем экспоненту*/
  while (GET(dec, expo) > MAX_SCALE) *left = s21_DownscaleMul(dec);
  return ret;
}

/**
 * @brief Выполняет сложение двух беззнаковых 96-битных чисел.
 *
 * @param val1 Первое число.
 * @param val2 Второе число.
 * @param result Указатель на результат сложения.
 *
 * Функция выполняет сложение трех блоков чисел (LOW, MIDDLE, HIGH) и учитывает
 * возможные переполнения.
 *
 * @return 0, если операция выполнена успешно, 1 — если произошло переполнение.
 */
int s21_Madd(s21_decimal val1, s21_decimal val2, s21_decimal *result) {
  int ret = 0;

  unsigned *ldword = (unsigned *)&result->bits[LOW];
  const unsigned *ldword1 = (const unsigned *)&val1.bits[LOW];
  const unsigned *ldword2 = (const unsigned *)&val2.bits[LOW];

  unsigned *mdword = (unsigned *)&result->bits[MIDDLE];
  unsigned *mdword1 = (unsigned *)&val1.bits[MIDDLE];
  const unsigned *mdword2 = (const unsigned *)&val2.bits[MIDDLE];

  unsigned *hdword = (unsigned *)&result->bits[HIGH];
  unsigned *hdword1 = (unsigned *)&val1.bits[HIGH];
  const unsigned *hdword2 = (const unsigned *)&val2.bits[HIGH];

  *ldword = *ldword1 + *ldword2;
  if (*ldword < *ldword2 || *ldword < *ldword1) {  // Складываем младшие 32 бита
    (*mdword1)++;  // Обнаруживаем переполнение младших бит
    if (*mdword1 == 0) {
      (*hdword1)++;
      if (*hdword1 == 0) ret = 1;
    }
  }
  *mdword = *mdword1 + *mdword2;  // Складываем средние 32 бита
  if (*mdword < *mdword2 || *mdword < *mdword1) {
    (*hdword1)++;
    if (*hdword1 == 0) ret = 1;
  }
  *hdword = *hdword1 + *hdword2;
  if (*hdword < *hdword2 || *hdword < *hdword1) ret = 1;
  return ret;
}

int s21_Msub(s21_decimal val1, s21_decimal val2, s21_decimal *result) {
  int ret = 0;

  unsigned *ldword = (unsigned *)&result->bits[LOW];
  const unsigned *ldword1 = (const unsigned *)&val1.bits[LOW];
  const unsigned *ldword2 = (const unsigned *)&val2.bits[LOW];

  unsigned *mdword = (unsigned *)&result->bits[MIDDLE];
  unsigned *mdword1 = (unsigned *)&val1.bits[MIDDLE];
  const unsigned *mdword2 = (const unsigned *)&val2.bits[MIDDLE];

  unsigned *hdword = (unsigned *)&result->bits[HIGH];
  unsigned *hdword1 = (unsigned *)&val1.bits[HIGH];
  const unsigned *hdword2 = (const unsigned *)&val2.bits[HIGH];

  // Начинаем вычитание с младшего разряда
  *ldword = *ldword1 - *ldword2;

  if (*ldword1 < *ldword2) {  // Проверяем, произошло ли заимствование
    (*mdword1)--;
    if (*mdword1 == UINT_MAX) {
      (*hdword1)--;
      if (*hdword1 == UINT_MAX) {
        ret = 1;  // Переполнение
      }
    }
  }

  *mdword = *mdword1 - *mdword2;
  if (*mdword1 < *mdword2) {  // Проверяем, произошло ли заимствование
    (*hdword1)--;
    if (*hdword1 == UINT_MAX) {
      ret = 1;  // Переполнение
    }
  }

  *hdword = *hdword1 - *hdword2;
  if (*hdword1 < *hdword2) {  // Если старший разряд тоже требует заимствования
    ret = 1;
  }

  return ret;
}

// Умножает 2 десятичных числа
// value_1: первый множитель
// value_2: второй множитель
// result: указатель для записи произведения
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = 0;
  if (!s21_IsValidDecimal(value_1) || !s21_IsValidDecimal(value_2) || !result) {
    ret = 1;
  } else {
    s21_ClearDecimal(result);
    if (!s21_IsZero(value_1) && !s21_IsZero(value_2)) {
      s21_decimal leftovers = {{0U}};
      GET(result, expo) = s21_GetScale(value_1) +
                          s21_GetScale(value_2);  // Экспонента суммируется
      GET(result, sign) = s21_GetSign(value_1) ^ s21_GetSign(value_2);
      ret = s21_DoubleSizeMul(value_1, value_2, result, &leftovers);
      unsigned carry = 0;
      ret += s21_MergeDev(result, leftovers, (int *)&carry);
      if (!ret) ret += s21_BankRound(result, carry);
      if (ret) ret = GET(result, sign) + 1;
    }
  }
  return ret;
}
