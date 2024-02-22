#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// In-order traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Pre-order traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Post-order traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to deallocate memory used by the nodes in the BST
void deallocateTree(struct Node* root) {
    if (root != NULL) {
        deallocateTree(root->left);
        deallocateTree(root->right);
        free(root);
    }
}

int main() {
    int i;
    struct Node* root = NULL;
    int numElements, element;

    // Take user input for the number of elements
    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &numElements);

    // Take user input for inserting elements into the BST
    printf("Enter %d elements:\n", numElements);
    for (i = 0;i< numElements; ++i) {
        scanf("%d", &element);
        root = insert(root, element);
    }

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Deallocate memory used by the tree nodes
    deallocateTree(root);

    return 0;
}
