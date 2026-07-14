#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20], pr[20];
    int ct[20], tat[20], wt[20];
    int min, shortest;

    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i + 1);

        printf("Arrival Time : ");
        scanf("%d", &at[i]);

        printf("Burst Time : ");
        scanf("%d", &bt[i]);

        printf("Priority : ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }

    while(completed != n)
    {
        shortest = -1;
        min = 9999;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0 && pr[i] < min)
            {
                min = pr[i];
                shortest = i;
            }
        }

        if(shortest == -1)
        {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0)
        {
            completed++;

            ct[shortest] = time;

            tat[shortest] = ct[shortest] - at[shortest];

            wt[shortest] = tat[shortest] - bt[shortest];

            avgwt += wt[shortest];

            avgtat += tat[shortest];
        }
    }

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt / n);

    printf("\nAverage Turnaround Time = %.2f\n", avgtat / n);

    return 0;
}
