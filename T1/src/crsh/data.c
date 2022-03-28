#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include <time.h>


void initList(List * lp)  // Ref: https://www.includehelp.com/ds/singly-linked-list-implementation-in-c.aspx
{
	lp->head = NULL;
	lp->tail = NULL;
}

Node * createNode(int PID, char* name, time_t time_s)
{
	Node * nNode;

	nNode = (Node *) malloc(sizeof(Node) + 1);

	nNode->PID = PID;
    nNode->name = name;
    nNode->time_s = time_s;
	nNode->time_e = -1;
	nNode->next = NULL;

	return nNode;
}

void addAtTail(List * lp, int PID, char* name, time_t time)
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
	printf("\nLIST OF ACTIVE CHILDREN PROCESS OCCURRING\n");
	printf("\n|  PID  | |  Time(s) | | Name |\n");  // AJUSTAR AL FINAL
	while(node != NULL)
	{
		//float time;
		if (node->time_e == -1){
			int status;
			if (waitpid(node->PID, &status, WNOHANG) == 0)
			{
				time_t end_t;
				time(&end_t);
				printf("| %d | |   %.2f   | | %s |\n",node->PID, difftime(end_t, node->time_s), node->name);
			}
		}
		//else{
		//	time = ((double)(node->time_e - node->time_s) / CLOCKS_PER_SEC);  // TIEMPO TOTAL SI TERMINÓ
		//	printf("| %d | | %f | | %s |\n",node->PID, time, node->name);
		//}
		node = node->next;
	}
}

void fixtime(List *lp, int PID)
{
	Node * node;
	if(lp->head == NULL)
	{
		return;
	}
	node = lp->head;
	while(node != NULL)
	{
		if (node->PID == PID)
		{
			if (node->time_e == -1){
				node->time_e = clock();
			}
		}
		node = node->next;
	}
}

//void freeList(List* lp)
//{
//    Node * node;
//	Node * tmp;
//	if(lp->head == NULL)
//ss	{
//		return;
//	}
//	node = lp->head;
//    while (node != NULL)
//    {
//       tmp = node;
//       node = node->next;
//       free(tmp);
//    }
//
//}