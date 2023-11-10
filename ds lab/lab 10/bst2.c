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

// Implement in-order traversal iteratively
void inOrderIterative(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    printf("In-Order Traversal (Iterative): ");
    while (1) {
        while (current) {
            stack[++top] = current;
            current = current->left;
        }

        if (top >= 0) {
            current = stack[top--];
            printf("%d ", current->data);
            current = current->right;
        } else
            break;
    }
    printf("\n");
}

// Implement post-order traversal iteratively
void postOrderIterative(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        struct Node* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left)
            stack1[++top1] = current->left;

        if (current->right)
            stack1[++top1] = current->right;
    }

    printf("Post-Order Traversal (Iterative): ");
    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
    printf("\n");
}

// Implement pre-order traversal iteratively
void preOrderIterative(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    printf("Pre-Order Traversal (Iterative): ");
    while (top >= 0) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right)
            stack[++top] = current->right;

        if (current->left)
            stack[++top] = current->left;
    }
    printf("\n");
}

// Function to find the parent of a given element in the binary tree
struct Node* findParent(struct Node* root, int target) {
    if (root == NULL)
        return NULL;

    if ((root->left && root->left->data == target) || (root->right && root->right->data == target))
        return root;

    struct Node* left = findParent(root->left, target);
    struct Node* right = findParent(root->right, target);

    return (left ? left : right);
}

// Function to find the depth of the binary tree
int findDepth(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Function to print ancestors of a given element in the binary tree
void printAncestors(struct Node* root, int target) {
    if (root == NULL)
        return;

    if (root->data == target)
        return;

    if (findParent(root, target)) {
        printf("%d ", root->data);
        printAncestors(findParent(root, target), root->data);
    }
}

// Function to count the number of leaf nodes in a binary tree
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    int leftLeaves = countLeafNodes(root->left);
    int rightLeaves = countLeafNodes(root->right);

    return leftLeaves + rightLeaves;
}

int main() {
    struct Node* root = NULL;

    // Input the binary tree elements
    int n, data;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        if (root == NULL)
            root = createNode(data);
        else {
            struct Node* current = root;
            while (1) {
                if (data < current->data) {
                    if (current->left == NULL) {
                        current->left = createNode(data);
                        break;
                    } else
                        current = current->left;
                } else {
                    if (current->right == NULL) {
                        current->right = createNode(data);
                        break;
                    } else
                        current = current->right;
                }
            }
        }
    }

    int target;
    printf("Enter the target element for finding ancestors: ");
    scanf("%d", &target);

    inOrderIterative(root);
    postOrderIterative(root);
    preOrderIterative(root);

    struct Node* parent = findParent(root, target);
    if (parent)
        printf("Parent of %d: %d\n", target, parent->data);
    else
        printf("Parent of %d not found.\n", target);

    int depth = findDepth(root);
    printf("Depth of the tree: %d\n", depth);

    printf("Ancestors of %d: ", target);
    printAncestors(root, target);
    printf("\n");

    int leaves = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leaves);

    // You can add more tree-related operations here.

    return 0;
}
