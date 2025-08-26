#include "./../s21_matrix.h"
/**
 * @return 0 - не равны 1 - равны
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (s21_PtrIsNull(A) || s21_PtrIsNull(B) || s21_EqualSize(A, B)) {
    return FAILURE;
  }
  int code = SUCCESS;

  for (int i = 0; code && i < A->rows; i++) {
    for (int j = 0; code && j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
        code = FAILURE;
      }
    }
  }

  return code;
}