/*
	˳������
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

//����˳���б�
void CreateSqList(pSqList L,int n);

//����Ԫ��,����֮ǰ
void EndInsertSqList(pSqList L, ElemType data, int Index);

//����Ԫ�أ�����֮��
void PreInsertSqList(pSqList L, ElemType data, int Index);

//ͨ��Ԫ�ػ�ȡ����
int GetElemIndex(pSqList L, ElemType data);

//��ȡ����Ԫ��
bool GetElemByIndex(pSqList L, int Index, ElemType *Data);

//��ȡ�б��С
int GetSqListSize(pSqList L);

//ɾ������Ԫ��
bool DeleteDataByIndex(pSqList L,int Index);

//ɾ����ͬ��Ԫ��
void DeleteData(pSqList L, ElemType data);

//�ݼ�����
void SortSqListDesc(pSqList L);

//��������
void SortSqListAsc(pSqList L);

//�����б�
void Reverse_SqList(pSqList L);

//��ʾ˳���б�
void Display_SqList(pSqList L);

#endif
