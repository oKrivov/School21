#include <stdio.h>
#include <stdlib.h>

int input(int *arr, int *n);
void output(int *ar, int n);
void sort(int *ar, int n);

int main() {
    int length = 0;
    int *array = malloc((sizeof(int)) * length);
    if (array != NULL) {
        if (input(array, &length)) {
            sort(array, length);
            output(array, length);
        } else {
            printf("n/a");
        }
    }
    free(array);
    return 0;
}
int input(int *arr, int *n) {
    int out = 1;
    int a;
    if ((scanf("%d", n) == 1) && (*n < (*n + 1)) && (*n > 0)) {
        for (int i = 0; i < *n; i++) {
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

void output(int *ar, int n) {
    int i = 0;
    while (i < n) {
        printf("%d ", ar[i++]);
    }
}

void sort(int *ar, int n) {
    int pos;
    for (int i = 0; i < n - 1; ++i) {
        pos = i;
        for (int j = i + 1; j < n; ++j) {
            if (ar[pos] > ar[j]) {
                pos = j;
            }
        }
        if (pos != i) {
            int t = ar[i];
            ar[i] = ar[pos];
            ar[pos] = t;
        }
    }
}
