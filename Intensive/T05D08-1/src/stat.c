#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

// void output_result(int max_v, int min_v, double mean_v);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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
double variance(int *a, int n) {
    double res = 0;
    double m = mean(a, n);

    for (int *p = a; p - a < n; p++) {
        res += (*p - m) * (*p - m);
    }

    return res / n;
}

int max(int *a, int n) {
    int max = a[0];
    for (int *p = a; p - a < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

int min(int *a, int n) {
    int min = a[0];
    for (int *p = a; p - a < n; p++) {
        if (*p < min) {
            min = *p;
        }
    }
    return min;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (*p) printf("%d ", *p);
    }
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("\n%d %d %.6lf %.6f", max_v, min_v, mean_v, variance_v);
}

int input(int *a, int *n) {
    char c;
    int out = 1;
    int num;
    if ((scanf("%d%c", n, &c) == 2) && ((int)c == 10) && (*n < (NMAX + 1)) && (*n > 0)) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", &num) == 1) {
                *p = num;
            } else {
                out = 0;
            }
        }
    } else {
        out = 0;
    }
    return out;
}