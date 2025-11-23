// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void powerSet(int ind, vector<int> &temp, vector<int> &arr, int currSum, int sum)
{

    if (ind >= arr.size())
    {
        if (currSum == sum)
        {
            for (int i : temp)
            {
                cout << i << " ";
            }
            if (temp.size() == 0)
                cout << "{}" << " ";
            cout << endl;
        }
        // cout<<arr[ind]<<endl;
        return;
    }

    temp.push_back(arr[ind]);
    currSum += arr[ind];
    powerSet(ind + 1, temp, arr, currSum, sum);

    temp.pop_back();
    currSum -= arr[ind];
    powerSet(ind + 1, temp, arr, currSum, sum);
}

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";
    int sum = 2;
    vector<int> arr = {1, 1, 2, 3};
    vector<int> temp = {};
    int currSum = 0;

    powerSet(0, temp, arr, currSum, sum);
    return 0;
}