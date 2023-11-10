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

struct Node* deleteRear(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    if (tail->prev != NULL) {
        struct Node* newTail = tail->prev;
        free(tail);
        newTail->next = NULL;
        return newTail;
    } else {
        free(tail);
        return NULL;
    }
}

struct Node* insertPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    struct Node* current = head;
    int currentPos = 1;
    while (current != NULL && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }
    if (current == NULL) {
        printf("Position out of bounds. Element not inserted.\n");
        return head;
    }
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

struct Node* deletePosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    if (position == 1) {
        struct Node* newHead = head->next;
        free(head);
        if (newHead != NULL) {
            newHead->prev = NULL;
        }
        return newHead;
    }
    struct Node* current = head;
    int currentPos = 1;
    while (current != NULL && currentPos < position) {
        current = current->next;
        currentPos++;
    }
    if (current == NULL) {
        printf("Position out of bounds. Element not deleted.\n");
        return head;
    }
    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
    return head;
}

struct Node* insertAfter(struct Node* head, int data, int element) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == element) {
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            return head;
        }
        current = current->next;
    }
    printf("Element not found. Element not inserted.\n");
    return head;
}

struct Node* insertBefore(struct Node* head, int data, int element) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == element) {
            newNode->prev = current->prev;
            newNode->next = current;
            if (current->prev != NULL) {
                current->prev->next = newNode;
            } else {
                head = newNode;
            }
            current->prev = newNode;
            return head;
        }
        current = current->next;
    }
    printf("Element not found. Element not inserted.\n");
    return head;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* reverseList(struct Node* head) {
    struct Node* current = head;
    struct Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        head = current;
        current = current->prev;
    }
    return head;
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int choice, data, position, element;

    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert an element at the rear end\n");
        printf("2. Delete an element from the rear end\n");
        printf("3. Insert an element at a given position\n");
        printf("4. Delete an element from a given position\n");
        printf("5. Insert an element after another element\n");
        printf("6. Insert an element before another element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                tail = insertRear(tail, data);
                if (head == NULL) {
                    head = tail;
                }
                break;
            case 2:
                tail = deleteRear(tail);
                if (tail == NULL) {
                    head = NULL;
                }
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertPosition(head, data, position);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deletePosition(head, position);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &element);
                head = insertAfter(head, data, element);
                break;
            case 6:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &element);
                head = insertBefore(head, data, element);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                head = reverseList(head);
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
