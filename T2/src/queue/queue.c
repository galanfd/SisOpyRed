#include "queue.h"
#include "../process/process.h"
#include <stdlib.h>
#include <stdio.h>


int empty = 0;

Queue* createQueue(int capacity, int type) {  // Ref: https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/?ref=lbp
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->data = malloc(capacity * sizeof(Process)); // array of Processes
    queue->size = 0;
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->type = type;
    return queue;
}

// Ref: Asistido por Copilot

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, Process* item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = *item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item->pid);
}

Process* dequeue(Queue* queue) {
    if (isEmpty(queue))
        return NULL;
    Process* item = &queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    printf("%d dequeued from queue\n", item->pid);
    return item;
}

Process* front(Queue* queue) {
    if (isEmpty(queue))
        return NULL;
    return &queue->data[queue->front];
}

Process* rear(Queue* queue) {
    if (isEmpty(queue))
        return NULL;
    return &queue->data[queue->rear];
}
