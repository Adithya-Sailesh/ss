#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,req[20],head,total,size;
    printf("Enter the number of request");
    scanf("%d",&n);
    printf("Enter the requests");
    for(int i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter head");
    scanf("%d",&head);
    printf("\n Enter size");
    scanf("%d",&size);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(req[j]<req[i]){
                int temp;
                temp=req[i];
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
    }int ch;
    printf("ENTER DIRECTION 1for right 2Forleft");
    scanf("%d",&ch);
    if(ch==1){
        for(int i=index;i<n;i++){
                total=total+abs(req[i]-head);
                head=req[i];
            }
            total=total+abs(size-head-1);
            head=size-1;
            for(int i=index;i>=0;i--){
                total=total+abs(req[i]-head);
                head=req[i];
            }
    }
    else if(ch==2){
        for(int i=index-1;i>=0;i--){
            total=total+abs(req[i]-head);
            head=req[i];
        }
        total=total+abs(head-0);
        head=0;
        for(int i=index;i<n;i++){
            total=total+abs(req[i]-head);
            head=req[i];
        }
    }
    printf("Total Head Movement =%d",total);
}
