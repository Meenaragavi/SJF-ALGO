#include<stdio.h>
int main()
{
    int bt[100],at[100],tat[100],wt[100],temp,p[100],n,ct[100];
    printf("Enter no of process: ");
    scanf("%d",&n);
    printf("Enter the arrival time of the each process: ");
    for(int i=1;i<=n;i++)
    {
        printf("\nEnter the arrival time of the process%d: ",i);
        scanf("%d",&at[i]);
        p[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        printf("\nEnter the burst time of the process%d: ",i);
        scanf("%d",&bt[i]);
    }
    for(int i=1;i<=n;i++)
    {
       for(int j=1;j<=(n-i);j++)
       {
           if(bt[j]>bt[j + 1])
           {
               temp=p[j + 1];
               p[j+1]=p[j];
               p[j]=temp;
               temp=at[j + 1];
               at[j + 1]=at[j];
               at[j]=temp;
               temp=bt[j + 1];
               bt[j + 1]=bt[j];
               bt[j]=temp;
           }
       }
    }
    ct[1]=at[1]+bt[1];
    for(int i=2;i<=n;i++)
    {
        temp=0;
        if(ct[i - 1]<at[i])
        {
            temp=at[i]-ct[i - 1];
        }
        ct[i]=ct[i - 1]+bt[i]+temp;
    }
    
    double tot_t=0,tot_w=0;
    for(int i=1;i<=n;i++)
    {
        tat[i]=ct[i]-at[i];
        tot_t=tot_t+tat[i];
        wt[i]=tat[i]-bt[i];
        tot_w=tot_w+wt[i];
    }
    printf("\n Execution order: ");
    for(int i=1;i<=n;i++)
    {
        printf("\nProcess%d\n\tarrival time = %d\n\tburst time = %d\n\tturn around time = %d\n\twaiting  time = %d\n",p[i],at[i],bt[i],tat[i],wt[i]);
    }
    printf("\nAverage turn around time=%f",tot_t/n);
    printf("\nAverage waiting time=%f",tot_w/n);
}