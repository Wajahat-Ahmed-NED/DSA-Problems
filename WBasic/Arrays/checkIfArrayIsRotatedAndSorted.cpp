class Solution
{
public:
    bool check(vector<int> &nums)
    {
        // vector<int> nums = {3, 4, 5, 1, 2};
        int count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                count++;
            }
        }

        if (nums[0] < nums[nums.size() - 1])
        {
            count++;
        }
        // if rotated then nums[0] should be > nums[nums.size()-1]
        return count <= 1;
    }
};