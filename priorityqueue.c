#include<stdio.h>
#include<stdlib.h>
#define size 100
int queue[size];
typedef struct priorityQueue{
    int element;
    int priority;
} PQueue;

PQueue pq[size];
int front =-1,rear=-1;

int isEmpty(){
    return (front==-1)? 1 : 0;
}
int isFull(){
    return (rear==size-1)? 1 : 0;
}

void enqueue(int data,int priority){
    rear++;
    pq[rear].element=data;
    pq[rear].priority=priority;
    if(front==-1)
        front=rear;
    printf("Element Inserted!!!\n");
}

int getHigherPriorityElement(){
    int max=0,index;
    for(int i=front;i<=rear;i++){
        if(pq[i].priority>max){
            max=pq[i].priority;
            index=i;
        }
    }
    return index;
}

int dequeue(){
    int index=getHigherPriorityElement();
    int data=pq[index].element;
    if(index==front && index==rear)
        front=rear=-1;
    else if(index==front)
        front++;
    else{
        for(int i=index;i<rear;i++){
            pq[i]=pq[i+1];
        }
        rear--;
    }
    return data;
}

int peek(){
    int i=getHigherPriorityElement();
    return pq[i].element;
}

void display(){
    printf("Elements of priority queue are: \n");
    for(int i=front;i<=rear;i++){
        printf("Element: %d => Priority: %d\n",pq[i].element,pq[i].priority);
    }
}

int main(){
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice,data,p;
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(isFull())
                    printf("Queue Overflow!!!\n");
                else{
                    printf("Enter element:");
                    scanf("%d",&data);
                    printf("Enter priority:");
                    scanf("%d",&p);
                    enqueue(data,p);
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
                    printf("Element having higher priority is %d\n",peek());
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
