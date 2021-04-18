#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include"../inc/qgsort.h"


//ֱ�Ӳ�������
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

    //��ʼ�ϲ��������飻
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

    //��temp�����еĽ��װ��a����
    for(i = 0;i < k;i++){
        a[begin + i] = temp[i];
    }
}

void MergeSort(int *a,int begin,int end,int *temp){
    if(begin < end){

        int mid = (begin + end) / 2;
        /**
         *  �ֱ�ݹ��������Ҳ��Ϊ2-·�鲢��
         */
        MergeSort(a,begin,mid,temp);   //�������
        MergeSort(a,mid + 1,end,temp);   //�ұ�����
        MergeArray(a,begin,mid,end,temp); //�������������������ϲ�
    }
}

void QuickSort_Recursion(int *a, int begin, int end)
{
    int i = begin, j = end;
    int temp;
    int pivot = a[begin]; //ѡȡ��һ��Ԫ��Ϊ��׼��

    while(i <= j)
    {
        //�ҵ���ߴ��ڻ�׼���Ԫ��
        while(a[i] < pivot)
        {
            i++;
        }
        //�ҵ��ұ�С�ڻ�׼���Ԫ��
        while(a[j] > pivot)
        {
            j--;
        }

        //������±�С���ұ�ʱ������Ԫ��
        if(i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            //������i, j��������
            i++;
            j--;
        }
    }

    //��߽��еݹ�
    if(i < end)
    {
        QuickSort_Recursion(a, i, end);
    }
    //�ұ߽��еݹ�
    if(begin < j)
    {
        QuickSort_Recursion(a, begin, j);
    }
}

void CountSort(int *a, int size , int max)
{
    int i;
    int *count, *sorted;

    //�����������������������ռ�
    count = (int *)malloc(sizeof(int) * (max + 1));
    sorted = (int *)malloc(sizeof(int) * size);
    if(count == NULL || sorted == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }

    //���������ʼ��Ϊ0
    for(i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    //�ռ�ԭ������ÿ��ֵ�ĸ���
    for(i = 0; i < size; i++)
    {
        count[a[i]]++;
    }
    //ͳ������С�ڵ��ڸ�ֵ��Ԫ�ظ���
    for(i = 1; i < max + 1; i++)
    {
        count[i] += count[i - 1];
    }
    //������Ԫ�ذ��ռ�����䵽��Ӧλ�ã��������Ŀ������
    for(i = size - 1; i >= 0; i--)
    {
        //�Ƚ����������ж�Ӧֵ-1
        count[a[i]]--;
        sorted[count[a[i]]] = a[i];
    }
    //�������������ԭ����
    for(i = 0; i < size; i++)
    {
        a[i] = sorted[i];
    }

    //�ͷ��ڴ�
    free(count);
    free(sorted);
}
void RadixCountSort(int *a,int size)
{
    int base = 10; //������Ϊ10
    int i, n, index, max, maxnum, pval;
    int *count, *sorted;

    //���������е����ֵ
    max = arrayMax(a, size);
    //�����������λ
    maxnum = getDigitNum(max);

    //�����������������������ռ�
    count = (int *)malloc(sizeof(int) * base);
    sorted = (int *)malloc(sizeof(int) * size);
    if(count == NULL || sorted == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }

    for(n = 0; n < maxnum; n++)
    {
        //���������ʼ��Ϊ0
        for(i = 0; i < base; i++)
        {
            count[i] = 0;
        }
        //����λ��ֵ
        pval = pow(base, n);
        //ͳ�Ƶ�ǰλ��ÿ����ֵ���ֵĴ���
        for(i = 0; i < size; i++)
        {
            index = a[i] / pval % base;
            count[index]++;
        }
        //ͳ������С�ڵ��ڸ�ֵ��Ԫ�ظ���
        for(i = 1; i < base; i++)
        {
            count[i] += count[i - 1];
        }
        //������Ԫ�ذ��ռ�����䵽��Ӧλ��
        for(i = size - 1; i >= 0; i--)
        {
            index = a[i] / pval % base;
            count[index]--;
            sorted[count[index]] = a[i];
        }
        //�������������ԭ����
        memcpy(a, sorted, sizeof(int) * size);
    }

    //�ͷ��ڴ�
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
        int res;//�������λ
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
	//��ʱa[mid] <= a[begin] <= a[end]
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
    int len, max, i; //���鳤�ȣ��������ֵ��������
    int *data; //����ԭʼ����
    int *arr1, *arr2, *arr3, *arr4, *arr5, *arr6, *arr7, *arr8; //���и������������
    int *temp = NULL;

    //printf("û��д���������̵Ĺ��ܣ����Ե�ʱ���밴Ҫ�����룡\n");
    //¼������
    printf("���������鳤�ȣ�");
    scanf("%d", &len);
    data = (int *)malloc(sizeof(int) * len);
    if(data == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return ;
    }
    printf("��¼����������(�Իس����)��\n");
    for(i = 0; i < len; i++)
    {
        scanf("%d", data + i);
    }
    //��ӡԭʼ����
    printf("����¼�����\n¼�������Ϊ��\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(data + i));
    }
    printf("\n");

    //���в�������
    arr3 = (int *)malloc(sizeof(int) * len);
    if(arr3 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return ;
    }
    memcpy(arr3, data, sizeof(int) * len);
    insertSort(arr3, len);
    printf("�������������\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr3 + i));
    }
    printf("\n");

    //���й鲢����
    arr4 = (int *)malloc(sizeof(int) * len);
    if(arr4 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return ;
    }
    temp = (int *)malloc(sizeof(int) * len);
    if(temp == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return ;
    }
    memcpy(arr4, data, sizeof(int) * len);
    MergeSort(arr4, 0, len - 1, temp);
    printf("�鲢���������\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr4 + i));
    }
    free(temp);
    printf("\n");

    //���п�������(�ݹ�)
    arr5 = (int *)malloc(sizeof(int) * len);
    if(arr5 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return ;
    }
    memcpy(arr5, data, sizeof(int) * len);
    QuickSort_Recursion(arr5, 0, len - 1);
    printf("��������(�ݹ�)������\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr5 + i));
    }
    printf("\n");


    //���м�������
    arr7 = (int *)malloc(sizeof(int) * len);
    if(arr7 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return ;
    }
    memcpy(arr7, data, sizeof(int) * len);
    //�ҵ������е����ֵ
    max = arrayMax(arr7, len);
    CountSort(arr7, len, max);
    printf("�������������\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr7 + i));
    }
    printf("\n");

    //���л�������
    arr8 = (int *)malloc(sizeof(int) * len);
    if(arr8 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return ;
    }
    memcpy(arr8, data, sizeof(int) * len);
    RadixCountSort(arr8, len);
    printf("�������������\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr8 + i));
    }
    printf("\n");

    //�ͷ��ڴ�
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
