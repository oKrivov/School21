#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  if (format == S21_NULL || str == S21_NULL) {
    return 0;
  }

  va_list first_opt_arg;
  va_start(first_opt_arg, format);

  char *reserve_str = str;

  int correct_work = 1;
  while (*format && correct_work) {
    Parametrs parametrs = {};
    parametrs.precision = -1;

    char *percent = s21_strchr(format, '%');
    if (percent) {
      s21_strncpy(reserve_str, format, percent - format);
      reserve_str += percent - format;

      format = ++percent;

      if (*format && s21_Parser(&format, &parametrs, &first_opt_arg)) {
        correct_work = s21_Formating(&reserve_str, &parametrs, &first_opt_arg);
      } else {
        correct_work = 0;
      }
    } else {
      break;
    }
  }

  if (correct_work) {
    const char *reserve_format = format;
    format = s21_strchr(format, '\0');
    s21_memcpy(reserve_str, reserve_format, format - reserve_format);

    reserve_str += format - reserve_format;
    correct_work = reserve_str - str;
  }

  va_end(first_opt_arg);

  return correct_work;
}

int s21_Parser(const char **format, Parametrs *parametrs, va_list *opt_arg) {
  s21_ParseFlags(format, &parametrs->flag);

  parametrs->width = s21_GetNumber(format, opt_arg);

  if (**format == '.') {
    ++(*format);
    parametrs->precision = s21_GetNumber(format, opt_arg);
  }

  int found = 0;
  if (s21_ParseLength(format, &parametrs->length)) {
    parametrs->specifier = **format;

    if (parametrs->specifier) {
      ++(*format);
      found = 1;
    }
  }

  return found;
}

void s21_ParseFlags(const char **format, Flags *flag) {
  int found = 1;
  while (found) {
    switch (**format) {
      case '-':
        flag->minus = 1;
        if (flag->null) {
          flag->null = 0;
        }
        break;

      case '+':
        flag->plus = 1;
        if (flag->space) {
          flag->space = 0;
        }
        break;

      case ' ':
        if (!flag->plus) {
          flag->space = 1;
        }
        break;

      case '#':
        flag->hash = 1;
        break;

      case '0':
        if (!flag->minus) {
          flag->null = 1;
        }
        break;

      default:
        found = 0;
        break;
    }
    if (found) {
      ++(*format);
    }
  }
}

int s21_GetNumber(const char **format, va_list *opt_arg) {
  int number = 0;
  if (**format == '*') {
    number = va_arg(*opt_arg, int);
    ++(*format);
  } else {
    char *end_number = S21_NULL;
    number = strtol(*format, &end_number, 10);
    *format = end_number;
  }
  return number;
}

int s21_ParseLength(const char **format, Length *length) {
  int correct_work = 1;
  for (int found = 2; found > 0; --found) {
    switch (**format) {
      case 'h':
        if (length->L && length->l) {
          found = 0;
          correct_work = 0;
        } else {
          ++(length->h);
        }
        break;

      case 'l':
        if (length->L && length->h) {
          found = 0;
          correct_work = 0;
        } else {
          ++(length->l);
        }
        break;

      case 'L':
        if ((length->l && length->h) || length->L) {
          found = 0;
          correct_work = 0;
        } else {
          length->L = 1;
          --found;
        }
        break;

      default:
        found = 0;
        break;
    }
    if (found) {
      ++(*format);
    }
  }
  return correct_work;
}

int s21_Formating(char **reserve_str, Parametrs *parametrs, va_list *opt_arg) {
  int found = 1;
  switch (parametrs->specifier) {
    case 'c':
      s21_SpecifierChar(reserve_str, parametrs, va_arg(*opt_arg, int));
      break;
    case 'd':
    case 'i':
      if (parametrs->length.l == 2) {
        s21_SpecifierDigit(reserve_str, parametrs,
                           va_arg(*opt_arg, long long int));
      } else if (parametrs->length.l == 1) {
        s21_SpecifierDigit(reserve_str, parametrs, va_arg(*opt_arg, long int));
      } else {
        s21_SpecifierDigit(reserve_str, parametrs, va_arg(*opt_arg, int));
      }
      break;
    case 'e':
    case 'E':
      if (parametrs->length.L) {
        s21_SpecifierExponent(reserve_str, parametrs,
                              va_arg(*opt_arg, long double));
      } else {
        s21_SpecifierExponent(reserve_str, parametrs, va_arg(*opt_arg, double));
      }
      break;
    case 'f':
      if (parametrs->length.L) {
        s21_SpecifierFloat(reserve_str, parametrs,
                           va_arg(*opt_arg, long double));
      } else {
        s21_SpecifierFloat(reserve_str, parametrs, va_arg(*opt_arg, double));
      }
      break;
    case 'g':
    case 'G':
      if (parametrs->length.L) {
        s21_SpecifierG(reserve_str, parametrs, va_arg(*opt_arg, long double));
      } else {
        s21_SpecifierG(reserve_str, parametrs, va_arg(*opt_arg, double));
      }
      break;
    case 's':
      s21_SpecifierString(reserve_str, parametrs, va_arg(*opt_arg, char *));
      break;
    case 'u':
      if (parametrs->length.l == 2) {
        s21_SpecifierUnsigned(reserve_str, parametrs,
                              va_arg(*opt_arg, unsigned long long));
      } else if (parametrs->length.l == 1) {
        s21_SpecifierUnsigned(reserve_str, parametrs,
                              va_arg(*opt_arg, unsigned long));
      } else {
        s21_SpecifierUnsigned(reserve_str, parametrs,
                              va_arg(*opt_arg, unsigned int));
      }
      break;
    case 'o':
    case 'x':
    case 'X':
      if (parametrs->length.l == 2) {
        s21_SpecifierHexOct(reserve_str, parametrs,
                            va_arg(*opt_arg, unsigned long long));
      } else if (parametrs->length.l == 1) {
        s21_SpecifierHexOct(reserve_str, parametrs,
                            va_arg(*opt_arg, unsigned long));
      } else {
        s21_SpecifierHexOct(reserve_str, parametrs,
                            va_arg(*opt_arg, unsigned int));
      }
      break;
    case 'p':
      s21_SpecifierPointer(reserve_str, parametrs, va_arg(*opt_arg, void *));
      break;
    case '%':
      s21_SpecifierPercent(reserve_str);
      break;
    default:
      found = 0;
      break;
  }
  return found;
}