#include "./../s21_matrix.h"

/**
 * @brief Функция проверяет ли указатель матрицы NULL
 *
 *  @return 0 - not NULL 1 - NULL
 */
int s21_PtrIsNull(const matrix_t* A) { return A == NULL; }

/**
 * @brief Функция проверяет что размер rows & columns <= 0
 *
 *  @return 0 - больше 1 - меньше
 */
int s21_NegativeSize(int rows, int columns) {
  return rows <= 0 || columns <= 0;
}

/**
 * @brief Функция проверяет  равны ли размеры матрицы A размерам матрицы B
 *
 *  @return 0 - равны 1 - не равны
 */
int s21_EqualSize(const matrix_t* A, const matrix_t* B) {
  return A->columns != B->columns || A->rows != B->rows;
}

/**
 * @brief Функция проверяет является ли значения матрицы не чилом  или
 * бесканечностью
 *
 *  @return 0 - не является 2 - является
 */
int s21_IsInfOrNan(const matrix_t* A) {
  int code = OK;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
        code = CALCULATION_ERROR;
        i = A->rows;
        j = A->columns;
      }
    }
  }
  return code;
}

void s21_GetMinor(matrix_t* A, int indx_row, int indx_col, matrix_t* minor) {
  if (A->rows - 1 > 0 && A->columns - 1 > 0) {
    s21_remove_matrix(minor);
    s21_create_matrix(A->rows - 1, A->columns - 1, minor);

    for (int i = 0, i_m = 0; i < A->rows; i++, i_m++) {
      {
        if (i == indx_row) i++;
        for (int j = 0, j_m = 0; j < A->columns; j++, j_m++) {
          if (j == indx_col) j++;
          if (i < A->rows && j < A->columns) {
            minor->matrix[i_m][j_m] = A->matrix[i][j];
          }
        }
      }
    }
  } else if (A->rows == 1 && A->columns == 1) {
    s21_remove_matrix(minor);
    s21_create_matrix(A->rows, A->columns, minor);
    minor->matrix[0][0] = A->matrix[0][0];
  }
}