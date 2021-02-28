#include <stdio.h>

//力扣oj题

//题目：原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)
//通过定义2个下标变量，1个用来遍历这个数组的，另一个用来更新这个数组的（把这个数组中要消除的那个元素删掉）

//int removeElement(int* nums, int numsSize, int val)
//{
//	//定义2个下标变量
//	int i = 0;
//	int j = 0;
//	while (i < numsSize)
//	{
//		if (nums[i] == val)
//		{
//			i++;
//		}
//		else
//		{
//			nums[j] = nums[i];
//			i++;
//			j++;
//		}
//	}
//	return j;
//}

//题目：删除排序数组中的重复项
//

//1. 笨方法，循环遍历

//int removeDuplicates(int* nums, int numsSize) {
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		for (j = i + 1; j < numsSize; j++)
//		{
//			if (nums[i] == nums[j])
//			{
//				int ret = j;
//				while (ret < numsSize - 1)
//				{
//					nums[ret] = nums[ret + 1];
//					ret++;
//				}
//				numsSize--;
//				j--;
//			}
//		}
//	}
//	return numsSize;
//}

//2.双指针法

//int removeDuplicates(int* nums, int numsSize)
//{
//	int* fast = nums + 1;
//	int* low = nums;
//
//	if (numsSize < 2)
//		return numsSize;
//	while (fast != nums + numsSize)
//	{
//		if (*fast != *low)
//		{
//			low++;
//			*low = *fast;
//			fast++;
//		}
//		else
//		{
//			fast++;
//		}
//	}
//	return (int)((low - nums) + 1);
//}
//
//int main()
//{
//	int nums[] = {1,1,3,3,2};
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int ret = removeDuplicates(nums, numsSize);
//	printf("%d\n", ret);
//}

//3. 双下标移动法

//int removeDuplicates(int* nums, int numsSize)
//{
//	int prev = 0;
//	int cur = 1;
//	if (numsSize < 2)
//		return numsSize;
//	while (cur < numsSize)
//	{
//		if (nums[prev] != nums[cur])
//		{
//			prev++;
//			nums[prev] = nums[cur];
//			cur++;
//		}
//		else
//		{
//			cur++;
//		}
//	}
//	return prev + 1;
//}
//
//int main()
//{
//	int nums[] = { 1,1,2,2,2,2,2,3};
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int ret = removeDuplicates(nums, numsSize);
//	printf("%d\n", ret);
//}

//题目：合并2个有序数组

//void merge(int* nums1,int m, int* nums2, int n)
//{
//	int i = 0;
//	int j = 0;
//
//	while (j < n)
//	{
//		if (nums1[i] <= nums2[j] && i < m)
//		{
//			i++;
//		}
//		else
//		{
//			m++;
//			int ret = m;
//			for (;ret > i;ret--)
//			{
//				nums1[ret] = nums1[ret - 1];
//			}
//			nums1[i] = nums2[j];
//			j++;
//			i++;
//		}
//	}
//}
//
//int main()
//{
//	int nums1[20] = { 1,2,3,4,5,6,10};
//	int m = 7;
//	int nums2[] = {2,5,6,7,8,9};
//	int n = 6;
//	merge(nums1, m, nums2, n);
//}

//题目：数组形式的整数加法

//#include <math.h>
//#include <malloc.h>
//
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
//	int i = 0;
//	int num = 0;
//	for (i = 0; i < ASize; i++)
//	{
//		num += (int)pow(10, ASize - i - 1) * A[i];
//	}
//	num += K;
//	int count = 0;
//	int n = num;
//	while (num)
//	{
//		num /= 10;
//		count++;
//	}
//	int ret = 0;
//	i = 0;
//	returnSize = (int*)malloc(count * sizeof(int));
//	int* tmp = returnSize;
//	while (count)
//	{
//		ret = n % (int)pow(10, count - 1);
//		*(tmp + i) = n / (int)pow(10, count - 1);
//		n = ret;
//		i++;
//		count--;
//	}
//	return returnSize;
//}
//
//int main()
//{
//	int A[] = { 1,2,0,0 };
//	int ASize = 4;
//	int K = 34;
//	int* returnSize = NULL;
//	returnSize = addToArrayForm( A,  ASize,  K, returnSize);
//	
//	return 0;
//}

//小心数组越界！！！，当数组长度小于数字的时候，会出现访问数组的时候数组越界的情况
//#include <stdlib.h>
//
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
//{
//	int count = 0;
//	int ret = K;
//	while (ret)
//	{
//		ret /= 10;
//		count++;
//	}
//	int len = (count > ASize ? count : ASize);
//	int* retArr = (int*)calloc(len + 1, sizeof(int));
//	int i = 0;
//	int sum = 0;
//	while (len > i)
//	{
//		int Ai = 0;
//		if (ASize > i)
//		{
//			Ai = A[ASize - 1 - i];
//		}
//		if ((sum = Ai + K % 10) >= 10)
//		{
//			retArr[len - i - 1]++;
//		}
//		retArr[len - i] = retArr[len - i] + sum % 10;
//		if (retArr[len - i] >= 10)
//		{
//			retArr[len - i - 1]++;
//		}
//		retArr[len - i] %= 10;
//		i++;
//		K /= 10;
//	}
//	if (retArr[0])
//	{
//		*returnSize = len + 1;
//		return retArr;
//	}
//	else
//	{
//		*returnSize = len;
//		return retArr + 1;
//	}
//}
//
//int main()
//{
//	int A[] = { 1 };
//	int ASize = sizeof(A) / sizeof(A[0]);
//	int K = 33;
//	int L = 0;
//	int* returnSize = addToArrayForm(A, ASize, K, &L);
//	return 0;
//}