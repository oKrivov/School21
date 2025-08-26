#ifndef S21_SSCANF
#define S21_SSCANF

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_string.h"

const char *SkipWhitespace(const char *str);
void ProccessLengthAndWidth(const char **p_format, const char **p_input,
                            int *width, char *length);
int GetStrtolBase(const char p_format);
int ProccessSignedIntNumbers(va_list args, const char *p_format,
                             const char **p_input, int width, char length);
int ProccessUnsignedIntNumbers(va_list args, const char *p_format,
                               const char **p_input, int width, char length);
int ProccessFloatNumbers(va_list args, const char **p_input, int width,
                         char length);
void ProccessChar(va_list args, const char **p_input);
void ProccessString(va_list args, const char **p_input, int width);
void ProccessN(va_list args, const char *p_input, const char *input);
void ProccessPointer(va_list args, const char **p_input);
int ProccessPercent(va_list args, const char **p_input);
int ScanText(va_list args, const char *input, const char *format);
int s21_sscanf(const char *input, const char *format, ...);

#endif