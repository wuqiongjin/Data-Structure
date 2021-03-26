#pragma once
#include <stdio.h>


//������
void Rise_ShellSort(int* a, int n)
{
	int gap = n;
	//�ж�����gap > 1  ===>> ��֤ gap = 1 ����һ������ͽ�����
	while (gap > 1)
	{
		gap = gap / 3 + 1;//���� + 1 ���Ա�֤����gap��ȡ��1
		int i = 0;
		//����++i�ͱ�������Ҫ���治ͬ�����ȥ���򡾵���ʵ������ͷֿ�ȥ������һ���ġ�
		for (i = 0; i < n - gap; ++i)//ע�������i�ķ�Χ��i���һ����Ҫ���в������������n - gap��λ��
		{
			int cmp = i;
			//���������cmp + gap������ǰ���i�ķ�Χ����С�� n - gap
			int tmp = a[cmp + gap];//��Ҫ���бȽϵ�ֵ

			while (cmp >= 0)
			{
				//����ֱ�Ӳ���Ƚϵ�����
				if (a[cmp] > tmp)
				{
					a[cmp + gap] = a[cmp];
					a[cmp] = tmp;
					cmp -= gap;
				}
				else
				{
					break;
				}
			}
		}

	}
}

