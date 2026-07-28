#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message {
    long type;
    char text[100];
};

int main() {
    struct message msg;
    int msgid;

    msgid = msgget(1234, 0666 | IPC_CREAT);

    msg.type = 1;

    printf("Enter message: ");
    scanf("%s", msg.text);

    msgsnd(msgid, &msg, sizeof(msg.text), 0);

    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);

    printf("Received Message: %s\n", msg.text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
