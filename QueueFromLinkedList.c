#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
} *rear = NULL, *front = NULL;       //struct Node* top = NULL;

void enqueue(int val){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL)
        printf("Stack Overflow!!!\n");
    else{
        struct Node* temp=front;
        temp->data=val;
        temp->next=NULL;
        if(front==NULL)
            front=rear=temp;
        else{
            rear->next=temp;
            rear=temp;
        }
        printf("Element Inserted!!!\n");
    }
}
int dequeue(){
    if(front==NULL){
        printf("Queue Underflow!!\n");
        return -1;
    }
    else{
        int val=front->data;
        struct Node* temp=front;
        front=front->next;
        if(front==NULL){
            rear=NULL;
        }
        free(temp);
        return val;
    }
}
int peek(){
    if(front==NULL){
        printf("Queue Underflow!!\n");
        return -1;
    }
    else
        return  front->data;
}
void show(){
    if(front==NULL){
        printf("Queue is Empty!!\n");
    }
    else{
        printf("Queue elements are:\n");
        struct Node *temp=front;
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Show\n");
        printf("5. Exit\n");
        int choice,data;
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value:");
                scanf("%d",&data);
                enqueue(data);
                break;

            case 2:
                data=dequeue();
                if(data!=-1)
                    printf("%d dequeue from Queue",data);
                break;
            
            case 3:
                data=peek();
                if(data!=-1)
                    printf("%d is topmost element of stack",data);
                break;

            case 4:
                show();
                break;

            case 5:
                exit(0);
            default:
                printf("Inavlid choice!!!!\n");
        }
        printf("\n");
        system("pause");
    }
}
