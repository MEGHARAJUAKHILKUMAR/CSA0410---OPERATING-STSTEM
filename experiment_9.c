#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = 1234;
    int shmid;
    char *data;

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    data = (char *)shmat(shmid, NULL, 0);

    printf("Enter message: ");
    scanf("%s", data);

    printf("Stored Message: %s\n", data);

    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
