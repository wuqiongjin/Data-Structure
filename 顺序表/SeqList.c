//#pragma once
//
//#include "SeqList.h"
//
////��ʼ��˳���
//void SeqListInit(SL* ps)
//{
//	ps->pa = (SLDatatype*)malloc(sizeof(SLDatatype) * 4);
//	ps->size = 0;
//	ps->capacity = 4;
//}
//
////��ӡ˳���
//void SeqListPrint(SL* ps)
//{
//	int i = 0;
//	for (i = 0;i < ps->size;i++)
//	{
//		printf("%d ", ps->pa[i]);
//	}
//}
//
////����Ƿ���������������˽���2����������
//void SeqListCheckCapacity(SL* ps)
//{
//	SLDatatype* tmp = NULL;
//	assert(ps);
//	if (ps->size == ps->capacity)
//	{
//		ps->capacity *= 2;
//		tmp = realloc(ps->pa, sizeof(SLDatatype)*(ps->capacity));
//		if (tmp!=NULL)
//		{
//			ps->pa = tmp;
//		}
//		else
//		{
//			perror("Error");
//		}
//	}
//}
//
////β��Ԫ��
//void SeqListPushBack(SL* ps, SLDatatype x)
//{
//	assert(ps);
//	//�������/���ݲ���
//	SeqListCheckCapacity(ps);
//	
//	ps->pa[ps->size] = x;
//	ps->size++;
//}
//
////β��ɾ��
//void SeqListPopBack(SL* ps)
//{
//	assert(ps);
//	ps->size--;
//}
//
////ͷ��
//void SeqListPushFront(SL* ps, SLDatatype x)
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	int ret = ps->size;
//	//��˳����е�����Ԫ������ƶ�1��λ��
//	while (ret > 0)
//	{
//		ps->pa[ret] = ps->pa[ret - 1];
//		ret--;
//	}
//	ps->pa[0] = x;
//	ps->size++;
//}
//
////ͷ��ɾ��
//void SeqListPopFront(SL* ps)
//{
//	assert(ps);
//	int ret = 0;
//	while (ret < ps->size - 1)
//	{
//		ps->pa[ret] = ps->pa[ret + 1];
//		ret++;
//	}
//	ps->size--;
//}
//
////����λ�õĲ���
//void SeqListInsert(SL* ps, int pos, SLDatatype x)
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	int ret = ps->size;
//	while (ret > pos)
//	{
//		ps->pa[ret] = ps->pa[ret - 1];
//		ret--;
//	}
//	ps->pa[pos] = x;
//	ps->size++;
//}
//
////����λ�õ�ɾ��
//void SeqListErase(SL* ps, int pos)
//{
//	assert(ps);
//	while (pos < ps->size - 1)
//	{
//		ps->pa[pos] = ps->pa[pos + 1];
//		pos++;
//	}
//	ps->size--;
//}
//
////˳���Ĳ��ҡ������±꡿
//int SeqListFind(const SL* ps, SLDatatype x)
//{
//	assert(ps);
//	int i = 0;
//	for (i = 0;i < ps->size;i++)
//	{
//		if (ps->pa[i] == x)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
////˳��������
//void SeqListDestory(SL* ps)
//{
//	free(ps->pa);
//	ps->pa = NULL;
//}