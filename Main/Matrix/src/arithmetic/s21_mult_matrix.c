#include "./../s21_matrix.h"

int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (s21_PtrIsNull(A) || s21_PtrIsNull(B) || s21_PtrIsNull(result)) {
    return INCORRECT_MATRIX;
  } else if (A->columns != B->rows || s21_IsInfOrNan(A) || s21_IsInfOrNan(B)) {
    return CALCULATION_ERROR;
  }
  int code = OK;
  code = s21_create_matrix(A->rows, B->columns, result);

  for (int i = 0; !code && i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return code;
}