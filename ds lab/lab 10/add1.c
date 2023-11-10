#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if two trees are equal
int areTreesEqual(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1->data == root2->data &&
            areTreesEqual(root1->left, root2->left) &&
            areTreesEqual(root1->right, root2->right));
}

// Function to build a binary tree based on user input
struct Node* buildTree() {
    int data;
    struct Node* root = NULL;

    printf("Enter the data for the root node (Enter -1 for an empty tree): ");
    scanf("%d", &data);

    if (data != -1) {
        root = createNode(data);
        printf("Enter the left subtree for node %d:\n", data);
        root->left = buildTree();
        printf("Enter the right subtree for node %d:\n", data);
        root->right = buildTree();
    }

    return root;
}

int main() {
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;

    printf("Enter the first tree:\n");
    root1 = buildTree();

    printf("Enter the second tree:\n");
    root2 = buildTree();

    if (areTreesEqual(root1, root2))
        printf("The two trees are equal.\n");
    else
        printf("The two trees are not equal.\n");

    return 0;
}
