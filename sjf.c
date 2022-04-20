#include<stdio.h>

struct process{
int pid, btime, wtime,ttime;
}p[10];
void main(){
int n,chart[20],i,j;
float sum_wtime,sum_ttime;
struct process temp;
printf("Enter the number of processes:");
scanf("%d",&n);
for(int i = 0;i<n;i++){
printf("\nBurst time for process P%d (in ms):",i+1);
scanf("%d",&p[i].btime);
p[i].pid = i+1;
}
//Sorting the process in ascending order of burst time for(i=0;i<n-1;i++){
for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].btime>p[j+1].btime){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
//Assigning
printf("\nSJF SCHEDULING");
printf("\n----------------------------------------");
printf("\nProcess\tBT\tTAT\tWT");
printf("\n----------------------------------------");
for(i=0;i<n;i++){
if(i==0){
p[0].wtime = 0;
p[0].ttime = p[0].btime;
sum_ttime = p[0].ttime;
chart[0] = 0;
}
else{
p[i].wtime = p[i-1].wtime + p[i-1].btime;
p[i].ttime = p[i].btime + p[i].wtime;
chart[i] = p[i].wtime;
sum_wtime += p[i].wtime;
sum_ttime += p[i].ttime;
}
printf("\nP%d\t%d\t%d\t%d",p[i].pid,p[i].btime,p[i].ttime,p[i].wtime);
}
printf("\nAverage waiting time:%f",sum_wtime/n);
printf("\nAverage turnaround time:%f",sum_ttime/n);
chart[n] =p[n-1].ttime;
printf("\n\tGANTT CHART");
printf("\n---------------------------------------------------------------------------------\n"); for(i=0;i<n;i++){
printf("|\tP%d\t",p[i].pid);
}
printf("|\n---------------------------------------------------------------------------------\n"); for(i=0;i<=n;i++){
printf("%d\t\t",chart[i]);
}

}

