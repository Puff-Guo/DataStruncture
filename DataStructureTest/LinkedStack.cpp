/*
*	LinkedStack.cpp ����ջ
*	author:puff
*	time:2017-9-18 10:35
*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

pLinkStack Init_Stack(void)
{
	pLinkStack S = ( pLinkStack )malloc(sizeof(LinkStack));
	S->Top == NULL;	

	return S;
}

pLinkStack push_back(pLinkStack S, Elemtype data)//�������β�˲��룬������pop����
{
	if (S != NULL)
	{
		pLinkStack tmp = (pLinkStack)malloc(sizeof(linkstack));

		tmp->data = data;
		tmp->Top = S;

		return tmp;
	}	
}

pLinkStack pop_up(pLinkStack S)
{
	pLinkStack tmp = NULL;

	if (S != NULL && S->Top != NULL)
	{
		tmp = S;
		S = S->Top;

		free(tmp);
	}

	return S;
}

void GetopStack(pLinkStack S, Elemtype *data)
{
	if (S != NULL && S->Top != NULL)
	{
		*data = S->data;
	}
}

bool IsEmptyStack(pLinkStack S)
{
	bool bRet = true;

	if (S != NULL && S->Top != NULL)
	{
		bRet = false;
	}

	return bRet;
}

int GetStackLen(pLinkStack S)
{
	int len = 0;

	while (S->Top)
	{
		len++;
		S = S->Top;
	}

	return len;
}

void ClearStack(pLinkStack S)
{
	pLinkStack tmp = NULL;

	while (S)
	{				
		tmp = S;
		S = S->Top;

		free(tmp);		
	}	
}
