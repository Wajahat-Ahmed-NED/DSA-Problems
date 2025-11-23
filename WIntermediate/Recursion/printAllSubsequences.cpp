// Online C++ compiler to run C++ program online
// Order is preserved in subsequence, subsequence never comes in backward direction
#include <iostream>
#include <vector>
using namespace std;

void powerSet(int ind, vector<int> &temp, vector<int> &arr)
{
    if (ind >= arr.size())
    {
        for (int i : temp)
        {
            cout << i << " ";
        }
        if (temp.size() == 0)
            cout << "{}" << " ";
        cout << endl;

        return;
    }

    temp.push_back(arr[ind]);
    powerSet(ind + 1, temp, arr);

    temp.pop_back();
    powerSet(ind + 1, temp, arr);
}

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";
    vector<int> arr = {1, 2, 3};
    vector<int> temp = {};

    powerSet(0, temp, arr);
    return 0;
}