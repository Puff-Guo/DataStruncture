/*
*	TestAllMain.cpp
*	author:jack
*	date:2017-9-7 23:49
*/
#include <stdio.h>
#include <stdlib.h>
#include "orderlist.h"
#include "OrderTree.h"

//*	this file main use to test all data structure
void TestOrderList();
void testordertree(void);

int main()
{
	testordertree();
	system("pause");
	//TestOrderList();
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

void testordertree(void)
{
	int arr[] = { 1, 5, 4, 3, 2, 6 };
	#define TBL_SIZE(a) ((sizeof(a)) / (sizeof(a[0])))
						
	int i, ilen;
	pOrderTree root = InitOrderTree(arr[0]);
		
	printf("== �������: ");
	ilen = TBL_SIZE(arr);
	for (i = 1; i<ilen; i++)
	{
		printf("%d ", arr[i]);
		root = InsertOrderTree(root, arr[i]);
	}
		
	printf("\n== ǰ�����: ");
	PreOrder(root);
		
	printf("\n== �������: ");
	InOrder(root);
		
	printf("\n== �������: ");
	PostOrder(root);
	printf("\n");
		
	printf("== ��Сֵ: %d\n", Minimum(root)->data);
	printf("== ���ֵ: %d\n", Maxmum(root)->data);
	printf("== ������ϸ��Ϣ: \n");
	PrintTree(root, root->data, 0);
		
	printf("\n== ɾ�����ڵ�: %d", arr[3]);
	DeleteOrderTree(root, arr[3]);
		
	printf("\n== �������: ");
	InOrder(root);
	printf("\n");
		
	// ���ٶ�����
	DestroyTree(root);
}
