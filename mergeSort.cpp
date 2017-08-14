/*
 *归并排序，其实就利用递归与分治技术将数据列划分成越来越小的半字表，然后对半字表进行排序，排好序后就进行合并操作
*时间:20170814 
 */

#include<bits/stdc++.h>
using namespace std;

void Merge(int array[],int left,int mid,int right)
{
	int rightLen,leftLen;
	int i,j,k;

	leftLen = mid-left+1;	//1-1+1
	rightLen = right - mid;

	int *leftArray = new int[leftLen];//左侧数组
	int *rightArray = new int[rightLen];//

	for(int i=0,j=left;i<leftLen;i++,j++)
		leftArray[i]=array[j];	//将左侧的值复制过来

	for(int i=0,j=mid+1;i<rightLen;i++,j++)
		rightArray[i]=array[j];	//将左侧的值复制过来

	//进行合并排序,其实这就是两个有序队列合并成一个有序队列，思想就是谁小谁先放
	
	for(k=left,i=0,j=0;i<leftLen && j<rightLen;k++ )
	{
		if(leftArray[i]>rightArray[j])
		{
			array[k] = leftArray[i];
			i++;
		}
		else
		{
			array[k] = rightArray[j];
			j++;
		}
	}

	if(i<leftLen)//两者长度不一致，会有剩余
	{
		//左边剩余
		for(j=i;j<leftLen;j++,k++)
			array[k]=leftArray[j];
	}

	if(j<rightLen)//两者长度不一致，会有剩余
	{
		//右边剩余
		for(j=i;j<rightLen;j++,k++)
			array[k]=rightArray[j];
	}
}

void MergeSort(int array[],int left,int right)
{
	if(left < right)
	{
		int mid = (left+right)/2;//二分
		MergeSort(array,left,mid);
		MergeSort(array,mid+1,right);
		Merge(array,left,mid,right);//将分开好的序列进行合并,最后会是两个数进行比较然后合并
	}
}
int main()
{
	int i=0;

	int testArray[]={5,4,9,8,7,6,0,1,3,2};
	int len = sizeof(testArray)/sizeof(testArray[0]);

	cout<<"len="<<len;
	MergeSort(testArray,0,len-1);
	for(i=0;i<len;i++)
		cout<<testArray[i]<<" ";
	return 0;
}
