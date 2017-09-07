/*
*	TestAllMain.cpp
*	author:jack
*	date:2017-9-7 23:49
*/
#include <stdio.h>
#include <stdlib.h>
#include "orderlist.h"

//*	this file main use to test all data structure
void TestOrderList();

int main()
{
	TestOrderList();
	return 0;
}

void TestOrderList()
{
	printf("now test orderlist function !\n");

	SqList List;

	CreateSqList(&List,3);
	Display_SqList(&List);

	printf("now test insert data\n");
	system("pause");
	EndInsertSqList(&List,9,0);
	PreInsertSqList(&List,5,0);
	Display_SqList(&List);

	system("pause");
	EndInsertSqList(&List, 8, List.Length -1);
	Display_SqList(&List);

	system("pause");
	PreInsertSqList(&List, 6, 0);
	Display_SqList(&List);
	printf("the 6 elem's index is d%\n", GetElemIndex(&List,6));


	ElemType Data;
	GetElemByIndex(&List, 3, &Data);
	printf("the 3th elem is %d\n", Data);

	system("pause");
	EndInsertSqList(&List,6,2);
	Display_SqList(&List);

	system("pause");
	PreInsertSqList(&List, 3, 2);
	Display_SqList(&List);

	printf("now test reverse list\n");
	system("pause");
	Reverse_SqList(&List);
	Display_SqList(&List);

	printf("now test sort data\n");
	system("pause");
	SortSqListAsc(&List);
	Display_SqList(&List);

	system("pause");
	SortSqListDesc(&List);
	Display_SqList(&List);

	printf("now test delete data\n");
	system("pause");
	DeleteData(&List,6);
	Display_SqList(&List);

	system("pause");
	DeleteDataByIndex(&List,1);
	Display_SqList(&List);

	system("pause");
	DeleteDataByIndex(&List, List.Length -1);
	Display_SqList(&List);

	system("pause");
	DeleteDataByIndex(&List, 0);
	Display_SqList(&List);
	
	system("pause");

}