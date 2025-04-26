#include<stdio.h>
#include<limits.h>
#define MAX 100
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}; //*top=NULL;//userdefined variable declared & initialize datatype node
struct Node* top=NULL;
struct Node* createNode(int ele){
    struct  Node* newNode=(struct Node*)malloc(sizeof(struct Node));//pointer ko memeory de rahe hain issliye pointer mein typecasting ki hai
   newNode->data=ele;//newnode ke data field mein element de diya
  newNode->next=NULL;
   return newNode;

}
void push(int value){     // insertion dynamically
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL)
    printf("Stack Overflow !!!!");
    else{
        temp->data=value;
        temp->next=top;
        top=temp;
   printf("Push %d into the stack\n",value);
    }
} 

int  pop(){     // it will return value that's why int
   if(top==NULL){
    printf("Stack Underflow !!!\n");
    return -1;
}
else{
    int val=top->data;
   struct Node*temp=top;
    top=top->next;
    free(temp);
    return val;
}
}
int  peek(){     // it will return value that's why int
    if(top==NULL){
        printf("Stack is empty!!!\n");
        return -1;
    }
    else{
       return top->data;
    }
}
void show(){
    if(top==NULL)
    printf("Stack is empty !!!!\n");
    else{
        printf("Stack Elements are : \n");
        struct Node* temp=top;
        while(temp!=NULL){
  printf("%d\n",temp->data);
  temp=temp->next;
        }
    }
}
int main(){
   system("cls");
    while(1){
        printf("1.Push\n");
        printf("2.Pop\n");
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
    push(val);
         break;
          case 2:
         val = pop();
         if(val!=-1)
         printf("%d is pop from the stack\n",val);
         break;
          case 3:
          val= peek();
        if(val!=-1)
         printf("Top element is %d\n",val);
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

    
