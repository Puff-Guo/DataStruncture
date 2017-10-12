/*
*	¶þ²æÊ÷
*	author:puff
*	date:2017-9-20
*/

#ifndef H_BINARYTREE_H
#define H_BINARYTREE_H

typedef int Elemtype;

typedef struct BiTnode
{
	Elemtype data;
	BiTnode *lchild, *rchild;
	int lflag, rflag;	
}BinaryTree,*pBinaryTree;

void InitBinaryTree(pBinaryTree T);




#endif