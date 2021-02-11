// To implement priority cpu scheduling algorithm
#include <stdio.h>

int main()
{
    int btime[20], p[20], wtime[20], tatime[20], pr[20], i, j, n, total = 0, pos, temp, avg_wtime, avg_tatime;
    printf("Enter Total Number of Process: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time and Priority\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]:", i + 1);
        printf("\tBurst Time: ");
        scanf("%d", &btime[i]);
        printf("\tPriority: ");
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
                pos = j;
        }

        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = btime[i];
        btime[i] = btime[pos];
        btime[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wtime[0] = 0;
    for (i = 1; i < n; i++)
    {
        wtime[i] = 0;
        for (j = 0; j < i; j++)
            wtime[i] += btime[j];

        total += wtime[i];
    }

    avg_wtime = total / n;
    total = 0;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        tatime[i] = btime[i] + wtime[i];
        total += tatime[i];
        printf("\nP[%d]\t%d\t\t%d\t\t%d", p[i], btime[i], wtime[i], tatime[i]);
    }

    avg_tatime = total / n;
    printf("\n\nAverage Waiting Time:%d", avg_wtime);
    printf("\nAverage Turnaround Time:%d", avg_tatime);
}
