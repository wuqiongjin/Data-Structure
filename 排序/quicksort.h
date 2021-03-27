#pragma once
#include <stdio.h>
#include "stack.h"

static void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//1. Horae法
int HoraeMethod(int* a, int begin, int end)
{
	//右边做key，“左边” 先移动！
	int key = end;

	while (begin < end)
	{
		//【因为end做key，左边先走】左边先走，找到比key大的
		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}
		//右边再走，找到比key小的
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}

		if (begin < end)
		{
			swap(&a[begin], &a[end]);
		}
	}
	//交换key与相遇点的值，这样key的左边都是比key小的，key的右边都是比key大的了
	swap(&a[key], &a[begin]);
	return begin;//返回相遇点
}


//2.挖坑法
int HoleMethod(int* a, int begin, int end)
{
	//左边挖坑，推荐从右边开始找
	int key = a[begin];

	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		//找到比key小的后，对这个位置进行挖坑（将这里的值赋给左边的坑）
		a[begin] = a[end];

		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//找到比key大的后，对这个位置进行挖坑（将这里的值赋给右边的坑）
		a[end] = a[begin];
	}
	//找到相遇点，把key的值填上去
	a[begin] = key;
	return begin;
}


//3.前后指针法
int PrevCurMethod(int* a, int begin, int end)
{
	//选定end作为key
	int key = a[end];
	int cur = begin;
	int prev = cur - 1;

	while (cur <= end)
	{
		//当cur对应的值小于key的时候，先让prev++，然后把cur的值和prev的值进行交换，然后cur++
		if (a[cur] <= key)
		{
			prev++;
			swap(&a[prev], &a[cur]);
		}
		//如果cur对应的值大于key，那么只有cur++，prev不做任何改变
		cur++;
	}
	
	return prev;
}


//非递归版
void quicksortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	//左边先入
	StackPush(&st, begin);
	StackPush(&st, end);

	//栈不为空代表时，代表仍有区间还未经过单趟快排
	while (!StackEmpty(&st))
	{
		//注意这里取出的时候，必须是right先取
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		//对left和right区间进行单趟快排
		//int keyindex = HoleMethod(a, left, right);
		int keyindex = HoraeMethod(a, left, right);
		//int keyindex = PrevCurMethod(a, left, right);

		//当left小于keyindex时，代表这段区间至少有2个元素，还需要进行单趟快排
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