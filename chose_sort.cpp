//选择排序其实就是比冒泡排序少一点交换次数，因为它记录的是index，等最后一次进行交换
//选择排序
template<typename T>
void quick_sort(T arr[],int length)
{
    for (int i = 0; i < length-1; i++)
    {
        int minIndex=i;
        for (int j = i+1; j < length; j++)
        {
            if (arr[j]<arr[i])
            {
                minIndex=j;
            }
        }
        if(minIndex!=i){
            T temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }

    }
}
