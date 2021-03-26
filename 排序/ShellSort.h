#pragma once
#include <stdio.h>


//排升序
void Rise_ShellSort(int* a, int n)
{
	int gap = n;
	//判断条件gap > 1  ===>> 保证 gap = 1 的那一趟排完就结束！
	while (gap > 1)
	{
		gap = gap / 3 + 1;//最后的 + 1 可以保证的是gap能取到1
		int i = 0;
		//这里++i就表明我们要交叉不同组的数去排序【但是实际上这和分开去排序是一样的】
		for (i = 0; i < n - gap; ++i)//注意这里的i的范围，i最后一个需要进行插入排序的是在n - gap的位置
		{
			int cmp = i;
			//由于这里的cmp + gap，所以前面的i的范围才是小于 n - gap
			int tmp = a[cmp + gap];//存要进行比较的值

			while (cmp >= 0)
			{
				//进行直接插入比较的排序
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

