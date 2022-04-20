#include<stdio.h>
#include<string.h>

void main(){
    FILE *fin,*flen,*fsym,*fop;
    int len,i;
    char add[20],label[20],opcode[20],oprnd[20],start[10],opvalue[20],opword[20],symtab[20],symadd[10];
    fin=fopen("output.txt","r");
    flen=fopen("length.txt","r");
    fsym=fopen("symtab.txt","r");
    fop=fopen("optab.txt","r");
    fscanf(fin,"%s%s%s",label,opcode,oprnd);
    if(strcmp(opcode,"START")==0){
        strcpy(start,oprnd);
        fscanf(flen,"%d",&len);
    }
    printf("H^%s^%s^%d\nT^00%s^",label,start,len,start);
    fscanf(fin,"%s%s%s%s",add,label,opcode,oprnd);
    while(strcmp(opcode,"END")!=0){
        fscanf(fop,"%s%s",opword,opvalue);
        while (!feof(fop)){
            if(strcmp(opcode,opword)==0){
                fscanf(fsym,"%s%s",symadd,symtab);
                while (!feof(fsym)){
                    if(strcmp(oprnd,symtab)==0){
                        printf("%s%s^",opvalue,symadd);
                        break;
                    }
                    fscanf(fsym,"%s%s",symadd,symtab);
                }
                break;
            }
            else
                fscanf(fop,"%s%s",opword,opvalue);
            }
        if(strcmp(opcode,"WORD")==0)
            printf("0000%s^",oprnd);
        else if(strcmp(opcode,"BYTE")==0){
            len=strlen(oprnd);
            for(i=2;i<len;i++)
                printf("%d",oprnd[i]);
            printf("^");
        }
    fscanf(fin,"%s%s%s%s",add,label,opcode,oprnd);
    fseek(fop,SEEK_SET,0);
    }
    printf("\nE^00%s",start);
    fclose(fin);
    fclose(fop);
    fclose(fsym);
    fclose(flen);
}
