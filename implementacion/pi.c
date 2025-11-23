/* Archivo: pi.c
   Version serial del cálculo de pi usando integración numérica
   Compilar: gcc -o pi_s pi.c -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

double f(double x) {
    return 4.0 / (1.0 + x*x);
}

double GetTime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec * 1e-6;
}

double CalcPi(long long n)
{
    double h = 1.0 / (double)n;
    double sum = 0.0;
    for (long long i = 0; i < n; i++) {
        double x = h * ((double)i + 0.5);
        sum += f(x);
    }
    return h * sum;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Uso: %s <n>\n", argv[0]);
        return 1;
    }

    long long n = atoll(argv[1]);

    double start = GetTime();
    double pi = CalcPi(n);
    double end = GetTime();

    printf("PI = %.12f\n", pi);
    printf("Tiempo serial = %.6f segundos\n", end - start);

    return 0;
}

