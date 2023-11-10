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

struct Node* insertFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    return newNode;
}

struct Node* deleteElement(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    struct Node* current = head;
    while (current->data != key && current->next != head) {
        current = current->next;
    }

    if (current->data != key) {
        printf("Element not found. Nothing deleted.\n");
        return head;
    }

    if (current->next == current) {
        free(current);
        return NULL;
    }

    if (current == head) {
        head = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    return head;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf(" (Circular)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nDoubly Linked Circular List Menu:\n");
        printf("1. Insert an element into the front\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertFront(head, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &key);
                head = deleteElement(head, key);
                break;
            case 3:
                printf("Current list: ");
                displayList(head);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
