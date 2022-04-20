#include<stdio.h>
struct process{

  int pid, priority, btime, wtime,ttime;

}p[10];
void main(){
  
  int n,chart[20];
  float sum_wtime,sum_ttime;
  struct process temp;
  printf("Enter the number of processes:");
  scanf("%d",&n);

  for(int i = 0;i<n;i++){
    printf("\nBurst time for process P%d (in ms):",i+1);
    scanf("%d",&p[i].btime);
    printf("\nPriority for process P%d :",i+1);
    scanf("%d",&p[i].priority);
    p[i].pid = i+1;
  }

  //Sorting the process in ascending order of priority

  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1-i;j++){
      if(p[j].priority > p[j+1].priority){
        temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;
      }
    }
  }
  //Assigning

  printf("\nPRIORITY SCHEDULING");
  printf("\n-----------------------------------------------");
  printf("\nProcess\tB-Time\tPriority\tT-Time\tW-Time");
  printf("\n-----------------------------------------------");

  for(int i=0;i<n;i++){
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
    printf("\nP%d\t%d\t%d\t\t%d\t%d",p[i].pid,p[i].btime,p[i].priority,p[i].ttime,p[i].wtime);
  }
  
  chart[n] =p[n-1].ttime;
  printf("\nAverage waiting time:%f",sum_wtime/n);
  printf("\nAverage turnaround time:%f",sum_ttime/n);
  printf("\n\tGANTT CHART");
  printf("\n---------------------------------------------------------------------------------\n");

  for(int i=0;i<n;i++){
    printf("|\tP%d\t",p[i].pid);
  }
  printf("|\n---------------------------------------------------------------------------------\n");
  for(int i=0;i<=n;i++)
    printf("%d\t\t",chart[i]);
  
}
