
#include<bits/stdc++.h>
using namespace std;

int sIndex=0;
int findCharNumber(string str,char c)
{
	int size = str.size();
    
    int flag=0;
    for(int i=sIndex;i<size;i++)
    {
    	if(str[i]==c)
        {
            flag++;
            sIndex=i;
        }
    }
    return flag;
}


int main()
{
    int num;
    string temp;
    int number1,number2,number3;
	cin>>num;
    
    for(int i=0;i<num;i++)
    {
    	cin>>temp;
        
        number1=findCharNumber(temp,'d');
        number2=findCharNumber(temp,'j');
        number3=findCharNumber(temp,'i');
        
        cout<<number1*number2*number3<<endl;
    }
	return 0;
}
