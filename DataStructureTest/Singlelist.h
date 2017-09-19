/*
	单链表
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

//初始化一个头节点
LinkList init_LinkList(void);
//头插法创建带头节点列表
LinkList Create_LinkListH(int n);
//尾插法创建带头节点列表
LinkList Create_LinkListT(int n);
//通过位置获取元素
LinkList GetElemByIndex(LinkList L,int Index);
//通过数据获取元素
LinkList GetIndexByElem(LinkList L,Elemtype data);
//获取列表长度
int  GetLenLinkList(LinkList L);
//获取尾节点
LinkList GetTail(LinkList L);
//获取头节点
LinkList GetHead(LinkList L);
//在元素的前端插入
void InsertBefore(LinkList L,Elemtype data,int Index);
//在元素的后端插入
void InsertEnd(LinkList L, Elemtype data, int Index);
//在尾端插入
void InsertTail(LinkList L, Elemtype data);
//在头端插入
void InsertHead(LinkList L, Elemtype data);
//修改元素
void ModifyLinkList(LinkList L,int pos,Elemtype data);
//通过索引删除元素
void DeleteLinkList(LinkList L,int Index);
//删除头节点
void DeleteHead(LinkList L);
//删除尾节点
void DeleteTail(LinkList L);
//删除所有元素
void DeleteLinkListData(LinkList L,Elemtype data);
//清除列表
void ClearLinkList(LinkList L);
//显示列表
void Display_LinkList(LinkList L);
//降序排序
void SortLinkListDesc(LinkList L);
//升序排序
void SortLinkListAsc(LinkList L);
//快速升序排序
void QuickSortLinkListDesc(LinkList L);
//快速降序排序
void QuickSortLinkListAsc(LinkList L);
//倒序列表
void Reverse_Linklist(LinkList* L);
//合并有序列表返回有序列表
LinkList MergeTwoOrderLinkList(LinkList FirstList,LinkList SecondList);
//合并两个列表
void MergeTwoLinkList(LinkList HeadList,LinkList SecondList);
//交换两个元素的列表
void SwopElemPos(LinkList L, LinkList FirstNode, LinkList SecondNode);

#endif
