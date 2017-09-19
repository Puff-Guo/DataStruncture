/*
*	singlelist.cpp
*	author:puff
*	date:2017-9-8 21:19
*/
#include <stdio.h>
#include <stdlib.h>
#include "singlelist.h"

//所有的索引pos从0开始
LinkList init_LinkList(void)
{
	//带头节点
	LinkList L = (LinkList)malloc(sizeof(LNode));	
	L->next = NULL;

	return L;
}

LinkList Create_LinkListH(int n)
{
	//实际的排序和输入的排序相反
	Elemtype data;
	LinkList NewNode = NULL;

	LinkList CurNode = NULL;
	LinkList L = (LinkList)malloc(sizeof(LNode));

	L->next = CurNode;	
	printf("please input the data to create linklist!\n");
	
	for (int i = 0; i < n;i++)
	{
		scanf_s("%d",&data);

		NewNode = (LinkList)malloc(sizeof(LNode));
		NewNode->data = data;

		NewNode->next = CurNode;
		CurNode = NewNode;

		L->next = CurNode;
	}
	
	return L;
}

LinkList Create_LinkListT(int n)
{
	//实际的排序和输入的排序相同
	Elemtype data;
	LinkList NewNode = NULL;

	LinkList CurNode = NULL;
	LinkList L = (LinkList)malloc(sizeof(LNode));

	L->next = CurNode;
	CurNode = L;

	printf("please input the data to create linklist!\n");

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &data);

		NewNode = (LinkList)malloc(sizeof(LNode));
		NewNode->data = data;
		NewNode->next = NULL;

		CurNode ->next = NewNode;
		CurNode = NewNode;		
	}

	return L;
}

LinkList GetElemByIndex(LinkList L, int Index)
{
	// 0 < i <= n
	LinkList Ret = NULL;
	
	int i = 0;
	// 0 <= Index < n
	while ( i <= Index && L->next != NULL)
	{		
		i++;
		L = L->next;
	}	

	if (i == Index + 1)
	{
		Ret = L;
	}

	return Ret;
}

LinkList GetIndexByElem(LinkList L, Elemtype data)
{
	LinkList Ret = L->next;

	while (Ret != NULL && Ret->data != data)//适当合并条件，简化表达式
		Ret = Ret->next;

	return Ret;
}

int  GetLenLinkList(LinkList L)
{
	int iRet = 0;

	while (L->next != NULL)
	{
		L = L->next;
		iRet++;
	}

	return iRet;
}

//获取尾节点
LinkList GetTail(LinkList L)
{
	LinkList Tail = NULL;

	while (L->next != NULL)
	{
		Tail = L->next;
		L = L->next;
	}

	return Tail;
}

//获取头节点
LinkList GetHead(LinkList L)
{
	return L->next;
}

void InsertBefore(LinkList L, Elemtype data, int Index)
{
	LinkList temp = GetElemByIndex(L,Index);
	//
	if (Index == 0 && temp != NULL)
	{
		L->next = (LinkList)malloc(sizeof(LNode));
		L->next->data = data;

		L->next->next = temp;
	}
	else if (Index > 0 && temp != NULL)
	{
		LinkList temp2 = GetElemByIndex(L,Index -1);
		temp2->next = (LinkList)malloc(sizeof(LNode));

		temp2->next->data = data;
		temp2->next->next = temp;
	}	
}

void InsertEnd(LinkList L, Elemtype data, int Index)
{
	LinkList temp = GetElemByIndex(L, Index);
	LinkList temp2 = GetElemByIndex(L, Index + 1 );
	
	if (temp != NULL)
	{
		temp->next = (LinkList)malloc(sizeof(LNode));
		temp->next->data = data;

		temp->next->next = temp2;
	}
}

void InsertTail(LinkList L, Elemtype data)
{
	LinkList Tail = NULL;

	do
	L = L->next;
	while (L->next != NULL);

	Tail = L;

	if (Tail == NULL)
	{
		L->next = (LinkList)malloc(sizeof(LNode));
		L->next->data = data;
	}
	else
	{
		Tail = (LinkList)malloc(sizeof(LNode));
		Tail->data = data;
	}
}

void InsertHead(LinkList L, Elemtype data)
{
	LinkList temp = L->next;

	L->next = (LinkList)malloc(sizeof(LNode));
	L->data = data;

	L->next = temp;
}

void ModifyLinkList(LinkList L, int pos, Elemtype data)
{
	LinkList temp = GetElemByIndex(L, pos);	

	if (temp != NULL)
	{
		temp->data = data;
	}
}

void DeleteLinkList(LinkList L, int Index)
{
	LinkList tempcur = GetElemByIndex(L, Index);

	if (tempcur != NULL && Index == 0)
	{
		LinkList tempnext = GetElemByIndex(L, Index + 1);
		L->next = tempnext;

		free(tempcur);
	}
	else if (tempcur != NULL)
	{
		LinkList tempnext = GetElemByIndex(L, Index + 1);
		LinkList temppre = GetElemByIndex(L, Index - 1);

		temppre->next = tempnext;
		free(tempcur);
	}
}

void DeleteHead(LinkList L)
{
	LinkList tempcur = NULL;

	if (L->next != NULL)
	{
		tempcur = L->next;
		L->next = tempcur->next;
		free(tempcur);
	}
}

void DeleteTail(LinkList L)
{
	LinkList Tail = NULL;
	LinkList Pre = NULL;

	while (L->next != NULL)
	{
		Pre = L;
		Tail = L->next;

		L = L->next;
	}

	if (Tail != NULL)
	{
		Pre->next = NULL;
		free(Tail);
	}

}

void DeleteLinkListData(LinkList L, Elemtype data)
{
	LinkList Tempcur = NULL;
	LinkList Temppre = NULL;

	while (L->next != NULL)
	{
		Temppre = L;
		Tempcur = L->next;

		if (Tempcur->data == data)
		{
			Temppre->next = Tempcur->next;
			free(Tempcur);
		}
		else
		{
			L = L->next;
		}		
	}
}

void ClearLinkList(LinkList L)
{
	while (L->next != NULL)
	DeleteHead(L);
}

void Display_LinkList(LinkList L)
{
	while (L->next != NULL)
	{
		printf("%d ", L->next->data);
		L = L->next;
	}

	printf("\n");
}

void SortLinkListDesc(LinkList L)
{
	LinkList TempPre = NULL;
	LinkList TempCur = NULL;
	LinkList TempNext = NULL;

	L = L->next;
	TempPre = L;


	while (L != NULL && L->next != NULL)
	{
		TempCur = L->next;
		TempNext = L->next;
	}	


}

void SortLinkListAsc(LinkList L)
{

}

void QuickSortLinkListDesc(LinkList L)
{

}

void QuickSortLinkListAsc(LinkList L)
{

}

void Reverse_Linklist(LinkList L)
{
	LinkList tempcur = NULL;
	LinkList temppre = NULL;
	LinkList tempnext = NULL;

	if (L->next != NULL)
	{
		temppre = L->next;
		tempcur = temppre->next;
	}

	while (tempcur != NULL)
	{
		tempnext = tempcur->next;
		tempcur->next = temppre;

		temppre = tempcur;
		tempcur = tempnext;
	}

	if (L->next != NULL)
	{
		L->next->next = NULL;
		L->next = temppre;
	}		
}

LinkList MergeTwoOrderLinkList(LinkList FirstList, LinkList SecondList)
{
	LinkList NewHead = NULL;	
	LinkList NewHeadTail = NULL;

	if (FirstList->next == NULL)
	{
		NewHead = SecondList;
	}
	else if (SecondList->next == NULL)
	{
		NewHead = FirstList;
	}
	else
	{
		if (FirstList->next->data < SecondList->next->data)
		{
			NewHead = FirstList;		
			FirstList = FirstList->next;
			NewHead->next = FirstList;
		}
		else
		{
			NewHead = SecondList;
			SecondList = SecondList->next;
			NewHead->next = SecondList;
		}

		NewHeadTail = NewHead->next;

		while (FirstList->next != NULL && SecondList->next != NULL)
		{
			if (FirstList->next->data < SecondList->next->data)
			{
				NewHeadTail->next = FirstList->next;
				FirstList = FirstList->next;
			}
			else
			{
				NewHeadTail->next = SecondList->next;
				SecondList = SecondList->next;
			}

			NewHeadTail = NewHeadTail->next;
		}

		if (FirstList->next != NULL)
		{
			NewHeadTail->next = SecondList;
		}
		else
		{
			NewHeadTail->next = FirstList;
		}
	}

	return NewHead;
}

void MergeTwoLinkList(LinkList HeadList, LinkList SecondList)
{
	LinkList HeadlistTail = GetTail(HeadList);

	if (HeadlistTail != NULL && SecondList->next != NULL)
	{
		HeadlistTail->next = SecondList->next;
	}
	else if (HeadlistTail == NULL)
	{
		HeadList->next = SecondList->next;
	}

	SecondList->next = NULL;
	free(SecondList);
}

void SwopElemPos(LinkList L, int pos1,int pos2)
{
	LinkList temp1 = GetElemByIndex(L,pos1);
	LinkList temp2 = GetElemByIndex(L, pos2);

	if (temp1 != NULL && temp2 != NULL)
	{
		Elemtype temp;

		temp = temp1->data;
		temp1->data = temp2->data;
		temp2->data = temp;
	}
}
