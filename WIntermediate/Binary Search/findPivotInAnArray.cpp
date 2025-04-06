// Source: None
class Solution
{
public:
    int findPivotInAnArray(vector<int> &arr) // same as finding minimum element in a rotated sorted array
    {
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {
            if (arr[mid] < arr[0])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }
};

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int findPivotInAnArray(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid;

    while (s < e)
    {
        mid = s + (e - s) / 2;

        if (arr[mid] < arr[0])
        {
            e = mid;
        }
        else
            s = mid + 1;
    }

    return e;
}
int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";
    vector<int> arr = {5, 6, 7, 8, 1, 2, 3, 4};
    cout << findPivotInAnArray(arr) << endl;

    return 0;
}