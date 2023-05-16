#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure representing the stack
typedef struct Stack {
    int* data;
    int top;
    int capacity;
} Stack;

// Function to create a new stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(const Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(const Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
bool push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return false;
    }
    stack->data[++stack->top] = element;
    printf("Inserted: %d\n", element);
    return true;
}

// Function to pop an element from the stack
bool pop(Stack* stack, int* element) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return false;
    }
    *element = stack->data[stack->top--];
    printf("Popped: %d\n", *element);
    return true;
}

// Function to get the top element of the stack without removing it
bool top(const Stack* stack, int* element) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return false;
    }
    *element = stack->data[stack->top];
    return true;
}

// Function to deallocate the memory occupied by the stack
void destroyStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

int main() {
    // Usage example
    Stack* stack = createStack(5);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    int topElement;
    if (top(stack, &topElement))
        printf("Top element: %d\n", topElement);

    int poppedElement;
    if (pop(stack, &poppedElement))
        printf("Popped element: %d\n", poppedElement);

    destroyStack(stack);

    return 0;
}
