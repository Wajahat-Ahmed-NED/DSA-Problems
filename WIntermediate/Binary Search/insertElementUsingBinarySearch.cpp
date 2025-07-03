// Leetcode Link: https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        int start = 0;
        int end = nums.size() - 1;

        int mid = 0;

        if (target > nums[nums.size() - 1])
            return nums.size();

        else if (target < nums[0])
        {
            return 0;
        }

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
                if (nums[mid + 1] > target)
                {
                    return mid + 1;
                }
            }
            else
            {
                end = mid - 1;
                if (nums[mid - 1] < target)
                {
                    return mid;
                }
            }
        }

        return 0;
    }
};