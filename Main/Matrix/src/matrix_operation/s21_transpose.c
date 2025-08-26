#include "./../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (s21_PtrIsNull(A) || s21_PtrIsNull(result)) {
    return INCORRECT_MATRIX;
  }
  int code = OK;
  code = s21_create_matrix(A->columns, A->rows, result);

  for (int i = 0; !code && i < A->columns; i++) {
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }

  return code;
}
