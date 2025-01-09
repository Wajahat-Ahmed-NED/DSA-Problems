// Source : HackerRank
#include <vector>
#include <iostream>
using namespace std;

int twoStacks(int maxSum, vector<int> a, vector<int> b)
{
    int cnt = 0;
    int sum = 0;
    int i = 0;
    int j = 0;

    while (i < a.size() && sum + a[i] <= maxSum)
    {
        sum += a[i];
        i++;
        cnt++;
    }

    while (j < b.size() && i >= 0)
    {

        sum += b[j];
        j++;

        while (sum > maxSum && i > 0)
        {
            i--;
            sum -= a[i];
        }

        if (sum <= maxSum)
        {
            cnt = max(cnt, i + j);
        }
    }
    return cnt;
}
