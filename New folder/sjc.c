#include<stdio.h>
#include<stdlib.h>
int main() {
    int n;
    printf("Enter the no.of processors\n");
    scanf("%d",&n);
    int t,m,q;
    int pid[20];
    int at[20];
    int bt[20];
    int ct[20];
    int tat[20];
    int wt[20];
    int sum_tat=0;
    int sum_wt=0;
    for(int i=0;i<n;i++)
    {
        printf("Enter the process id\n");
        scanf("%d",&pid[i]);
        printf("Enter the arrival time\n");
        scanf("%d",&at[i]);
        printf("Enter burst time\n");
        scanf("%d",&bt[i]);
    }

    //sorting
    for(int b=0;b<n-1;b++)
    {
        for(int d=0;d<n-1;d++)
        {
            if(at[d]>at[d+1])
            {
                //arrival time sorting
                t=at[d];
                at[d]=at[d+1];
                at[d+1]=t;

                 q=pid[d];
                pid[d]=pid[d+1];
                pid[d+1]=q;

                 m=bt[d];
                bt[d]=bt[d+1];
                bt[d+1]=m;
            }
            else if (at[d]==at[d+1])
            {
                if(bt[d]>bt[d+1])
                {
                    t=at[d];
                at[d]=at[d+1];
                at[d+1]=t;

                 q=pid[d];
                pid[d]=pid[d+1];
                pid[d+1]=q;

                 m=bt[d];
                bt[d]=bt[d+1];
                bt[d+1]=m;
                }
                else if(bt[d]==bt[d+1])
                {
                    if(pid[d]>pid[d+1])
                    {
                        t=at[d];
                        at[d]=at[d+1];
                        at[d+1]=t;

                        q=pid[d];
                        pid[d]=pid[d+1];
                        pid[d+1]=q;

                        m=bt[d];
                        bt[d]=bt[d+1];
                        bt[d+1]=m;
                }
                }
            }
            
        }
    }
    
    ct[0]=at[0]+bt[0];
    for(int k=0;k<n;k++)
    {
        //completion time
        ct[k+1]=ct[k]+bt[k+1];
    
        if(at[k]<=ct[k])
        {           
        for(int b=0;b<n-1;b++)
        {
            for(int d=0;d<n-1;d++)
            {
            
                    t=at[d];
                    at[d]=at[d+1];
                    at[d+1]=t;

                    q=pid[d];
                    pid[d]=pid[d+1];
                    pid[d+1]=q;

                    m=bt[d];
                    bt[d]=bt[d+1];
                    bt[d+1]=m;
                
            }
        }
        }
        }
    
    for(int l=0;l<n;l++)
    {
        //Total completion time
        tat[l]=ct[l]-at[l];
        sum_tat+=tat[l];
    }
    for(int m=0;m<n;m++)
    {
        //waiting time
        wt[m]=tat[m]-bt[m];
        sum_wt+=wt[m];
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int k=0;k<n;k++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[k],at[k],bt[k],ct[k],tat[k],wt[k]);
    }
    float avg_wt= (float)sum_wt/n;
    float avg_tct = (float)sum_tat/n;
    printf("Average waiting time:-\n");
    printf("%f\n",avg_wt); 
    printf("Average total completion time:-\n");
    printf("%f",avg_tct); 
    return 0;
}