/*
*	¡¥±Ì’ª
*	author:puff
*	data:2017-9-18 10:29
*/

#ifndef H_LINKSTACK_H
#define H_LINKSTACK_H

typedef int Elemtype;

typedef struct linkstack
{
	Elemtype data;
	linkstack *Top;	
}LinkStack, *pLinkStack;

pLinkStack Init_Stack(void);

pLinkStack push_back(Elemtype data);

pLinkStack pop_up(pLinkStack S);

void GetopStack(pLinkStack Stack, Elemtype *data);

bool IsEmptyStack(pLinkStack Stack);

int GetStackLen(pLinkStack stack);

void ClearStack(pLinkStack stack);

#endif
