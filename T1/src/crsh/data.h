#pragma once
typedef struct process
{
	int PID;
    char* name;
    int time;
	struct process *  next;
}Node;

typedef struct
{
	Node * head;
	Node * tail;

}List;

void initList(List * lp);
Node * createNode(int PID, char* name, int time);
void addAtTail(List * lp, int PID, char* name, int time);
void printList(List *lp);