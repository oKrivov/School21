#include <math.h>
#include <stdio.h>

#define NMAX 10

int input(int *arr, int *n);
void output(int *ar, int n);
void sort(int *ar, int n);

int main() {
    int array[NMAX];
    int n;

    if (input(array, &n)) {
        sort(array, n);
        output(array, n);
    } else {
        printf("n/a");
    }

    return 0;
}
int input(int *arr, int *n) {
    int out = 1;
    int a;
    if ((scanf("%d", n) == 1) && (*n < (NMAX + 1)) && (*n > 0)) {
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
