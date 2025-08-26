#include <stdio.h>
int abs(int n);
int isPrime(int n);
int mod(int a, int b);
int maxPrimeDev(int num);

int main() {
    int inputNum;
    int max = 2;
    int rc = scanf("%d", &inputNum);
    inputNum = abs(inputNum);

    if ((1 != rc) || (inputNum == 0) || (inputNum == 1)) {
        printf("n/a");
    } else {
        max = maxPrimeDev(inputNum);
    }

    printf("%d", max);

    return 0;
}

int maxPrimeDev(int num) {
    int max = 2;
    for (int i = 2; i < num; i++) {
        if ((isPrime(i) == 1) && (mod(num, i) == 0)) {
            max = i;
        }
    }
    return max;
}

int mod(int a, int b) {
    while (a >= b) {
        a -= b;
    }
    return a;
}

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i < num; i++) {
        int j = i;
        while (j < num) {
            j += i;
        }
        if (j == num) {
            return 0;
        }
    }
    return 1;
}

int abs(int n) {
    if (n <= 0) {
        return -n;
    }
    return n;
}