/*
*	À≥–Ú∂”¡–
*	author£∫puff
*	time:2017-9-19 
*/

#ifndef H_VECQUEUE_H
#define H_VECQUEUE_H

#define MAXSIZE 100	
typedef int Elemtype;

typedef struct Node
{
	Elemtype data[MAXSIZE];
	int front, rear,count;
}SqQueue,*pSqQueue;

void initQueue(pSqQueue Q);

void InQueue(pSqQueue Q, Elemtype data);

void OutQueue(pSqQueue Q, Elemtype* data);

bool EmptyQueue(pSqQueue Q);

bool FullQueue(pSqQueue Q);

int GetQueueLen(pSqQueue Q);

void GetFrontData(pSqQueue Q, Elemtype* data);

void GetRearData(pSqQueue Q,Elemtype* data);

#endif