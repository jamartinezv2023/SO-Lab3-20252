
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <n>\n", argv[0]);
        return 1;
    }

    long n = atol(argv[1]);
    double sum = 0.0;

    for (long i = 0; i < n; i++) {
        double x = (i + 0.5) / n;
        sum += 4.0 / (1.0 + x * x);
    }

    double pi = sum / n;
    printf("pi (serial) = %.12f\n", pi);

    return 0;
}
