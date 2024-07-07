// Leetcode Link: https://leetcode.com/problems/first-missing-positive/
// TLE occured
#include <algorithm>

class Solution
{
public:
    vector<long long> countPositiveNum(vector<int> &nums)
    {
        int cnt = 0;
        long long min = 0;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                cnt++;
                sum += nums[i];
                if (min == 0)
                    min = nums[i];
                else if (min > nums[i])
                    min = nums[i];
            }
        }
        vector<long long> arr = {cnt, min, sum};
        return arr;
    }

    bool isElementPresent(vector<int> arr, long long size, long long target)
    {

        for (int i = 0; i < size; ++i)
        {
            if (arr[i] == target)
            {
                return true;
            }
        }
        return false;
    }
    int firstMissingPositive(vector<int> &nums)
    {
        vector<long long> arr = countPositiveNum(nums);
        if (arr[1] > 1)
            return 1;
        else if (arr[1] == 1)
        {

            for (int i = 0; i <= nums.size(); i++)
            {
                bool flag = isElementPresent(nums, nums.size(), i + 1);
                if (!flag)
                {
                    return i + 1;
                }
            }
        }
        return 1;
    }
};