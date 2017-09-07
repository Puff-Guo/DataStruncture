/*
	顺序链表
*/

#ifndef H_ORDERLIST_H
#define H_ORDERLIST_H

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int Length;
}SqList,*pSqList;

//创建顺序列表
void CreateSqList(pSqList L,int n);

//插入元素,索引之前
void EndInsertSqList(pSqList L, ElemType data, int Index);

//插入元素，索引之后
void PreInsertSqList(pSqList L, ElemType data, int Index);

//通过元素获取索引
int GetElemIndex(pSqList L, ElemType data);

//获取索引元素
bool GetElemByIndex(pSqList L, int Index, ElemType *Data);

//获取列表大小
int GetSqListSize(pSqList L);

//删除索引元素
bool DeleteDataByIndex(pSqList L,int Index);

//删除相同的元素
void DeleteData(pSqList L, ElemType data);

//递减排序
void SortSqListDesc(pSqList L);

//递增排序
void SortSqListAsc(pSqList L);

//倒序列表
void Reverse_SqList(pSqList L);

//显示顺序列表
void Display_SqList(pSqList L);

#endif
