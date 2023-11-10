#include <stdio.h>
#include <stdlib.h>

struct Node {
    int washingMachineID;
    int timeDuration;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int machineID, int duration) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->washingMachineID = machineID;
    newNode->timeDuration = duration;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

void insertEnd(struct Node** head, int machineID, int duration) {
    struct Node* newNode = createNode(machineID, duration);
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
        printf("Machine ID: %d, Time Duration: %d\n", current->washingMachineID, current->timeDuration);
        current = current->next;
    } while (current != head);
}

int main() {
    struct Node* washingMachines = NULL;

    int numMachines, machineID, duration;

    printf("Enter the number of washing machines: ");
    scanf("%d", &numMachines);

    for (int i = 1; i <= numMachines; i++) {
        printf("Enter time duration for machine %d: ", i);
        scanf("%d", &duration);
        insertEnd(&washingMachines, i, duration);
    }

    printf("Washing Machines Queue:\n");
    displayList(washingMachines);

    // Implement the washing machine renting system here.

    return 0;
}
