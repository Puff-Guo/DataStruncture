#include <stdlib.h>
#include <stdio.h>
#include "OrderTree.h"

//初始化查找二叉树的形式，首先二叉树可以是空，但是空二叉树没有意义，需要有一个根节点，节点的值也必须有意义
//不能随意指定，所以这里设定在初始化查找二叉树时需要指定元素值，返回创建的节点地址作为二叉树
pOrderTree InitOrderTree(Elemtype data)
{
	pOrderTree T = (pOrderTree)malloc(sizeof(OrderTree));

	T->data = data;
	T->lchild = NULL;
	T->rchild = NULL;
	T->parent = NULL;
	return T;
}

//在插入二叉树时只需要判断大小，大的在右，小的在左
//这里的T算是值传递，所以需要return TREE
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

	//最后的点怎么判断是左边还是右边？
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

//删除二叉树时按元素删除
//先查找元素 
//查找二叉树不旋转，重新简单设置左右孩子的顺序保证删除后的查找树依然是有序的，情况如下：
//1 该节点有左右孩子		parent的该子节点为右子树 左子树为右子树的左节点的子树
//a.找到结点p的前驱结点s，把结点s的数据转移到结点p，然后删除结点s，由于结点s为p的左子树中最右的结点
//因而s无右子树，删除结点s可以归结到情况3 
//b.找到结点p的后继结点s，把结点s的数据转移到结点p，然后删除结点s，由于结点s为p的右子树总最左的结点
//因而s无左子树，删除结点s可以归结到情况3
//c.找到p的中序直接前驱s，将p的左子树接到父节点上，将p的右子树接到s的右子树上，然后删除结点p。

//2 只有左孩子/子树			左孩子代替该节点
//3 只有右孩子/子树			右孩子代替该节点
//4 左右都没有/子树			情况如下：


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

//查找元素的节点
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

//前驱节点,按顺序在它前面的数是它的前驱	这里对前驱的理解是否有错？
//1 有左孩子，前驱为左孩子
//2 没有左孩子 且是父节点的右孩子 前驱是父节点
//3 没有左孩子 且是父节点的左孩子 前驱为父节点的父节点直到该父节点有右孩子
//结合图片http://note.youdao.com/noteshare?id=079ab6a620a548c96ab7ed8f7125f159&sub=70B642F038A340E38A2ED0AE7BC288F5
//2 节点的前驱3
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

	while (Temp != NULL && N->lchild == Temp)//父节点有左孩子继续循环
	{
		N = Temp;
		Temp = Temp->parent;
	}
	return Temp;
}

//后继节点 按顺序排在它后面的节点	这里对后继的理解是否有错？
//如果有右孩子，后继是右子树的根节点
//如果没有右子树，且是根节点的左孩子，后继是父节点
//如果没有右子树，且是根节点的右孩子，后继是父节点的某个父节点但该父节点必须有左子书
//结合图片http://note.youdao.com/noteshare?id=079ab6a620a548c96ab7ed8f7125f159&sub=70B642F038A340E38A2ED0AE7BC288F5
//5 节点的前驱6
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

	while (Temp != NULL && N->rchild == Temp)//父节点有右孩子继续循环
	{
		N = Temp;
		Temp = Temp->parent;
	}
	return Temp;
}

//先序遍历
void PreOrder(pOrderTree T)
{
	if (T != NULL)
	{
		printf("%d ",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}

	//printf("\n");调用时用户换行
}

//中序遍历
void InOrder(pOrderTree T)
{
	if (T != NULL)
	{		
		InOrder(T->lchild);
		printf("%d ", T->data);
		InOrder(T->rchild);
	}
}

//后续遍历
void PostOrder(pOrderTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);		
		PostOrder(T->rchild);
		printf("%d ", T->data);
	}
}

//打印树
void PrintTree(pOrderTree T, Elemtype data, int direction)
{
	if (T != NULL)
	{
		if (direction == 0)    // tree是根节点
			printf("%2d is root\n", T->data);
		else                // tree是分支节点
			printf("%2d is %2d's %6s child\n", T->data, data, direction == 1 ? "right" : "left");

		PrintTree(T->lchild, T->data, -1);
		PrintTree(T->rchild, T->data, 1);
	}
}

//最大值
pOrderTree Maxmum(pOrderTree T)
{
	while (T->rchild != NULL)
	{
		T = T->rchild;
	}

	return T;
}

//最小值
pOrderTree Minimum(pOrderTree T)
{
	while (T->lchild != NULL)
	{
		T = T->lchild;
	}

	return T;
}

//销毁查找二叉树
//注意销毁顺序 
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
