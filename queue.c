#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure representing the queue
typedef struct Queue {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// Function to create a new queue
Queue* createQueue(int maxQueueSize) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(maxQueueSize * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = maxQueueSize;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(const Queue* queue) {
    return queue->size == 0;
}

// Function to check if the queue is full
bool isFull(const Queue* queue) {
    return queue->size == queue->capacity;
}

// Function to add an element to the queue (enqueue)
bool enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow!\n");
        return false;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = value;
    queue->size++;
    printf("Enqueued: %d\n", value);
    return true;
}

// Function to remove an element from the queue (dequeue)
bool dequeue(Queue* queue, int* value) {
    if (isEmpty(queue)) {
        printf("Queue underflow!\n");
        return false;
    }
    *value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    printf("Dequeued: %d\n", *value);
    return true;
}

int main() {
    // Usage example
    Queue* queue = createQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    int frontElement;
    if (!isEmpty(queue)) {
        frontElement = queue->data[queue->front];
        printf("Front element: %d\n", frontElement);
    }

    int dequeuedElement;
    if (dequeue(queue, &dequeuedElement))
        printf("Dequeued element: %d\n", dequeuedElement);

    free(queue->data);
    free(queue);

    return 0;
}
