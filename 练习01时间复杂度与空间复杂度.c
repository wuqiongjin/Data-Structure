#include <stdio.h>

//一组0~N的所有数字中缺少了1个，请找出消失的那1个数字----O(N)以内
//1.可以先排序，然后再进行二分查找（思路相似）或者挨个挨个比较
//2.异或

//int main()
//{
//	int i = 0;
//	int nums[] = { 0,1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18 };
//	int N = sizeof(nums) / sizeof(nums[0]);
//	int ret = 0;
//	for (i = 0;i <= N;i++)
//	{
//		ret ^= i;
//		if (i < N)
//			ret ^= nums[i];
//	}
//	printf("%d ", ret);
//	return 0;
//}

//-----------------------------------------写博客---------------------------------------------------------
//找出一组数中只出现1次的那 1 个数
//1.双层循环（都从0开始，保证count计数不出现问题），用计数器count，如果2个数相同，count++，若count == 1，则break 
//2.异或 --- 相同为0，相异为1

//int main()
//{
//	int arr[] = { 1,1,2,2,3,3,4,5,5,6,6,7,7,8,8,9,9,0,0 };
//	int i = 0;
//	int ret = 0;
//	for (i = 0;i < sizeof(arr) / sizeof(arr[0]);i++)
//		ret = ret ^ arr[i];
//	printf("%d ", ret);
//	return 0;
//}

//找出一组数中只出现1次的 2 个数
// 1,2,2,3,3,4,4,5
//0001	1
//0010	2
//0011	3
//0100	4
//0101	5
//分组思路---------------------------------------------------------------------------------------------
//先把所有数都异或在一起，然后根据异或的结果，看异或的结果中的哪一位先出现1（从最低位开始算，需要与1进行按位与&）
//然后根据这一位进行分组，因为这一位为1，代表只出现1次的那两个数这一位肯定不同，所以可以根据这一位进行分组
//然后分组的同时进行按位异或，最后2组的结果就是只出现1次的2个数

//int main()
//{
//	int arr[] = { 2,2,3,3,4,5,8,8 };//4,5
//	int i = 0;
//	int res = 0;
//	for (i = 0;i < sizeof(arr) / sizeof(arr[0]);i++)
//		res = res ^ arr[i];//先把所有数字异或在一起
//	int num = 0;
//	while (res & (1 << num) == 0)
//	{
//		num++;//确定第几位先出现了1（二进制中）
//	}
//	int retA = 0;
//	int retB = 0;
//	for (i = 0;i < sizeof(arr) / sizeof(arr[0]);i++)
//	{
//		if (arr[i] & (1<<num))//分组条件
//		{
//			retA ^= arr[i];//组别1
//		}
//		else
//		{
//			retB ^= arr[i];//组别2
//		}
//	}
//	printf("%d %d", retA, retB);
//	return 0;
//}
