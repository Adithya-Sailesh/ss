#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    printf("---------------------RELOACTING LOADER-------------------\n");
    int i,j,hexadd,start;
    char line[50],add[50];
    FILE *f1;
    printf("Enter the new address");
    scanf("%x",&start);
    f1=fopen("input.txt","r");
    do{
        fscanf(f1,"%s",line);
        if(line[0]=='T'){
            for(i=1,j=0;i<=6;i++,j++){
                add[j]=line[i];
            }add[j]='\0';
            sscanf(add,"%x",&hexadd);
            hexadd=hexadd+start;
            i=9;
            while (line[i]!='$')
            {
                printf("00%x \t %c%c \n",hexadd,line[i],line[i+1]);
                hexadd++;
                i=i+2;
            }
            
        }
        else if(line[0]=='E'){
            printf("End");
            break;
        }
    }while(!feof(f1));
    fclose(f1);
}
