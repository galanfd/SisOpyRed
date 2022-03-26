#pragma once
typedef struct process
{
	int PID;
    char* name;
    float time;
	struct process *  next;
}Node;

typedef struct
{
	Node * head;
	Node * tail;

}List;

void initList(List * lp);
Node * createNode(int PID, char* name, float time);
void addAtTail(List * lp, int PID, char* name, float time);
void printList(List *lp);