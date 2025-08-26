#include "./../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_PtrIsNull(A) || s21_PtrIsNull(B) || s21_PtrIsNull(result)) {
    return INCORRECT_MATRIX;
  } else if (s21_EqualSize(A, B)) {
    return CALCULATION_ERROR;
  }
  int code = OK;
  code = s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; !code && i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return code;
}