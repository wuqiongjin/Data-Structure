#pragma once
#include <stdio.h>
#include "stack.h"
#include <string.h>

void PrintSort(int* a, int n)
{
	int i = 0;
	for (i = 0;i < n;++i)
		printf("%d ", a[i]);
}

void PrintQuicksort(int* a, int n)
{
	int i = 0;
	for (i = 0;i < n;++i)
		printf("%d ", a[i]);
}

//直接插入排序
void InsertSort1(int* a, int n)
{
	int i = 0;
	for (i = 1; i < n; ++i)
	{
		int j = i;
		for (j = i; j > 0; --j)
		{
			if (a[j] < a[j - 1])
			{
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
			else
			{
				break;
			}
		}
	}
}

//直接插入排序
void InsertSort2(int* a, int n)
{
	int i = 0;
	for (i = 1; i < n; ++i)
	{
		//ret保存需要进行插入排序的那个值
		int ret = a[i];
		int cmp = i - 1;
		while (cmp >= 0)
		{
			if (a[cmp] > ret)
			{
				//不交换，进行替换值
				a[cmp + 1] = a[cmp];
				a[cmp] = ret;
				cmp--;
			}
			else//a[cmp] <= ret
			{
				break;
			}
		}
	}

}


//希尔排序
void ShellSort(int* a, int n)
{
	//排序
	//gap > 1时为预排序			接近有序
	//gap = 1时为直接插入排序		有序
	int gap = n;
	while(gap > 1)
	{
		gap = gap / 3 + 1;//保证最后1次gap一定是1
		//预排序
		int i = 0;
		for (i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > a[end + gap])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}
}

void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


//选择排序 O(N^2)
//这里是从2边同时开始的选择排序【不是一边的】
void SelectSort(int* a, int n)
{
	int i = 0;
	//定义2个下标：begin和end，同时进行最大位置和最小位置的选择
	int begin = 0;
	int end = n - 1;
	while (end > begin)
	{
		int maxi = begin;
		int mini = end;
		for (i = begin;i <= end; ++i)
		{
			if (a[i] > a[maxi])
				maxi = i;
			if (a[i] < a[mini])
				mini = i;
		}
		int ret = a[maxi];
		swap(&a[begin], &a[mini]);
		//maxi如果被换走，需要进行修正！！！[maxi和begin重合，那么就会被换走。]
		if (maxi == begin)
			maxi = mini;
		swap(&a[end], &a[maxi]);

		begin++;
		end--;
	}
}




//堆排序
void HeapSort(int* a, int n)
{

}

//冒泡排序
void BubbleSort(int* a, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n -1; ++i)
	{
		int flag = 1;
		for (j = 0; j < n - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				flag = 0;
				swap(&a[j], &a[j + 1]);
			}
		}
		if (flag)
			break;
	}
}



//Hoare法
int HoareMethod(int* a, int begin, int end)
{
	//单趟快排
	int key = end;

	while (end > begin)
	{
		while (a[begin] <= a[key] && end > begin)
		{
			begin++;
		}

		while (a[end] >= a[key] && end > begin)
		{
			end--;
		}

		if (end > begin)
		{
			swap(&a[end], &a[begin]);
		}
	}
	//交换key的值和相遇点的值
	swap(&a[key], &a[end]);
	
	//返回相遇点
	return begin;
}

//2.挖坑法
int HoleMethod(int* a, int begin, int end)
{
	int key = a[begin];

	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		//把左边的坑填上，右边进行挖坑
		a[begin] = a[end];

		while (begin < end && a[begin] <= key)
		{
			begin++;
		}	
		//把右边的坑填上，左边进行挖坑
		a[end] = a[begin];
	}
	//相遇点填上key值
	a[begin] = key;
	return begin;
}


//3.前后指针法
int PrevCurMethod(int* a, int begin, int end)
{
	int cur = begin;
	int prev = cur - 1;
	int key = a[end];

	while (cur <= end)
	{
		//cur的值小于key，那么prev先++，然后交换cur和prev的值，cur再++
		//if (a[cur] <= key) 
		if(a[cur] <= key && ++prev != cur)//小优化：如果++prev和cur相等，就不用换了
		{
			//prev++;
			swap(&a[prev], &a[cur]);
		}
		cur++;//如果cur的值比key大，那么只有cur++；
	}
	return prev;
}

//递归版---快速排序
void quicksort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	//int key = HoareMethod(a, begin, end);
	//int key = HoleMethod(a, begin, end);
	int key = PrevCurMethod(a, begin, end);

	//quicksort(a, begin, key - 1);
	//quicksort(a, key + 1, end);
}


//非递归版----快速排序【解决递归版本由于递归太深而导致栈溢出Stack Overflow的问题（因为这里用的是堆区）】
void quicksortNonR(int* a, int begin, int end)
{
	//非递归版要借用栈---利用栈的后进先出的特性！！！
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);//左边先入
	StackPush(&st, end);
	//栈为空的时候就代表所有区间都是有序的了
	while (!StackEmpty(&st))
	{
		//因为是end后入的，所以出的时候就是end先出，要用right接收
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		//这里要传left和right【代表传一个区间过去，对这个区间进行快排】
		int keyindex = PrevCurMethod(a, left, right);
		
		//不能取等【取等的时候代表这个区间就1个元素，那么这个元素就已经是有序的了】
		if (left < keyindex - 1)
		{
			//这里也必须是左边先入，右边后入；对应开头写的右边先Pop，左边后Pop
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


//归并-递归
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	//只剩1个元素的时候，判断其为有序，递归结束【return】
	if (begin >= end)
		return;

	//无序时，开始拆分
	//定义一个mid，左子树和右子树分别进行拆分
	int mid = (begin + end) >> 1;//使用右移1位来进行除以2的操作（移位的效率高一些）
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//有序后，开始归并

	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int index = begin;//这里必须从begin开始，因为递归的时候，每次递归中的起始位置是begin
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	if (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	if (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//注意，这里的拷贝的起始地址，必须是a + begin。因为在递归过程中，不是每次都是从0开始的，而是从 0 + begin
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}

//归并排序
void MergeSort(int* a, int begin, int end)
{
//	int* tmp = (int*)calloc((end - begin + 1),sizeof(int));
	int* tmp = (int*)malloc(sizeof(int)*(end - begin + 1));
	_MergeSort(a, begin, end, tmp);
	free(tmp);
}


//计数排序
void CountSort(int* a, int n)
{
	//创建临时数组
	int max = a[0];
	int min = a[0];
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* tmp = calloc(range, sizeof(int));

	//统计次数
	for (i = 0; i < n; ++i)
	{
		tmp[(a[i] - min)]++;
	}

	//展开
	int j = 0;
	for (i = 0; i < n; ++i)
	{
		while (tmp[i])
		{
			tmp[i]--;
			a[j++] = i + min;
		}
	}
}


void TestSort()
{
	int arr[] = { 4,7,3,5,1,2,8,0,9,6 };
	//int arr[10] = { 1,3,5,7,9,2,4,6,8,0 };
	//int arr[] = { 65,56,72,99,86,25,34,66 };
	int sz = sizeof(arr)/sizeof(arr[0]);
	//InsertSort1(arr, sz); 
	//InsertSort2(arr, sz);
	//ShellSort(arr, sz);

	//SelectSort(arr, sz);
	//BubbleSort(arr, sz);

	quicksort(arr, 0, sz - 1);
	//quicksortNonR(arr, 0, sz - 1);
	
	//MergeSort(arr, 0, sz - 1);
	
	//CountSort(arr, sz);
	
	//HoareMethod(arr, 0, sz - 1);
	PrintSort(arr, sz);
//	PrintQuicksort(a, sizeof(a) / sizeof(a[0]));
}