#pragma once
#include "../process/process.h"

typedef struct queue {
    Process *data;
    int size;
    int capacity;
    int front;
    int rear;
}Queue; 


Queue* createQueue(int capacity);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, Process* item);
Process* dequeue(Queue* queue);
Process* front(Queue* queue);
Process* rear(Queue* queue);
void freeQueue(Queue* queue);
