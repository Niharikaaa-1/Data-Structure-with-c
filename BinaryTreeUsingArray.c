#include<stdio.h>
#include<stdlib.h>
#define max 100
int tree[max];
int size=0;
void init(){
    for(int i=0;i<max;i++){
        tree[i]=-1;
    }
}
void insert(int n){
    for(int i=0;i<n;i++){
        scanf("%d",&tree[size++]);
    }
}
void preorder(int root){
    if(tree[root]==-1)
        return;
    printf("%d ",tree[root]);
    preorder(2*root+1);
    preorder(2*root+2);
}
void inorder(int root){
    if(tree[root]==-1)
        return;
    inorder(2*root+1);
    printf("%d ",tree[root]);
    inorder(2*root+2);
}
void postorder(int root){
    if(tree[root]==-1)
        return;
    postorder(2*root+1);
    postorder(2*root+2);
    printf("%d ",tree[root]);
}
int search(int target){
    for(int i=0;i<size;i++){
        if(tree[i]==target)
            return i;
    }
    return -1;
}
void delete(int value){
    int i=search(value);
    if(i==-1)
        printf("Element not found !!\n");
    else{
        tree[i]=tree[size-1];
        tree[size-1]=-1;
        size--;
        printf("Element deleted!!\n");
    }
}
int main(){
    init();
    int n,choice,val;
    while(1){
        printf("1. Insert\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter value of n:");
                scanf("%d",&n);
                insert(n);
                printf("Inserted!!\n");
                break;
            case 2:
                printf("\n Preorder:");
                preorder(0);
                break;
            case 3:
                printf("\n Inorder:");
                inorder(0);
                break;
            case 4:
                printf("\n Postorder:");
                postorder(0);
                break;
            case 5:
                printf("Enter value:");
                scanf("%d",&val);
                int i=search(val);
                if(i==-1)
                    printf("Not found!!\n");
                else
                    printf("Element found at %d position",i);
                break;
            case 6:
                printf("Enter value:");
                scanf("%d",&val);
                delete(val);
                printf("Deleted!!\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!!\n");

        }
        printf("\n");
    }
    return 0;
}
