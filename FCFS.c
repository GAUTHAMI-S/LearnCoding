##include<stdio.h>
struct process{
    int pid, at,bt,et,ft,tat,wt;        //process id=pid   arival time burst time waiting time turnaround time
}p[10];
void main(){
    struct process temp;
    int size,time = 0,i,j;
    float sum_tat = 0,sum_wt =0;
    printf("Enter the number of processes:");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("\nEnter the process id:");
        scanf("%d",&p[i].pid);
        printf("\nEnter the arrival time:");
        scanf("%d",&p[i].at);
        printf("\nEnter the burst time:");
        scanf("%d",&p[i].bt);
    }
    //Sorting the processes in ascending arrival time struct process temp;
    for(i=0 ; i<size-1 ; i++){
        for(j=0 ; j<size-i-1 ; j++){
            if(p[j].at> p[j+1].at){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    printf("\nPid\tA.T\tB.T\tE.T\tF.T\tTAT\tW.T");
    printf("\n---------------------------------------------------------------");
    for(i=0; i<size;){
        if(p[i].at <= time){
            p[i].et = time;
            p[i].wt = time - p[i].at;
            p[i].tat = p[i].wt + p[i].bt;
            time += p[i].bt;
            p[i].ft = time;
            sum_tat += p[i].tat;
            sum_wt += p[i].wt;
            printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].at, p[i].bt,p[i].et,p[i].ft,p[i].tat,p[i].wt);
            i++;
        }
        else
            time++;
    }
    printf("\n---------------------------------------------------------------");
    printf("\nAverage Turnaround time:%f",sum_tat/size);
    printf("\nAverage waiting time:%f",sum_wt/size);
    printf("\n---------------------------------------------------------------");
    printf("\n\tGANTT CHART");
    printf("\n-------------------------------------------------------------\n"); //display processes in gantt chart
    i=0;
    for(j=0;j<=p[size-1].ft;j++){
        if(j == p[i].et){
        printf("|P%d\t",p[i].pid);
        }
        else if(j == p[i+1].et && j == p[i].ft){
        printf("|P%d\t",p[i+1].pid);
        i++;
        }
        else if(j == p[i].ft){
        printf("|\t");
        i++;
        }
        else
        printf(" ");
    }
    // display time in gantt CHART
    printf("\n-------------------------------------------------------------\n"); i=0;
    for(j=0;j<=p[size-1].ft;j++){
        if(j == p[i].et){
        printf("%d \t",j);
        }
        else if(j == p[i+1].et && j == p[i].ft){
        printf("%d \t",j);
        i++;
        }
        else if(j == p[i].ft){
        printf("%d\t",j);
        i++;
        }
        else
        printf(" ");
    }
}
