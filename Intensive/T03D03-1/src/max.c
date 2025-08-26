#include <stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }

int main() {
    float a, b;
    char c;
    int rc = scanf("%f%f%c", &a, &b, &c);

    if ((a != (int)a) || (b != (int)b) || ((int)c > 31 && (int)c != 127) || rc != 3) {
        printf("n/a \n");

    } else {
        printf("%d\n", max(a, b));
    }

    return 0;
}
