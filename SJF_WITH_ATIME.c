#include<stdio.h>
struct sjf{
    int pid;
    int atime;
    int btime;
    int ctime;
    int ttime;
    int wtime;
}p[10],temp;
void main(){
    int n,time=0,remain,finish[10]={0},index,order[10],j=0;
    float tat=0,wt=0;
    printf("-----------------SJF-------------");
    printf("Enter the number of process");
    scanf("%d",&n);
    remain=n;
    for(int i=0;i<n;i++){
        printf("\n Enter the details pid atime btime");
        scanf("%d %d %d",&p[i].pid,&p[i].atime,&p[i].btime);
    }
    while (remain!=0)
    {   
        index=-1;
        for(int i=0;i<n;i++){
            if(finish[i]==0 && p[i].atime<=time){
                if(index==-1){
                    index=i;
                }
                else{
                    if(p[i].btime<p[index].btime){
                        index=i;
                    }
                }
            }
        }
        if(index==-1){
            printf("Hello");
            time++;
        }
        else{
            printf("test1");
            finish[index]=1;
            remain--;
            time=time+p[index].btime;
            order[j++]=p[index].pid;
            p[index].ctime=time;
            p[index].ttime=p[index].ctime-p[index].atime;
            p[index].wtime=p[index].ttime-p[index].btime;
            tat=tat+p[index].ttime;
            wt=wt+p[index].wtime;
        }
    }
    for(int i=0;i<n;i++){
    printf("P%d \t",order[i]);
  } 
    for(int i=0;i<n;i++){
    printf("\n  %d \t %d \t %d \t %d \t %d \t %d \t  \n ",p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].ttime,p[i].wtime);
  } 
    printf("\n  TurnAroundTime %f \n  Waiting Time %f\n",tat,wt);
    printf("\n Average TurnAroundTime %f \n Average Waiting Time %f\n",tat/n,wt/n);
    
}
