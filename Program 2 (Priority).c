#include <stdio.h>

int main() {
    int n, bt[20], pr[20], p[20], wt[20], tat[20];
    int i, j, pos, temp, total = 0;
    float awt = 0, atat = 0;

    printf("Enter Total Number of Process: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time and Priority\n");
    for (i = 0; i < n; i++) {
        printf("\nP[%d]\nBurst Time:", i+1);
        scanf("%d", &bt[i]);
        printf("Priority:");
        scanf("%d", &pr[i]);
        p[i] = i + 1;            // store process id
    }

    // sort by priority (lower value = higher priority)
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i+1; j < n; j++)
            if (pr[j] < pr[pos]) pos = j;

        temp = pr[i]; pr[i] = pr[pos]; pr[pos] = temp;
        temp = bt[i]; bt[i] = bt[pos]; bt[pos] = temp;
        temp = p[i];  p[i]  = p[pos];  p[pos]  = temp;
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        awt += wt[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        atat += tat[i];
        printf("\nP[%d]\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time=%.0f", awt/n);
    printf("\nAverage Turnaround Time=%.0f\n", atat/n);

    return 0;
}
