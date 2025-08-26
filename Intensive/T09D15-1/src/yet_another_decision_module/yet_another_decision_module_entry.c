#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"
int main() {
    int n;
    scanf("%d", &n);
    double *data = (double *)malloc(n * sizeof(double));
    input(data, n);

    if (data) {
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
    } else
        printf("ERROR");

    free(data);
    return 0;
}
