#include<stdio.h>
typedef struct
{
int  pid,at,bt,ct,tat,wt;
}non_preemptive;
int main()
{
non_preemptive process[10],temp;
int i,j,n;
{
non_preemptive process[10],temp;
int i,j,n;
printf("Enter no.of processes: ");
scanf("%d",&n);
printf("Enter AT and  BT of all processes:\n");
for(i=0;i<n;i++)
{
process[i].pid=i;
scanf("%d %d",&process[i].at,&process[i].bt);
}
for(j=0;j<n-1;++j)
{
if(process[i].at>process[i+1].at)
{
temp=process[i];
process[i+1]=temp;
}
}
}
for(i=0;i<n;++i)
{
if(i==0)
{
process[i].ct=process[i].at+process[i].bt;
}
else
{
process[i].ct=process[i-1].ct+process[i].bt;
}
process[i].tat=process[i].ct-process[i].at;
process[i].wt=process[i].tat-process[i].bt;
}
printf("PID\tAT\tBT\tCT\tTAT\tTWT\t\n");
for(i=0;i<n;++i)
{
{
printf("%d\t%d\t%d\t%d\t%d\t%d\n",process[i].pid,process[i].at,process[i].bt,process[i].ct,process[i].tat,process[i].wt);
}
int avg1=0,avg2=0;
for(i=0;i<n;++i)
{
avg1=avg1+process[i].tat;
avg2=avg2+process[i].wt;
}
avg1=avg1/n;
avg2=avg2/n;
printf("Average TAT is %d, Average WT is  %d.",avg1,avg2);
return 0;
}
}
