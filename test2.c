//#pragma once
//#include "SList.h"
//
//
//void SListTest1()
//{
//	//创建链表
//	SListNode* pList = NULL;
//
//	//尾插结点
//	SListPushBack(&pList, 1);//传地址是因为，如果plist指向的是NULL，插入结点后plist的值会发生变化
//	SListPushBack(&pList, 2);
//	SListPushBack(&pList, 3);
//	SListPrint(pList);
//
//	//尾删结点
//	SListPopBack(&pList);
//	SListPopBack(&pList);
//	SListPopBack(&pList);
//	SListPrint(pList);
//
//	//头插结点
//	SListPushFront(&pList, -1);
//	SListPushFront(&pList, -2);
//	SListPushFront(&pList, -3);
//	SListPrint(pList);
//
//	//头删结点
//	SListPopFront(&pList);
//	SListPopFront(&pList);
//	SListPopFront(&pList);
//	SListPrint(pList);
//}
//
//void SListTest2()
//{
//	//创建链表
//	SListNode* pList = NULL;
//
//	//尾插结点
//	SListPushBack(&pList, 1);//传地址是因为，如果plist指向的是NULL，插入结点后plist的值会发生变化
//	SListPushBack(&pList, 2);
//	SListPushBack(&pList, 3);
//	SListPrint(pList);
//
//}
//
//int main()
//{
////	SListTest1();
////	SListTest2();
//	
//	return 0;
//}