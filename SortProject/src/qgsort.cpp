#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include"../inc/qgsort.h"


//直接插入排序：
void insertSort(int * a,int n)
{
	int i,j;
	int t;
	for(i=1;i<n;i++)
	{
		if(a[i]<a[i-1])
		{
			t=a[i];
			for(j=i-1;j>=0&&a[j]>t;j--)
				a[j+1]=a[j];
			a[j+1]=t;
		}
	}
}


void MergeArray(int *a,int begin,int mid,int end,int *temp){

    int i = begin,j = mid + 1;
    int m = mid,n = end;
    int k = 0;

    //开始合并两个数组；
    while(i <= m && j <= n){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }

    while(i <= m){
        temp[k++] = a[i++];
    }

    while(j <= n){
        temp[k++] = a[j++];
    }

    //把temp数组中的结果装回a数组
    for(i = 0;i < k;i++){
        a[begin + i] = temp[i];
    }
}

void MergeSort(int *a,int begin,int end,int *temp){
    if(begin < end){

        int mid = (begin + end) / 2;
        /**
         *  分别递归进行排序，也称为2-路归并；
         */
        MergeSort(a,begin,mid,temp);   //左边有序
        MergeSort(a,mid + 1,end,temp);   //右边有序
        MergeArray(a,begin,mid,end,temp); //将左右两边有序的数组合并
    }
}

void QuickSort_Recursion(int *a, int begin, int end)
{
    int i = begin, j = end;
    int temp;
    int pivot = a[begin]; //选取第一个元素为基准点

    while(i <= j)
    {
        //找到左边大于基准点的元素
        while(a[i] < pivot)
        {
            i++;
        }
        //找到右边小于基准点的元素
        while(a[j] > pivot)
        {
            j--;
        }

        //当左边下标小于右边时，互换元素
        if(i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            //互换后i, j继续靠近
            i++;
            j--;
        }
    }

    //左边进行递归
    if(i < end)
    {
        QuickSort_Recursion(a, i, end);
    }
    //右边进行递归
    if(begin < j)
    {
        QuickSort_Recursion(a, begin, j);
    }
}

void CountSort(int *a, int size , int max)
{
    int i;
    int *count, *sorted;

    //给计数器和已排序数组分配空间
    count = (int *)malloc(sizeof(int) * (max + 1));
    sorted = (int *)malloc(sizeof(int) * size);
    if(count == NULL || sorted == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }

    //计数数组初始化为0
    for(i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    //收集原数组中每种值的个数
    for(i = 0; i < size; i++)
    {
        count[a[i]]++;
    }
    //统计所有小于等于该值的元素个数
    for(i = 1; i < max + 1; i++)
    {
        count[i] += count[i - 1];
    }
    //将所有元素按收集表分配到对应位置，反向填充目标数组
    for(i = size - 1; i >= 0; i--)
    {
        //先将计数数组中对应值-1
        count[a[i]]--;
        sorted[count[a[i]]] = a[i];
    }
    //已排序数组替代原数组
    for(i = 0; i < size; i++)
    {
        a[i] = sorted[i];
    }

    //释放内存
    free(count);
    free(sorted);
}
void RadixCountSort(int *a,int size)
{
    int base = 10; //基数设为10
    int i, n, index, max, maxnum, pval;
    int *count, *sorted;

    //计算数组中的最大值
    max = arrayMax(a, size);
    //计算数据最高位
    maxnum = getDigitNum(max);

    //给计数器和已排序数组分配空间
    count = (int *)malloc(sizeof(int) * base);
    sorted = (int *)malloc(sizeof(int) * size);
    if(count == NULL || sorted == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }

    for(n = 0; n < maxnum; n++)
    {
        //计数数组初始化为0
        for(i = 0; i < base; i++)
        {
            count[i] = 0;
        }
        //计算位置值
        pval = pow(base, n);
        //统计当前位上每个数值出现的次数
        for(i = 0; i < size; i++)
        {
            index = a[i] / pval % base;
            count[index]++;
        }
        //统计所有小于等于该值的元素个数
        for(i = 1; i < base; i++)
        {
            count[i] += count[i - 1];
        }
        //将所有元素按收集表分配到对应位置
        for(i = size - 1; i >= 0; i--)
        {
            index = a[i] / pval % base;
            count[index]--;
            sorted[count[index]] = a[i];
        }
        //已排序数组替代原数组
        memcpy(a, sorted, sizeof(int) * size);
    }

    //释放内存
    free(count);
    free(sorted);
}

int arrayMax(int *arr, int size)
{
    int i, max = arr[0];
    for(i = 0; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int getDigitNum(int x)
{
    if(x == 0)
    {
        return 1;
    }
    else
    {
        int res;//数据最高位
        while(x != 0)
        {
            x /= 10;
            res++;
        }
        return res;
    }
}

int NumberOfThree(int *a,int begin,int end)
{
	int mid = (begin + end) / 2 + begin;

	if (a[mid] > a[end])
	{
		Swap(&a[mid], &a[end]);
	}
	if (a[begin] > a[end])
	{
		Swap(&a[begin], &a[end]);
	}
	if (a[mid] > a[begin])
	{
		Swap(&a[mid], &a[begin]);
	}
	//此时a[mid] <= a[begin] <= a[end]
	return a[begin];
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void print()
{
    int len, max, i; //数组长度，数组最大值，计数器
    int *data; //存入原始数据
    int *arr1, *arr2, *arr3, *arr4, *arr5, *arr6, *arr7, *arr8; //进行各种排序的数组
    int *temp = NULL;

    //printf("没有写防脸滚键盘的功能，测试的时候请按要求输入！\n");
    //录入数据
    printf("请输入数组长度：");
    scanf("%d", &len);
    data = (int *)malloc(sizeof(int) * len);
    if(data == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return ;
    }
    printf("请录入整型数据(以回车间隔)：\n");
    for(i = 0; i < len; i++)
    {
        scanf("%d", data + i);
    }
    //打印原始数据
    printf("数据录入完毕\n录入的数据为：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(data + i));
    }
    printf("\n");

    //进行插入排序
    arr3 = (int *)malloc(sizeof(int) * len);
    if(arr3 == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return ;
    }
    memcpy(arr3, data, sizeof(int) * len);
    insertSort(arr3, len);
    printf("插入排序后结果：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr3 + i));
    }
    printf("\n");

    //进行归并排序
    arr4 = (int *)malloc(sizeof(int) * len);
    if(arr4 == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return ;
    }
    temp = (int *)malloc(sizeof(int) * len);
    if(temp == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return ;
    }
    memcpy(arr4, data, sizeof(int) * len);
    MergeSort(arr4, 0, len - 1, temp);
    printf("归并排序后结果：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr4 + i));
    }
    free(temp);
    printf("\n");

    //进行快速排序(递归)
    arr5 = (int *)malloc(sizeof(int) * len);
    if(arr5 == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return ;
    }
    memcpy(arr5, data, sizeof(int) * len);
    QuickSort_Recursion(arr5, 0, len - 1);
    printf("快速排序(递归)后结果：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr5 + i));
    }
    printf("\n");


    //进行计数排序
    arr7 = (int *)malloc(sizeof(int) * len);
    if(arr7 == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return ;
    }
    memcpy(arr7, data, sizeof(int) * len);
    //找到数组中的最大值
    max = arrayMax(arr7, len);
    CountSort(arr7, len, max);
    printf("计数排序后结果：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr7 + i));
    }
    printf("\n");

    //进行基数排序
    arr8 = (int *)malloc(sizeof(int) * len);
    if(arr8 == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return ;
    }
    memcpy(arr8, data, sizeof(int) * len);
    RadixCountSort(arr8, len);
    printf("基数排序后结果：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr8 + i));
    }
    printf("\n");

    //释放内存
    free(data);
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);
    free(arr6);
    free(arr7);
    free(arr8);

    system("pause");
}
