
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long n;
int num_threads;
double sum = 0.0;
pthread_mutex_t lock;

void *compute_pi(void *arg) {
    int thread_id = *(int *)arg;
    double local_sum = 0.0;

    long start = (n / num_threads) * thread_id;
    long end   = (thread_id == num_threads - 1) ? n : start + (n / num_threads);

    for (long i = start; i < end; i++) {
        double x = (i + 0.5) / n;
        local_sum += 4.0 / (1.0 + x * x);
    }

    pthread_mutex_lock(&lock);
    sum += local_sum;
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <n> <num_threads>\n", argv[0]);
        return 1;
    }

    n = atol(argv[1]);
    num_threads = atoi(argv[2]);

    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, compute_pi, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("pi (pthread) = %.12f\n", sum / n);

    return 0;
}
