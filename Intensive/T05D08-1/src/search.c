#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int data[NMAX], n;
    if (input(data, &n)) {
        output(data, n);
    } else {
        printf("n/a");
    }

    return 0;
}

double mean(int *a, int n) {
    double res = 0;
    for (int *p = a; p - a < n; p++) {
        res += *p;
    }
    return (res / n);
}

int input(int *a, int *n) {
    char c;
    int out = 1;
    int num;
    if ((scanf("%d%c", n, &c) == 2) && ((int)c == 10) && (*n < (NMAX + 1)) && (*n > 0)) {
        for (int *p = a; p - a < *n; p++) {
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
    int res = 0;
    int sq = mean(a, n) + 3 * sqrt(variance(a, n));
    for (int i = 0; i < n; i++) {
        if ((a[i] % 2 == 0) && (a[i] >= mean(a, n)) && (a[i] <= sq) && (a[i] != 0)) {
            res = a[i];
        }
    }
    printf("%d", res);
}
double variance(int *a, int n) {
    double res = 0;
    double m = mean(a, n);

    for (int i = 0; i < n; i++) {
        res += (a[i] - m) * (a[i] - m);
    }

    return res / n;
}
