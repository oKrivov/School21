#include <stdio.h>
int crack(float x, float y);
int resq(float x, float y);

int main() {
    float x, y;
    char c;
    int rc = scanf("%f%f%c", &x, &y, &c);

    if (rc != 3 || ((int)c > 31 && (int)c != 127)) {
        printf("n/a");
    } else {
        crack(x, y);
    }

    return 0;
}

int crack(float x, float y) {
    if (resq(x, y) < 25) {
        printf("GOTCHA");
    } else {
        printf("MISS");
    }
    return 0;
}

int resq(float x, float y) { return (x * x + y * y); }