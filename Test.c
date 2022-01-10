#include "Sort.h"
#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAXNUM 100000

int main()
{
    ET array[MAXNUM] = {0};
    FILE *fp, *fq;
    clock_t start, finish;
    int grp_num, t, grp[20];
    int i, o, length = 0;
    if ((fq = fopen("./Sort 1/Data/UnsortedData.TXT", "r")) == NULL)
        Error("Fail to open file!\n");
    while (1)
    {
        Menu();
        scanf("%d", &i);
        switch (i)
        {
        case -1:
            if ((fp = fopen("./Sort 1/Data/UnsortedData.TXT", "w")) == NULL)
                Error("Fail to open file!\n");
            fprintf(fp, "");
            printf("Clear successfully!\n");
            puts("");
            break;
        case 0:
            return 0;

        case 1:
            printf("How many groups of data you wanna generate?\n>");
            scanf("%d", &grp_num);
            printf("Please input the total number of each groups\n>");
            for (t = 0; t < grp_num; t++)
            {
                scanf("%d", &grp[t]);
                RandomNum(grp[t]);
                Sleep(1500);
            }
            printf("These generated data are saved in file,choose 3 in the menu to use!\n");
            break;
        case 2: //Read data in keyboard
            memset(array, 0, sizeof(array));
            printf("Please input the total number of the sequence you need sort:\n>");
            scanf("%d", &length);
            printf("Please input the sequence you need sort:\n>");
            for (o = 0; o < length; o++)
                scanf("%d", &array[o]);
            break;

        case 3: //Read in file
            memset(array, 0, sizeof(array));
            if (fscanf(fq, "%d", &length) == EOF)
                Error("Read EOF of data file\n");
            for (o = 0; o < length; o++)
                fscanf(fq, "%d", &array[o]);
            break;

        case 4:
            printf("You choosed : BubbleSort\n");
            if (length == 0)
            {
                printf("Please firstly input data from file of keyboard!\n");
                puts("");
                break;
            }
            start = clock();
            BubbleSort(array, length);
            finish = clock();
            printf("The running time is %f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
            break;

        case 5:
            printf("You choosed : BubbleSortOptimization1\n");
            if (length == 0)
            {
                printf("Please firstly input data from file of keyboard!\n");
                puts("");
                break;
            }
            start = clock();
            BubbleSortOptimization1(array, length);
            finish = clock();
            printf("The running time is %f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
            break;

        case 6:
            printf("You choosed : BubbleSortOptimization2\n");
            if (length == 0)
            {
                printf("Please firstly input data from file of keyboard!\n");
                puts("");
                break;
            }
            start = clock();
            BubbleSortOptimization2(array, length);
            finish = clock();
            printf("The running time is %f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
            break;

        case 7:
            printf("You choosed : QuickSort\n");
            if (length == 0)
            {
                printf("Please firstly input data from file of keyboard!\n");
                puts("");
                break;
            }
            start = clock();
            QuickSort(array, length);
            finish = clock();
            printf("The running time is %f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
            break;

        case 8:
            printf("You choosed : QuickSortOptimization\n");
            if (length == 0)
            {
                printf("Please firstly input data from file of keyboard!\n");
                puts("");
                break;
            }
            start = clock();
            QuickSortOptimization(array, length);
            finish = clock();
            printf("The running time is %f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
            break;

        default:
            break;
        }
    }
    fclose(fp);
    return 0;
}