
#include<bits/stdc++.h>
using namespace std;

int checkBinary(unsigned int a,unsigned int b)
{
	unsigned int c=a^b;//异或操作
    unsigned int move=1;
   
    int n=1;
    int flag=0;
    while(n<=31)
    {
    	if((c&move)>0)
            flag++;
        move=1<<n;
        n++;
    }
    return flag;
}

int main()
{
    vector<unsigned int> data;
    int num;
    unsigned int temp;
    cin>>num;
    for(int i=0;i<num;i++)
    {
    	cin>>temp;
        data.push_back(temp);
    }
    
    int result=0;
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
        	if(data[i]!=data[j])
                result+=checkBinary(data[i],data[j]);
        }
    }
    
    cout<<result;
    
	return 0;
}
