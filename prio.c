#include<stdio.h>
#include<stdlib.h>
struct fcfs{
    int pid;
    int atime;
    int prio;
    int btime;
    int ctime;
    int ttime;
    int wtime;
}p[10];
void main(){
    int n,finish[10]={0},remain,index,time=0;
    float tat,wt,atat,awt;
    printf("---------------priority-------------\n");
    printf("Entert the number of process");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Enter the arrival time ");
        scanf("%d",&p[i].atime);
        printf("Enter the burst time ");
        scanf("%d",&p[i].btime);
        printf("Enter the priority ");
        scanf("%d",&p[i].prio);
    }
    remain=n;
    while(remain!=0){
        index=-1;
        for(int i=0;i<n;i++){
            if(p[i].atime<=time && finish[i]==0){
                if(index==-1){
                    index=i;
                }
                else{
                    if(p[i].prio<p[index].prio){
                        index=i;
                    }
                }
            }
        }
        if(index==-1){
            time=time+1;
        }
        else{
            finish[index]=1;
            remain=remain-1;
            time=time+p[index].btime;
            p[index].ctime=time;
            p[index].ttime=p[index].ctime-p[index].atime;
            p[index].wtime=p[index].ttime-p[index].btime;
            tat=tat+p[index].ttime;
            wt=wt+p[index].wtime;
        }

    }
     printf("total tat =%d",tat);
     
}
