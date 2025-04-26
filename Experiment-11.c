#include<stdio.h>
#include<limits.h>
#define MAX 100
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*front=NULL,*rear=NULL;
void enqueue(int value){     
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL)
    printf("Queue Overflow !!!!");
    else{
       temp->data=value;
       temp->next=NULL;
       if(front==NULL)//if queue doesn't contain any node
         
         front= rear =temp;
       else{
           rear->next=temp;
           rear=temp;
       }
    printf("%d inserted in queue!!!\n",value);
    }
   
}
int  dequeue(){     // it will return value that's why int
    if(front==NULL){
        printf("Queue Underflow !!!\n");
        return -1;
    }
    else{
        int val=front->data;
        struct Node* temp=front;
        front=front->next;
       if(front==NULL)
       rear=NULL;
        free(temp);
        return val;
    }
}
int  peek(){     // it will return value that's why int
    if(front==NULL){
        printf("Queue Underflow !!!\n");
        return -1;
    }
    else{
        return front->data;
    }
}
void show(){
    if(front==NULL)
    printf("Stack is empty !!!!\n");
    else{
        printf("Stack Elements are : \n");
        struct Node* temp=front;
        while(temp!=NULL){
  printf("%d\n",temp->data);
  temp=temp->next;
        }
    }
}
int main(){
   system("cls");
    while(1){
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Show\n");
        printf("5.Exit\n");
        int choice,val;
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
         case 1:
       printf("Enter Value : ");
       scanf("%d",&val);
    enqueue(val);
         break;
          case 2:
         val = dequeue();
         if(val!=-1)
         printf("%d isremovefrom the queue\n",val);
         break;
          case 3:
          val= peek();
        if(val!=-1)
         printf("first element of queue is %d\n",val);
         break;
          case 4:
       show();
         break;
          case 5:
        exit(0);
         break;
         default:
         printf("Invalid Choice !!!!!\n");
        }
        printf("\n");
        system("pause"); // without pressing system will not work
 }
return 0;
}

    
