//#include "SeqList.h"
//
//void SLPushPopTest(SL* s)//由于这已经是指针了（传了结构体的地址）
//{
//	SeqListPushBack(s,1);//这里直接传值即可，因为指针的值就是结构体的地址！！！！！！！！！！！
//	SeqListPushBack(s,2);
//	SeqListPushBack(s,3);
//	SeqListPushBack(s,4);
//	SeqListPushBack(s,5);
//	SeqListPushBack(s,6);
//	SeqListPrint(s);
//	printf("\n");
//
//	SeqListPopBack(s);
//	SeqListPopBack(s);
//	SeqListPopBack(s);
//	SeqListPrint(s);
//	printf("\n");
//	
//	SeqListPushFront(s, -1);
//	SeqListPushFront(s, -2);
//	SeqListPushFront(s, -3);
//	SeqListPrint(s);
//	printf("\n");
//
//	SeqListPopFront(s);
//	SeqListPopFront(s);
//	SeqListPopFront(s);
//	SeqListPrint(s);
//	printf("\n");
//
//	SeqListInsert(s, 2, 15);
//	SeqListPrint(s);
//	printf("\n");
//
//	SeqListErase(s, 2);
//	SeqListPrint(s);
//	printf("\n");
//
//	int Find_result = 0;
//	Find_result = SeqListFind(s, 3);
//	if (Find_result == -1)
//	{
//		printf("你要找的元素不存在！\n");
//	}
//	else
//	{
//		printf("你要找的元素的下标是%d ", Find_result);
//	}
//
//	//顺序表的销毁
//	SeqListDestory(s);
//}

//int main()
//{
//	SL s;
//	SeqListInit(&s);
//	SLPushPopTest(&s);
//	return 0;
//}