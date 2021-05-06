// To implement FCFS cpu scheduling algorithm
#include <stdio.h>

int main() {
	int n,btime[20],wtime[20],tatime[20],avg_wtime=0,avg_tatime=0,i,j;
	printf("Enter total number of processes(maximum 20):");
	scanf("%d",&n);
	printf("\nEnter Process Burst Time:\n");
	for (i=0;i<n;i++) {
		printf("P[%d]:",i+1);
		scanf("%d",&btime[i]);
	}
	
	wtime[0]=0;
	for (i=1;i<n;i++) {
		wtime[i]=0;
		for (j=0;j<i;j++)
			wtime[i]+=btime[j];
	}
	
	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
	for (i=0;i<n;i++) {
		tatime[i]=btime[i]+wtime[i];
		avg_wtime+=wtime[i];
		avg_tatime+=tatime[i];
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,btime[i],wtime[i],tatime[i]);
	}
	
	avg_wtime/=i;
	avg_tatime/=i;
	printf("\n\nAverage Waiting Time:%d",avg_wtime);
	printf("\nAverage Turnaround Time:%d",avg_tatime);
}
