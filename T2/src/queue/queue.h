#pragma once
#include "../process/process.h"

typedef struct queue {
    int *data;
    int size;
    int capacity;
    int front;
    int rear;
}Queue; 


struct Queue* createQueue(int capacity);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, Process* item);
Process* dequeue(Queue* queue);
int front(Queue* queue);
int rear(Queue* queue);
void freeQueue(Queue* queue);
