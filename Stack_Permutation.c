#include<stdio.h>
void permute(char a[],int i ,int s);
void swap(char a[],int x,int y);


int main(){
    int s,i;
    printf("Enter the size of array:");
    scanf("%d",&s);
    char a[s];
    printf("Enter the elements:");
    for(i=0;i<s;i++){
        scanf("%s",&a[i]);
    }
    permute(a,0,s-1);
    return 1;
}
void permute(char a[],int i ,int s){
   int j;
   if(i==s)
        printf("%s\n",a);
   else{
    for(j=i;j<=s;j++){
        swap(a,i,j);
        permute(a,i+1,s);
        swap(a,i,i);
      }
   }
}
void swap(char a[],int x,int y){
    char temp;
    temp=a[x];
    a[x]=a[y];
    a[y]=temp;

}
