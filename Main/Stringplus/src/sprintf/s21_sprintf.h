#ifndef S21_SPRINTF
#define S21_SPRINTF

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "../s21_string.h"

typedef struct {
  char minus;
  char plus;
  char space;
  char hash;
  char null;
} Flags;

typedef struct {
  char h;
  char l;
  char L;
} Length;

typedef struct {
  Flags flag;
  int width;
  int precision;
  Length length;
  char specifier;
} Parametrs;

int s21_sprintf(char *str, const char *format, ...);
int s21_Parser(const char **format, Parametrs *parametrs,
               va_list *opt_parametr);
void s21_ParseFlags(const char **format, Flags *flag);
int s21_GetNumber(const char **format, va_list *opt_arg);
int s21_ParseLength(const char **format, Length *length);
int s21_Formating(char **reserve_str, Parametrs *parametrs, va_list *opt_arg);
void s21_SpecifierChar(char **str, const Parametrs *parameters, int for_print);
void s21_SpecifierDigit(char **str, const Parametrs *parameters,
                        long long for_print);
void s21_SpecifierFloat(char **str, const Parametrs *parameters,
                        long double for_print);
void s21_SpecifierString(char **str, const Parametrs *parameters,
                         char *for_print);
void s21_SpecifierUnsigned(char **str, const Parametrs *parameters,
                           unsigned long long for_print);
void s21_SpecifierExponent(char **str, const Parametrs *parameters,
                           long double for_print);
void s21_SpecifierHexOct(char **str, const Parametrs *parameters,
                         unsigned long long for_print);
void s21_SpecifierPointer(char **str, const Parametrs *parameters,
                          void *for_print);
void s21_SpecifierG(char **str, Parametrs *parameters, long double for_print);
// void s21_SpecifierN(char *reserve_str, char *str, int *count);
void s21_SpecifierPercent(char **str);
int GetIntLength(long long value, int delim);
int GetUnsingedIntLength(unsigned long long value, int delim);
int GetExponent(long double value);
long double Round(long double value, int prec);
void LongDoubleToString(char *dest, long double value, int precision, int hash);
int GetExpMeaningPrecision(long double value, int exp, int precision);
int GetFloatMeaningPrecision(long double value, int exp, int precision);

#endif
