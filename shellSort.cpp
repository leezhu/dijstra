/*
 *希尔排序,也称为缩小增量排序，基本原理是:按步长进行交换,最后的步长交换是1,即相邻进行交换,最终得到有序的序列
 *时间:20170814
 */

#include<bits/stdc++.h>
using namespace std;

void ShellSort(int array[],int length)
{
	int swapTemp;

	for(int h=length/2;h>0;h=h/2)	//折半步长
	{
		for(int i=0;i<length-h;i++)
		{
			if(array[i]>array[i+h])//如果大就交换
			{
				swapTemp = array[i];
				array[i] = array[i+h];
				array[i+h] = swapTemp;
			}
		}
	}
}
int main()
{
	int i=0;
	int array[] = {5,4,9,8,7,6,0,1,3,2};
	int len = sizeof(array)/sizeof(array[0]);

	ShellSort(array,len);
	for(i=0;i<len;i++)
		cout<<array[i];

	return 0;
}
