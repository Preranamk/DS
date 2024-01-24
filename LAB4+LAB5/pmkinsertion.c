#include<stdio.h>

#include<stdlib.h>



struct Node

{

    int data;

    struct Node* next;

};



struct Node* createNode(int value){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){

        printf("Memory allocation failed\n");

        exit(1);

    }

    newNode->data = value;

    newNode->next = NULL;

    return newNode;

}



struct Node* insertAtBeginning(struct Node* head, int value){

    struct Node* newNode = createNode(value);

    newNode->next = head;

    return newNode;

}



struct Node* insertAtAnyPos(struct Node* head, int value, int pos){

    struct Node* newNode = createNode(value);

    struct Node* temp = head;



    if(pos == 1){

        newNode->next = head;

        return newNode;

    }



    for(int i = 1; i < pos - 1; i++){

        temp = temp->next;

    }



    newNode->next = temp->next;

    temp->next = newNode;

    return head;

}



struct Node* insertAtEnd(struct Node* head, int value){

    struct Node* newNode = createNode(value);



    if(head == NULL){

        return newNode;

    }



    struct Node* temp = head;

    while(temp->next != NULL){

        temp = temp->next;

    }



    temp->next = newNode;

    return head;

}



void displayList(struct Node* head){

    struct Node* temp = head;

    while(temp != NULL){

        printf("%d -> ", temp->data);

        temp = temp->next;

    }

    printf("NULL\n");

}



int main(){

    struct Node* head = NULL;

    int choice, value, pos;



    while(1){

        printf("1. Insert at end\n");

        printf("2. Insert at beginning\n");

        printf("3. Insert at any position\n");

        printf("4. Display List\n");

        printf("5. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);



        switch(choice){

            case 1:

                printf("Enter the value to be inserted: ");

                scanf("%d", &value);

                head = insertAtEnd(head, value);

                break;



            case 2:

                printf("Enter the value to be inserted: ");

                scanf("%d", &value);

                head = insertAtBeginning(head, value);

                break;



            case 3:

                printf("Enter the value to be inserted: ");

                scanf("%d", &value);

                printf("Enter the position at which to insert: ");

                scanf("%d", &pos);

                head = insertAtAnyPos(head, value, pos);

                break;



            case 4:

                displayList(head);

                break;



            case 5:

                exit(0);



            default:

                printf("Invalid choice. Please try again.\n");

        }

    }



    return 0;

}
