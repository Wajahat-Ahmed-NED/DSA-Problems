class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> seen;
        for (int num : nums)
        {
            if (seen[num])
            {
                return true;
            }
            seen[num] = 1;
        }
        return false;
    }
};