#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node* head=NULL;
Node* createNode(int ele){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=ele;
    newNode->next=NULL;
    return newNode;
}
void insertNodeInBeginning(int ele){
    Node* newNode = createNode(ele);
    if(head==NULL){
        head=newNode;
        newNode->next=newNode;
    }
    else{
        newNode->next=head;
        Node* temp = head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        head=newNode;
    }
    printf("Node Inserted!!!\n");
}
void insertNodeAtEnd(int ele){
    Node* newNode = createNode(ele);
    if(head==NULL){
        head=newNode;
        newNode->next=newNode;
    }
    else{
        Node* temp=head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
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
        while(count<pos-1 && temp->next!=head){
            temp=temp->next;
            count++;
        }
        if(temp->next!=head && count>1){
            newNode->next=temp->next;
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
    else if(head->next==head){
        struct Node *temp=head;
        head=NULL;
        free(temp);
        printf("Node Deleted!!\n");
    }
    else{
        Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        Node* t=head;
        head=head->next;
        temp->next=head;
        free(t);
        printf("Node Deleted!!\n");
    }
}
void deleteFromEnd(){
    if(head==NULL)
        printf("List is Empty!!!\n");
    else if(head->next==head){
        Node* temp=head;
        head=NULL;
        free(temp);
        printf("Node Deleted!!!\n");
    }
    else{
        Node* temp=head;
        while(temp->next->next!=head){
            temp=temp->next;
        }
        Node* t = temp->next;
        temp->next=head;
        free(t);
        printf("Node Deleted!!\n");
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
        while(count<pos-1 && temp->next!=head){
            temp=temp->next;
            count++;
        }
        if(temp->next!=head && pos>0){
            Node *t=temp->next;
            temp->next=temp->next->next;
            free(t);
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
        while(temp->next!=head){
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
        Node* temp=head;
        printf("Elements are:\n");
        while(temp->next!=head){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
int main(){
    while(1){
        printf("----Circular Singly Linked List---------\n");
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
