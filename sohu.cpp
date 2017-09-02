/*
 *
 */

#include<iostream>
using namespace std;

int main()
{
	int x1,x2,x3,x4,x5,x6;
	int count=0;

	while(cin>>x1>>x2>>x3>>x4>>x5>>x6)
	{
		if(x1==0 && x2==0 && x3==0 && x4==0 && x5==0 && x6==0)
			break;

		count=0;

		if(x6!=0)
		{
			count+=x6;
		}
		
		if(x5!=0)
		{
			if(x1!=0)	//只能填x1	
			{
				if(x1>91*x5)
				{
					x1=x1-91*x5;
				}else
					x1=0;
			}
			count+=x5;
		}
		
		if(x4!=0)
		{
			count+=x4;

			if(x2>(152*x4)/8)
				x2=x2-(152*x4)/8;
			else if(x1!=0)
			{
				x2=0;
				if(x1>(152*x4-x2*8))
					x1=x1-(152*x4-x2*8);
				else
					x1=0;
			}
		}
		
		if(x3!=0)
		{
			int nu=1;
			int le=0;
			if(x3>8)
			{
				if(x3%8==0)
					nu=x3/8;
				else
				{
					nu=x3/8+1;
					le=8-x3%8;
				}
			}
			count+=nu;

			int le1=0;
			if(le!=0)
			{
				if(x2!=0)
				{
					if(x2>le)
					{
						x2=x2-le;
						le1=19*le;
					}else
					{
						x2=0;
						le1=x2*19+(le-x2);
						le=le-x2;
						
					}
				}

				if(le1!=0)
				{
					if(x1>le1)
						x1=x1-le1;
					else
						x1=0;
				}
			}
		
		}
		
		if(x2!=0)
		{
			int nu=0;
			int le=0;
			if(x2>27)
			{
				if(x2%27==0)
					nu=x3/27;
				else
				{
					nu=x3/27+1;
					le=(27-x2%27)*8;
				}
			}
			count+=nu;
			if(le!=0)
			{
				if(x1>le)
					x1=x1-le;
				else
					x1=0;
			}

		}
		
		if(x1!=0)
		{
			if(x1>216)
				if(x1%216==0)
					count+=x1/216;
				else
					count+=x1/216+1;
			else
				count++;

		}

		cout<<count;
	}
	return 0;
}
