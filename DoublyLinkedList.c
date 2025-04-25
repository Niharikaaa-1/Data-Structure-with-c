#include<stdio.h>
#include<stdlib.h> 
typedef struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
}Node;

Node* head=NULL;
Node* createNode(int ele){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->prev=NULL;
    newNode->data=ele;
    newNode->next=NULL;
    return newNode;
}
void insertNodeInBeginning(int ele){
    Node* newNode = createNode(ele);
    if(head==NULL)
        head=newNode;
    else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    printf("Node Inserted!!!\n");
}
void insertNodeAtEnd(int ele){
    Node* newNode = createNode(ele);
    if(head==NULL)
        head=newNode;
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
    printf("Node Inserted!!!\n");
}
void insertNodeAtanyPosition(int ele,int pos){
    if(head==NULL)
        printf("List is Empty!!!\n");
    else if(pos==1){
        insertNodeInBeginning(ele);
    }  
    else{
        Node* newNode = createNode(ele);
        Node* temp=head;
        int count=1;
        while(count<pos-1 && temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        if(temp!=NULL && count>1){
            newNode->next=temp->next;
            newNode->prev=temp;
            temp->next->prev=newNode;
            temp->next=newNode;
            printf("Node Inserted!!!\n");
        }
        else{
            printf("Invalid Position!!!\n");
        }
    }
}
void deleteFromBeginning(){
    if(head==NULL)
        printf("List is Empty!!!\n");
    else{
        Node* temp=head;
        head=head->next;
        if(head!=NULL)
            head->prev=NULL;
        free(temp);
        printf("Node Deleted!!\n");
    }
}
void deleteFromEnd(){
    if(head==NULL)
        printf("List is Empty!!!\n");
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        if(temp->prev!=NULL){
            temp->prev->next=NULL;
        }
        else{
            head=NULL;
        }
        free(temp);
        printf("Node Deleted!!!\n");
    }
}
void deleteFromanyPosition(int pos){
    if(head==NULL)
        printf("List is Empty!!!\n");
    else if(pos==1)
        deleteFromBeginning();
    else{
        Node* temp=head;
        int count=1;
        while(count!=pos && temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        if(temp!=NULL && pos>0){
            temp->prev->next=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            free(temp);
            printf("Node Deleted!!!\n");
        }
        else
            printf("Invalid Position!!\n");
    }
}
void search(int ele){
    if(head==NULL)
        printf("List is Empty!!\n");
    else{
        Node* temp=head;
        int i=0;
        while(temp!=NULL){
            i++;
            if(temp->data==ele){
                printf("Found at %d position!!!\n",i);
                return;
            }
            temp=temp->next;
        }
        printf("Not Found!!\n");
    }
}
void display(){
    if(head==NULL)
        printf("List is Empty!!\n");
    else{
        printf("Elements are:\n");
        for(Node* temp=head;temp!=NULL;temp=temp->next){
            printf("%d ",temp->data);
        }
    }
}
int main(){
    while(1){
        printf("---------Doubly Linked List---------\n");
        printf("1.Insert Node in Beginning\n");
        printf("2.Insert Node at End\n");
        printf("3.Insert Node at any position\n");
        printf("4.Delete Node from Beginning\n");
        printf("5.Delete Node from End\n");
        printf("6.Delete Node from any position\n");
        printf("7.Search elemnet in list\n");
        printf("8.Display elements\n");
        printf("9.Exit\n\n");
        int choice,value,pos;
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value:");
                scanf("%d",&value);
                insertNodeInBeginning(value);
                break;
            case 2:
                printf("Enter value:");
                scanf("%d",&value);
                insertNodeAtEnd(value);
                break;
            case 3:
                printf("Enter value:");
                scanf("%d",&value);
                printf("Enter position:");
                scanf("%d",&pos);
                insertNodeAtanyPosition(value,pos);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position:");
                scanf("%d",&pos);
                deleteFromanyPosition(pos);
                break;
            case 7:
                printf("Enter value:");
                scanf("%d",&value);
                search(value);
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!!!!\n");
        }
        printf("\n");
    }
    return 0;
}
