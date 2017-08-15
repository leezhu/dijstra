/*
 *堆排序:对于给定的n个记录，初始时把这些看成是顺序存储的一颗二叉树,然后调整为一个大顶堆
 然后将堆的最后一个元素与堆顶交换,堆的最后一个元素即为最大纪录,接着重新将前面的n-1个元素调整为最大堆
 堆排序两个过程:
	1、构建堆
	2、交换堆顶元素和最后一个元素位置
 *时间:20170814
 */

#include<bits/stdc++.h>
using namespace std;

void AdjustMinHeap(int array[],int beginPos,int len)
{
	int temp;//置换所用
	int child;//子节点

	for(temp = array[beginPos];2*beginPos+1<=len;beginPos=child)	//子节点不能超过末尾节点序号
	{
		child = 2*beginPos+1;
		if(child<len-1 && array[child]>array[child+1])	//如果右子节点小于左边，那么子节点变成是右边
			child++;

		if(array[child]<temp)	//比右节点小，比父节点也小，那么父节点和此左节点置换
		{
			array[beginPos] = array[child];
			array[child] = temp;//进行置换
		}
		else
			break;	//如果父节点比子节点都小，那么就不需要置换，停止
	}
}
void Swap(int& a,int&b)
{
	int temp=a;
	a = b;
	b=temp;
}

void HeapSort(int array[],int len)
{
	for(int i=len/2-1;i>=0;i--)	//调整堆，从最后一个节点所在的父节点的字数开始比较，其实就是比较三个数或者两个数，子节点父节点
		AdjustMinHeap(array,i,len-1);

	for(int i=len-1;i>=0;i--)
	{
		Swap(array[0],array[i]);	//置换第一个最小根节点到末尾
		AdjustMinHeap(array,0,i-1);	//然后调整置换后的前面的堆
	}

}
int main()
{
	int array[]={0,13,1,14,27,18};
	int length = sizeof(array)/sizeof(array[0]);

	HeapSort(array,length);

	for(int i=0;i<length;i++)
		cout<<array[i]<<" ";
	return 0;
}
