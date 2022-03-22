#include <stdio.h>
#include <stdlib.h>
#include "data.h"


void initList(List * lp)  // Ref: https://www.includehelp.com/ds/singly-linked-list-implementation-in-c.aspx
{
	lp->head = NULL;
	lp->tail = NULL;
}

Node * createNode(int PID, char* name, int time)
{
	Node * nNode;

	nNode = (Node *) malloc(sizeof(Node));

	nNode->PID = PID;
    nNode->name = name;
    nNode->time = time;
	nNode->next = NULL;

	return nNode;
}

void addAtTail(List * lp, int PID, char* name, int time)
{
	Node * node;
	node = createNode(PID, name, time);
	if(lp->head == NULL)
	{
		lp->head = node;
		lp->tail = node;
	}
	else
	{
		lp->tail->next  = node;
		lp->tail = lp->tail->next;
	}		
}

void printList(List *lp)
{
	Node * node;
	if(lp->head == NULL)
	{
		printf("\nEmpty List");  // VERIFICAR SI ESTO PUEDE PASAR O NO
		return;
	}
	node = lp->head;
	printf("\n| PID | | Time | | Name |\n");  // AJUSTAR AL FINAL
	while(node != NULL)
	{
		printf("| %d | | %d | | %s |\n",node->PID, node->time, node->name);
		node = node->next;
	}
}