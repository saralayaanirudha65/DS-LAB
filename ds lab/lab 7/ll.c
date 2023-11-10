#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertBefore(struct Node* head, int data, int element) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        printf("List is empty. Element not inserted.\n");
        return head;
    }
    if (head->data == element) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data != element) {
        current = current->next;
    }
    if (current->next != NULL) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        printf("Element not found. Element not inserted.\n");
    }
    return head;
}

struct Node* insertAfter(struct Node* head, int data, int element) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    while (current != NULL && current->data != element) {
        current = current->next;
    }
    if (current != NULL) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        printf("Element not found. Element not inserted.\n");
    }
    return head;
}

struct Node* deleteElement(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    } else {
        printf("Element not found. Nothing deleted.\n");
    }
    return head;
}

void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

struct Node* sortList(struct Node* head) {
    if (head == NULL) {
        return head;
    }
    struct Node* current = head;
    struct Node* index = NULL;
    int temp;
    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
    return head;
}

struct Node* deleteAlternateNodes(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
    return head;
}

struct Node* insertSorted(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL || data <= head->data) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position <= 0) {
        printf("Invalid position. Element not inserted.\n");
        return head;
    }
    if (position == 1) {
        newNode->next = head;
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
    current->next = newNode;
    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, data, element, position;

    while (1) {
        printf("\nLinked List Menu:\n");
        printf("1. Insert an element before another element\n");
        printf("2. Insert an element after another element\n");
        printf("3. Delete an element from the list\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert an element in a sorted list\n");
        printf("9. Insert at the beginning\n");
        printf("10. Insert at the end\n");
        printf("11. Insert at a given position\n");
        printf("12. Delete from the beginning\n");
        printf("13. Delete from the end\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter element before which to insert: ");
                scanf("%d", &element);
                head = insertBefore(head, data, element);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter element after which to insert: ");
                scanf("%d", &element);
                head = insertAfter(head, data, element);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                head = deleteElement(head, data);
                break;
            case 4:
                printf("List: ");
                traverseList(head);
                break;
            case 5:
                head = reverseList(head);
                break;
            case 6:
                head = sortList(head);
                break;
            case 7:
                head = deleteAlternateNodes(head);
                break;
            case 8:
                printf("Enter data to insert in sorted order: ");
                scanf("%d", &data);
                head = insertSorted(head, data);
                break;
            case 9:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 10:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 11:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 12:
                head = deleteFromBeginning(head);
                break;
            case 13:
                head = deleteFromEnd(head);
                break;
            case 14:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
