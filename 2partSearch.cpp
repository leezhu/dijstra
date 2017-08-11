/*
 *描述:二分法，递归和非递归
 *时间:20170811
 */

#include<iostream>
using namespace std;

//非递归方法
int BinarySearch(int array[],int len,int findData)
{
	if(array==NULL || len<=0)
		return -1;
	int start =0;
	int end= len-1;
	while(start<=end)//判断相遇的最后节点
	{
		int mid = start+(end-start)/2;
		if(array[mid]==findData)
			return mid;
		else if(findData<array[mid])
			end = mid-1;
		else
			start=mid+1;
	}
	return -1;//没有找到
}

//递归算法
int BinarySearchRecursion(int array[],int findData,int start,int end)
{
	if(start>end)
		return -1;

	int mid = start+(end-start)/2;
	if(array[mid]==findData)
		return mid;
	else if(findData<array[mid])
		return BinarySearchRecursion(array,findData,start,end-1);
	else 
		return BinarySearchRecursion(array,findData,start+1,end);
}
int main()
{
	return 0;
}
