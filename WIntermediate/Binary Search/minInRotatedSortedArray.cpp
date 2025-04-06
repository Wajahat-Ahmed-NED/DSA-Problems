// Leetcode Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <vector>
class Solution
{
public:
    int findMin(vector<int> &nums) // same as finding Pivot in a rotated sorted array
    {

        int s = 0;
        int e = nums.size() - 1;
        int mid;

        while (s < e)
        {
            mid = s + (e - s) / 2;
            if (nums[mid] > nums[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }

        return nums[s];
    }
};