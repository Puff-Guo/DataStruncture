/*
*	˳����
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

//��ʼ�����Ҷ���������ʽ�����ȶ����������ǿգ����ǿն�����û�����壬��Ҫ��һ�����ڵ㣬�ڵ��ֵҲ����������
//��������ָ�������������趨�ڳ�ʼ�����Ҷ�����ʱ��Ҫָ��Ԫ��ֵ�����ش����Ľڵ��ַ��Ϊ������
pOrderTree InitOrderTree(Elemtype data);

//�ڲ��������ʱֻ��Ҫ�жϴ�С��������ң�С������
pOrderTree InsertOrderTree(pOrderTree T,Elemtype data);

//ɾ��������ʱ��Ԫ��ɾ��
void DeleteOrderTree(pOrderTree T,Elemtype data);

//����Ԫ�صĽڵ�
pOrderTree RecurSearch(pOrderTree T,Elemtype data);

pOrderTree NoRecurSearch(pOrderTree T, Elemtype data);

//ǰ���ڵ�
pOrderTree precursor(pOrderTree T, pOrderTree N);

//��̽ڵ�
pOrderTree succee(pOrderTree T, pOrderTree N);

//�������
void PreOrder(pOrderTree T);

//�������
void InOrder(pOrderTree T);

//��������
void PostOrder(pOrderTree T);

//��ӡ��
void PrintTree(pOrderTree T,Elemtype data,int direction);

//���ֵ
pOrderTree Maxmum(pOrderTree T);

//��Сֵ
pOrderTree Minimum(pOrderTree T);

//���ٶ�����
void DestroyTree(pOrderTree T);

#endif

