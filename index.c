#include<stdio.h>
void main(){
    int files[50],index[50]={0};
    printf("----------INDEXED FILE----------\n");
    while(1){
        int ind,n,ch,flag=0;
        printf("\nEnter the choice \n1) to add file \n2)exit\n");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter the index block");
            scanf("%d",&ind);
            if(files[ind]==1){
                printf("Index Already in Use");
            }
            else{
                files[ind]=1;
                printf("\nEnter the number of blocks nedded");
                scanf("%d",&n);
                printf("\nEnter Block Numbers");
                for(int i=0;i<n;i++){
                    scanf("%d",&index[i]);
                    if(files[index[i]]==1){
                        flag=1;
                    }
                    else{
                        files[index[i]]=1;
                    }
                }
                if(flag==1){
                    printf("Block Already allocated");
                    files[ind]=0;
                }
                else{
                    printf("\n----FILE ALLOCATED----\n");
                    for (int i=0; i<n; i++){
                        printf("%d ------> %d\n", ind, index[i],files[index[i]]);
                    }  
                } 
            }
        }
        else{
            printf("Program Exited !!!!!!!!!!!!!!!");
            break;
        }
    }
}
