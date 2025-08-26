#include <stdio.h>
int fib(int n);

int main() {
    int n;

    if (scanf("%d", &n) == 1)
        printf("%d", fib(n));
    else
        printf("n/a");
    return 0;
}

int fib(int n) {
    if (n < 2) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}