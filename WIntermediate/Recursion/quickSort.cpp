#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (pivot >= arr[i])
        {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] > arr[pivotIndex])
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    // left part ko sort kro
    quickSort(arr, s, p - 1);

    // right part ko sort kro
    quickSort(arr, p + 1, e);
}

int main()
{

    int arr[10] = {0, 31, 23, 3, 14, 45, 6, 5, 2, 8};
    int n = 10;

    quickSort(arr, 0, n - 1);

    return 0;
}