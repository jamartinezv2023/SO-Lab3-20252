/* Archivo: fibonacci.c
   Generación de N números de Fibonacci con un hilo trabajador
   Compilar: gcc -o fibonacci fibonacci.c -lpthread
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    long long *arr;
    int N;
} fib_arg;

void *worker(void *arg)
{
    fib_arg *a = (fib_arg*) arg;

    if (a->N >= 1) a->arr[0] = 0;
    if (a->N >= 2) a->arr[1] = 1;

    for (int i = 2; i < a->N; i++) {
        a->arr[i] = a->arr[i-1] + a->arr[i-2];
    }
    return NULL;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Uso: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    long long *arr = malloc(sizeof(long long) * N);

    fib_arg arg;
    arg.arr = arr;
    arg.N = N;

    pthread_t th;

    pthread_create(&th, NULL, worker, &arg);
    pthread_join(th, NULL);

    for (int i = 0; i < N; i++) {
        printf("%lld\n", arr[i]);
    }

    free(arr);
    return 0;
}

