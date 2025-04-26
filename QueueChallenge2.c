#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int queue[n],results[n];
    for(int i=0;i<n;i++){
        scanf("%d",&queue[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(queue[(i+j)%n]>queue[i]){
                results[i]=queue[(i+j)%n];
                break;
            }
            else{
                results[i]=-1;
            }
        }
    }  
    for(int i=0;i<n;i++){
        printf("%d ",results[i]);
    }
    return 0;
}
