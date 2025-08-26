#include "data_stat.h"

double max(double *data, int n) {
    double max = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }

    return max;
}
double min(double *data, int n) {
    double min = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}
double mean(double *data, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += data[i];
    }
    return (res / n);
}
double variance(double *data, int n) {
    double res = 0.0;
    double m = mean(data, n);

    for (int i = 0; i < n; i++) {
        res += (data[i] - m) * (data[i] - m);
    }
    return (res / (double)n);
}
