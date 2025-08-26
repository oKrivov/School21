#include "./../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->rows > 0 && A->columns > 0) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
      }
    }
    A->rows = 0;
    A->columns = 0;
    free(A->matrix);
  }
}
