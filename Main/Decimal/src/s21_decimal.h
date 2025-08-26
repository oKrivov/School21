#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// коды ошибок, возвращаемых функциями:
// нет ошибки
#define ERROR_OK 0
// число слишком велико или равно бесконечности
#define ERROR_BIG 1
// число слишком мало или равно отрицательной бесконечности
#define ERROR_SMALL 2
// ошибка конвертации
#define ERROR_CONVERT 1

// индекс младшей части
#define LOW 0
// индекс средней части
#define MIDDLE 1
// индекс старшей части
#define HIGH 2
// индекс части с коэффициентом масштабирования и знаком
#define SCALE_SIGN 3

#define START_BIT_3 96

// максимальная степень
#define MAX_SCALE 28

#define MAX_DECIMAL 7.92281625e+28  // 2^96 - 1
#define MIN_DECIMAL 1e-28

#define MAX_LEFT_SHIFT (int)((unsigned)1 << 31)

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[8];
} s21_big_decimal;

#define GET(DEC, ADDR)    \
  ((s21_scale_sign *)DEC) \
      ->ADDR  // Преобразует DEC в s21_scale_sign * и извлекает поле ADDR
#define GET_BIT(DEC, ADDR)                              \
  (((DEC)->bits[(ADDR) / 32] & (1 << ((ADDR) % 32))) >> \
   ((ADDR) % 32))  // проверяет конкретный бит в числе

typedef struct s21_scale_sign {
  int bits[3];
  int zero1 : 16;     // 16 бит зарезервировано
  int expo : 8;       // 8 бит под экспоненту
  int zero2 : 7;      // 7 бит зарезервировано
  unsigned sign : 1;  // 1 бит - знак
} s21_scale_sign;

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);
int s21_truncate(s21_decimal dcml, s21_decimal *result);
int s21_round(s21_decimal dcml, s21_decimal *result);
int s21_floor(s21_decimal dcml, s21_decimal *result);
int s21_from_decimal_to_int(s21_decimal dcml, int *dst);

// for big_decimal (sub/div)
int s21_SubBigDecimal(s21_big_decimal big_value_1, s21_big_decimal big_value_2,
                      s21_big_decimal *big_result);
int s21_DivBigDecimal(s21_big_decimal value_1, s21_big_decimal value_2,
                      s21_big_decimal *result);

int s21_GetExpBigDecimal(s21_big_decimal value);
void s21_SetExpBigDecimal(s21_big_decimal *value, int exp);
int s21_GetSignBigDecimal(s21_big_decimal value);
void s21_SetSignBigDecimal(s21_big_decimal *result, int sign);
int s21_GetBitBigDecimal(s21_big_decimal value, int bit_number);
void s21_SetBitBigDecimal(s21_big_decimal *result, int bit_number, int bit);

void s21_NormalizeBigDecimal(s21_big_decimal *value_1,
                             s21_big_decimal *value_2);
void s21_MultiplyingByTenBigDecimal(s21_big_decimal *value);
void s21_ShiftBitsBigDecimal(s21_big_decimal *value, int shift);
void s21_MoveStartPointBigDecimal(s21_big_decimal *value, int begining);

int s21_IsGreaterModuleBigDecimal(s21_big_decimal value_1,
                                  s21_big_decimal value_2);
int s21_IsEqualBigDecimal(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_IsZeroBigDecimal(s21_big_decimal value);

void s21_AddBitsBigDecimal(s21_big_decimal value_1, s21_big_decimal value_2,
                           s21_big_decimal *result);
void s21_SubBitsBigDecimal(s21_big_decimal value_1, s21_big_decimal value_2,
                           s21_big_decimal *result);
void s21_DivBitsBigDecimal(s21_big_decimal remainder, s21_big_decimal divider,
                           s21_big_decimal *big_result);
void s21_DivBitsWithRemainderBigDecimal(s21_big_decimal *remainder,
                                        s21_big_decimal divider, int shift,
                                        s21_big_decimal *big_result);

void s21_ShiftDividerBigDecimal(s21_big_decimal *divider,
                                s21_big_decimal reserve_divider, int shift);
int s21_GetShiftBigDecimal(s21_big_decimal divisor, s21_big_decimal divider);
int s21_GetBitCountBigDecimal(s21_big_decimal value);

void s21_BankRoundBigDecimal(s21_big_decimal *big_result);
void s21_CutBigDecimal(s21_big_decimal value, s21_big_decimal *result);
void s21_ResetBigDecimal(s21_big_decimal *value);

int s21_GetErrorCodeBigDecimal(s21_big_decimal *big_result);
void s21_GetResultFromBigDecimal(s21_big_decimal big_result,
                                 s21_decimal *result);

// add
void s21_Copy(s21_decimal *dst, s21_decimal src);
s21_decimal s21_MaxValue();
int s21_SumOverflow(s21_decimal a, s21_decimal b);
int s21_Downscale(s21_decimal *dec);
void s21_ScaleIncrease(s21_decimal *value, int shift);
unsigned int s21_MulByTen(s21_decimal *dec);
int s21_ScaleEqualize(s21_decimal *first, s21_decimal *second);
int s21_IsZeroAdd(s21_decimal value);
int s21_DownscaleReal(s21_decimal *dec);
int s21_Compare(s21_decimal a, s21_decimal b);

// mull
int s21_DownscaleRealMul(s21_decimal *dec, unsigned left);
int s21_DoubleSizeMul(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result, s21_decimal *leftovers);
int s21_MergeDev(s21_decimal *dec, s21_decimal leftovers, int *left);
int s21_Msub(s21_decimal val1, s21_decimal val2, s21_decimal *result);
int s21_Madd(s21_decimal val1, s21_decimal val2, s21_decimal *result);
int s21_DownscaleMul(s21_decimal *dec);

// common
void s21_SetSign(s21_decimal *result, int sign);
int s21_GetSign(s21_decimal d);
int s21_GetScale(s21_decimal d);
void s21_SetScale(s21_decimal *num, int scale);
void s21_PrintDecimal(s21_decimal value);
void s21_ClearDecimal(s21_decimal *dcml);
int s21_IsValidDecimal(s21_decimal value);
int s21_IsZero(s21_decimal value);
int s21_GetBit(s21_decimal decl, int index);
void s21_SetBit(s21_decimal *decl, int index, int bit);
int s21_BankRound(s21_decimal *dec, int digit);
s21_decimal s21_RoundHandle(s21_decimal integer_part,
                            s21_decimal fractional_part);

s21_decimal s21_GetIncorrectDecimal(void);
s21_decimal s21_Abs(s21_decimal dcml);

// for comparison
int s21_IsLessScale(s21_decimal dec, s21_decimal dec_2, int is_negat,
                    int is_negat_2);
int s21_IsLessOrEqualScale(s21_decimal dec, s21_decimal dec_2, int is_negat,
                           int is_negat_2);
int s21_IsGreaterOrEqualScale(s21_decimal dec, s21_decimal dec_2, int is_negat,
                              int is_negat_2);
int s21_IsGreaterScale(s21_decimal dec, s21_decimal dec_2, int is_negat,
                       int is_negat_2);

int s21_NoScaleIsCompar(s21_decimal dec, s21_decimal dec_2);
int s21_NoScaleIsComparSameSize(s21_decimal dec, s21_decimal dec_2);
int s21_ComparWithScale(s21_decimal dec, s21_decimal dec_2);
int s21_GetFirstBitPositionWithSlot(s21_decimal dec);

// s21_from_decimal_to_float
int s21_GetFirstBitPosition(s21_decimal dec);
int s21_CheckTheThirdElem(s21_decimal dec);

// truncate support functions
int s21_IsCorrectDecimal(s21_decimal dcml);

int s21_IsSetBit(int number, int index);
int s21_IsDcmlEqualZero(s21_decimal dcml);
int s21_BinaryCompareInt128(s21_decimal dcml_1, s21_decimal dcml_2);
s21_decimal s21_BinaryNotInt128(s21_decimal dcml);
s21_decimal s21_BinaryXorInt128(s21_decimal dcml_1, s21_decimal dcml_2);
s21_decimal s21_BinaryAndInt128(s21_decimal dcml_1, s21_decimal dcml_2);
s21_decimal s21_BinarySubInt128(s21_decimal dcml_1, s21_decimal dcml_2);
s21_decimal s21_BinaryAddInt128(s21_decimal dcml_1, s21_decimal dcml_2);
s21_decimal s21_BinaryOneRightShiftInt128(s21_decimal dcml);
s21_decimal s21_BinaryRightShift(s21_decimal dcml, int shift);
s21_decimal s21_BinaryLeftShift(s21_decimal dcml, int shift);
s21_decimal s21_BinaryOneLeftShiftInt128(s21_decimal dcml);
s21_decimal s21_TruncateHandler(s21_decimal dcml_1, s21_decimal dcml_2);

#endif
