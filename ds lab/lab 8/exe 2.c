#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertRear(struct Node* tail, int data) {
    struct Node* newNode = createNode(data);
    if (tail == NULL) {
        return newNode;
    }
    tail->next = newNode;
    newNode->prev = tail;
    return newNode;
}

void concatenateLists(struct Node** X1, struct Node* X2) {
    if (*X1 == NULL) {
        *X1 = X2;
    } else if (X2 != NULL) {
        struct Node* current = *X1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = X2;
        X2->prev = current;
    }
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* X1 = NULL;
    struct Node* X2 = NULL;
    int choice, data;

    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert an element into list X1\n");
        printf("2. Insert an element into list X2\n");
        printf("3. Concatenate X1 and X2\n");
        printf("4. Display X1\n");
        printf("5. Display X2\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for X1: ");
                scanf("%d", &data);
                X1 = insertRear(X1, data);
                break;
            case 2:
                printf("Enter data for X2: ");
                scanf("%d", &data);
                X2 = insertRear(X2, data);
                break;
            case 3:
                concatenateLists(&X1, X2);
                X2 = NULL; // X2 is now empty
                break;
            case 4:
                printf("X1: ");
                displayList(X1);
                break;
            case 5:
                printf("X2: ");
                displayList(X2);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
