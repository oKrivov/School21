#include "./../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (s21_PtrIsNull(A) || s21_PtrIsNull(result)) {
    return INCORRECT_MATRIX;
  }

  double determinant = 0.0;
  s21_determinant(A, &determinant);
  if (A->rows != A->columns || determinant == 0.0) {
    return CALCULATION_ERROR;
  }

  int code = OK;
  if (A->rows == 1) {
    code = s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1 / determinant;
  } else {
    matrix_t transposed_mtrx = {0}, compl_mtrx = {0};
    s21_transpose(A, &transposed_mtrx);
    s21_calc_complements(&transposed_mtrx, &compl_mtrx);
    s21_mult_number(&compl_mtrx, 1 / determinant, result);

    s21_remove_matrix(&transposed_mtrx);
    s21_remove_matrix(&compl_mtrx);
  }

  return code;
}