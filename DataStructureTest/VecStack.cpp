/*
*	VecStack.cpp À≥–Ú’ª
*	author:puff
*	time:2017-9-18
*/

#include <stdio.h>
#include <stdlib.h>
#include "VecStack.h"

void Init_Stack(pSqStack S)
{
	S->top = -1;
}

bool push_back(pSqStack S, Elemtype data)
{
	bool bRet = false;

	if (S->top < MAXSIZE - 1)
	{		
		S->data[++S->top] = data;

		bRet = true;
	}

	return bRet;
}

bool pop_up(pSqStack S,Elemtype* data)
{
	bool bRet = false;

	if (S->top >= 0)
	{
		S->data[S->top--] = 0;
		bRet = true;
	}

	return bRet;
}

void GetTopStack(pSqStack S, Elemtype *data)
{
	if (S->top >= 0)
	{
		*data = S->data[S->top];
	}
}

bool IsEmptyStack(pSqStack S)
{
	bool bRet = false;

	if (S->top == -1)
	{
		bRet = true;
	}

	return bRet;
}

int GetStackLen(pSqStack S)
{
	return S->top;
}

void ClearStack(pSqStack S)
{
	S->top = 0;
}
