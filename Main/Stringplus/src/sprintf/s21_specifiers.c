#include "s21_sprintf.h"

// char *str - то, куда будет заносится отформатированные аргументы
// for_print - в зависимости от функции будет иметь разный тип данных, содержит
// аргументы для форматирования
/**
 * @brief Спецификатор для %c.
 *
 * @param str Указатель на строку, куда будет записан результат.
 * @param parameters Указатель на структуру с параметрами форматирования.
 * @param for_print Символ типа `char`, который нужно отформатировать.
 *
 * Функция форматирует символ в строку `str` на основе параметров `parametrs`.
 */
void s21_SpecifierChar(char **str, const Parametrs *parameters, int for_print) {
  int len = parameters->width > 1 ? parameters->width : 1;

  s21_memset(*str, ' ', len);

  if (parameters->flag.minus) {
    (*str)[0] = (unsigned char)for_print;
  } else {
    (*str)[len - 1] = (unsigned char)for_print;
  }
  *str += len;
}
/**
 * @brief Спецификатор для %d и %i.
 *
 * @param str Указатель на строку, куда будет записан результат.
 * @param parameters Указатель на структуру с параметрами форматирования.
 * @param for_print Целое число типа `long long`, которое нужно отформатировать.
 *
 * Функция форматирует целое число в строку `str` на основе параметров
 * `parametrs`. Использовать с неявным кастом в `long long`.
 */
void s21_SpecifierDigit(char **str, const Parametrs *parameters,
                        long long for_print) {
  int digit_length = GetIntLength(for_print, 10);
  int sign =
      for_print < 0 || parameters->flag.plus || parameters->flag.space ? 1 : 0;
  int len = parameters->width > digit_length + sign ? parameters->width
                                                    : digit_length + sign;
  if (parameters->precision > 0) {
    if (parameters->width < parameters->precision &&
        digit_length + sign < parameters->precision) {
      len = parameters->precision;
    }
    if (parameters->precision > digit_length + sign) {
      digit_length = parameters->precision;
    }
  }
  if (parameters->flag.null)
    s21_memset(*str, '0', len);
  else
    s21_memset(*str, ' ', len);
  long long digit = for_print;
  int index = parameters->flag.minus ? digit_length + sign - 1 : len - 1;
  for (int i = 0; i < digit_length; i++) {
    char c = abs((int)(digit % 10)) + '0';
    (*str)[index--] = c;
    digit /= 10;
  }
  if (for_print < 0)
    if (parameters->flag.null)
      (*str)[0] = '-';
    else
      (*str)[index--] = '-';
  else if (parameters->flag.plus)
    (*str)[index--] = '+';
  else if (parameters->flag.space)
    (*str)[index--] = ' ';
  *str += len;
}

/**
 * @brief Спецификатор для %f.
 *
 * @param str Указатель на строку, куда будет записан результат.
 * @param parameters Указатель на структуру с параметрами форматирования.
 * @param for_print Число с плавающей точкой типа `long double`, которое
 * нужно отформатировать.
 *
 * Функция форматирует число с плавающей точкой в строку `str` на основе
 * параметров `parametrs`. Использовать с неявным кастом в `long double`.
 */
void s21_SpecifierFloat(char **str, const Parametrs *parameters,
                        long double for_print) {
  int sign = for_print < 0.0L || parameters->flag.plus || parameters->flag.space
                 ? 1
                 : 0;
  int precision = parameters->precision >= 0 ? parameters->precision : 6;
  long double rounded_num = Round(for_print, precision);
  char temp[1000];
  LongDoubleToString(temp, fabsl(rounded_num), precision,
                     parameters->flag.hash);
  int float_length = s21_strlen(temp);
  int len = parameters->width > float_length + sign ? parameters->width
                                                    : float_length + sign;
  if (parameters->flag.null)
    s21_memset(*str, '0', len);
  else
    s21_memset(*str, ' ', len);
  int index = parameters->flag.minus ? 0 : len - float_length - sign;
  if (for_print < 0.0L)
    (*str)[index++] = '-';
  else if (parameters->flag.plus)
    (*str)[index++] = '+';
  else if (parameters->flag.space)
    (*str)[index++] = ' ';
  for (int i = 0; i < float_length; i++) (*str)[index++] = temp[i];
  *str += len;
}
/**
 * @brief Спецификатор для %s.
 *
 * @param str Указатель на строку, куда будет записан результат.
 * @param parameters Указатель на структуру с параметрами форматирования.
 * @param for_print Массив символов типа `char*`, который нужно
 * отформатировать.
 *
 * Функция форматирует массив символов в строку `str` на основе параметров
 * `parametrs`.
 */
void s21_SpecifierString(char **str, const Parametrs *parameters,
                         char *for_print) {
  int str_length = s21_strlen(for_print);
  if (parameters->precision < str_length && parameters->precision != -1) {
    str_length = parameters->precision;
  }
  int len = parameters->width > str_length ? parameters->width : str_length;

  s21_memset(*str, ' ', len);

  int index = parameters->flag.minus ? 0 : len - str_length;
  for (int i = 0; i < str_length; i++) {
    (*str)[index++] = for_print[i];
  }
  *str += len;
}
/**
 * @brief Спецификатор для %u.
 *
 * @param str Указатель на строку, куда будет записан результат.
 * @param parameters Указатель на структуру с параметрами форматирования.
 * @param for_print Беззнаковое целое число типа `unsigned long long`, которое
 * нужно отформатировать.
 *
 * Функция форматирует беззнаковое целове число в строку `str` на основе
 * параметров `parametrs`. Использовать с неявным кастом в `unsigned long
 * long`.
 */
void s21_SpecifierUnsigned(char **str, const Parametrs *parameters,
                           unsigned long long for_print) {
  int digit_length = GetUnsingedIntLength(for_print, 10);
  int len = parameters->width > digit_length ? parameters->width : digit_length;

  if (parameters->precision > 0) {
    if (parameters->width < parameters->precision &&
        digit_length < parameters->precision) {
      len = parameters->precision;
    }
    if (parameters->precision > digit_length) {
      digit_length = parameters->precision;
    }
  }

  if (parameters->flag.null) {
    s21_memset(*str, '0', len);
  } else {
    s21_memset(*str, ' ', len);
  }

  int index = parameters->flag.minus ? digit_length - 1 : len - 1;
  for (int i = 0; i < digit_length; i++) {
    char c = for_print % 10 + '0';
    (*str)[index--] = c;
    for_print /= 10;
  }
  *str += len;
}

/**
 * @brief Спецификатор для %e и %E, символ берется из parameters->specifier.
 *
 * @param str Указатель на строку, куда будет записан результат.
 * @param parameters Указатель на структуру с параметрами форматирования.
 * @param for_print Число с плавающей точкой типа `long double`, которое нужно
 * отформатировать.
 *
 * Функция форматирует беззнаковое целове число в строку `str` на основе
 * параметров `parametrs`. Использовать с неявным кастом в `long double`.
 */
void s21_SpecifierExponent(char **str, const Parametrs *parameters,
                           long double for_print) {
  int sign = for_print < 0.0L || parameters->flag.plus || parameters->flag.space
                 ? 1
                 : 0;
  int precision = parameters->precision >= 0 ? parameters->precision : 6;
  long double value = fabsl(for_print);
  int exp = GetExponent(for_print);
  value = exp < 0 ? value * powl(10, abs(exp)) : value / powl(10, exp);
  double rounded_value = Round(value, precision);
  int exp_len = GetIntLength(exp, 10) <= 2 ? 2 : GetIntLength(exp, 10);
  int value_len = precision + sign + exp_len +
                  (precision != 0 || parameters->flag.hash ? 4 : 3);
  int len = parameters->width > value_len ? parameters->width : value_len;
  if (parameters->flag.null)
    s21_memset(*str, '0', len);
  else
    s21_memset(*str, ' ', len);
  int index = parameters->flag.minus ? 0 : len - value_len;
  if (for_print < 0.0L)
    (*str)[index++] = '-';
  else if (parameters->flag.plus)
    (*str)[index++] = '+';
  else if (parameters->flag.space)
    (*str)[index++] = ' ';
  (*str)[index++] = '0' + (int)rounded_value;
  rounded_value -= (int)rounded_value;
  if (precision > 0 || parameters->flag.hash) (*str)[index++] = '.';
  long double eps = 0.5L / powl(10, precision);
  rounded_value += eps;
  for (int i = 0; i < precision; i++) {
    rounded_value *= 10.0L;
    (*str)[index++] = '0' + (int)rounded_value;
    rounded_value -= (int)rounded_value;
  }
  (*str)[index++] = parameters->specifier;
  if (exp < 0)
    (*str)[index] = '-';
  else
    (*str)[index] = '+';
  index += exp_len;
  for (int i = 0; i < exp_len; i++) {
    (*str)[index--] = '0' + abs(exp % 10);
    exp /= 10;
  }
  *str += len;
}

/**
 * @brief Спецификатор для %o, %x и %X
 *
 * @param str Указатель на строку, куда будет записан результат.
 * @param parameters Указатель на структуру с параметрами форматирования.
 * @param for_print Целое беззнаковое число типа `unsigned long long`, которое
 * нужно отформатировать в шестнадцетиричный или восьмиричный формат.
 *
 * Функция вставляет беззнаковое целое число в шестнадцетиричном формате в
 * строку `str` на основе параметров `parametrs`.
 */
void s21_SpecifierHexOct(char **str, const Parametrs *parameters,
                         unsigned long long for_print) {
  char start_hex = parameters->specifier == 'x' ? 'a' : 'A';
  int radix = parameters->specifier == 'o' ? 8 : 16;
  int hex_length = GetUnsingedIntLength(for_print, radix);
  int hash_len = 0;
  if (parameters->flag.hash) {
    hash_len++;
    if (parameters->specifier != 'o') hash_len++;
  }
  if (parameters->precision > hex_length) {
    hex_length = parameters->precision;
    if (parameters->specifier == 'o') hash_len = 0;
  }
  int len = parameters->width > hex_length + hash_len ? parameters->width
                                                      : hex_length + hash_len;
  if (parameters->width < parameters->precision &&
      hex_length < parameters->precision)
    len = parameters->precision;
  if (parameters->flag.null)
    s21_memset(*str, '0', len);
  else
    s21_memset(*str, ' ', len);
  int index = parameters->flag.minus ? hex_length + hash_len - 1 : len - 1;
  for (int i = 0; i < hex_length; i++) {
    int digit = for_print % radix;
    (*str)[index--] = digit < 10 ? '0' + digit : start_hex + (digit - 10);
    for_print /= radix;
  }
  if (hash_len > 0) {
    switch (parameters->specifier) {
      case 'x':
      case 'X':
        (*str)[index--] = parameters->specifier;
        break;
      default:
        break;
    }
    (*str)[index--] = '0';
  }
  *str += len;
}

/**
 * @brief Спецификатор для %p
 *
 * @param str Указатель на строку, куда будет записан результат.
 * @param parameters Указатель на структуру с параметрами форматирования.
 * @param for_print Указатель типа `void *`, которое нужно
 * отформатировать.
 *
 * Функция вставляет указатель в шестнадцетиричном формате в строку `str` на
 * основе параметров `parametrs`.
 */
void s21_SpecifierPointer(char **str, const Parametrs *parameters,
                          void *for_print) {
  if (for_print == S21_NULL) {
    int nil_len;
    char *nil;
#if defined(__linux__)
    nil_len = 5;
    nil = "(nil)";
#elif defined(__APPLE__) || defined(__MACH__)
    nil_len = 3;
    nil = "0x0";
#endif
    int len = parameters->width > nil_len ? parameters->width : nil_len;
    int index = parameters->flag.minus ? 0 : len - nil_len;
    s21_memset(*str, ' ', len);
    int i = 0;
    while (nil[i]) {
      (*str)[index++] = nil[i++];
    }
    *str += len;
  } else {
    unsigned long address = (unsigned long)for_print;
    const char *hex = "0123456789abcdef";

    int ptr_length = GetUnsingedIntLength(address, 16);
    int len =
        parameters->width > ptr_length + 2 ? parameters->width : ptr_length + 2;
    s21_memset(*str, ' ', len);
    int index = parameters->flag.minus ? 1 + ptr_length : len - 1;
    while (address > 0) {
      (*str)[index--] = hex[address % 16];
      address /= 16;
    }
    (*str)[index--] = 'x';
    (*str)[index--] = '0';
    *str += len;
  }
}
/**
 * @brief Спецификатор для %g и %G
 *
 * @param str Указатель на строку, куда будет записан результат.
 * @param parameters Указатель на структуру с параметрами форматирования.
 * @param for_print Число с плавающей точкой типа `long double`, которое нужно
 * отформатировать.
 *
 * Функция вставляет число с плавающей точкой в строку `str` на
 * основе параметров `parametrs`.
 */
void s21_SpecifierG(char **str, Parametrs *parameters, long double for_print) {
  int precision = parameters->precision >= 0 ? parameters->precision : 6;
  int exp = GetExponent(for_print);
  if ((exp > 0 && exp >= precision) || (exp < -4)) {
    parameters->specifier = parameters->specifier == 'g' ? 'e' : 'E';
    parameters->precision = GetExpMeaningPrecision(for_print, exp, precision);
    if (parameters->flag.hash)
      parameters->precision += precision - 1 - parameters->precision;
    s21_SpecifierExponent(str, parameters, for_print);
  } else {
    parameters->precision = GetFloatMeaningPrecision(for_print, exp, precision);
    if (parameters->flag.hash) {
      parameters->precision += precision - 1 - exp - parameters->precision;
    }
    s21_SpecifierFloat(str, parameters, for_print);
  }
}
/**
 * @brief Спецификатор для %n
 *
 * @param str Указатель на строку, куда будет записан результат.
 *
 * Функция заносит количество символов, напечатанных до появления %n, в
 * переменную типа int*
 */
// void s21_SpecifierN(char *reserve_str, char *str, int *count) {
//   *count = (int)(reserve_str - str);
// }
/**
 * @brief Спецификатор для %%.
 *
 * @param str Указатель на строку, куда будет записан результат.
 * @param parameters Указатель на структуру с параметрами форматирования.
 *
 * Функция вставляет символ `%` в строку `str` на основе параметров
 * `parametrs`.
 */
void s21_SpecifierPercent(char **str) {
  s21_memset(*str, ' ', 1);
  (*str)[0] = '%';
  (*str)++;
}

/**
 * @brief Получение длины `long long` с учетом делителя
 *
 * @param value Целое число типа `long long`, длину которого необходимо получить
 * @param delim Делитель типа `int`, относительно которого вычисляется длина
 *
 * @return Длина входного числа
 */
int GetIntLength(long long value, int delim) {
  int len = 0;
  if (value == 0) {
    len = 1;
  }
  while (value != 0) {
    len++;
    value /= delim;
  }
  return len;
}
/**
 * @brief Получение длины `unsigned long long` с учетом делителя
 *
 * @param value Целое число типа `unsigned long long`, длину которого необходимо
 * получить
 * @param delim Делитель типа `int`, относительно которого вычисляется длина
 *
 * @return Длина входного числа
 */
int GetUnsingedIntLength(unsigned long long value, int delim) {
  int len = 0;
  if (value == 0) {
    len = 1;
  }
  while (value != 0) {
    len++;
    value /= delim;
  }
  return len;
}
/**
 * @brief Получение экспоненты у числа с плавающей точкой
 *
 * @param value Число с плавающей точкой типа `long double`
 *
 * @return Возвращает экспоненту типа `int` входного числа
 */
int GetExponent(long double value) {
  const long double eps = 1e-15L;
  int exp = 0;
  value = fabsl(value);
  if (value != 0.0L) {
    while (value < 1.0L - eps) {
      value *= 10.0L;
      exp--;
    }
    while (value >= 10.0L - eps) {
      value /= 10.0L;
      exp++;
    }
  }
  return exp;
}
/**
 * @brief Функция для округления входного числа с учетом точности округления
 *
 * @param value Число с плавающей точнкой типа `long double`, которое необходимо
 * округлить
 * @param prec Целое число типа `int`, указывающее какое число после запятой
 * необходимо округлить
 *
 * @return Округленное число с плавающей запятой типа `long double`
 */
long double Round(long double value, int prec) {
  return roundl(value * pow(10, prec)) / pow(10, prec);
}
/**
 * @brief Функция для конвертирования и записи числа с плавающей точкой в строку
 *
 * @param dest Строка типа `char*`, в которую необходимо записать число
 * @param value Число с плавающей точкой типа `long double`, которое наобходимо
 * конвертировать
 * @param precision Целое число типа `int`, указывающее сколько цифр после
 * запятой записать в строку
 * @param hash Флаг `#`: необходимо ли ставить точку или нет
 *
 */
void LongDoubleToString(char *dest, long double value, int precision,
                        int hash) {
  value = fabsl(value);
  long long int_part = (long long)value;
  long double frac_part = fabsl(value - int_part);
  char *buf = dest;
  if (int_part == 0LL) {
    *buf++ = '0';
  } else {
    char temp[128];
    int i = 0;
    while (int_part > 0) {
      temp[i++] = '0' + int_part % 10LL;
      int_part /= 10LL;
    }
    while (--i >= 0) {
      *buf++ = temp[i];
    }
  }
  if (precision > 0 || hash) {
    *buf++ = '.';
    long double eps = 0.5L / powl(10, precision);
    frac_part += eps;
    for (int i = 0; i < precision; i++) {
      frac_part *= 10.0L;
      int digit = (int)frac_part;
      *buf++ = '0' + digit;
      frac_part -= digit;
    }
  }
  *buf = '\0';
}
/**
 * @brief Функция для получения значимой точности для экспоненциального числа с
 * плавающей точкой
 *
 * @param value (`long double`) - Очень большое или маленькое число, у
 * которого необходимо определить значимую точность
 * @param exp (`int`) - Экспонента числа
 * @param precision (`int`) - Ранее имеющаяся точность числа, относительно
 * которого вычисляется значимая точность
 *
 * @return Значимая точность типа `int` входного числа
 *
 * Применятеся для экспоненцеального вывода числа с плавающей точкой
 */
int GetExpMeaningPrecision(long double value, int exp, int precision) {
  int result = 0;
  if (exp < 0) {
    value *= powl(10, abs(exp));
  } else {
    value /= powl(10, abs(exp));
  }
  value = Round(value, precision - 1);
  value -= (int)value;
  for (int i = 0; i < precision - 1; i++) {
    value *= 10.0L;
    int digit = (int)value;
    value -= digit;
    if (digit != 0) {
      result = i + 1;
    }
  }
  return result;
}
/**
 * @brief Функция для получения значимой точности для экспоненциального числа с
 * плавающей точкой
 *
 * @param value (`long double`) - Число, у которого необходимо определить
 * значимую точность
 * @param exp (`int`) - Экспонента числа
 * @param precision (`int`) - Ранее имеющаяся точность числа, относительно
 * которого вычисляется значимая точность
 *
 * @return Значимая точность типа `int` входного числа
 *
 * Применяется для обычного вывода числа с плавающей точкой
 */
int GetFloatMeaningPrecision(long double value, int exp, int precision) {
  int result = 0;
  char temp[256];
  LongDoubleToString(temp, value, precision + abs(exp), 0);
  int found_no_zero = 0;
  if (exp < 0) {
    for (int i = 2; i < (int)s21_strlen(temp); i++) {
      if (found_no_zero) found_no_zero++;
      if (temp[i] != '0' && found_no_zero - 1 < precision) {
        result = i - 1;
        found_no_zero = found_no_zero ? found_no_zero : 1;
      }
    }
  } else {
    int index = 0;
    while (temp[index++] != '.') {
      result = precision - index;
    }
    for (int i = 0; i < precision - index + 1; i++) {
      if (temp[i + index] != '0') {
        result = i + 1;
        found_no_zero = 1;
      }
    }
    if (!found_no_zero) {
      result = 0;
    }
  }
  return result;
}