/* Implement FCFS, SJF, SRTF using c.
   Input: Process id, AT, BT.
   Output:1. Sequence of process execution.
          2. TAT, WT, RT for individual process.
          3.Avg TAT, Avg WT*/
//FCFS
#include <stdio.h>
int main()
{
    int pid[15];
    int bt[15];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter process id of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
    }
    printf("Enter BT of the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    int i, wt[n];
    wt[0]=0;
    for(i=1; i<n; i++)
    {
        wt[i]= bt[i-1]+ wt[i-1];
    }
    printf("Process ID  |   Burst Time  |   Waiting Time  |   Turn Around Time\n");
    float twt=0.0;
    float tat= 0.0;
    for(i=0; i<n; i++)
    {
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", bt[i]+wt[i]);
        printf("\n");
        twt += wt[i];
        tat += (wt[i]+bt[i]);
    }
    float att,awt;
    awt = twt/n;
    att = tat/n;
    printf("Avg. waiting time= %f\n",awt);
    printf("Avg. turnaround time= %f",att);
}