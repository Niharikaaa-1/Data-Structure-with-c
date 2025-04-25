#include<stdio.h>
#include<stdlib.h>
#define size 100
int queue[size];
int rear=-1,front=-1;

int isEmpty(){
    return (front==-1)? 1 : 0;
}
int isFull(){
    return (rear==size-1)? 1 : 0;
}
void enqueue(int data){
    queue[++rear]=data;
    if(front==-1)
        front=rear;
    printf("Element Inserted!!!\n");
}
int dequeue(){
    int data=queue[front];
    if(front==rear)
        front=rear=-1;
    else 
        front++;
    return data;
}
int peek(){
    return queue[front];
}
void display(){
    printf("Queue Elements are: \n");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}

int main(){
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice,data;
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(isFull())
                    printf("Queue Overflow!!!\n");
                else{
                    printf("Enter element:");
                    scanf("%d",&data);
                    enqueue(data);
                }
                break;

            case 2:
                if(isEmpty())
                    printf("Queue Underflow!!!\n");
                else{   
                    printf("%d dequeue from the queue\n",dequeue());
                }
                break;
            
            case 3:
                if(isEmpty())
                    printf("Queue is Empty!!!\n");
                else
                    printf("%d is available element in queue's front end",peek());
                break;

            case 4:
                if(isEmpty())
                    printf("Queue is Empty!!!\n");
                else
                    display();
                break;

            case 5:
                exit(0);
        }
        printf("\n");
        system("pause");
    }
}
