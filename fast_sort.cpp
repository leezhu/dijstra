//快速排序其实就是填坑的过程，每次交换后，都出现了一个坑。后面交换到前面的值需要前面索引增加，找出一个值来进行填坑，这样的过程是相反的

//核心代码如下
first=left;
high=right;

key=arr[first];
while(first < high)
{
    while(first < high && arr[high] > key)    //从后面开始寻找，如果出现比key大，那就往前面移动，不需要交换        high--;
    arr[first] = arr[high];    //一旦出现比key小的，就交换，形成一个坑

    while(first < high && arr[first] < key)    //都是大的，就不需要填坑交换
            first++;
    arr[high] = arr[first];
}

arr[first] = key;填好最后一次坑，这样就实现了一次排序循环，接着就是递归迭代

qsort(arr,0,first-1);
qsort(arr,first+1,right)
