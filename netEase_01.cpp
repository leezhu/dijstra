/*
 *网易内推测试第一题
 *问题:给出一行数字，每次将数字放入队列中，然后将这个队列逆置，最后得到此队列
 *思路:首先考虑的是直接用算法库里面的逆置函数来做，虽然可以，但是复杂度非常高，只有50%正确率
	考虑用斐波拉契数列思想，可以查看到规律，比如说输入数字1，2，3，4
	那么第一次  1，
		第二次：2 1
		第三次：3 1 2
		第四次：4 2 1 3
	可以看到第三次的结果是第一次的内容加上当前的和第二次第一个元素的组合，完全符合斐波拉契数列，但是考虑到输入的数字非常多，采用递归会发生内存不够情况，所以采用常规方法。
 */
#include<iostream>
#include<algorithm>
#include<string>
#include<list>
using namespace std;


int main()
{
	int num;
	int integer;

	list<int> sequence_1,sequence_2,sequence;

	cin>>num;

	//方法1:类似于斐波拉契数列数列方法，可以查看到规律
		for(int i=0;i<num;i++)
		{
			cin>>integer;
			if(i==0)
			{
				sequence_1.push_back(integer);
				sequence_2.push_back(integer);
				sequence.push_back(integer);
			}
			else if(i == 1)
			{
				sequence_2.push_front(integer);
				sequence.push_front(integer);
			}
			else
			{
				sequence.clear();
				

				list<int>:: iterator ite=sequence_2.begin();
				sequence.assign(sequence_1.begin(),sequence_1.end());
				sequence.push_front(integer);
				sequence.push_back(*ite);

				sequence_1.clear();
				sequence_1.assign(sequence_2.begin(),sequence_2.end());

				sequence_2.clear();
				sequence_2.assign(sequence.begin(),sequence.end());
			}
		}


		//方法二:直接用算法函数，逆置复杂度高
	/*
	for(int i=0;i<num;i++)
	{
		cin>>integer;
		sequence.push_back(integer);
		reverse(sequence.begin(),sequence.end());
	}
	*/
	list<int>::iterator ite = sequence.begin();
	for(;ite!=sequence.end();)
	{
		cout<<*ite;
		ite++;
		if(ite!=sequence.end())
			cout<<" ";
	}
	return 0;
}
