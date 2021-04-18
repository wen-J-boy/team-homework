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

//�궨�峣��
#define LEN 10000 //���Դ���������������鳤��
#define N 100000 //ִ�д���
#define M 100 //ÿ������ĳ���
#define RANGE 1000 //�������Χ

int main()
{

    print();
    return 0;

    //test

    /*int i, j, max;
    int test1[LEN], test2[M];
    int *temp;
    clock_t start, end;
    //���ɴ�����
    for(i = 0; i < LEN; i++) //����LEN�������
    {
        test1[i] = rand() % RANGE; //����0~999������(range - 1)
    }

    ofstream ofs;
    ofs.open(FILENAME, ios::in);//���ļ�
    for(int x=0;x<LEN;x++)
    {
        ofs<<test1[x]<<" ";
    }
    cout << "����ɹ�" << endl;
    ofs.close();//�ر��ļ�

    ifstream ifs;
    ifs.open(FILENAME, ios::in);//���ļ�
    if (!ifs.is_open())//�ж��Ƿ����
    {
        cout << "�ļ�������" << endl;
        ifs.close();
        return 0;
    }
    int y=0;
    while(ifs>>test1[y]){
        y++;
    }
    ifs.close();//�ر��ļ�

    //�����ݲ���
    printf("������%d�����ݵ����������\n", LEN);

    //��������
    start = clock();
    insertSort(test1, LEN);
    end = clock();
    printf("��������%d ms\n", end - start);

    //�鲢����
    temp = (int *)malloc(sizeof(int) * LEN);
    if(temp == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    start = clock();
    MergeSort(test1, 0, LEN - 1, temp);
    end = clock();
    printf("�鲢����%d ms\n", end - start);
    free(temp);

    //��������(�ݹ�)
    start = clock();
    QuickSort_Recursion(test1, 0, LEN - 1);
    end = clock();
    printf("��������(�ݹ�)��%d ms\n", end - start);

    //��������
    start = clock();
    max = arrayMax(test1, LEN);
    CountSort(test1, LEN, max);
    end = clock();
    printf("��������%d ms\n", end - start);

    //��������
    start = clock();
    RadixCountSort(test1, LEN);
    end = clock();
    printf("��������%d ms\n", end - start);

    //���Դ���С����
    //����100k������ÿ�ζԴ�СΪ100�������������
    printf("������Դ���С����\n");

    //��������
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
    printf("��������%d ms\n", end - start);

    //�鲢����
    start = clock();
    for(i = 0; i < N; i++)
    {
        temp = (int *)malloc(sizeof(int) * M);
        if(temp == NULL)
        {
            printf("�ڴ����ʧ��\n");
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
    printf("�鲢����%d ms\n", end - start);

    //��������(�ݹ�)
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
    printf("��������(�ݹ�)��%d ms\n", end - start);

    //��������
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
    printf("��������%d ms\n", end - start);

    //��������
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
    printf("��������%d ms\n", end - start);

    system("pause");
    return 0;
    */
}
