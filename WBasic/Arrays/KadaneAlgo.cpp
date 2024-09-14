// Max sub array sum

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";
    vector<int> arr = {-5, -3, 2, 5, 6, -5, 3, -9};
    int curr = 0;
    int maxTillNow = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        curr += arr[i];
        maxTillNow = max(curr, maxTillNow);
        if (curr < 0)
            curr = 0;
    }

    cout << maxTillNow << endl;

    return 0;
}