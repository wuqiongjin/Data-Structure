//#pragma once
//
//#include "SeqList.h"
//
////初始化顺序表
//void SeqListInit(SL* ps)
//{
//	ps->pa = (SLDatatype*)malloc(sizeof(SLDatatype) * 4);
//	ps->size = 0;
//	ps->capacity = 4;
//}
//
////打印顺序表
//void SeqListPrint(SL* ps)
//{
//	int i = 0;
//	for (i = 0;i < ps->size;i++)
//	{
//		printf("%d ", ps->pa[i]);
//	}
//}
//
////检查是否满容量，如果满了进行2倍扩充增容
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
////尾插元素
//void SeqListPushBack(SL* ps, SLDatatype x)
//{
//	assert(ps);
//	//检查容量/增容操作
//	SeqListCheckCapacity(ps);
//	
//	ps->pa[ps->size] = x;
//	ps->size++;
//}
//
////尾部删除
//void SeqListPopBack(SL* ps)
//{
//	assert(ps);
//	ps->size--;
//}
//
////头插
//void SeqListPushFront(SL* ps, SLDatatype x)
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	int ret = ps->size;
//	//把顺序表中的所有元素向后移动1个位置
//	while (ret > 0)
//	{
//		ps->pa[ret] = ps->pa[ret - 1];
//		ret--;
//	}
//	ps->pa[0] = x;
//	ps->size++;
//}
//
////头部删除
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
////给定位置的插入
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
////给定位置的删除
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
////顺序表的查找【返回下标】
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
////顺序表的销毁
//void SeqListDestory(SL* ps)
//{
//	free(ps->pa);
//	ps->pa = NULL;
//}