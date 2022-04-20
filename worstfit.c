#include <stdio.h>
int main()
{
    int  block[20], process[20], bno, pno, i, j, temp,highest=0;
    static int b_arr[20], p_arr[20];
    printf("Worst Fit Memory Managment\n\nEnter the number of blocks : ");
    scanf("%d",&bno);
    printf("Enter the size of blocks:\n");
    for(i=1;i<=bno;i++)
    {
        printf("Enter the size of block[%d] : ",i);
        scanf("%d",&block[i]);
    }
    printf("\nEnter the number of processes : ");
    scanf("%d",&pno);
    printf("Enter the size of processes:\n");
    for(i=1;i<=pno;i++){
        printf("Enter the size of process[%d] : ",i);
        scanf("%d",&process[i]);
    }
    for (i = 1; i <= pno; i++)
    {
        for (j = 1; j <= bno; j++)
            if (b_arr[j] != 1)
            {
                temp = block[j] - process[i];
                if (temp >= 0)
                    if (highest<temp)
                    {
                        p_arr[i] = j;
                        highest = temp;
                    }
            }
        b_arr[p_arr[i]] = 1;
        highest=0;
    }
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size");
    for (i = 1; i <= pno; i++)
    {
        printf("\n%d\t\t%d\t\t", i, process[i]);
        if(p_arr[i] == 0)
            printf("Not Allocated");
        else
            printf( "%d\t\t%d", p_arr[i], block[p_arr[i]]);
    }
    printf("\n");
}
