#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int HpDataType;

typedef struct Heap
{
	HpDataType* _a;
	int			_size;
	int			_capacity;
}Heap;

//向下调整算法
void AdjustDown(int* a, int n, int root);

//堆的创建
void HeapCreate(Heap* hp, HpDataType* a, int sz);

//向堆中插入元素
void HeapPush(Heap* hp, HpDataType x);

//打印堆中的元素
void HeapPrint(Heap* hp);

//向上调整算法
void AdjustUp(int* a, int child);

//移除堆顶元素
void HeapPop(Heap* hp);

//堆排序【降序】用最小堆
void HeapSort(Heap* hp);

//判断堆是否为空
int HeapEmpty(Heap* hp);

//获取堆顶元素
HpDataType HeapTop(Heap* hp);