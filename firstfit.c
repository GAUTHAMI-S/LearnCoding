#include<stdio.h>
void main(){
    int i,j,block[10],process[10],pno,bno;
    static int flag[10],pos[10];
    printf("First Fit Memory Management\n\nEnter the number of blocks:");
    scanf("%d",&bno);
    printf("Enter the size of blocks\n");
    for(i=0;i<bno;i++){
        printf("Block[%d]:",i+1);
        scanf("%d",&block[i]);
    }
    printf("Enter the number of blocks:");
    scanf("%d",&pno);
    printf("Enter the size of process\n");
    for(i=0;i<pno;i++){
        printf("Process[%d]:",i+1);
        scanf("%d",&process[i]);
    }
    for(i=0;i<pno;i++){
        for(j=0;j<bno;j++){
            if(flag[j]==0&&block[j]>=process[i]){
                pos[j]=i;
                flag[j]=1;
                break;
            }
        }
    }
    printf("\nblock no\tblock size\tprocess no\tprocess size\n");
    for(i=0;i<bno;i++){
        printf("%d\t\t%d\t\t\t",i+1,block[i]);
        if(flag[i]==1)
            printf("%d\t\t%d\n",pos[i]+1,process[pos[i]]);
        else
            printf("Not Allocated\n");
    }
}
