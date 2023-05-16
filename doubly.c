#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the middle of the doubly linked list
void insertMiddle(Node* head, int data) {
    if (head == NULL) {
        printf("Invalid list!\n");
        return;
    }

    Node* newNode = createNode(data);
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    newNode->next = slow->next;
    if (slow->next != NULL)
        slow->next->prev = newNode;
    slow->next = newNode;
    newNode->prev = slow;
}

// Function to remove a node from the doubly linked list
void removeNode(Node* head, Node* node) {
    if (head == NULL || node == NULL) {
        printf("Invalid list or node!\n");
        return;
    }

    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;

    free(node);
}

// Function to print the elements of the doubly linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to print the successor and predecessor of a selected node
void printSuccessorAndPredecessor(Node* node) {
    if (node == NULL) {
        printf("Invalid node!\n");
        return;
    }

    if (node->prev != NULL)
        printf("Predecessor: %d\n", node->prev->data);
    else
        printf("No predecessor. The selected node is the head.\n");

    if (node->next != NULL)
        printf("Successor: %d\n", node->next->data);
    else
        printf("No successor. The selected node is the tail.\n");
}

int main() {
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);
    Node* tail = createNode(40);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = tail;
    tail->prev = third;

    printf("Elements in the list: ");
    printList(head);

    insertMiddle(head, 25);
    printf("After inserting 25 at the middle: ");
    printList(head);

    Node* selectedNode = second;
    printf("Successor and Predecessor of selected node (%d):\n", selectedNode->data);
    printSuccessorAndPredecessor(selectedNode);

    removeNode(head, third);
    printf("After removing the third node: ");
    printList(head);

    return 0; 
   } 
   
