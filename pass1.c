#include<stdio.h>
#include<string.h>
void main(){
    FILE *f1,*f2,*f3,*f4,*f5;
    int LOCCTR,oprnd,sa,o,len;
    char label[20],opcode[20],otp[20],op[20];
    f1=fopen("input.txt","r");
    f3=fopen("symtab.txt","w");
    f4=fopen("output.txt","w");
    f5=fopen("length.txt","w");
    fscanf(f1,"%s %s %d",label,opcode,&oprnd);
    if(strcmp(opcode,"START")==0){
        sa=oprnd;
        LOCCTR=sa;
        printf("\t%s\t%s\t%d\n",label,opcode,oprnd); //   \t=tabe
        fprintf(f4,"\t%s\t%s\t%d\n",label,opcode,oprnd);
    } else
        LOCCTR=0;
    fscanf(f1,"%s%s\n",label,opcode);
    while(!feof(f1)){
        fscanf(f1,"%s",op);
        printf("\n%d\t%s\t%s\t%s\n",LOCCTR,label,opcode,op);
        fprintf(f4,"\n%d\t%s\t%s\t%s\n",LOCCTR,label,opcode,op);
        if(strcmp(label,"-")!=0)
            fprintf(f3,"%d %s\n",LOCCTR,label);
        f2=fopen("optab.txt","r");
        fscanf(f2,"%s%d",otp,&o);
        while(!feof(f2)){
            if(strcmp(opcode,otp)==0){
             LOCCTR=LOCCTR+3;
             break;
            }
            fscanf(f2,"%s%d",otp,&o);
        }
        fclose(f2);
        if(strcmp(opcode,"WORD")==0)
            LOCCTR=LOCCTR+3;
        else if(strcmp(opcode,"RESW")==0){
            oprnd=atoi(op);
            LOCCTR=LOCCTR+(3*oprnd);
        }
        else if(strcmp(opcode,"BYTE")==0){
            if(op[0]=='X')
                LOCCTR=LOCCTR+1;
            else{
                len=strlen(op)-2;
                LOCCTR=LOCCTR+len;
            }
        }
        else if(strcmp(opcode,"RESB")==0){
                oprnd=atoi(op);
                LOCCTR=LOCCTR+oprnd;
        }
        fscanf(f1,"%s%s",label,opcode);
    }
        if(strcmp(opcode,"END")==0){
            printf("\n Program length :%d\n",LOCCTR-sa);
            fprintf(f5,"%d",LOCCTR-sa);

        }
        fclose(f1);
        fclose(f3);
        fclose(f4);
        fclose(f5);
}
