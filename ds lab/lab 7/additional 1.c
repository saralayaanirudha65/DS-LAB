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

struct Node* insertAtEnd(struct Node* head, int data) {
    if (head == NULL) {
        return createNode(data);
    } else {
        head->next = insertAtEnd(head->next, data);
        return head;
    }
}

void traverseList(struct Node* head) {
    if (head == NULL) {
        return;
    } else {
        printf("%d -> ", head->data);
        traverseList(head->next);
    }
}

int main() {
    struct Node* head = NULL;
    int data, numNodes;

    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    printf("Linked List: ");
    traverseList(head);
    printf("NULL\n");

    return 0;
}

