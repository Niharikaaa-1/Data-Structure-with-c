#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* head = NULL;

Node* createNode(int ele) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = NULL;
    return newNode;
}

void InsertNodeInBeg(int ele) {
    Node* newNode = createNode(ele);
    newNode->next = head;
    head = newNode;
    printf("Node Inserted at Beginning!!!\n");
}

void InsertNodeAtEnd(int ele) {
    Node* newNode = createNode(ele);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node Inserted at End!!!\n");
}

void InsertNodeAtAnyPosition(int ele, int pos) {
    if (head == NULL) {
        printf("List is Empty!!!\n");
        return;
    }

    if (pos == 1) {
        InsertNodeInBeg(ele);
        return;
    }

    Node* newNode = createNode(ele);
    Node* temp = head;
    int i = 1;

    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (i == pos - 1) {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node Inserted at Position %d!!!\n", pos);
    } else {
        printf("Invalid Position!!!!\n");
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty !!!\n");
    } else {
        printf("Elements are: ");
        Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    while(1) 
    {
        printf("---------Singly Linked List---------\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Searching in List\n");
        printf("8. Sort Elements\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        int choice, value, pos;
        printf("Enter your choice: ");
        scanf("%d",&choice);
      
        switch (choice)
        {
            case 1:
                printf("Enter Value: ");
                scanf("%d",&value);
                InsertNodeInBeg(value);
            break;
          
            case 2:
                printf("Enter Value: ");
                scanf("%d",&value);
                InsertNodeAtEnd(value);
            break;
          
            case 3:
                printf("Enter Value: ");
                scanf("%d",&value);
                printf("Enter position : ");
                scanf("%d", &pos);
                InsertNodeAtAnyPosition(value, pos);
            break;
          
            case 4:
            break;
          
            case 5:
            break;
          
            case 6:
            break;
          
            case 7:
            break;
          
            case 8:
            break;
          
            case 9:
            break;
          
            case 10:
            exit(0);
            break;
          
            default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
