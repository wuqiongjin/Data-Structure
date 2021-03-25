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

//ֱ�Ӳ�������
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

//ֱ�Ӳ�������
void InsertSort2(int* a, int n)
{
	int i = 0;
	for (i = 1; i < n; ++i)
	{
		//ret������Ҫ���в���������Ǹ�ֵ
		int ret = a[i];
		int cmp = i - 1;
		while (cmp >= 0)
		{
			if (a[cmp] > ret)
			{
				//�������������滻ֵ
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


//ϣ������
void ShellSort(int* a, int n)
{
	//����
	//gap > 1ʱΪԤ����			�ӽ�����
	//gap = 1ʱΪֱ�Ӳ�������		����
	int gap = n;
	while(gap > 1)
	{
		gap = gap / 3 + 1;//��֤���1��gapһ����1
		//Ԥ����
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


//ѡ������ O(N^2)
//�����Ǵ�2��ͬʱ��ʼ��ѡ�����򡾲���һ�ߵġ�
void SelectSort(int* a, int n)
{
	int i = 0;
	//����2���±꣺begin��end��ͬʱ�������λ�ú���Сλ�õ�ѡ��
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
		//maxi��������ߣ���Ҫ��������������[maxi��begin�غϣ���ô�ͻᱻ���ߡ�]
		if (maxi == begin)
			maxi = mini;
		swap(&a[end], &a[maxi]);

		begin++;
		end--;
	}
}




//������
void HeapSort(int* a, int n)
{

}

//ð������
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



//Hoare��
int HoareMethod(int* a, int begin, int end)
{
	//���˿���
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
	//����key��ֵ���������ֵ
	swap(&a[key], &a[end]);
	
	//����������
	return begin;
}

//2.�ڿӷ�
int HoleMethod(int* a, int begin, int end)
{
	int key = a[begin];

	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		//����ߵĿ����ϣ��ұ߽����ڿ�
		a[begin] = a[end];

		while (begin < end && a[begin] <= key)
		{
			begin++;
		}	
		//���ұߵĿ����ϣ���߽����ڿ�
		a[end] = a[begin];
	}
	//����������keyֵ
	a[begin] = key;
	return begin;
}


//3.ǰ��ָ�뷨
int PrevCurMethod(int* a, int begin, int end)
{
	int cur = begin;
	int prev = cur - 1;
	int key = a[end];

	while (cur <= end)
	{
		//cur��ֵС��key����ôprev��++��Ȼ�󽻻�cur��prev��ֵ��cur��++
		//if (a[cur] <= key) 
		if(a[cur] <= key && ++prev != cur)//С�Ż������++prev��cur��ȣ��Ͳ��û���
		{
			//prev++;
			swap(&a[prev], &a[cur]);
		}
		cur++;//���cur��ֵ��key����ôֻ��cur++��
	}
	return prev;
}

//�ݹ��---��������
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


//�ǵݹ��----�������򡾽���ݹ�汾���ڵݹ�̫�������ջ���Stack Overflow�����⣨��Ϊ�����õ��Ƕ�������
void quicksortNonR(int* a, int begin, int end)
{
	//�ǵݹ��Ҫ����ջ---����ջ�ĺ���ȳ������ԣ�����
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);//�������
	StackPush(&st, end);
	//ջΪ�յ�ʱ��ʹ����������䶼���������
	while (!StackEmpty(&st))
	{
		//��Ϊ��end����ģ����Գ���ʱ�����end�ȳ���Ҫ��right����
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		//����Ҫ��left��right������һ�������ȥ�������������п��š�
		int keyindex = PrevCurMethod(a, left, right);
		
		//����ȡ�ȡ�ȡ�ȵ�ʱ�������������1��Ԫ�أ���ô���Ԫ�ؾ��Ѿ���������ˡ�
		if (left < keyindex - 1)
		{
			//����Ҳ������������룬�ұߺ��룻��Ӧ��ͷд���ұ���Pop����ߺ�Pop
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


//�鲢-�ݹ�
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	//ֻʣ1��Ԫ�ص�ʱ���ж���Ϊ���򣬵ݹ������return��
	if (begin >= end)
		return;

	//����ʱ����ʼ���
	//����һ��mid�����������������ֱ���в��
	int mid = (begin + end) >> 1;//ʹ������1λ�����г���2�Ĳ�������λ��Ч�ʸ�һЩ��
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//����󣬿�ʼ�鲢

	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int index = begin;//��������begin��ʼ����Ϊ�ݹ��ʱ��ÿ�εݹ��е���ʼλ����begin
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
	//ע�⣬����Ŀ�������ʼ��ַ��������a + begin����Ϊ�ڵݹ�����У�����ÿ�ζ��Ǵ�0��ʼ�ģ����Ǵ� 0 + begin
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}

//�鲢����
void MergeSort(int* a, int begin, int end)
{
//	int* tmp = (int*)calloc((end - begin + 1),sizeof(int));
	int* tmp = (int*)malloc(sizeof(int)*(end - begin + 1));
	_MergeSort(a, begin, end, tmp);
	free(tmp);
}


//��������
void CountSort(int* a, int n)
{
	//������ʱ����
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

	//ͳ�ƴ���
	for (i = 0; i < n; ++i)
	{
		tmp[(a[i] - min)]++;
	}

	//չ��
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