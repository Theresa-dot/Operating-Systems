#include <stdio.h>

int main(){
    int m,n;
    printf("Enter no of blocks: ");
    scanf("%d",&m);
    printf("Enter no of processes: ");
    scanf("%d",&n);
    int block[m],process[n],allocation[n];
    for(int i=0;i<m;i++){
        printf("Enter size of block %d: ",i+1);
        scanf("%d",&block[i]);
    }
    for(int i=0;i<n;i++){
        printf("Enter size of process %d: ",i+1);
        scanf("%d",&process[i]);
    }
    for(int i=0;i<n;i++) allocation[i]=-1;
    for(int i=0;i<n;i++){
        int index=-1;
        for(int j=0;j<m;j++){
            if(block[j]>=process[i]){
                if(index==-1) index=j;
                else if(block[j]<block[index]) index=j;
            }
        }
        if(index!=-1){
            allocation[i]=index;
            block[index]-=process[i];
        }
    }
    printf("ProcessNo ProcessSize BlockAlloc\n");
    for(int i=0;i<n;i++){
        if (allocation[i]==-1){
            printf("%d\t%d\tNot allocated\n",i+1,process[i]);
        }
        else{
            printf("%d\t%d\t%d\n",i+1,process[i],allocation[i]+1);
        }
    }
}