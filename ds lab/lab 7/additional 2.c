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

struct Node* mergeSortedLists(struct Node* X, struct Node* Y) {
    struct Node* Z = NULL;
    struct Node* ptrX = X;
    struct Node* ptrY = Y;
    struct Node* ptrZ = NULL;

    while (ptrX != NULL && ptrY != NULL) {
        struct Node* newNode;
        if (ptrX->data < ptrY->data) {
            newNode = createNode(ptrX->data);
            ptrX = ptrX->next;
        } else {
            newNode = createNode(ptrY->data);
            ptrY = ptrY->next;
        }

        if (Z == NULL) {
            Z = newNode;
            ptrZ = Z;
        } else {
            ptrZ->next = newNode;
            ptrZ = newNode;
        }
    }

    // Append any remaining nodes in X or Y to Z
    if (ptrX != NULL) {
        if (Z == NULL) {
            Z = ptrX;
        } else {
            ptrZ->next = ptrX;
        }
    }

    if (ptrY != NULL) {
        if (Z == NULL) {
            Z = ptrY;
        } else {
            ptrZ->next = ptrY;
        }
    }

    return Z;
}

void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create two sorted linked lists X and Y
    struct Node* X = createNode(1);
    X->next = createNode(3);
    X->next->next = createNode(5);

    struct Node* Y = createNode(2);
    Y->next = createNode(4);
    Y->next->next = createNode(6);

    // Merge X and Y into Z
    struct Node* Z = mergeSortedLists(X, Y);

    // Print the merged list Z
    printf("Merged List Z: ");
    traverseList(Z);

    return 0;
}
