/*
*	VecQueue.cpp À≥–Ú∂”¡–
*	author:puff
*	time:2017-9-19
*/

#include <stdio.h>
#include <stdlib.h>
#include "VecQueue.h"

void initQueue(pSqQueue Q)
{
	Q->front = Q->rear = Q->count = 0;
}

void InQueue(pSqQueue Q, Elemtype data)
{
	if (!FullQueue(Q))
	{
		Q->data[Q->rear];
		Q->rear = (Q->rear + 1) % MAXSIZE;
		Q->count++;
	}
}

void OutQueue(pSqQueue Q, Elemtype *data)
{
	if (!EmptyQueue(Q))
	{
		*data = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAXSIZE;
		Q->count--;
	}
}

bool EmptyQueue(pSqQueue Q)
{
	return (Q->count == 0);
}

bool FullQueue(pSqQueue Q)
{
	return (Q->count == MAXSIZE);
}

int GetQueueLen(pSqQueue Q)
{
	return Q->count;
}

void GetFrontData(pSqQueue Q, Elemtype* data)
{
	if (!EmptyQueue(Q))
	{
		*data = Q->data[Q->front];
	}
}

void GetRearData(pSqQueue Q, Elemtype* data)
{
	if (!EmptyQueue(Q))
	{
		if (Q->rear == 0)
		{
			*data = MAXSIZE - 1;
		}
		else
		{
			*data = Q->data[Q->rear - 1];
		}		
	}
}
