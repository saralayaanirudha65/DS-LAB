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

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* getUnion(struct Node* list1, struct Node* list2) {
    struct Node* unionList = NULL;
    struct Node* current = list1;

    // Add all elements from the first list to the union list
    while (current != NULL) {
        insertAtEnd(&unionList, current->data);
        current = current->next;
    }

    // Add elements from the second list to the union list if they are not already present
    current = list2;
    while (current != NULL) {
        struct Node* temp = unionList;
        int exists = 0;
        while (temp != NULL) {
            if (temp->data == current->data) {
                exists = 1;
                break;
            }
            temp = temp->next;
        }
        if (!exists) {
            insertAtEnd(&unionList, current->data);
        }
        current = current->next;
    }

    return unionList;
}

struct Node* getIntersection(struct Node* list1, struct Node* list2) {
    struct Node* intersection = NULL;
    struct Node* current = list1;

    // Add elements from the first list to the intersection list if they are also in the second list
    while (current != NULL) {
        struct Node* temp = list2;
        while (temp != NULL) {
            if (temp->data == current->data) {
                insertAtEnd(&intersection, current->data);
                break;
            }
            temp = temp->next;
        }
        current = current->next;
    }

    return intersection;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* unionList = NULL;
    struct Node* intersection = NULL;
    int data, num1, num2;

    printf("Enter the number of elements for list 1: ");
    scanf("%d", &num1);
    printf("Enter elements for list 1:\n");
    for (int i = 0; i < num1; i++) {
        scanf("%d", &data);
        insertAtEnd(&list1, data);
    }

    printf("Enter the number of elements for list 2: ");
    scanf("%d", &num2);
    printf("Enter elements for list 2:\n");
    for (int i = 0; i < num2; i++) {
        scanf("%d", &data);
        insertAtEnd(&list2, data);
    }

    printf("List 1: ");
    traverseList(list1);
    printf("List 2: ");
    traverseList(list2);

    unionList = getUnion(list1, list2);
    intersection = getIntersection(list1, list2);

    printf("Union: ");
    traverseList(unionList);
    printf("Intersection: ");
    traverseList(intersection);

    return 0;
}

