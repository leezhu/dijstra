#include<bits/stdc++.h>
using namespace std;



int compar( const void* a, const void* b )
{
    // return *(const int*)b - *(const int*)a; 一开始考虑不周，这一步可能导致数值溢出
    if( *(const int*)b > *(const int*)a ) return +1;
    if( *(const int*)b < *(const int*)a ) return -1;
    return 0;
}


int main()
{
	int array[50000][2];
	int result[1000][2];

	int num;
	cin>>num;

	for(int i=0;i<num;i++)
		cin>>array[i][0]>>array[i][1];

	int flag=true;
	int m=0;

	for(int i=0;i<num-1;i++)
	{
		int j=i+1;
		for(;j<num;j++)
		{
			if(array[j][0]>array[i][0] && array[j][1]>array[i][1])
			{
				break;
			}
		
		}
			if(j==num)
			{
				result[m][0]=array[i][0];
				result[m][1]=array[i][1];
				m++;
			}
	}

	for(int i=0;i<m;i++)
	{
		cout<<result[i][0]<<" "<<result[i][1]<<endl;
	}
	cout<<"****************"<<endl;
	qsort(result,m,sizeof(result[0]),compar);
	
	for(int i=0;i<m;i++)
	{
		cout<<result[i][0]<<" "<<result[i][1]<<endl;
	}
	return 0;

}
