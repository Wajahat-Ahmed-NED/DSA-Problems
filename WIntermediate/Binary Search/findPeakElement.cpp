#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int mid;

        while (s <= e)
        {
            mid = s + (e - s) / 2;

            int prev = (mid - 1) < 0 ? INT_MIN : nums[mid - 1];
            int next = (mid + 1) >= n ? INT_MIN : nums[mid + 1];

            if (nums[mid] > prev && nums[mid] > next)
                return mid;
            else if (nums[mid] < prev && nums[mid] > next)
                e = mid - 1;
            else
                s = mid + 1;
        }

        return 0; // This line wont reach because according to the problem statement, there is always a peak element.
        // For this testcase [-2713125615] (INT_MIN), the output should be 0 because we can compare INT_MIN with INT_MIN.
        // So for this edge case we simply return 0.
    }
};