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

//���µ����㷨
void AdjustDown(int* a, int n, int root);

//�ѵĴ���
void HeapCreate(Heap* hp, HpDataType* a, int sz);

//����в���Ԫ��
void HeapPush(Heap* hp, HpDataType x);

//��ӡ���е�Ԫ��
void HeapPrint(Heap* hp);

//���ϵ����㷨
void AdjustUp(int* a, int child);

//�Ƴ��Ѷ�Ԫ��
void HeapPop(Heap* hp);

//�����򡾽�������С��
void HeapSort(Heap* hp);

//�ж϶��Ƿ�Ϊ��
int HeapEmpty(Heap* hp);

//��ȡ�Ѷ�Ԫ��
HpDataType HeapTop(Heap* hp);