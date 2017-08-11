//插入排序的原理其实就是从前面开始，逐渐的对排好序的数组进行插入值，这个插入的顺序就是从后往上，实现了往后移动，以便覆盖插入
//插入排序
template<typename T>
void insert_sort(T arr[],int length)
{
    for (int i = 1; i < length; i++)
    {
//记录要插入的值
        int temp=arr[i];
        int j;
        for ( j = i; j >0; j--)
        {
            

            if (temp < arr[j-1])
            {
                arr[j]=arr[j-1];
                arr[j-1] = temp;    //每次进行了覆盖，如果不这样，就需要特别考虑
            }

        }

    }
}
