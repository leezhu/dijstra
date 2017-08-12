/*
 *网易内推测试第一题
 *
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
