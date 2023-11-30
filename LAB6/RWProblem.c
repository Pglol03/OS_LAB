#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2
#define MAX_ITERATIONS 5

int data = 0;
pthread_mutex_t mutex;
pthread_cond_t noWriters;
int readCount = 0;
int writeCount = 0;

void *reader(void *arg) {
    int readerId = *(int *)arg;
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        pthread_mutex_lock(&mutex);
        while (writeCount > 0) {
            // Wait if a writer is active
            pthread_cond_wait(&noWriters, &mutex);
            printf("Reader %d Cannot Read, resource busy\n", readerId);
            sleep(1);
        }
        readCount++;
        pthread_mutex_unlock(&mutex);

        // Reading from the resource (file)
        printf("Reader %d reads: %d\n", readerId, data);

        pthread_mutex_lock(&mutex);
        readCount--;
        if (readCount == 0) {
            // Signal that there are no more readers, allowing writers to access
            pthread_cond_signal(&noWriters);
        }
        pthread_mutex_unlock(&mutex);

        // Sleep to simulate some work being done
        sleep(1);
    }
    pthread_exit(NULL);
}

void *writer(void *arg) {
    int writerId = *(int *)arg;
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        pthread_mutex_lock(&mutex);
        writeCount++;
        while (readCount > 0) {
            // Wait if there are active readers  
            printf("Writer %d Cannot write, resource busy\n", writerId);
            pthread_cond_wait(&noWriters, &mutex);
            sleep(1);
        }

        // Writing to the resource (file)
        data = writerId;
        printf("Writer %d writes: %d\n", writerId, data);

        writeCount--;
        // Signal that there are no more writers or readers, allowing both to access
        pthread_cond_broadcast(&noWriters);
        pthread_mutex_unlock(&mutex);

        // Sleep to simulate some work being done
        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int readerIds[NUM_READERS], writerIds[NUM_WRITERS];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&noWriters, NULL);

    // Initialize data to -1 (indicating resource is initially available)
    data = 0;

    for (int i = 0; i < NUM_READERS; i++) {
        readerIds[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &readerIds[i]);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        writerIds[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writerIds[i]);
    }

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&noWriters);

    return 0;
}
