// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void mergeArr(vector<int> &arr, int s, int mid, int e)
{
    int i = s, j = mid + 1;

    while (i <= mid && j <= e)
    {
        if (arr[i] <= arr[j])
        {
            i++;
        }
        else
        {
            int val = arr[j];
            int ind = j;

            while (ind > i)
            {
                arr[ind] = arr[ind - 1];
                ind--;
            }

            arr[i] = val;

            i++;
            mid++;
            j++;
        }
    }
}

void mergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    mergeArr(arr, s, mid, e);
}

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";

    vector<int> arr = {5, 6, 1, 2, 0, 3, 9, 8};
    // {5,6,1,2,0,3,9,8}
    mergeSort(arr, 0, arr.size() - 1);

    for (auto a : arr)
    {
        cout << a << " ";
    }

    return 0;
}