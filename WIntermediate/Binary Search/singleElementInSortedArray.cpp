#include <bits/stdc++.h>
using namespace std;

// My Approach

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums[0];

        int n = nums.size() - 1;
        int s = 0;
        int e = nums.size() - 1;
        int mid;

        while (s < e)
        {
            mid = s + (e - s) / 2;

            int prev = mid - 1 < 0 ? INT_MIN : nums[mid - 1];

            if (nums[mid] == nums[mid + 1])
            {
                if ((mid + n - 1) % 2 == 0)
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            else if (nums[mid] == prev)
            {
                if ((mid + 0 - 1) % 2 == 0)
                    s = mid + 1;
                else
                    e = mid - 1;
            }
            else
                return nums[mid];
        }

        return nums[e];
    }
};

// Good approach from chatgpt

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int s = 0, e = nums.size() - 1;

        while (s < e)
        {
            int mid = s + (e - s) / 2;

            // Ensure mid is even for checking the pair
            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1])
            {
                // Unique element is on the right
                s = mid + 2;
            }
            else
            {
                // Unique element is on the left including mid
                e = mid;
            }
        }

        return nums[s];
    }
};
