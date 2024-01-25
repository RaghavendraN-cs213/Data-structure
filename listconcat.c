#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Function to print the elements of the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to sort the linked list using bubble sort
void sortList(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }

    int swapped, temp;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head_ref;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to reverse a linked list
void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

// Function to concatenate two linked lists
void concatenateLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;
}

int main() {
    int i;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int n, data;

    // Input for the first linked list
    printf("Enter the number of elements for List 1: ");
    scanf("%d", &n);

    printf("Enter the elements for List 1:\n");
    for (i = 0; i < n; ++i) {
        scanf("%d", &data);
        append(&list1, data);
    }

    // Input for the second linked list
    printf("Enter the number of elements for List 2: ");
    scanf("%d", &n);

    printf("Enter the elements for List 2:\n");
    for (i = 0; i < n; ++i) {
        scanf("%d", &data);
        append(&list2, data);
    }

    // Displaying original lists
    printf("\nOriginal List 1: ");
    printList(list1);
    printf("Original List 2: ");
    printList(list2);

    // Sorting the lists
    sortList(&list1);
    sortList(&list2);

    // Displaying sorted lists
    printf("\nSorted List 1: ");
    printList(list1);
    printf("Sorted List 2: ");
    printList(list2);

    // Concatenating the lists
    concatenateLists(&list1, list2);

    // Displaying concatenated list
    printf("\nConcatenated List: ");
    printList(list1);

    // Reversing the concatenated list
    reverseList(&list1);

    // Displaying reversed list
    printf("\nReversed List: ");
    printList(list1);

    return 0;
}
