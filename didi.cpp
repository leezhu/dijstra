
#include<bits/stdc++.h>
using namespace std;

int RandomInRange(int start,int end)
    {
    return rand()%(end-start-1)+start;
}

void Swap(vector<int>& data,int p1,int p2)
    {
    int temp;
    temp=data[p1];
    data[p1]=data[p2];
    data[p2]=temp;
}



int Partition(vector<int> &data,int start,int end)
{
	int index = RandomInRange(start,end);
//	Swap(&data[index],&data[end]);
	
	int small = start-1;
	for(index = start;index<end;++index)
	{
		if(data[index]<data[end])
		{
			++small;
			if(small!=index)
				;
//				;Swap(&data[index],&data[small]);
		}
	}
	++small;
//	Swap(&data[small],&data[end]);
	return small;
}

 int patition(vector<int> &numbers,int left,int right)
        {
        
        int key = numbers[left];
        while(left<right)
            {
            while(left<right && key>numbers[right])
                right--;
            numbers[left]=numbers[right];
            //left++;
            while(left<right && key<numbers[left])
             	left++;
            numbers[right]=numbers[left];
            //right--;
        }
        numbers[left]=key;
        return left;
    }

int GetLeastNumbers_Solution(vector<int>& input, int k) {
        vector<int> result;
        //if(input.size()==0 || k<=0 || k>input.size())
           // return result;
        
        int left=0;
        int right=input.size()-1;
        int index=patition(input,left,right);
        
        while(index!=(k-1)){
            if(index>(k-1))
            	index = patition(input,left,index-1);
            else 
                index = patition(input,index+1,right);
        }
        //for(int i=0;i<k;i++)
        //    result.push_back(input[i]);
       // sort(result.begin(),result.end());
        return input[k-1];
    }
    
   

int main()
    {
    int k=2;
    int temp;
	int array[]={45,67,33,21};
    vector<int> data(array,array+4);
	sort(data.begin(),data.end());
	int len=data.size();
	cout<<data[len-k];
    //while(cin>>temp)
    //    {
    //    data.push_back(temp);
    //}
    //cin>>k;
    //cout<<GetLeastNumbers_Solution(data,k);
    return 0;
}

