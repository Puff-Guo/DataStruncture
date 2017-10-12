/*
*	顺序树
*	author:puff
*	time:2017-10-9
*/

#ifndef H_ORDERTREE_H
#define H_ORDERTREE_H

typedef int Elemtype;

typedef struct BiTnode
{
	Elemtype data;
	BiTnode *lchild, *rchild,*parent;	
}OrderTree, *pOrderTree;

//初始化查找二叉树的形式，首先二叉树可以是空，但是空二叉树没有意义，需要有一个根节点，节点的值也必须有意义
//不能随意指定，所以这里设定在初始化查找二叉树时需要指定元素值，返回创建的节点地址作为二叉树
pOrderTree InitOrderTree(Elemtype data);

//在插入二叉树时只需要判断大小，大的在右，小的在左
pOrderTree InsertOrderTree(pOrderTree T,Elemtype data);

//删除二叉树时按元素删除
void DeleteOrderTree(pOrderTree T,Elemtype data);

//查找元素的节点
pOrderTree RecurSearch(pOrderTree T,Elemtype data);

pOrderTree NoRecurSearch(pOrderTree T, Elemtype data);

//前驱节点
pOrderTree precursor(pOrderTree T, pOrderTree N);

//后继节点
pOrderTree succee(pOrderTree T, pOrderTree N);

//先序遍历
void PreOrder(pOrderTree T);

//中序遍历
void InOrder(pOrderTree T);

//后续遍历
void PostOrder(pOrderTree T);

//打印树
void PrintTree(pOrderTree T,Elemtype data,int direction);

//最大值
pOrderTree Maxmum(pOrderTree T);

//最小值
pOrderTree Minimum(pOrderTree T);

//销毁二叉树
void DestroyTree(pOrderTree T);

#endif

