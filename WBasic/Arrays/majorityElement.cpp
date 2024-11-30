// The code implements the Boyer-Moore Voting Algorithm, which assumes that a majority element exists in the array, where the majority element is defined as an element appearing more than n/2 times.

// can also be done using unordered_map

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int ele = nums[0];
        int cnt = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                cnt = 1;
                ele = nums[i];
            }
            else if (ele == nums[i])
                cnt++;
            else
                cnt--;
        }

        return ele;
    }
};