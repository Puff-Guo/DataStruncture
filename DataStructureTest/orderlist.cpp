/*
*	orderlist.cpp
*	author:puff
*	date:2017-9-7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orderlist.h"

void CreateSqList(pSqList L, int n)
{
	if (NULL !=L && n != 0)
	{
		printf("请输入%d个元素\n",n);
		L->Length = n;

		for (int i = 0; i < L->Length;i++)
		scanf_s("%d", &L->data[i]);
	}
	else
	{
		L->Length = 0;
		memset(L->data,0,MAXSIZE);		
	}
}

void EndInsertSqList(pSqList L, ElemType data, int Index)// 0 <= Index < MAXSIZE
{
	if ( L != NULL && Index == 0 &&  L->Length == 0)
	{
		L->data[L->Length] = data;//空列表插入
	}
	else if (L != NULL && Index >= 0 && Index < L->Length && L->Length < MAXSIZE)
	{
		int Len = 0;

		if (Index == L->Length - 1)//末尾插入
		{
			L->data[L->Length] = data;
		}		
		else 
		{
			for (Len = L->Length; Len > Index + 1; Len--)
				L->data[Len] = L->data[Len - 1];

			L->data[Len] = data;
		}		
	}

	L->Length++;
}

void PreInsertSqList(pSqList L, ElemType data, int Index)
{
	if (L != NULL && Index == 0 && L->Length == 0)
	{
		L->data[L->Length] = data;//空列表插入
	}
	else if (L != NULL && Index >= 0 && Index < L->Length && L->Length < MAXSIZE)
	{
		int Len = 0;

		if (Index == L->Length - 1)//末尾插入
		{
			L->data[L->Length] = data;
		}
		else
		{
			for (Len = L->Length; Len > Index; Len--)
				L->data[Len] = L->data[Len - 1];

			L->data[Len] = data;
		}
	}

	L->Length++;
}

int GetElemIndex(pSqList L, ElemType data)
{
	int iRet = -1;

	if (L != NULL)
	{
		int len = L->Length;
		for (int i = 0; i < len; i++)
		{
			if (L->data[i] == data)
			{
				iRet = i;
				break;
			}				
		}
	}

	return iRet;
}

bool GetElemByIndex(pSqList L, int Index, ElemType *Data)
{
	bool bRet = false;

	if (L != NULL && Index >= 0 && Index < L->Length)
	{
		*Data = L->data[Index];
		bRet = true;
	}

	return bRet;
}

int GetSqListSize(pSqList L)
{
	return L->Length;
}

bool DeleteDataByIndex(pSqList L, int Index)
{
	bool bRet = false;

	if (L != NULL && Index >= 0 && Index < L->Length && L->Length != 0)
	{
		for (int i = Index; i < L->Length; i++)		//这里需要把最后面的数据设置成0，虽然长度减一了
			L->data[i] = L->data[i + 1];
		L->Length--;
		bRet = true;
	}

	return bRet;
}

void DeleteData(pSqList L, ElemType data)
{
	bool bRet = false;
	
	if (L != NULL && L->Length != 0)
	{
		int Index = 0;

		while (Index < L->Length)
		{			
			if (L->data[Index] == data)
			{
				DeleteDataByIndex(L, Index);
			}
			else
			{
				Index++;
			}		
		}
	}		
}

//暂时只给出冒泡排序
void SortSqListDesc(pSqList L)
{
	if (L != NULL && L->Length != 0)
	{
		int len = L->Length;

		for (int i = 0; i < len; i++)
		for (int j = 0; j < len - i -1; j++)
		{
			if (L->data[j] < L->data[j+1])
			{
				ElemType Temp = L->data[j];
				L->data[j] = L->data[j + 1];
				L->data[j + 1] = Temp;
			}
		}				
	}
}

void SortSqListAsc(pSqList L)
{
	if (L != NULL && L->Length != 0)
	{
		int len = L->Length;

		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len - i - 1; j++)
			{
				if (L->data[j] > L->data[j + 1])
				{
					ElemType Temp = L->data[j];
					L->data[j] = L->data[j + 1];
					L->data[j + 1] = Temp;
				}
			}
		}
		
	}
}

void Reverse_SqList(pSqList L)
{
	if (L != NULL && L->Length > 1)
	{
		int len = L->Length;	

		int i = 0;
		int j = len - 1;

		while (i < j)
		{
			ElemType temp = L->data[i];
			L->data[i] = L->data[j];
			L->data[j] = temp;
			i++;
			j--;
		}		
	}
}

void Display_SqList(pSqList L)
{
	if (L != NULL && L->Length != 0)
	{
		int len = L->Length;
		printf("输出n个元素\n");
		for (int i = 0; i < len; i++)
		printf("%d ",L->data[i]);		

		printf("\n");
	}
}

void DbSortSqlistAsc(pSqList L)
{
	
}
