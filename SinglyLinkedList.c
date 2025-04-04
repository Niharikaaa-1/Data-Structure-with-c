#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

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

void DeleteNodeFromBeg() {
    if (head == NULL) {
        printf("List is empty, nothing to delete!\n");
        return;
    }
    Node* temp = head; // Store the current head
    head = head->next; // Move head to the next node
    free(temp); // Free the old head
    printf("Node deleted from the beginning.\n");    
}

void DeleteNodeFromEnd(){
    if (head == NULL) {
        printf("List is empty, nothing to delete!\n");
        return;
    }
    if (head->next == NULL) { // Only one node
        free(head);
        head = NULL; // Set head to NULL
        printf("Node deleted from the end.\n");
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) { // Traverse to the second-to-last node
        temp = temp->next;
    }
    free(temp->next); // Free the last node
    temp->next = NULL; // Set the second-to-last node's next to NULL
    printf("Node deleted from the end.\n");

}

void DeleteFromAnyPosition(int pos){
    if (head == NULL) {
        printf("List is empty, nothing to delete!\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid Position!!!!\n");
        return;
    }
    if (pos == 1) {
        DeleteNodeFromBeg(); // If position is 1, delete from the beginning
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next; // Traverse to the node before the position
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid Position!!!!\n");
        return;
    }

    Node* nodeToDelete = temp->next; // Node to be deleted
    temp->next = nodeToDelete->next; // Bypass the node to be deleted
    free(nodeToDelete); // Free the memory of the deleted node
    printf("Node deleted from position %d.\n", pos);
}

void Search(int val){
    Node* temp = head;
    while (temp != NULL) {
        if(temp->data == val) {
            printf("Element found!!!!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found!!!!\n");
}

void sort() {
    Node* last = NULL;
    for(Node* i = head; i->next != NULL; i=i->next){
        Node* j;
        for(j = head ; j->next != last; j = j->next){
            if(j->data > j->next->data){
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
        last = j;
    }
    printf("List Elements Sorted Successfully!!!!\n");
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
    while(1) {
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
                DeleteNodeFromBeg();
            break;
            case 5:
                DeleteNodeFromEnd();
            break;
            case 6:
                printf("Enter position : ");
                scanf("%d",&pos);
                DeleteFromAnyPosition(pos);
            break;
            case 7:
                printf("Enter value to search : ");
                int val;
                scanf("%d",&val);
                (Search(val));
            break;
            case 8:
                sort();
            break;
            case 9:
                display();
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
