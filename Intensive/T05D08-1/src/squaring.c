#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a, int *n) {
    char c;
    int out = 1;

    if ((scanf("%d%c", n, &c) == 2) && ((int)c == 10) && (*n < (NMAX + 1)) && (*n > 0)) {
        for (int *p = a; p - a < *n; p++) {
            int num;
            if (scanf("%d", &num) == 1) {
                a[p - a] = num;
            } else {
                out = 0;
            }
        }
    } else {
        out = 0;
    }
    return out;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            printf("%d ", a[i]);
        } else {
            printf("%d ", 0);
        }
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] *= a[i];
    }
}
