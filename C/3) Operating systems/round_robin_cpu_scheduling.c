// To implement Round Robin cpu scheduling algorithm
#include <stdio.h>
int main()
{
	int count, j, n, time, remain, flag = 0, time_quantum;
	int wtime = 0, tatime = 0, atime[10], btime[10], rtime[10];
	printf("Enter Total Processes: ");
	scanf("%d", &n);
	remain = n;

	printf("\nEnter Arrival and Burst Times:\n");
	for (count = 0; count < n; count++)
	{
		printf("P[%d]", count + 1);
		printf("\tArrival time: ");
		scanf("%d", &atime[count]);
		printf("\tBurst time: ");
		scanf("%d", &btime[count]);
		rtime[count] = btime[count];
	}

	printf("\nEnter Time Quantum: ");
	scanf("%d", &time_quantum);
	printf("\nProcess\t\tTurnaround Time\t\tWaiting Time\n");
	for (time = 0, count = 0; remain != 0;)
	{
		if (rtime[count] <= time_quantum && rtime[count] > 0)
		{
			time += rtime[count];
			rtime[count] = 0;
			flag = 1;
		}
		else if (rtime[count] > 0)
		{
			rtime[count] -= time_quantum;
			time += time_quantum;
		}
		if (rtime[count] == 0 && flag == 1)
		{
			remain--;
			printf("P[%d]\t\t%d\t\t\t%d\n", count + 1, time - atime[count], time - atime[count] - btime[count]);
			wtime += time - atime[count] - btime[count];
			tatime += time - atime[count];
			flag = 0;
		}
		if (count == n - 1)
			count = 0;
		else if (atime[count + 1] <= time)
			count++;
		else
			count = 0;
	}
	printf("\nAvg Waiting Time= %f\n", wtime * 1.0 / n);
	printf("Avg Turnaround Time = %f", tatime * 1.0 / n);
}
