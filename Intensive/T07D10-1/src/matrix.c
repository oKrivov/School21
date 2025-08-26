#include <stdio.h>
#include <stdlib.h>
#define N 100
#define M 100

int get_key_menu(int *key);
int ar_of_ptr_of_ar(int row, int col);
int get_row_col_matrix(int *row, int *col);
// int ar_of_ptr_of_ar_buf(int row, int col);
int get_stat_array(int row, int col);

int main() {
    int key = 0;
    int row, col;

    get_key_menu(&key);
    get_row_col_matrix(&row, &col);

    switch (key) {
        case 1:
            printf("CASE N1 \n");
            ar_of_ptr_of_ar(row, col);
            break;

        case 2:
            printf("CASE N2 \n");
            get_stat_array(row, col);
            break;

        case 3:
            printf("CASE N3 \n");
            get_stat_array(row, col);
            break;

        case 4:
            printf("CASE N4 \n");
            get_stat_array(row, col);
            break;
        default:
            printf("n/a");
            break;
    }

    return 0;
}
int get_key_menu(int *key) {
    int out = 1;
    printf("get_key_menu\n");
    if ((scanf("%d", key) == 1)) {
    } else {
        out = 0;
    }

    return out;
}

int get_row_col_matrix(int *row, int *col) {
    int error = 1;
    printf("get_row_col_matrix\n");
    if (2 != scanf("%d%d", row, col)) {
        error = 0;
    }
    return error;
}

int ar_of_ptr_of_ar(int row, int col) {
    int rc;
    int error = 1;
    int **ptr_arr = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        ptr_arr[i] = malloc(col * sizeof(int));
    }

    for (int i = 0; i < row; i++) {
        int tmp = 0;

        for (int j = 0; j < col; j++) {
            rc = scanf("%d", &tmp);
            if (1 != rc) {
                error = 0;
            } else {
                ptr_arr[i][j] = tmp;
            }
        }
    }

    if (rc != 0) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("%d ", ptr_arr[i][j]);
            }
            if (i < row - 1) printf("\n");
        }
    }

    for (int i = 0; i < row; i++) {
        free(ptr_arr[i]);
    }

    free(ptr_arr);
    return error;
}

int get_stat_array(int row, int col) {
    int matrix[N][M];
    int rc;
    int error = 1;

    for (int i = 0; i < row; i++) {
        int tmp = 0;

        for (int j = 0; j < col; j++) {
            rc = scanf("%d", &tmp);
            if (1 != rc) {
                error = 0;
            } else {
                matrix[i][j] = tmp;
            }
        }
    }

    if (rc != 0) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("%d ", matrix[i][j]);
            }
            if (i < row - 1) printf("\n");
        }
    }
    return error;
}

// int ar_of_ptr_of_ar_buf(int row, int col) {
//     int rc;
//     int error = 1;
//     int **ptr_arr = malloc(row * col * sizeof(int) + row * sizeof(int *));
//     int *ptr = (int *)(ptr_arr + row);
//     int tmp = 0;
//     for (int i = 0; i < row; i++) {
//         ptr_arr[i] = ptr + col * i;
//     }
//     for (int i = 0; i < row; i++) {
//         rc = scanf("%d", &tmp);
//         for (int j = 0; j < tmp; j++) {
//             ptr_arr[i][j] = ++tmp;
//         }
//     }
//     if (rc != 0) {
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 printf("%d ", ptr_arr[i][j]);
//             }
//             if (i < row - 1) printf("\n");
//         }
//     }
//     free(ptr_arr);
//     return error;
// }