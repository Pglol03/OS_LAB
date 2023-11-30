#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t mutex, empty, full;

void *producer(void *arg) {
    int producerId = *(int *)arg;

    for (int i = 0; i < NUM_ITEMS; i++) {
        int item = rand() % 100; // Produce a random item
        sleep(rand() % 2); // Simulate some work before producing

        sem_wait(&empty); // Wait if the buffer is empty
        sem_wait(&mutex);

        // Produce item and add it to the buffer
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;

        printf("Producer %d produces: %d\n", producerId, item);

        sem_post(&mutex);
        sem_post(&full); // Signal that the buffer is not empty
    }

    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int consumerId = *(int *)arg;

    for (int i = 0; i < NUM_ITEMS; i++) {
        sleep(rand() % 2); // Simulate some work before consuming

        sem_wait(&full); // Wait if the buffer is full
        sem_wait(&mutex);

        // Consume item from the buffer
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        printf("Consumer %d consumes: %d\n", consumerId, item);

        sem_post(&mutex);
        sem_post(&empty); // Signal that the buffer is not full
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producerThreads[NUM_PRODUCERS];
    pthread_t consumerThreads[NUM_CONSUMERS];
    int producerIds[NUM_PRODUCERS];
    int consumerIds[NUM_CONSUMERS];

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        producerIds[i] = i + 1;
        pthread_create(&producerThreads[i], NULL, producer, &producerIds[i]);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        consumerIds[i] = i + 1;
        pthread_create(&consumerThreads[i], NULL, consumer, &consumerIds[i]);
    }

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producerThreads[i], NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumerThreads[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
