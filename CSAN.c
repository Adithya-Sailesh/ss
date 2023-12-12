//only goes to right side
#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,req[20],head,total=0,size;
    printf("Enter the number of request");
    scanf("%d",&n);
    printf("Enter the requests");
    for(int i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("\nEnter head");
    scanf("%d",&head);
    printf("\nEnter the size");
    scanf("%d",&size);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(req[j]<req[i]){
                int temp=req[i];
                req[i]=req[j];
                req[j]=temp;
            }
        }
    }
    int index;
    for(int i=0;i<n;i++){
        if(head<req[i]){
            index=i;
            break;
        }
    }
    //moving to right
    for(int i=index;i<n;i++){
        total=total+abs(req[i]-head);
        head=req[i];
    }
    total=total+size-head-1;
    total=total+size-1;
    head=0;
    for(int i=0;i<index;i++){
        total=total+abs(req[i]-head);
        head=req[i];
    }
    printf("Total Head Movement =%d",total);
}
