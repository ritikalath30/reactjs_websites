#include<stdio.h>

typedef struct{
int pid,at,bt,ct,tat,wt;
}sjf;

int main()
{
sjf process[10],temp;
int i,j,k,l,n;
float avg_tat=0,avg_wt=0;
printf("Enter no. of processes: ");
scanf("%d",&n);
printf("Enter AT and BT of all processes:\n");
for(i=0;i<n;++i)
{
process[i].pid=i;
scanf("%d %d",&process[i].at,&process[i].bt);
}

for(i=0;i<n-1;++i)
{
for(j=0;j<n-1;++j)
{
if(process[i].at>process[i+1].at)
{
temp=process[i];
process[i]=process[i+1];
process[i+1]=temp;
}
}
}

for(i=0;i<n;++i)
{
for(j=i+1;j<n;++j)
{
if(process[j].at>(process[i].at+process[i].bt))
break;
}
for(k=i+1;k<j-1;++k)
{
for(l=i+1;l<j-1;++l)
{
if(process[l].bt>process[l+1].bt)
{
temp=process[l];
process[l]=process[l+1];
process[l+1]=temp;
}
}
}
}

//further calculation
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
avg_tat+=process[i].tat;
avg_wt+=process[i].wt;
}
avg_tat=avg_tat/n;
avg_wt=avg_wt/n;
printf("PID\tAT\tBT\tCT\tTAT\tWT\t\n");
for(i=0;i<n;++i)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\n",process[i].pid,process[i].at,process[i].bt,process[i].ct,process[i].tat,process[i].wt);
}
printf("Average TAT: %f\nAverage WT: %f\n",avg_tat,avg_wt);
return 0;
}
