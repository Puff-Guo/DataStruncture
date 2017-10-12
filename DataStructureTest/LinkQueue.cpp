/*
*	linkQueue.cpp ¡¥±Ì∂”¡–
*	author:puff
*	time:2017-9-19
*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

pLinkQueue InitQueue(void)
{
	QueuePtr Temp = (QueuePtr)malloc(sizeof(Qnode));
	Temp->next = NULL;

	pLinkQueue Q = (pLinkQueue)malloc(sizeof(LinkQueue));
	Q->front = Q->rear = Temp;	
	
	return Q;
}

bool EmptyQueue(pLinkQueue Q)
{
	return Q->front == Q->rear;
}

int LenQueue(pLinkQueue Q)
{
	int len = 0;
	QueuePtr temp = Q->front->next;

	while (temp)
	{
		len++;
		temp =  temp->next;
	}

	return len;
}

void GetFrontData(pLinkQueue Q, Elemtype *data)
{
	if (Q != NULL && Q->front->next != NULL)
	{
		*data = Q->front->data;
	}
}

void InQueue(pLinkQueue Q, Elemtype data)
{
	if (Q != NULL)
	{
		Q->rear->next = (QueuePtr)malloc(sizeof(Qnode));
		Q->rear = Q->rear->next;

		Q->rear->data = data;
		Q->rear->next = NULL;
	}
}

void OutQueue(pLinkQueue Q, Elemtype *data)
{
	if (!EmptyQueue(Q))
	{
		QueuePtr tmp = Q->front->next;

		if (tmp->next != NULL)
		{
			Q->front->next = tmp->next;			
		}
		else
		{
			Q->front->next = NULL;
			Q->rear = Q->front;
		}		

		*data = tmp->data;
		free(tmp);
	}
}


