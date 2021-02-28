//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
////顺序表
//
//typedef int SLDatatype;
//
//typedef struct SeqList
//{
//	SLDatatype* pa;
//	int size;//确定当前位置
//	int capacity;//确定顺序表容量
//}SL;
//
////顺序表的初始化
//void SeqListInit(SL* ps);
//
////打印顺序表
//void SeqListPrint(SL* ps);
////尾插
//void SeqListPushBack(SL* ps, SLDatatype x);
////尾部删除
//void SeqListPopBack(SL* ps);
////头插
//void SeqListPushFront(SL* ps, SLDatatype x);
////头部删除
//void SeqListPopFront(SL* ps);
////给定位置的插入
//void SeqListInsert(SL* ps, int pos, SLDatatype x);
////给定位置的删除
//void SeqListErase(SL* ps, int pos);
////顺序表的查找【返回下标】
//int SeqListFind(const SL* ps, SLDatatype x);
////顺序表的销毁
//void SeqListDestory(SL* ps);