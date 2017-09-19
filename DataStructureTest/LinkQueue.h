/*
*	¡¥±Ì∂”¡–
*	author£∫puff
*	time:2017-9-19
*/

#ifndef H_VECQUEUE_H
#define H_VECQUEUE_H

typedef int Elemtype;

typedef struct Qnode
{
	Elemtype data;
	struct Qnode * next;
}Qnode, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue,*pLinkQueue;

pLinkQueue InitQueue(void);

bool EmptyQueue(pLinkQueue Q);

int LenQueue(pLinkQueue Q);

void GetFrontData(pLinkQueue Q,Elemtype *data);

void InQueue(pLinkQueue Q, Elemtype data);

void OutQueue(pLinkQueue Q,Elemtype *data);

bool FullQueue(pLinkQueue Q);

#endif