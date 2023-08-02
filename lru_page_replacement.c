#include <stdio.h>
#include <stdbool.h>

int main(){
    int n;
    printf("Enter no of frames: ");
    scanf("%d",&n);
    int frames[n];
    printf("Enter no. of pages: ");
    int m;
    scanf("%d",&m);
    printf("Enter pages: ");
    int page_fault=0,index=0;
    for(int i=0;i<m;i++){
        int page;
        scanf("%d",&page);
        bool page_found=false;
        for(int j=0;j<index;j++){
            if(frames[j]==page){
                page_found=true;
                for(int k=j;k<index-1;k++){
                    frames[k]=frames[k+1];
                }
                frames[index-1]=page;
                break;
            }
        }
        if(!page_found){
            page_fault++;
            if(index<n) frames[index++]=page;
            else{
                for(int j=0;j<n-1;j++){
                    frames[j]=frames[j+1];
                }
                frames[n-1]=page;
            }
        }
        
    }
    printf("No of page faults: %d",page_fault);
}