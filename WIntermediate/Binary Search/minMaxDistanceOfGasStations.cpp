// Online C++ compiler to run C++ program online

// Using Priority Queue Approach

// TC => O (nlogn + klogn)
// SC => O (n-1)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
        cout << "First " << arr[i + 1] - arr[i] << " Sec " << i << endl;

        pq.push({arr[i + 1] - arr[i], i});
    }
    cout << endl;
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto tp = pq.top();
        pq.pop();

        int secInd = tp.second;

        howMany[secInd]++;

        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
        cout << "First " << newSecLen << " Sec " << secInd << endl;
        pq.push({newSecLen, secInd});
    }
    cout << pq.top().second << endl;
    return pq.top().first;
}

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";

    vector<int> arr = {1, 13, 17, 23};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << " The answer is: " << ans << "\n";

    return 0;
}

// Using Binary Search

// TC => O (nlogn + klogn)
// SC => O (1)

#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int> &arr)
{
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween))
        {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    // Find the maximum distance:
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    // Apply Binary search:
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
