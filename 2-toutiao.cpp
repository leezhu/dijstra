
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    int max=0;
    vector<int> arr;
    int temp;
	cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>temp;
		arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    

	int sum=0;
    for(int i=0;i<num;i++)
    {
    	sum+=arr[i];
    }
	int sum2=0;
	for(int i=0;i<num;i++)
	{
		sum2+=arr[0];
		if((sum*arr[i])>max)
			max=sum*arr[i];
		sum-=sum2;
	}
    cout<<max;
}
