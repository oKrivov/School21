#include "./../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (s21_PtrIsNull(A) || s21_PtrIsNull(result)) {
    return INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }
  int code = OK;
  code = s21_create_matrix(A->rows, A->columns, result);

  if (!code) {
    matrix_t minor = {0};
    double cell_value = 0.0;

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_GetMinor(A, i, j, &minor);
        s21_determinant(&minor, &cell_value);
        result->matrix[i][j] = cell_value * pow(-1, i + j);
      }
    }
    s21_remove_matrix(&minor);
  }

  return code;
}