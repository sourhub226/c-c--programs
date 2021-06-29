// To implement SJF cpu scheduling algorithm
#include <stdio.h>

int main()
{
    int btime[20], p[20], wtime[20], tatime[20], i, j, n, total = 0, pos, temp;
    float avg_wtime, avg_tatime;
    printf("Enter number of process: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++)
    {
        printf("p%d: ", i + 1);
        scanf("%d", &btime[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (btime[j] < btime[pos])
                pos = j;
        }

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

    avg_wtime = (float)total / n;
    total = 0;

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        tatime[i] = btime[i] + wtime[i];
        total += tatime[i];
        printf("\np%d\t\t%d\t\t%d\t\t%d", p[i], btime[i], wtime[i], tatime[i]);
    }

    avg_tatime = (float)total / n;
    printf("\n\nAverage Waiting Time = %f", avg_wtime);
    printf("\nAverage Turnaround Time = %f", avg_tatime);
}
