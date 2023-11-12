// source leetcode
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int len = nums.size();
        int totalSum = len * (len + 1) / 2;

        int sum = 0;

        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
        }

        return totalSum - sum;
    }
};