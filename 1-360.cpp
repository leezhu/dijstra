
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,a,b,c,d,x,y,z;
    cin>>m>>n;
    cin>>a>>b>>c>>d;
    cin>>x>>y>>z;
    
    //分三种情况
    int count1,count2,count3;
    
    count1=m/a<n/b?m/a:n/b;
    count2=m/c;
    count3=n/d;
    
    int maxMoney=0;
    int tempMax;
    int surpM;
    int surpN;
    
    
    for(int i=0;i<=count1;i++)
    {
    	tempMax=0;
        tempMax+=i*x;
        
		cout<<"i="<<i<<endl;
        //剩余的粉笔
        surpM=m-i*a;
        surpN=n-i*b;
        
		if(surpM>=d && (surpM/d)>=1)
			tempMax+=(surpM/d*z);

		if(surpN>=c && (surpN/c)>=1)
			tempMax+=(surpN/c*y);
        
        if(tempMax>maxMoney)
            maxMoney=tempMax;
    }
    cout<<maxMoney;
	return 0;
}
