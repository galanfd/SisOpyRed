#pragma once
#include <time.h>

typedef struct process
{
	int PID;
    char* name;
    time_t time_s;
	float time_e;
	struct process *  next;
}Node;

typedef struct
{
	Node * head;
	Node * tail;

}List;

void initList(List * lp);
Node * createNode(int PID, char* name, time_t time);
void addAtTail(List * lp, int PID, char* name, float time);
void printList(List *lp);
void fixtime(List *lp, int PID);