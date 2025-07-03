#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool getScore(long long sum, int len, long long k)
    {
        return (sum * len) < k;
    }

public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long long count = 0;
        int i = 0;
        int j = 0;
        long long sum = 0;

        while (j < nums.size())
        {
            sum += nums[j];

            while (i <= j && !getScore(sum, j - i + 1, k))
            {
                sum -= nums[i];
                i++;
            }

            count += (j - i + 1);
            j++;
        }

        return count;
    }
};