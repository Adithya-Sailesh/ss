#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    FILE *f1,*f2,*f3,*f4;
    char label[10],opcode[10],operand[10],code[10],mnemonic[10];
    int loc=0, sa=0,c=0;
    f1=fopen("input.txt","r");
    f2=fopen("opcode.txt","r");
    f3=fopen("symtab.txt","w");
    f4=fopen("inter.txt","w");
    fscanf(f1, "%s %s %s", label, opcode, operand);
    if(strcmp(opcode,"start") == 0){
        sa = atoi(operand);
        loc = sa;
        fprintf(f4,"%d %s %s %s \n", sa, label, opcode, operand);
        fscanf(f1, "%s %s %s", label, opcode, operand);
    }else{
        loc=0;
    }
    while(strcmp(opcode,"end")!=0){
        printf("%s\t%s\t%s\n",label, opcode, operand);
        fprintf(f4, "%d\t%s\t%s\t%s\n", loc, label, opcode, operand);
        if(strcmp(label,"**")!=0){
            fprintf(f3,"%s \t %d \n",label,loc);
        }
        fscanf(f2,"%s %s ",code,mnemonic);
        while(strcmp(code,"end")!=0){
            if(strcmp(opcode,code)==0){
                loc=loc+3;
                break;
            }
            fscanf(f2,"%s %s ",code,mnemonic);
        }
        if(strcmp(opcode,"word")==0){
            loc=loc+atoi(operand);
        }
        else if(strcmp(opcode,"resw")==0){
            loc=loc+ (3*atoi(operand));
        }
        else if(strcmp(opcode,"resb")==0){
            loc=loc+(atoi(operand));
        }
        else if(strcmp(opcode,"byte")==0){
            loc=loc+1;
        }

        fscanf(f1, "%s %s %s", label, opcode, operand);
    }
    printf("length %d",loc-sa);
    fclose(f1);
    fclose(f4);
    fclose(f2);
    fclose(f3);
    return 0;
}


************INPUT.txt****************
  copy start 1000
**   lda    alpha
**   mul    betta
alpha word 2
betta resw 3
gamma byte 2
** end 1000
*********************OPTAB.txt********************
lda 00
mul 5
end
