// 本程序可以用来计算各种排序对于数组长度的敏感度
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *bubble_sort(int *, int);
int *quick_sort(int *, int);

int main(void)
{
    int size = 0;
    printf("请输入数组长度");
    scanf("%d", &size);
    int arr[size];

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;
    }
    int start_time = time(NULL);
    bubble_sort(arr, size);
    int end_time = time(NULL);
    int time = end_time - start_time;
    printf("长度为%d的数组冒泡排序用时%d时%d分%d秒", size, time / 3600, time % 3600 / 60, time % 60);
    return 0;
}

int *bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] = arr[i] ^ arr[j];
                arr[j] = arr[j] ^ arr[i];
                arr[i] = arr[i] ^ arr[j];
            }
        }
    }
    return arr;
}

int *quick_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] = arr[i] ^ arr[j];
                arr[j] = arr[j] ^ arr[i];
                arr[i] = arr[i] ^ arr[j];
            }
        }
    }
    return arr;
}
