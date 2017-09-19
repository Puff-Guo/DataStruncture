/*
*	À≥–Ú’ª
*	author:puff
*	data:2017-9-18 10:13
*/

#ifndef H_VECSTACK_H
#define H_VECSTACK_H

#define MAXSIZE 100
typedef int Elemtype;

typedef struct vecstack
{
	Elemtype data[MAXSIZE];
	int top;
}SqStack,*pSqStack;

void Init_Stack(pSqStack S);

bool push_back(pSqStack S, Elemtype data);

bool pop_up(pSqStack S);

void GetopStack(pSqStack S,Elemtype *data);

bool IsEmptyStack(pSqStack S);

int GetStackLen(pSqStack S);

void ClearStack(pSqStack S);

#endif
