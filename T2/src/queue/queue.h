#pragma once
#include "../process/process.h"

typedef struct queue {
    Process *data;
    int size;
    int capacity;
    int front;
    int rear;
    int type; // 0 for FIFO, 1 for SJF
}Queue; 


Queue* createQueue(int capacity, int type);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, Process* item);
Process* dequeue(Queue* queue);
Process* front(Queue* queue);
Process* rear(Queue* queue);
int BestBurst(Queue* queue);
void freeQueue(Queue* queue);
void BestBurst(Queue* queue;
