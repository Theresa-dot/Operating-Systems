#include <stdio.h>

int main(){
    int m,n;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    int process[n];
    for(int i=0;i<n;i++){
        printf("Enter process size %d: ",i+1);
        scanf("%d",&process[i]);
    }
    printf("Enter no. of blocks: ");
    scanf("%d",&m);
    int block[m];
    for(int i=0;i<m;i++){
        printf("Enter block size %d: ",i+1);
        scanf("%d",&block[i]);
    }
    
    int allocation[n];
    for(int i=0;i<n;i++) allocation[i]=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(block[j]>=process[i]){
                allocation[i]=j;
                block[j]-=process[i];
                break;
            }
        }
    }
    printf("ProcessNo\tProcessSize\tBlockAllocated\n");
    for(int i=0;i<n;i++){
        if (allocation[i]==-1){
            printf("%d\t%d\tNot allocated",i+1,process[i]);
        }
        else{
            printf("%d\t%d\t%d\n",i+1,process[i],allocation[i]+1);
        }
    }
}