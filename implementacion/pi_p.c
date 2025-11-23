/* Archivo: pi_p.c
   Version paralela con Pthreads
   Compilar: gcc -o pi_p pi_p.c -lpthread -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>

typedef struct {
    long long start;
    long long end;
    double h;
    double partial_sum;
} thread_data;

double f(double x) {
    return 4.0 / (1.0 + x*x);
}

double GetTime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec * 1e-6;
}

// Función que ejecuta cada hilo
void *worker(void *arg)
{
    thread_data *d = (thread_data*) arg;
    double sum = 0.0;

    for (long long i = d->start; i < d->end; i++) {
        double x = d->h * ((double)i + 0.5);
        sum += f(x);
    }
    d->partial_sum = sum;
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Uso: %s <n> <num_hilos>\n", argv[0]);
        return 1;
    }

    long long n = atoll(argv[1]);
    int T = atoi(argv[2]);

    pthread_t threads[T];
    thread_data data[T];

    double h = 1.0 / (double)n;

    long long chunk = n / T;

    double start = GetTime();

    // Crear hilos
    for (int t = 0; t < T; t++) {
        data[t].start = t * chunk;
        data[t].end = (t == T - 1) ? n : (t + 1) * chunk;
        data[t].h = h;
        data[t].partial_sum = 0.0;
        pthread_create(&threads[t], NULL, worker, &data[t]);
    }

    // Esperar hilos
    double sum = 0.0;
    for (int t = 0; t < T; t++) {
        pthread_join(threads[t], NULL);
        sum += data[t].partial_sum;
    }

    double pi = h * sum;
    double end = GetTime();

    printf("PI paralelo = %.12f\n", pi);
    printf("Tiempo paralelo = %.6f segundos\n", end - start);

    return 0;
}

