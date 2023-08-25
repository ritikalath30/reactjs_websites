#include<stdio.h>
typedef struct {
    int pid,at,bt,ct,wt,tat;
}preemptive;
int main()
{
    preemptive process[10],temp;
    int i,j,n;
    printf("Enter no.of process:");
    scanf("%d",&n);
    printf("Enter at and bt of the processes");
    for(i=0;i<n;i++)
    {
        process[i].pid=i;
        scanf("%d %d",&process[i].at,&process[i].bt);
    }
    process[0].ct=process[0].bt+process[0].at;
    for(j=0;j<n;j++)
    {
        if(process[i].at==process[i+1].at)
        {
            if(process[i].bt<process[i+1].bt)
            {
                process[i].ct=process[i].ct+process[i].bt;
                if(process[i+1].bt<process[i].ct)
                {
                    process[i].bt=process[i].bt-process[i].at;
                }
            }
        }
        else if (process[i].at<process[i+1].at)
        {
            process[i].ct=process[i].ct+process[i].bt;
            if(process[i].ct>process[i].at)
            {
                process[i].bt=process[i].bt-process[i].at;
            }
        }
    }

}