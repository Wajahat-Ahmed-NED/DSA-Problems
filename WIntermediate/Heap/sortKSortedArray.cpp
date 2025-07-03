// Online C++ compiler to run C++ program online

// sortKSortedArray or nearlySortedArray
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    // Write C++ code here
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    vector<int> ans;

    int k = 3;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k + 1; i++)
    {
        pq.push(arr[i]);
    }

    int i = k + 1;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();

        if (i < arr.size())
        {
            pq.push(arr[i++]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << "Try programiz.pro";

    return 0;
}