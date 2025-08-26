#include <stdio.h>
#define NMAX 10

int input(int *arr, int *length);
int sum_numbers(int *arrIn, int length);
int find_numbers(int *arrIn, int length, int number, int *arrOut);

int main() {
    int arrIn[NMAX];
    int arrOut[NMAX];
    int length, number;

    if (input(arrIn, &length)) {
        number = sum_numbers(arrIn, length);
        int len_out = find_numbers(arrIn, length, number, arrOut);
        for (int i = 0; i < len_out; i++) {
            printf("%d ", arrOut[i]);
        }

    } else {
        printf("n/a");
    }

    return 0;
}

int sum_numbers(int *numbers, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (numbers[i] % 2 == 0) {
            sum += numbers[i];
        }
    }
    return sum;
}

int find_numbers(int *arrIn, int length, int number, int *arrOut) {
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (arrIn[i] != 0 && number % arrIn[i] == 0) {
            arrOut[j] = arrIn[i];
            j++;
        }
    }

    return j;
}

int input(int *arr, int *length) {
    int out = 1;
    int a;
    if ((scanf("%d", length) == 1) && (*length < (NMAX + 1)) && (*length > 0)) {
        for (int i = 0; i < *length; i++) {
            if (scanf("%d", &a) == 1) {
                arr[i] = a;
            } else {
                out = 0;
            }
        }
    } else {
        out = 0;
    }
    return out;
}
