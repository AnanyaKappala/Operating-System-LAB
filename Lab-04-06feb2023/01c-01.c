#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int pid[n],at[n],bt[n];
    int wt[n],tat[n],rt[n];
    for(i=0;i<n;i++)
    {
        printf("Enter process id, arrival time and burst time for process %d:",i+1);
        scanf("%d%d%d",&pid[i],&at[i],&bt[i]);
        rt[i]=bt[i];
    }
    int t=0;
    for(i=0;i<n;i++)
    {
        t+=bt[i];
        wt[i]=t-at[i]-bt[i];
        tat[i]=t-at[i];
    }
    printf("Process ID\t Arrival Time\t Burst Time\t Waiting Time\t Turn Around Time\t");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t %d\t\t %d\t\t %d\t\t\t %d",pid[i],at[i],bt[i],wt[i],tat[i]);
    }
    int total_wt=0,total_tat=0;
    for(i=0;i<n;i++)
    {
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    printf("\nAverage waiting time: %f",(float)total_wt/n);
    printf("\nAverage turn around time: %f",(float)total_tat/n);
    return 0;
}