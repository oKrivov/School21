#include <stdio.h>
#define NMAX 10
int input(int *arr, int *length, int *shift);
void shift_arr(int *arr, int length, int shift);

int main() {
    int arr[NMAX];
    int length;
    int shift;
    if (input(arr, &length, &shift) == 1) {
        shift_arr(arr, length, shift);
        for (int i = 0; i < length; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("n/a");
    }

    return 0;
}
void shift_arr(int *arr, int length, int shift) {
    shift = shift % length;
    if (shift > 0) {
        for (int j = 0; j < shift; j++) {
            int tmp = arr[0];
            for (int i = 0; i < length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arr[length - 1] = tmp;
        }
    } else if (shift < 0) {
        shift *= -1;
        for (int j = 0; j < shift; j++) {
            int tmp = arr[length - 1];
            for (int i = length - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = tmp;
        }
    }
}

int input(int *arr, int *length, int *shift) {
    int out = 1;
    char c;
    int a;
    if ((scanf("%d%c", length, &c) == 2) && (*length <= (NMAX)) && (*length > 0) && (c == ' ' || c == '\n')) {
        for (int i = 0; i < *length; i++) {
            if (scanf("%d%c", &a, &c) == 2 && (c == ' ' || c == '\n')) {
                arr[i] = a;
            } else {
                out = 0;
            }
        }

        if (scanf("%d%c", shift, &c) != 2) {
            out = 0;
        }
    } else {
        out = 0;
    }

    return out;
}