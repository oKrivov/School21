#include "./../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (s21_PtrIsNull(A) || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }

  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result = (A->matrix[0][0] * A->matrix[1][1]) -
              (A->matrix[0][1] * A->matrix[1][0]);
  } else {
    matrix_t minor = {0};
    *result = 0.0;
    double tmp_res = 0.0;
    for (int i = 0; i < A->columns; i++) {
      s21_GetMinor(A, 0, i, &minor);
      s21_determinant(&minor, &tmp_res);
      tmp_res *= A->matrix[0][i] * pow(-1, i);
      (*result) += tmp_res;
    }
    s21_remove_matrix(&minor);
  }

  return OK;
}
