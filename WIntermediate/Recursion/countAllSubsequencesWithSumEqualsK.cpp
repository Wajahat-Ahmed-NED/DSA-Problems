// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int powerSet(int ind, vector<int> &arr, int currSum, int sum)
{

    if (ind >= arr.size())
    {
        if (currSum == sum)
            return 1;
        return 0;
    }

    currSum += arr[ind];
    int l = powerSet(ind + 1, arr, currSum, sum);

    currSum -= arr[ind];
    int r = powerSet(ind + 1, arr, currSum, sum);

    return l + r;
}

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";
    int sum = 2;
    vector<int> arr = {1, 2, 3};
    vector<int> temp = {};
    int currSum = 0;

    cout << powerSet(0, arr, currSum, sum);
    return 0;
}