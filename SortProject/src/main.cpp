#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<fstream>
#include<iostream>
using namespace std;

#include "../inc/qgsort.h"

//宏定义常量
#define LEN 10000 //测试大数据下排序的数组长度
#define N 100000 //执行次数
#define M 100 //每个数组的长度
#define RANGE 1000 //随机数范围

int main()
{

    print();
    return 0;

    //test

    /*int i, j, max;
    int test1[LEN], test2[M];
    int *temp;
    clock_t start, end;
    //生成大数据
    for(i = 0; i < LEN; i++) //生成LEN个随机数
    {
        test1[i] = rand() % RANGE; //生成0~999的数据(range - 1)
    }

    ofstream ofs;
    ofs.open(FILENAME, ios::in);//读文件
    for(int x=0;x<LEN;x++)
    {
        ofs<<test1[x]<<" ";
    }
    cout << "保存成功" << endl;
    ofs.close();//关闭文件

    ifstream ifs;
    ifs.open(FILENAME, ios::in);//读文件
    if (!ifs.is_open())//判断是否存在
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return 0;
    }
    int y=0;
    while(ifs>>test1[y]){
        y++;
    }
    ifs.close();//关闭文件

    //大数据测试
    printf("下面是%d个数据的排序情况：\n", LEN);

    //插入排序
    start = clock();
    insertSort(test1, LEN);
    end = clock();
    printf("插入排序：%d ms\n", end - start);

    //归并排序
    temp = (int *)malloc(sizeof(int) * LEN);
    if(temp == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }
    start = clock();
    MergeSort(test1, 0, LEN - 1, temp);
    end = clock();
    printf("归并排序：%d ms\n", end - start);
    free(temp);

    //快速排序(递归)
    start = clock();
    QuickSort_Recursion(test1, 0, LEN - 1);
    end = clock();
    printf("快速排序(递归)：%d ms\n", end - start);

    //计数排序
    start = clock();
    max = arrayMax(test1, LEN);
    CountSort(test1, LEN, max);
    end = clock();
    printf("计数排序：%d ms\n", end - start);

    //基数排序
    start = clock();
    RadixCountSort(test1, LEN);
    end = clock();
    printf("基数排序：%d ms\n", end - start);

    //测试大量小数组
    //进行100k次排序，每次对大小为100的数组进行排序
    printf("下面测试大量小数组\n");

    //插入排序
    start = clock();
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            test2[j] = rand() % RANGE;
        }
        insertSort(test2, M);
    }
    end = clock();
    printf("插入排序：%d ms\n", end - start);

    //归并排序
    start = clock();
    for(i = 0; i < N; i++)
    {
        temp = (int *)malloc(sizeof(int) * M);
        if(temp == NULL)
        {
            printf("内存分配失败\n");
            system("pause");
            exit(0);
        }
        for(j = 0; j < M; j++)
        {
            test2[j] = rand() % RANGE;
        }
        MergeSort(test2, 0, M - 1, temp);
        free(temp);
    }
    end = clock();
    printf("归并排序：%d ms\n", end - start);

    //快速排序(递归)
    start = clock();
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            test2[j] = rand() % RANGE;
        }
        QuickSort_Recursion(test2, 0, M - 1);
    }
    end = clock();
    printf("快速排序(递归)：%d ms\n", end - start);

    //计数排序
    start = clock();
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            test2[j] = rand() % RANGE;
        }
        max = arrayMax(test2, M);
        CountSort(test2, M, max);
    }
    end = clock();
    printf("计数排序：%d ms\n", end - start);

    //基数排序
    start = clock();
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            test2[j] = rand() % RANGE;
        }
        RadixCountSort(test2, M);
    }
    end = clock();
    printf("基数排序：%d ms\n", end - start);

    system("pause");
    return 0;
    */
}
