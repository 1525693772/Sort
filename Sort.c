#include "Sort.h"
#include "fatal.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

void Menu()
{
    printf("================Menu================\n");
    printf("-1.Clear data file\n");
    printf("0.Exit\n");
    printf("1.Generate random number\n");
    printf("2.Read data in keyboard\n");
    printf("3.Read data in file\n");
    printf("4.Bubble sort\n");
    printf("5.Bubble sort Optimization1\n");
    printf("6.Bubble sort Optimization2\n");
    printf("7.Quick sort\n");
    printf("8.Quick sort Optimization\n");
    printf("=====================================\n");
}

void RandomNum(int size)
{
    FILE *fp;
    if ((fp = fopen("./Sort 1/Data/UnsortedData.TXT", "a")) == NULL)
        Error("Fail to open file!\n");
    setbuf(fp, NULL);
    srand((unsigned int)time(NULL));
    fprintf(fp, "%d\n", size);
    fflush(fp);
    int num, i;
    for (i = 0; i < size; i++)
    {
        if (i % 100 == 0)
        {
            Sleep(1500);
            srand((unsigned int)time(NULL));
        }
        fprintf(fp, "%d ", rand() % 100000);
        fflush(fp);
    }
    fprintf(fp, "\n");
    fflush(fp);
    fclose(fp);
}

void PrintArray(ET *array, const int length)
{
    int i;
    for (i = 0; i < length; i++)
        printf("%d ", array[i]);
    puts("");
}

void Swap(ET *a, ET *b)
{
    if (a == b)
        return;
    ET tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(ET *array, const int length)
{
    if (!array)
        Error("Invalid array!\n");
    int i, o;
    printf("The origin sequence : ");
    PrintArray(array, length);
    for (i = length - 1; i > 0; i--)
    {
        for (o = 0; o < i; o++)
            if (array[o] > array[o + 1])
                Swap(&array[o], &array[o + 1]);
    }
    printf("The ordered sequence is : ");
    PrintArray(array, length);
    puts("");
}

void BubbleSortOptimization1(ET *array, const int length)
{
    if (!array)
        Error("Invalid array!\n");
    int i, o, flag;
    printf("The origin sequence : ");
    PrintArray(array, length);
    for (i = length - 1; i > 0; i--)
    {
        flag = 0;
        for (o = 0; o < i; o++)
            if (array[o] > array[o + 1])
            {
                Swap(&array[o], &array[o + 1]);
                flag = 1; //If there has a swap,flag=1
            }
        if (flag == 0) //This means there isn't swap,the sequence is ordered
            break;
    }
    printf("The ordered sequence is : ");
    PrintArray(array, length);
    puts("");
}

void BubbleSortOptimization2(ET *array, const int length)
{
    if (!array)
        Error("Invalid array!\n");
    int i, o, flag;
    printf("The origin sequence : ");
    PrintArray(array, length);
    for (i = length - 1; i > 0; i = flag)
    {
        flag = 0;
        for (o = 0; o < i; o++) //start from 0 to flag
            if (array[o] > array[o + 1])
            {
                Swap(&array[o], &array[o + 1]);
                flag = o; //Record the last swap's position
            }
    }
    printf("The ordered sequence is : ");
    PrintArray(array, length);
    puts("");
}

void InsertionSort_NoPrint(ET *array, const int length)
{
    if (!array)
        Error("Invalid array!\n");
    int i, o, tmp;
    for (i = 1; i < length; i++)
    {
        tmp = array[i];
        for (o = i; o > 0 && array[o - 1] > tmp; o--)
            array[o] = array[o - 1];
        array[o] = tmp;
    }
}

int Median3(ET *array, int left, int right)
{
    int mid = (right + left) / 2;
    if (array[left] > array[mid])
        Swap(&array[left], &array[mid]);
    if (array[mid] > array[right])
        Swap(&array[mid], &array[right]);
    if (array[left] > array[mid])
        Swap(&array[left], &array[mid]);
    Swap(&array[mid], &array[right - 1]);
    return array[right - 1];
}

void QSort(ET *array, int left, int right)
{
    if (left >= right)
        return;
    int Pivot = Median3(array, left, right);
    int i = left + 1, j = right - 2;
    while (i < j)
    {
        while (array[i] < Pivot && i < j)
            i++;
        while (array[j] >= Pivot && i < j)
            j--;
        Swap(&array[i], &array[j]);
    }
    if (array[i] >= array[right])
        Swap(&array[i], &array[right]);
    else
        left++;
    if (left)
        QSort(array, left, i - 1);
    QSort(array, i + 1, right);
}

void QSortOptimization(ET *array, int left, int right)
{
    if (left + Cutoff <= right) //If the size is less than 34,then use insertion sort
    {
        int Pivot = Median3(array, left, right);
        int i = left + 1, j = right - 2;
        while (i < j)
        {
            while (array[i] < Pivot && i < j)
                i++;
            while (array[j] >= Pivot && i < j)
                j--;
            Swap(&array[i], &array[j]);
        }
        if (array[i] >= array[right])
            Swap(&array[i], &array[right]);
        else
            left++;
        if (left)
            QSortOptimization(array, left, i - 1);
        QSortOptimization(array, i + 1, right);
    }
    else
    {
        InsertionSort_NoPrint(array + left, right - left + 1);
    }
}

void QuickSort(ET *array, const int length)
{
    if (!array)
        Error("Invalid array!\n");
    printf("The origin sequence  :   ");
    PrintArray(array, length);
    QSort(array, 0, length - 1);
    printf("The result sequence is : ");
    PrintArray(array, length);
    puts("");
}

void QuickSortOptimization(ET *array, const int length)
{
    if (!array)
        Error("Invalid array!\n");
    printf("The origin sequence  :   ");
    PrintArray(array, length);
    QSortOptimization(array, 0, length - 1);
    printf("The result sequence is : ");
    PrintArray(array, length);
    puts("");
}

void ShellSort(ET *array, const int length)
{
    if (!array)
        Error("Invalid array!\n");
    int inc, i, j, o = 1;
    int temp;
    for (inc = length / 2; inc > 0; inc /= 2)
    {
        for (i = inc; i < length; i++)
        {
            temp = array[i];
            for (j = i - inc; j >= 0 && array[j] > temp; j -= inc)
                array[j + inc] = array[j];
            array[j + inc] = temp;
        }
    }
}