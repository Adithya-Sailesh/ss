#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,req[20],head,total;
    printf("Enter the number of request");
    scanf("%d",&n);
    printf("Enter the requests");
    for(int i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter head");
    scanf("%d",&head);
    for(int i=0;i<n;i++){
        total=total+abs(req[i]-head);
        head=req[i];
    }
    printf("Total Head Movement =%d",total);
}
