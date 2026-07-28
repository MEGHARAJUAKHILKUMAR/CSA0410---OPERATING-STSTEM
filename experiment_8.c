#include <stdio.h>

int main() {
    int bt[20], rem[20], wt[20], tat[20];
    int n, tq, i, complete = 0, time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Burst Time P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while(complete < n) {
        for(i = 0; i < n; i++) {
            if(rem[i] > 0) {
                if(rem[i] <= tq) {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                    complete++;
                } else {
                    rem[i] -= tq;
                    time += tq;
                }
            }
        }
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
