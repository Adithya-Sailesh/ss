#include<stdio.h>
#include<stdlib.h>
void main(){
    FILE *f1,*f2;
    int str,j,i;
    char line[50],stradd[10];
    printf("--------------Absolute Loader---------------\n");
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");
    do{
        fscanf(f1,"%s",line);
        if(line[0]=='T'){
                for(int i=2,j=0;i<8;i++,j++){
                        stradd[j]=line[i];
                }
                str=atoi(stradd);
                i=12;
                while(line[i]!='$'){
                    if(line[i]!='^'){
                        printf("00%d \t %c%c \n",str,line[i],line[i+1]);
                        fprintf(f2,"%d \t %c%c",str,line[i],line[i+1]);
                        str++;
                        i=i+2;
                    }
                    else{
                        i=i+1;
                    }

                }
        }
        else if(line[0]=='E'){
            printf("End");
            break;
            
        }
    }while(!feof(f1));
}



*******************************INPUT.TXT***********************
H^SAMPLE^001000^0035
T^001000^0C^001003^071009$
T^002000^03^111111$
E^001000
