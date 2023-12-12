#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    printf("----------------ABSOLUTE LOADER ----------------\n");
    FILE *f1;
    int i,j,hexadd;
    char line[50],add[10];
    f1=fopen("input.txt","r");
    fscanf(f1,"%s",line);
    printf("%s \n",line);
    do{
        fscanf(f1,"%s",line);
        if(line[0]=='T'){
            for(i=1,j=0;i<=6;i++,j++){
                add[j]=line[i];
            }add[j]='\0';
        sscanf(add,"%x",&hexadd);
        i=9;
        while(line[i]!='$'){
            printf("00%x \t %d%d \n",hexadd,line[i],line[i+1]);
            hexadd++;
            i=i+2;
        }
        }
        else if(line[0]=='E'){
            printf("end");
            break;
        }
    }while(!feof(f1));
    fclose(f1);
}

