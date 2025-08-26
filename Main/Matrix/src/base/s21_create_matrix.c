#include "./../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  if (s21_PtrIsNull(result) || s21_NegativeSize(rows, columns)) {
    return INCORRECT_MATRIX;
  }

  result->matrix = (double**)calloc(rows, sizeof(double*));

  for (int ptr = 0; ptr < rows; ptr++) {
    result->matrix[ptr] = (double*)calloc(columns, sizeof(double));
  }

  result->rows = rows;
  result->columns = columns;

  return OK;
};