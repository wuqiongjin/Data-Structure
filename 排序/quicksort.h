#pragma once
#include <stdio.h>
#include "stack.h"

static void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//1. Horae��
int HoraeMethod(int* a, int begin, int end)
{
	//�ұ���key������ߡ� ���ƶ���
	int key = end;

	while (begin < end)
	{
		//����Ϊend��key��������ߡ�������ߣ��ҵ���key���
		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}
		//�ұ����ߣ��ҵ���keyС��
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}

		if (begin < end)
		{
			swap(&a[begin], &a[end]);
		}
	}
	//����key���������ֵ������key����߶��Ǳ�keyС�ģ�key���ұ߶��Ǳ�key�����
	swap(&a[key], &a[begin]);
	return begin;//����������
}


//2.�ڿӷ�
int HoleMethod(int* a, int begin, int end)
{
	//����ڿӣ��Ƽ����ұ߿�ʼ��
	int key = a[begin];

	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		//�ҵ���keyС�ĺ󣬶����λ�ý����ڿӣ��������ֵ������ߵĿӣ�
		a[begin] = a[end];

		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//�ҵ���key��ĺ󣬶����λ�ý����ڿӣ��������ֵ�����ұߵĿӣ�
		a[end] = a[begin];
	}
	//�ҵ������㣬��key��ֵ����ȥ
	a[begin] = key;
	return begin;
}


//3.ǰ��ָ�뷨
int PrevCurMethod(int* a, int begin, int end)
{
	//ѡ��end��Ϊkey
	int key = a[end];
	int cur = begin;
	int prev = cur - 1;

	while (cur <= end)
	{
		//��cur��Ӧ��ֵС��key��ʱ������prev++��Ȼ���cur��ֵ��prev��ֵ���н�����Ȼ��cur++
		if (a[cur] <= key)
		{
			prev++;
			swap(&a[prev], &a[cur]);
		}
		//���cur��Ӧ��ֵ����key����ôֻ��cur++��prev�����κθı�
		cur++;
	}
	
	return prev;
}


//�ǵݹ��
void quicksortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	//�������
	StackPush(&st, begin);
	StackPush(&st, end);

	//ջ��Ϊ�մ���ʱ�������������仹δ�������˿���
	while (!StackEmpty(&st))
	{
		//ע������ȡ����ʱ�򣬱�����right��ȡ
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		//��left��right������е��˿���
		//int keyindex = HoleMethod(a, left, right);
		int keyindex = HoraeMethod(a, left, right);
		//int keyindex = PrevCurMethod(a, left, right);

		//��leftС��keyindexʱ�������������������2��Ԫ�أ�����Ҫ���е��˿���
		if(left < keyindex - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyindex - 1);
		}

		if (keyindex + 1 < right)
		{
			StackPush(&st, keyindex + 1);
			StackPush(&st, right);
		}
	}
	
	StackDestory(&st);
}