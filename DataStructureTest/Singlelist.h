/*
	������
*/

#ifndef H_SIGNELLIST_H
#define H_SIGNELLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct node
{
	int data;
	struct node * next;
}LNode, *LinkList;

//��ʼ��һ��ͷ�ڵ�
LinkList init_LinkList(void);
//ͷ�巨������ͷ�ڵ��б�
LinkList Create_LinkListH(int n);
//β�巨������ͷ�ڵ��б�
LinkList Create_LinkListT(int n);
//ͨ��λ�û�ȡԪ��
LinkList GetElemByIndex(LinkList L,int Index);
//ͨ�����ݻ�ȡԪ��
LinkList GetIndexByElem(LinkList L,Elemtype data);
//��ȡ�б���
int  GetLenLinkList(LinkList L);
//��ȡβ�ڵ�
LinkList GetTail(LinkList L);
//��ȡͷ�ڵ�
LinkList GetHead(LinkList L);
//��Ԫ�ص�ǰ�˲���
void InsertBefore(LinkList L,Elemtype data,int Index);
//��Ԫ�صĺ�˲���
void InsertEnd(LinkList L, Elemtype data, int Index);
//��β�˲���
void InsertTail(LinkList L, Elemtype data);
//��ͷ�˲���
void InsertHead(LinkList L, Elemtype data);
//�޸�Ԫ��
void ModifyLinkList(LinkList L,int pos,Elemtype data);
//ͨ������ɾ��Ԫ��
void DeleteLinkList(LinkList L,int Index);
//ɾ��ͷ�ڵ�
void DeleteHead(LinkList L);
//ɾ��β�ڵ�
void DeleteTail(LinkList L);
//ɾ������Ԫ��
void DeleteLinkListData(LinkList L,Elemtype data);
//����б�
void ClearLinkList(LinkList L);
//��ʾ�б�
void Display_LinkList(LinkList L);
//��������
void SortLinkListDesc(LinkList L);
//��������
void SortLinkListAsc(LinkList L);
//������������
void QuickSortLinkListDesc(LinkList L);
//���ٽ�������
void QuickSortLinkListAsc(LinkList L);
//�����б�
void Reverse_Linklist(LinkList* L);
//�ϲ������б��������б�
LinkList MergeTwoOrderLinkList(LinkList FirstList,LinkList SecondList);
//�ϲ������б�
void MergeTwoLinkList(LinkList HeadList,LinkList SecondList);
//��������Ԫ�ص��б�
void SwopElemPos(LinkList L, LinkList FirstNode, LinkList SecondNode);

#endif
