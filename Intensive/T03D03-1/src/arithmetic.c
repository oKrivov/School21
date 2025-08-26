#include <stdio.h>

int sum(int a, int b);
int del(int a, int b);
int min(int a, int b);
int mul(int a, int b);

int main() {
    float a, b;
    char c;
    int rc = scanf("%f%f%c", &a, &b, &c);
    if ((a != (int)a) || (b != (int)b) || ((int)c > 31 && (int)c != 127) || rc != 3) {
        printf("n/a \n");

    } else {
        printf("%d %d %d ", sum(a, b), min(a, b), mul(a, b));
        del(a, b);
    }
    return 0;
}
int sum(int a, int b) { return a + b; }
int min(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int del(int a, int b) {
    if (a == 0 || b == 0) {
        printf("n/a\n");
    } else {
        printf("%d\n", a / b);
    }
}