#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

void insertEnd(struct Node** head, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->prev = (*head)->prev;
        newNode->next = *head;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Empty list.\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != head) {
            printf(" + ");
        }
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    int numTerms1, numTerms2, coefficient, exponent;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &numTerms1);

    printf("Enter the terms of the first polynomial:\n");
    for (int i = 0; i < numTerms1; i++) {
        printf("Coefficient: ");
        scanf("%d", &coefficient);
        printf("Exponent: ");
        scanf("%d", &exponent);
        insertEnd(&poly1, coefficient, exponent);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &numTerms2);

    printf("Enter the terms of the second polynomial:\n");
    for (int i = 0; i < numTerms2; i++) {
        printf("Coefficient: ");
        scanf("%d", &coefficient);
        printf("Exponent: ");
        scanf("%d", &exponent);
        insertEnd(&poly2, coefficient, exponent);
    }

    printf("First Polynomial: ");
    displayList(poly1);
    printf("Second Polynomial: ");
    displayList(poly2);

    // Implement the polynomial multiplication here.

    return 0;
}
