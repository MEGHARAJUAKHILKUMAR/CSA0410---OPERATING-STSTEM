#include <stdio.h>
#include <pthread.h>

void *display(void *arg) {
    printf("Hello from Thread!\n");
    return NULL;
}

int main() {
    pthread_t tid;

    pthread_create(&tid, NULL, display, NULL);
    pthread_join(tid, NULL);

    printf("Thread execution completed.\n");

    return 0;
}