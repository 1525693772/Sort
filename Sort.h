#define Cutoff 32

typedef int ET;

void Menu();

void RandomNum(int size);

void PrintArray(ET *array, const int length);

void Swap(ET *a, ET *b);

void BubbleSort(ET *array, const int length);
void BubbleSortOptimization1(ET *array, const int length);
void BubbleSortOptimization2(ET *array, const int length);

void InsertionSort_NoPrint(ET *array, const int length);

int Median3(ET *array, int left, int right);
void QSort(ET *array, int left, int right);
void QSortOptimization(ET *array, int left, int right);
void QuickSort(ET *array, const int length);
void QuickSortOptimization(ET *array, const int length);

void ShellSort(ET *array, const int length);