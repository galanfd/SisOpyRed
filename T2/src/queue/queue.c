#include "queue.h"
#include "../process/process.h"


struct Queue* createQueue(int capacity) {  // Ref: https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/?ref=lbp
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->data = (Process*) malloc(capacity * sizeof(Process));
    queue->size = 0;
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

// Ref: Asistido por Copilot

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    printf("%d dequeued from queue\n", item);
    return item;
}

int front(Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->data[queue->front];
}

int rear(Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->data[queue->rear];
}

void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}