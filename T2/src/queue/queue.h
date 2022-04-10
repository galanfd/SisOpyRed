#pragma once

typedef struct queue {
    int *data;
    int size;
    int capacity;
    int front;
    int rear;
}Queue; 


struct Queue* createQueue(int capacity);
int isFull(struct Queue* queue);
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, int item);
int dequeue(struct Queue* queue);
int front(struct Queue* queue);
int rear(struct Queue* queue);
void freeQueue(struct Queue* queue);
