#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum { OK, INCORRECT_MATRIX, CALCULATION_ERROR } result_code;

int s21_create_matrix(int rows, int columns, matrix_t* result);
void s21_remove_matrix(matrix_t* A);
int s21_eq_matrix(matrix_t* A, matrix_t* B);
int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_mult_number(matrix_t* A, double number, matrix_t* result);
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_transpose(matrix_t* A, matrix_t* result);
int s21_determinant(matrix_t* A, double* result);
int s21_calc_complements(matrix_t* A, matrix_t* result);
int s21_inverse_matrix(matrix_t* A, matrix_t* result);

/*
 * ****************
 * SUPPORT FUNCTIONS
 * ****************
 */

int s21_PtrIsNull(const matrix_t* A);
int s21_NegativeSize(int rows, int columns);
int s21_EqualSize(const matrix_t* A, const matrix_t* B);
int s21_IsInfOrNan(const matrix_t* A);
void s21_GetMinor(matrix_t* A, int indx_row, int indx_col, matrix_t* minor);

#endif  // S21_MATRIX_H