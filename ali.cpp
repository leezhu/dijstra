#include<bits/stdc++.h>
using namespace std;

void mincut(const string& str, const set<string>& dict)
{
     int dSize=dict.size();
     int sSize = str.size();
     if(dSize==0 || sSize==0)
         {
            cout<<"n/a";
            return;
         }
	//查找一样的
	
	 int index=0;
	 int temp;
	 int maxLen;

	 set<string>::iterator ite = dict.begin();
	 while(index!=sSize)
	 {
		 ite = dict.begin();
		 cout<<"ite111="<<*ite<<endl;
		 cout<<"index="<<index<<endl;
		 maxLen=-1;
		 for(;ite!=dict.end();ite++)
		 {
			 temp = str.find(*ite,index);	
			
			cout<<"ite222="<<*ite<<endl;
			cout<<"temp="<<temp<<" ,index="<<index<<endl;
			 if(temp==index)	//找到了可以符合相同的单词
				{
					//if(maxLen<(*ite).size())
						maxLen=(*ite).size();
					cout<<"****maxLen="<<maxLen;
				}
		 }
		cout<<"maxLen="<<maxLen<<endl;
		 if(maxLen==-1)	//说明一个都不符合，都没找到，
		 {
			cout<<"n/a";
			return;
		 }else
		 {
			index = temp+maxLen;	//然其往下走	
		 }

	 }
	 cout<<"ok"<<endl;
}


int main(int argc, const char * argv[])
{
    string strS="ilikealibaba";
    string dictStr;
    int nDict;
    set<string> dict;
    
    cin>>nDict;
    for (int i = 0; i < nDict; i++)
    {
        cin>>dictStr;
        dict.insert(dictStr);
		cout<<dictStr<<endl;
    }
    mincut(strS, dict);
    
    return 0;
}
