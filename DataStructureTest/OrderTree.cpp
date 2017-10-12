#include <stdlib.h>
#include <stdio.h>
#include "OrderTree.h"

//��ʼ�����Ҷ���������ʽ�����ȶ����������ǿգ����ǿն�����û�����壬��Ҫ��һ�����ڵ㣬�ڵ��ֵҲ����������
//��������ָ�������������趨�ڳ�ʼ�����Ҷ�����ʱ��Ҫָ��Ԫ��ֵ�����ش����Ľڵ��ַ��Ϊ������
pOrderTree InitOrderTree(Elemtype data)
{
	pOrderTree T = (pOrderTree)malloc(sizeof(OrderTree));

	T->data = data;
	T->lchild = NULL;
	T->rchild = NULL;
	T->parent = NULL;
	return T;
}

//�ڲ��������ʱֻ��Ҫ�жϴ�С��������ң�С������
//�����T����ֵ���ݣ�������Ҫreturn TREE
pOrderTree InsertOrderTree(pOrderTree T, Elemtype data)
{
	pOrderTree Temp = NULL;
	pOrderTree TempT = T;

	while (TempT != NULL)
	{
		Temp = TempT;

		if (TempT->data > data)
			TempT = TempT->lchild;
		else
			TempT = TempT->rchild;
	}

	//���ĵ���ô�ж�����߻����ұߣ�
	if (Temp->data < data)
	{
		Temp->rchild = (pOrderTree)malloc(sizeof(OrderTree));
		Temp->rchild->data = data;
		Temp->rchild->lchild = NULL;
		Temp->rchild->rchild = NULL;
		Temp->rchild->parent = Temp;
	}
	else
	{
		Temp->lchild = (pOrderTree)malloc(sizeof(OrderTree));
		Temp->lchild->data = data;
		Temp->lchild->lchild = NULL;
		Temp->lchild->rchild = NULL;
		Temp->lchild->parent = Temp;
	}

	return T;
}

//ɾ��������ʱ��Ԫ��ɾ��
//�Ȳ���Ԫ�� 
//���Ҷ���������ת�����¼��������Һ��ӵ�˳��֤ɾ����Ĳ�������Ȼ������ģ�������£�
//1 �ýڵ������Һ���		parent�ĸ��ӽڵ�Ϊ������ ������Ϊ����������ڵ������
//a.�ҵ����p��ǰ�����s���ѽ��s������ת�Ƶ����p��Ȼ��ɾ�����s�����ڽ��sΪp�������������ҵĽ��
//���s����������ɾ�����s���Թ�ᵽ���3 
//b.�ҵ����p�ĺ�̽��s���ѽ��s������ת�Ƶ����p��Ȼ��ɾ�����s�����ڽ��sΪp��������������Ľ��
//���s����������ɾ�����s���Թ�ᵽ���3
//c.�ҵ�p������ֱ��ǰ��s����p���������ӵ����ڵ��ϣ���p���������ӵ�s���������ϣ�Ȼ��ɾ�����p��

//2 ֻ������/����			���Ӵ���ýڵ�
//3 ֻ���Һ���/����			�Һ��Ӵ���ýڵ�
//4 ���Ҷ�û��/����			������£�


void DeleteOrderTree(pOrderTree T, Elemtype data)
{
	pOrderTree Temp1 = NULL;

	Temp1 = NoRecurSearch(T,data);
	//4 CASE
	if (Temp1->lchild == NULL && Temp1->rchild == NULL)
	{
		if (Temp1->data > Temp1->parent->data)
		{
			Temp1->parent->rchild = NULL;
			free(Temp1);
		}
		else
		{
			Temp1->parent->lchild = NULL;
			free(Temp1);
		}
	}
	//2 CASE
	else if (Temp1->lchild != NULL && Temp1->rchild == NULL)
	{
		if (Temp1->data > Temp1->parent->data)
		{
			Temp1->parent->rchild = Temp1->lchild;
			free(Temp1);
		}
		else
		{
			Temp1->parent->lchild = Temp1->lchild;
			free(Temp1);
		}
	}
	//3 CASE
	else if (Temp1->lchild == NULL && Temp1->rchild != NULL)
	{
		if (Temp1->data > Temp1->parent->data)
		{
			Temp1->parent->rchild = Temp1->rchild;
			free(Temp1);
		}
		else
		{
			Temp1->parent->lchild = Temp1->rchild;
			free(Temp1);
		}
	}
	//1 CASE
	else
	{
		/*
		//A:
		{
			pOrderTree Temp2 = NULL;

			Temp2 = precursor(T, Temp1);

			Temp1->data = Temp2->data;

			if (Temp2->data > Temp2->parent->data)
			{
				Temp2->parent->rchild = Temp2->rchild;				
			}
			else
			{
				Temp2->parent->lchild = Temp2->rchild;				
			}

			free(Temp2);

		}

		//B:
		{
			pOrderTree Temp2 = NULL;

			Temp2 = succee(T, Temp1);

			Temp1->data = Temp2->data;

			if (Temp2->data > Temp2->parent->data)
			{
				Temp2->parent->rchild = Temp2->lchild;
			}
			else
			{
				Temp2->parent->lchild = Temp2->lchild;
			}

			free(Temp2);
		}
		*/

		//C:
		pOrderTree Temp2 = NULL;

		Temp2 = precursor(T, Temp1);

		if (Temp1->data > Temp1->parent->data)
		{
			Temp1->parent->rchild = Temp1->lchild;					
		}
		else
		{
			Temp1->parent->lchild = Temp1->lchild;			
		}
		
		Temp2->rchild = Temp1->rchild;
		free(Temp1);
	}
}

//����Ԫ�صĽڵ�
pOrderTree RecurSearch(pOrderTree T, Elemtype data)
{	
	if (T->data == data)
	{
		return T;
	}
	else if (T->data > data)
	{
		return RecurSearch(T->lchild, data);
	}
	else
	{
		return RecurSearch(T->rchild, data);
	}		
}

pOrderTree NoRecurSearch(pOrderTree T, Elemtype data)
{
	while (T != NULL && T->data != data)
	{
		if (T->data > data)
			T = T->lchild;
		else
			T = T->rchild;
	}

	return T;
}

//ǰ���ڵ�,��˳������ǰ�����������ǰ��	�����ǰ��������Ƿ��д�
//1 �����ӣ�ǰ��Ϊ����
//2 û������ ���Ǹ��ڵ���Һ��� ǰ���Ǹ��ڵ�
//3 û������ ���Ǹ��ڵ������ ǰ��Ϊ���ڵ�ĸ��ڵ�ֱ���ø��ڵ����Һ���
//���ͼƬhttp://note.youdao.com/noteshare?id=079ab6a620a548c96ab7ed8f7125f159&sub=70B642F038A340E38A2ED0AE7BC288F5
//2 �ڵ��ǰ��3
pOrderTree precursor(pOrderTree T, pOrderTree N)
{
	//1 case
	if (N->lchild != NULL)
		return N->lchild;
	/*
	//2 case
	else if (N->data > N->parent->data)
	{
		return N->parent;
	}
	//3 case
	else if (N->data < N->parent->data)
	{
		pOrderTree Temp = N->parent;

		while (Temp != NULL && N->lchild == Temp)
		{
			N = Temp;
			Temp = Temp->parent;
		}
		return Temp;
	}
	*/

	//2 case and 3 case union
	pOrderTree Temp = N->parent;

	while (Temp != NULL && N->lchild == Temp)//���ڵ������Ӽ���ѭ��
	{
		N = Temp;
		Temp = Temp->parent;
	}
	return Temp;
}

//��̽ڵ� ��˳������������Ľڵ�	����Ժ�̵�����Ƿ��д�
//������Һ��ӣ�������������ĸ��ڵ�
//���û�������������Ǹ��ڵ�����ӣ�����Ǹ��ڵ�
//���û�������������Ǹ��ڵ���Һ��ӣ�����Ǹ��ڵ��ĳ�����ڵ㵫�ø��ڵ������������
//���ͼƬhttp://note.youdao.com/noteshare?id=079ab6a620a548c96ab7ed8f7125f159&sub=70B642F038A340E38A2ED0AE7BC288F5
//5 �ڵ��ǰ��6
pOrderTree succee(pOrderTree T,pOrderTree N)
{
	//1 case
	if (N->rchild != NULL)
		return N->rchild;
	/*
	//2 case
	else if (N->data > N->parent->data)
	{
	return N->parent;
	}
	//3 case
	else if (N->data < N->parent->data)
	{
	pOrderTree Temp = N->parent;

	while (Temp != NULL && N->rchild == Temp)
	{
	N = Temp;
	Temp = Temp->parent;
	}
	return Temp;
	}
	*/

	//2 case and 3 case union
	pOrderTree Temp = N->parent;

	while (Temp != NULL && N->rchild == Temp)//���ڵ����Һ��Ӽ���ѭ��
	{
		N = Temp;
		Temp = Temp->parent;
	}
	return Temp;
}

//�������
void PreOrder(pOrderTree T)
{
	if (T != NULL)
	{
		printf("%d ",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}

	//printf("\n");����ʱ�û�����
}

//�������
void InOrder(pOrderTree T)
{
	if (T != NULL)
	{		
		InOrder(T->lchild);
		printf("%d ", T->data);
		InOrder(T->rchild);
	}
}

//��������
void PostOrder(pOrderTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);		
		PostOrder(T->rchild);
		printf("%d ", T->data);
	}
}

//��ӡ��
void PrintTree(pOrderTree T, Elemtype data, int direction)
{
	if (T != NULL)
	{
		if (direction == 0)    // tree�Ǹ��ڵ�
			printf("%2d is root\n", T->data);
		else                // tree�Ƿ�֧�ڵ�
			printf("%2d is %2d's %6s child\n", T->data, data, direction == 1 ? "right" : "left");

		PrintTree(T->lchild, T->data, -1);
		PrintTree(T->rchild, T->data, 1);
	}
}

//���ֵ
pOrderTree Maxmum(pOrderTree T)
{
	while (T->rchild != NULL)
	{
		T = T->rchild;
	}

	return T;
}

//��Сֵ
pOrderTree Minimum(pOrderTree T)
{
	while (T->lchild != NULL)
	{
		T = T->lchild;
	}

	return T;
}

//���ٲ��Ҷ�����
//ע������˳�� 
void DestroyTree(pOrderTree T)
{
	if (T == NULL)
		return;
	
	if (T->lchild != NULL)
	DestroyTree(T->lchild);

	if (T->rchild != NULL)
	DestroyTree(T->rchild);
	
	free(T);	
}
